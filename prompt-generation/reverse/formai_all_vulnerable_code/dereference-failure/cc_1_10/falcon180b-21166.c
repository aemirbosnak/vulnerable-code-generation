//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_FILES 1000

typedef struct {
    char name[100];
    long long size;
    int isDir;
} FileInfo;

void getDirectoryContents(char* path, FileInfo files[MAX_FILES]) {
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(path))!= NULL) {
        int count = 0;

        while ((ent = readdir(dir))!= NULL) {
            if (count >= MAX_FILES) {
                break;
            }

            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
                continue;
            }

            FileInfo file;
            strcpy(file.name, ent->d_name);
            file.size = ent->d_type == DT_DIR? 0 : ent->d_reclen;
            file.isDir = ent->d_type == DT_DIR? 1 : 0;

            files[count++] = file;
        }

        closedir(dir);
    }
}

void printFileInfo(FileInfo file) {
    if (file.isDir) {
        printf("[DIR] %s\n", file.name);
    } else {
        printf("%s (%lld bytes)\n", file.name, file.size);
    }
}

void printFileSizes(FileInfo files[MAX_FILES], int count) {
    printf("Total size of directory: %lld bytes\n", 0);

    for (int i = 0; i < count; i++) {
        printf("File %d:\n", i + 1);
        printFileInfo(files[i]);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }

    char path[1000];
    strcpy(path, argv[1]);

    FileInfo files[MAX_FILES];
    getDirectoryContents(path, files);

    int count = 0;
    for (int i = 0; i < MAX_FILES && files[i].name[0]!= '\0'; i++) {
        count++;
    }

    printFileSizes(files, count);

    return 0;
}