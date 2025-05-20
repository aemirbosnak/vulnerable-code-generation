//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char **argv) {
    DIR *dir;
    struct dirent *ent;
    struct stat statbuf;
    struct passwd *pw;
    struct group *gr;
    char path[BUFSIZ];
    char timebuf[BUFSIZ];
    int i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s directory\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((dir = opendir(argv[1])) == NULL) {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ent = readdir(dir)) != NULL) {
        snprintf(path, BUFSIZ, "%s/%s", argv[1], ent->d_name);

        if (lstat(path, &statbuf) == -1) {
            perror(path);
            continue;
        }

        if ((pw = getpwuid(statbuf.st_uid)) == NULL) {
            perror("getpwuid");
            continue;
        }

        if ((gr = getgrgid(statbuf.st_gid)) == NULL) {
            perror("getgrgid");
            continue;
        }

        ctime_r(&statbuf.st_mtime, timebuf);
        timebuf[strlen(timebuf) - 1] = '\0';

        printf("%-10s %3d %s %s %-8s %-8s %10ld %s\n",
               ent->d_name,
               statbuf.st_nlink,
               pw->pw_name,
               gr->gr_name,
               timebuf,
               (S_ISDIR(statbuf.st_mode)) ? "d" : "-",
               statbuf.st_size,
               path);
    }

    closedir(dir);

    return EXIT_SUCCESS;
}