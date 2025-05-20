//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_FILE_NAME_LENGTH 100
#define MAX_BUFFER_SIZE 2048
#define MIN_LINE_LENGTH 10

void clearScreen() {
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

void displayMainMenu() {
    printf("--------------------------------------------------\n");
    printf("| CEbook Reader v1.0                            |\n");
    printf("|------------------------------------------------|\n");
    printf("| 1. Load a text file                           |\n");
    printf("| 2. Exit                                       |\n");
    printf("--------------------------------------------------\n");
}

int isFileValid(char *fileName) {
    int fileExtensionIndex = strlen(fileName) - 4;
    if (fileExtensionIndex >= 0 && (strcmp(&fileName[fileExtensionIndex], ".txt") == 0))
        return 1;
    else
        return 0;
}

int main() {
    char fileName[MAX_FILE_NAME_LENGTH];
    char buffer[MAX_BUFFER_SIZE];
    int fileIsOpen = 0;

    while (1) {
        clearScreen();
        displayMainMenu();

        int choice;
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", fileName);
                getchar(); // consume newline

                if (strlen(fileName) > MAX_FILE_NAME_LENGTH) {
                    printf("Error: File name too long.\n");
                    getchar();
                    break;
                }

                if (!isFileValid(fileName)) {
                    printf("Error: Invalid file format.\n");
                    getchar();
                    break;
                }

                FILE *file = fopen(fileName, "r");
                if (file == NULL) {
                    printf("Error: Could not open file %s.\n", fileName);
                    getchar();
                    break;
                }

                fileIsOpen = 1;
                int lineNumber = 1;
                while (fgets(buffer, MAX_BUFFER_SIZE, file)) {
                    if (strlen(buffer) < MIN_LINE_LENGTH) {
                        printf("\nError: Line %d too short.\n", lineNumber);
                        fclose(file);
                        getchar();
                        break;
                    }
                    printf("%s", buffer);
                    lineNumber++;
                }

                if (feof(file)) {
                    printf("\nEnd of file reached.\n");
                } else {
                    fclose(file);
                    printf("\nError: Unexpected end of file.\n");
                }

                getchar();
                break;

            case 2:
                if (fileIsOpen) {
                    fclose(file);
                }
                return 0;

            default:
                printf("\nError: Invalid choice.\n");
                getchar();
        }
    }

    return 0;
}