//FormAI DATASET v1.0 Category: File Synchronizer ; Style: rigorous
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>
#include <pthread.h>

#define MAX 1024
#define BUFSIZE 4096

typedef struct argstruct {
    char src[MAX];
    char dest[MAX];
    char file[MAX];
} ARGSTRUCT;

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

void *copyfile(void *ptr) {
    ARGSTRUCT *arg = (ARGSTRUCT *) ptr;

    char fullsrc[MAX];
    char fulldest[MAX];

    sprintf(fullsrc, "%s/%s", arg->src, arg->file);
    sprintf(fulldest, "%s/%s", arg->dest, arg->file);

    int sfd = open(fullsrc, O_RDONLY);

    if (sfd == -1) {
        printf("Error Opening File [%s] in source: %s\n", arg->file,
                strerror(errno));
        pthread_exit(NULL);
    }

    int dfd = open(fulldest, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (dfd == -1) {
        printf("Error Opening File [%s] in destination: %s\n", arg->file,
                strerror(errno));
        pthread_exit(NULL);
    }

    char buffer[BUFSIZE];
    int bytesread;

    while (1) {
        bytesread = read(sfd, buffer, BUFSIZE);

        if (bytesread == -1) {
            printf("Error Reading File [%s]: %s\n", arg->file,
                    strerror(errno));
            pthread_exit(NULL);
        }

        if (bytesread == 0) {
            break;
        }

        if (write(dfd, buffer, bytesread) == -1) {
            printf("Error Writing File [%s]: %s\n", arg->file,
                    strerror(errno));
            pthread_exit(NULL);
        }
    }

    close(sfd);
    close(dfd);

    printf("File [%s] Copied from [%s] to [%s]\n", arg->file, arg->src, arg->dest);
    pthread_exit(NULL);
}

void *syncfunc(void *ptr) {
    ARGSTRUCT *arg = (ARGSTRUCT *) ptr;

    pthread_t tid[BUFSIZE];
    int tidx = 0;

    DIR *sdirp = opendir(arg->src);

    if (sdirp == NULL) {
        printf("Error Opening Directory [%s]: %s\n", arg->src,
                strerror(errno));
        pthread_exit(NULL);
    }

    DIR *ddirp = opendir(arg->dest);

    if (ddirp == NULL) {
        printf("Error Opening Directory [%s]: %s\n", arg->dest,
                strerror(errno));
        closedir(sdirp);
        pthread_exit(NULL);
    }

    struct dirent *sdentp;
    struct dirent *ddentp;

    while (1) {
        sdentp = readdir(sdirp);

        if (sdentp == NULL) {
            break;
        }

        if (strcmp(sdentp->d_name, ".") && strcmp(sdentp->d_name, "..")) {

            bool found = false;

            while (1) {
                ddentp = readdir(ddirp);

                if (ddentp == NULL) {
                    printf("File [%s/%s] Not Found in Destination. Copying.\n",
                            arg->src, sdentp->d_name);

                    ARGSTRUCT *copyarg = (ARGSTRUCT *) malloc(sizeof(ARGSTRUCT));
                    strncpy(copyarg->src, arg->src, MAX - 1);
                    strncpy(copyarg->dest, arg->dest, MAX - 1);
                    strncpy(copyarg->file, sdentp->d_name, MAX - 1);
                    pthread_create(&(tid[tidx++]), NULL, copyfile,
                            (void *) copyarg);

                    break;
                }

                if (!strcmp(sdentp->d_name, ddentp->d_name)) {
                    found = true;
                    break;
                }
            }

            if (found) {
                struct stat sstat;
                struct stat dstat;

                char fullsrc[MAX];
                char fulldest[MAX];

                sprintf(fullsrc, "%s/%s", arg->src, sdentp->d_name);
                sprintf(fulldest, "%s/%s", arg->dest, sdentp->d_name);

                if (stat(fullsrc, &sstat) == -1) {
                    printf("Error Reading File [%s]: %s\n", fullsrc,
                            strerror(errno));
                    continue;
                }

                if (stat(fulldest, &dstat) == -1) {
                    printf("Error Reading File [%s]: %s\n", fulldest,
                            strerror(errno));
                    continue;
                }

                if (difftime(sstat.st_mtime, dstat.st_mtime) > 0) {
                    pthread_mutex_lock(&mut);

                    if (difftime(sstat.st_mtime, dstat.st_mtime) > 0) {
                        ARGSTRUCT *copyarg =
                                (ARGSTRUCT *) malloc(sizeof(ARGSTRUCT));
                        strncpy(copyarg->src, arg->src, MAX - 1);
                        strncpy(copyarg->dest, arg->dest, MAX - 1);
                        strncpy(copyarg->file, sdentp->d_name, MAX - 1);
                        pthread_create(&(tid[tidx++]), NULL, copyfile,
                                (void *) copyarg);
                    }

                    pthread_mutex_unlock(&mut);
                }
            }
        }
    }

    while (1) {
        ddentp = readdir(ddirp);

        if (ddentp == NULL) {
            break;
        }

        if (strcmp(ddentp->d_name, ".") && strcmp(ddentp->d_name, "..")) {
            bool found = false;

            rewinddir(sdirp);

            while (1) {
                sdentp = readdir(sdirp);

                if (sdentp == NULL) {
                    printf(
                            "File [%s/%s] Not Found in Source. Deleting from Destination.\n",
                            arg->dest, ddentp->d_name);

                    char fullpath[MAX];

                    sprintf(fullpath, "%s/%s", arg->dest, ddentp->d_name);

                    if (remove(fullpath) == -1) {
                        printf("Error Deleting File [%s]: %s\n", fullpath,
                                strerror(errno));
                    }

                    break;
                }

                if (!strcmp(sdentp->d_name, ddentp->d_name)) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                printf(
                        "File [%s/%s] Not Found in Source. Deleting from Destination.\n",
                        arg->dest, ddentp->d_name);

                char fullpath[MAX];

                sprintf(fullpath, "%s/%s", arg->dest, ddentp->d_name);

                if (remove(fullpath) == -1) {
                    printf("Error Deleting File [%s]: %s\n", fullpath,
                            strerror(errno));
                }
            }
        }
    }

    closedir(sdirp);
    closedir(ddirp);

    while (tidx--) {
        pthread_join(tid[tidx], NULL);
    }

    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <src_dir> <dest_dir>\n", argv[0]);
        return 0;
    }

    ARGSTRUCT arg;
    strncpy(arg.src, argv[1], MAX - 1);
    strncpy(arg.dest, argv[2], MAX - 1);
    strncpy(arg.file, "", MAX - 1);

    pthread_t tid;
    pthread_create(&tid, NULL, syncfunc, (void *) &arg);

    pthread_join(tid, NULL);

    pthread_mutex_destroy(&mut);

    return 0;
}