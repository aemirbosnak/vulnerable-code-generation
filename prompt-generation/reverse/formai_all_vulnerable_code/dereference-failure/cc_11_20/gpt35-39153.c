//FormAI DATASET v1.0 Category: File Synchronizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAXPATHLENGTH 256

/*Function to recursively traverse the directory and synchronize files*/
void doSync(char srcPath[MAXPATHLENGTH], char desPath[MAXPATHLENGTH]) {
    DIR *srcDir, *desDir;
    struct dirent *srcEnt, *desEnt;
    struct stat srcStat, desStat;
    char srcFilePath[MAXPATHLENGTH], desFilePath[MAXPATHLENGTH];
    int srcfd, desfd;

    /*Open the source directory*/
    srcDir = opendir(srcPath);
    if(srcDir == NULL) {
        perror("Unable to open source directory");
        exit(EXIT_FAILURE);
    }

    /*Open the destination directory*/
    desDir = opendir(desPath);
    if(desDir == NULL) {
        perror("Unable to open destination directory");
        exit(EXIT_FAILURE);
    }

    /*Read directory entries and synchronize files*/
    while(1) {
        srcEnt = readdir(srcDir);
        if(srcEnt == NULL) {
            break;
        }
        if(strcmp(srcEnt->d_name, ".") == 0 || strcmp(srcEnt->d_name, "..") == 0) {
            continue;
        }

        snprintf(srcFilePath, MAXPATHLENGTH, "%s/%s", srcPath, srcEnt->d_name);
        stat(srcFilePath, &srcStat);

        snprintf(desFilePath, MAXPATHLENGTH, "%s/%s", desPath, srcEnt->d_name);
        if(stat(desFilePath, &desStat) == -1) {
            //Destination file does not exist
            if(S_ISREG(srcStat.st_mode)) {
                //Regular file, copy to destination
                srcfd = open(srcFilePath, O_RDONLY);
                if(srcfd == -1) {
                    perror("Unable to open source file");
                    continue;
                }
                desfd = open(desFilePath, O_WRONLY | O_CREAT, srcStat.st_mode);
                if(desfd == -1) {
                    perror("Unable to create destination file");
                    continue;
                }
                char buf[1024];
                int n;
                while((n = read(srcfd, buf, sizeof(buf))) > 0) {
                    write(desfd, buf, n);
                }
                close(srcfd);
                close(desfd);
            } else if(S_ISDIR(srcStat.st_mode)) {
                //Directory, create in destination
                mkdir(desFilePath, srcStat.st_mode);
            }
        } else {
            //Destination file exists, compare modification times
            if(S_ISREG(srcStat.st_mode) && S_ISREG(desStat.st_mode)) {
                if(srcStat.st_mtime > desStat.st_mtime) {
                    //Source file is newer, copy to destination
                    srcfd = open(srcFilePath, O_RDONLY);
                    if(srcfd == -1) {
                        perror("Unable to open source file");
                        continue;
                    }
                    desfd = open(desFilePath, O_WRONLY | O_TRUNC);
                    if(desfd == -1) {
                        perror("Unable to open destination file");
                        continue;
                    }
                    char buf[1024];
                    int n;
                    while((n = read(srcfd, buf, sizeof(buf))) > 0) {
                        write(desfd, buf, n);
                    }
                    close(srcfd);
                    close(desfd);
                } else if(srcStat.st_mtime < desStat.st_mtime) {
                    //Destination file is newer, copy to source
                    srcfd = open(desFilePath, O_RDONLY);
                    if(srcfd == -1) {
                        perror("Unable to open source file");
                        continue;
                    }
                    desfd = open(srcFilePath, O_WRONLY | O_TRUNC);
                    if(desfd == -1) {
                        perror("Unable to open destination file");
                        continue;
                    }
                    char buf[1024];
                    int n;
                    while((n = read(srcfd, buf, sizeof(buf))) > 0) {
                        write(desfd, buf, n);
                    }
                    close(srcfd);
                    close(desfd);
                }
            } else if(S_ISDIR(srcStat.st_mode) && S_ISDIR(desStat.st_mode)) {
                //Both source and destination are directories, recurse into both
                doSync(srcFilePath, desFilePath);
            } else {
                printf("Cannot synchronize file %s with %s\n", srcFilePath, desFilePath);
            }
        }
    }

    /*Close directories*/
    closedir(srcDir);
    closedir(desDir);
}

/*Main function*/
int main(int argc, char *argv[]) {
    /*Parse command line arguments*/
    if(argc != 3) {
        printf("Usage: %s [source directory] [destination directory]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *srcPath = argv[1];
    char *desPath = argv[2];

    /*Synchronize files*/
    doSync(srcPath, desPath);

    printf("Synchronization complete");
    return 0;
}