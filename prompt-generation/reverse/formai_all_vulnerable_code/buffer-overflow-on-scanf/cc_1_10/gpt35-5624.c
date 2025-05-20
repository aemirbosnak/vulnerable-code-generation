//FormAI DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// function to create a new file
void createFile(char *filename) {
    FILE *fp;
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file\n");
        exit(1);
    }
    fclose(fp);
    printf("File created successfully\n");
}

// function to append content to an existing file
void appendToFile(char *filename, char *content) {
    FILE *fp;
    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fprintf(fp, "%s", content);
    fclose(fp);
    printf("Content appended successfully\n");
}

// function to read content from a file
void readFile(char *filename) {
    char ch;
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    printf("Content of the file:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

int main() {
    printf("File handling program\n");
    printf("---------------------\n");
    char filename[50], content[100];
    int choice;
    do {
        printf("1. Create a new file\n");
        printf("2. Append content to an existing file\n");
        printf("3. Read content from a file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the name of the file: ");
                scanf("%s", filename);
                createFile(filename);
                break;
            case 2:
                printf("Enter the name of the file: ");
                scanf("%s", filename);
                printf("Enter the content: ");
                scanf("%s", content);
                appendToFile(filename, content);
                break;
            case 3:
                printf("Enter the name of the file: ");
                scanf("%s", filename);
                readFile(filename);
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