//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 1000
#define MAX_FILE_NAME_SIZE 50

typedef struct {
    char file_name[MAX_FILE_NAME_SIZE];
    int file_size;
} File;

int main() {
    char directory[MAX_FILE_NAME_SIZE];
    printf("Enter the directory to analyze: ");
    scanf("%s", directory);

    FILE *fp = fopen(directory, "r");
    if (fp == NULL) {
        printf("Error: Directory does not exist or cannot be opened.\n");
        return 1;
    }

    int file_count = 0;
    File files[MAX_FILES];

    while (file_count < MAX_FILES && fscanf(fp, "%s %d\n", files[file_count].file_name, &files[file_count].file_size)!= EOF) {
        file_count++;
    }

    fclose(fp);

    printf("\n");
    printf("+----------------------+\n");
    printf("| Directory: %s\n", directory);
    printf("+----------------------+\n");
    printf("| File Count: %d\n", file_count);
    printf("+----------------------+\n");
    printf("| Total Disk Space: %d bytes\n", 0);
    printf("+----------------------+\n");

    int total_disk_space = 0;

    for (int i = 0; i < file_count; i++) {
        total_disk_space += files[i].file_size;

        printf("| File Name: %s\n", files[i].file_name);
        printf("| File Size: %d bytes\n", files[i].file_size);
        printf("+----------------------+\n");
    }

    printf("\n");
    printf("+----------------------+\n");
    printf("| Total Disk Space: %d bytes\n", total_disk_space);
    printf("+----------------------+\n");

    return 0;
}