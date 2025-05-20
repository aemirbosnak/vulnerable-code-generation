//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

typedef struct _File {
    char name[255];
    long size;
} File;

void print_size(long size) {
    char unit[] = " KMGTPE";
    int i = 0;
    while(size >= 1024 && i < 7) {
        size /= 1024;
        i++;
    }
    printf("%ld%cB", size, unit[i]);
}

void print_file_list(File* files, int size) {
    printf("%-30s %-20s\n", "File Name", "Size");
    for(int i = 0; i < size; i++) {
        printf("%-30s ", files[i].name);
        print_size(files[i].size);
        printf("\n");
    }
}

int compare_file_size(const void* a, const void* b) {
    long sa = ((File*)a)->size;
    long sb = ((File*)b)->size;
    if(sa == sb) return 0;
    else if(sa < sb) return 1;
    else return -1;
}

int main(int argc, char* argv[]) {
    char dir[255];
    if(argc == 2) {
        strcpy(dir, argv[1]);
    } else {
        printf("Enter a directory: ");
        scanf("%s", dir);
    }

    DIR* d = opendir(dir);
    if(!d) {
        perror("Error opening directory");
        return 1;
    }

    struct dirent* entry;
    struct stat info;
    int size = 0;
    while((entry = readdir(d)) != NULL) {
        char path[255];
        sprintf(path, "%s/%s", dir, entry->d_name);
        if(stat(path, &info) < 0) {
            perror("Error stating file");
            continue;
        }
        if(S_ISREG(info.st_mode)) {
            size++;
        }
    }
    rewinddir(d);

    File files[size];
    int i = 0;
    while((entry = readdir(d)) != NULL) {
        char path[255];
        sprintf(path, "%s/%s", dir, entry->d_name);
        if(stat(path, &info) < 0) {
            perror("Error stating file");
            continue;
        }
        if(S_ISREG(info.st_mode)) {
            strcpy(files[i].name, entry->d_name);
            files[i].size = info.st_size;
            i++;
        }
    }
    closedir(d);

    qsort(files, size, sizeof(File), compare_file_size);

    print_file_list(files, size);

    return 0;
}