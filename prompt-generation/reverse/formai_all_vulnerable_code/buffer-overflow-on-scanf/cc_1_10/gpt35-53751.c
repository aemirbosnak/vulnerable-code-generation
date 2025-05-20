//FormAI DATASET v1.0 Category: System administration ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void printMenu() {
    printf("System Administration Example Program\n");
    printf("-------------------------------------\n\n");
    printf("Menu:\n");
    printf("1: List all files in current directory\n");
    printf("2: Create a new file\n");
    printf("3: Delete a file\n");
    printf("4: Exit program\n\n");
}

void listFiles() {
    system("ls");
}

void createFile() {
    char filename[MAX_LENGTH];
    FILE *fp;

    printf("Enter file name: ");
    fgets(filename, MAX_LENGTH, stdin);
    strtok(filename, "\n");

    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error creating file %s\n", filename);
        return;
    }

    printf("File %s created successfully\n", filename);
    fclose(fp);
}

void deleteFile() {
    char filename[MAX_LENGTH];

    printf("Enter file name to delete: ");
    fgets(filename, MAX_LENGTH, stdin);
    strtok(filename, "\n");

    if (remove(filename) == 0) {
        printf("File %s deleted successfully\n", filename);
    } else {
        printf("Error deleting file %s\n", filename);
    }
}

int main() {
    int choice;

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1:
                listFiles();
                break;
            case 2:
                createFile();
                break;
            case 3:
                deleteFile();
                break;
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

        printf("\n");

    } while (choice != 4);

    return 0;
}