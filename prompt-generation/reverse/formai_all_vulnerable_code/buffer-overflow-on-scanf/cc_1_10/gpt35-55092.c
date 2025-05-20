//FormAI DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>

FILE *fp;

void createFile() {
    char fileName[20];
    printf("Enter the name of file to create: ");
    scanf("%s", fileName);
    fp = fopen(fileName, "w");

    if (fp == NULL) {
        printf("Error creating file.\n");
        exit(1);
    }
    printf("File created successfully!\n");
}

void writeFile() {
    char text[100];
    printf("Enter text to write into the file: ");
    scanf(" %[^\n]", text);

    fputs(text, fp);

    printf("Text written successfully to the file!\n");
}

void readFile() {
    char ch;
    printf("Reading contents of file:\n");
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    printf("\n");
}

void closeFile() {
    fclose(fp);
    printf("File closed successfully!\n");
}

int main() {
    int choice;
    do {
        printf("\n1. Create File\n2. Write to File\n3. Read from File\n4. Close File\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile();
                break;

            case 2:
                if (fp == NULL) {
                    printf("File not created yet!\n");
                    break;
                }
                writeFile();
                break;

            case 3:
                if (fp == NULL) {
                    printf("File not created yet!\n");
                    break;
                }
                readFile();
                break;

            case 4:
                if (fp == NULL) {
                    printf("File not created yet!\n");
                    break;
                }
                closeFile();
                break;

            case 5:
                exit(0);
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}