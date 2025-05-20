//Falcon-180B DATASET v1.0 Category: File handling ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_FILE_NAME_SIZE 50

typedef struct {
    char name[MAX_FILE_NAME_SIZE];
    FILE *fp;
} File;

int main() {
    File file;
    char line[MAX_LINE_SIZE];
    int num_files = 0;

    // Open first file
    printf("Enter file name: ");
    scanf("%s", file.name);
    file.fp = fopen(file.name, "r");
    if (file.fp == NULL) {
        printf("Error opening file %s\n", file.name);
        return 1;
    }

    // Read first file
    while (fgets(line, MAX_LINE_SIZE, file.fp)!= NULL) {
        printf("%s", line);
    }

    // Open subsequent files
    char choice;
    do {
        printf("\nDo you want to open another file? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            printf("Enter file name: ");
            scanf("%s", file.name);
            file.fp = fopen(file.name, "r");
            if (file.fp == NULL) {
                printf("Error opening file %s\n", file.name);
                return 1;
            }
            num_files++;
        }
    } while (choice == 'y' || choice == 'Y');

    // Read subsequent files
    for (int i = 0; i < num_files; i++) {
        printf("\nContents of file %s:\n", file.name);
        rewind(file.fp);
        while (fgets(line, MAX_LINE_SIZE, file.fp)!= NULL) {
            printf("%s", line);
        }
    }

    // Close files
    for (int i = 0; i < num_files; i++) {
        fclose(file.fp);
    }

    return 0;
}