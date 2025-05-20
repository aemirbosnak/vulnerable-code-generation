#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_FILE_CONTENTS 4096

void writeToFile() {
    char filename[MAX_FILENAME_LENGTH];
    char contents[MAX_FILE_CONTENTS];
    printf("Enter filename: ");
    scanf("%255s", filename);
    printf("Enter file contents (up to 4096 characters): ");
    scanf(" %[^\n]", contents);
    FILE *file = fopen(filename, "w");
    if (file) {
        fprintf(file, "%s", contents);
        fclose(file);
        printf("File written successfully.\n");
    } else {
        printf("Error opening file.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nSimple File System\n");
        printf("1. Write to file\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                writeToFile();
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
