//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILES 100

struct File {
    char name[100];
    char path[200];
    int size;
    int modified;
};

void read_files(struct File files[], int num_files) {
    char line[200];
    FILE *fp;

    for (int i = 0; i < num_files; i++) {
        sprintf(files[i].path, "%s/%s", "source", files[i].name);
        fp = fopen(files[i].path, "r");

        if (fp == NULL) {
            printf("File not found: %s\n", files[i].name);
            exit(1);
        }

        fgets(line, 200, fp);
        sscanf(line, "%d", &files[i].size);

        fclose(fp);
    }
}

void sync_files(struct File source_files[], struct File dest_files[], int num_files) {
    char command[200];

    for (int i = 0; i < num_files; i++) {
        if (source_files[i].modified!= dest_files[i].modified) {
            if (source_files[i].modified > dest_files[i].modified) {
                sprintf(command, "cp -r %s %s", source_files[i].path, dest_files[i].path);
                system(command);
            } else {
                sprintf(command, "cp -r %s %s", dest_files[i].path, source_files[i].path);
                system(command);
            }

            dest_files[i].modified = source_files[i].modified;
        }
    }
}

int main() {
    struct File source_files[MAX_FILES], dest_files[MAX_FILES];
    int num_source_files, num_dest_files;

    printf("Enter number of files in source directory: ");
    scanf("%d", &num_source_files);

    printf("Enter number of files in destination directory: ");
    scanf("%d", &num_dest_files);

    read_files(source_files, num_source_files);
    read_files(dest_files, num_dest_files);

    sync_files(source_files, dest_files, num_source_files);

    return 0;
}