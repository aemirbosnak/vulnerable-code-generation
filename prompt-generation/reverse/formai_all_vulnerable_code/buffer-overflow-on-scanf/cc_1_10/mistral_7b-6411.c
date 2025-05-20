//MISTRAL-7B DATASET v1.0 Category: System administration ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_FILES 10
#define MAX_CHARS 100

typedef struct {
    char name[MAX_CHARS];
    int size;
    struct stat stat_buf;
} file_info;

int main() {
    int i, fd;
    file_info files[MAX_FILES];

    printf("Welcome to the Magical File Organizer v1.0!\n");
    printf("This program will help you find and sort your files based on their magical properties.\n");

    for (i = 0; i < MAX_FILES; i++) {
        printf("Enter the name of the file %d: ", i + 1);
        scanf("%s", files[i].name);

        if ((fd = open(files[i].name, O_RDONLY)) < 0) {
            perror("Error opening file");
            continue;
        }

        if (fstat(&files[i].stat_buf, (struct stat*)&files[i].stat_buf) < 0) {
            perror("Error getting file status");
            close(fd);
            continue;
        }

        files[i].size = files[i].stat_buf.st_size;
        close(fd);
    }

    printf("\nFiles added successfully!\n");
    printf("Now we will sort them based on their magical properties...\n");

    // Sorting files based on their magical properties
    for (i = 0; i < MAX_FILES - 1; i++) {
        for (int j = i + 1; j < MAX_FILES; j++) {
            if (files[i].size > files[j].size) {
                file_info temp = files[i];
                files[i] = files[j];
                files[j] = temp;
            }
        }
    }

    // Printing sorted files
    printf("\nFiles sorted based on their size:\n");
    for (i = 0; i < MAX_FILES; i++) {
        printf("%s - %d bytes\n", files[i].name, files[i].size);
    }

    return 0;
}