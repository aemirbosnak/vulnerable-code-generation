//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 256

struct fileinfo {
    char path[MAX_PATH_LENGTH];
    char type[10];
    long size;
};

int main() {
    DIR *dirp;
    struct dirent *ep;
    struct fileinfo file;
    int i;

    dirp = opendir("/");
    if (dirp == NULL) {
        perror("opendir");
        exit(1);
    }

    while ((ep = readdir(dirp))!= NULL) {
        strcpy(file.path, ep->d_name);
        if (ep->d_type == DT_DIR) {
            if (chdir(ep->d_name) == -1) {
                perror("chdir");
                exit(1);
            }
            struct dirent *dep;
            dirp = opendir(".");
            if (dirp == NULL) {
                perror("opendir");
                exit(1);
            }
            while ((dep = readdir(dirp))!= NULL) {
                if (strcmp(dep->d_name, ".") == 0 || strcmp(dep->d_name, "..") == 0) {
                    continue;
                }
                strcpy(file.path, dep->d_name);
                struct stat buf;
                if (stat(file.path, &buf) == 0) {
                    file.size = buf.st_size;
                    file.type[0] = '\0';
                    switch (S_ISDIR(buf.st_mode)) {
                        case 1:
                            strcpy(file.type, "Directory");
                            break;
                        case 2:
                            strcpy(file.type, "Regular File");
                            break;
                        case 3:
                            strcpy(file.type, "Symlink");
                            break;
                        case 4:
                            strcpy(file.type, "Character Device");
                            break;
                        case 5:
                            strcpy(file.type, "Block Device");
                            break;
                        case 6:
                            strcpy(file.type, "FIFO");
                            break;
                        case 7:
                            strcpy(file.type, "Socket");
                            break;
                        default:
                            strcpy(file.type, "Unknown");
                            break;
                    }
                    printf("%s %s %ld\n", file.path, file.type, file.size);
                }
            }
            closedir(dirp);
        }
    }
    closedir(dirp);

    return 0;
}