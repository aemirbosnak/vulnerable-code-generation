//FormAI DATASET v1.0 Category: File handling ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100 // Maximum length of file name and file content

void createFile(char fileName[MAX_LEN], char fileContent[MAX_LEN])
{
    FILE *fp;
    fp = fopen(fileName, "w");
    if (fp == NULL) {
        printf("Unable to create file!\n");
        exit(1);
    }
    fputs(fileContent, fp);
    printf("File created successfully.\n");
    fclose(fp);
}

void readFile(char fileName[MAX_LEN])
{
    FILE *fp;
    char ch;
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Unable to read file!\n");
        exit(1);
    }
    printf("\nFile content:\n");
    while ((ch = fgetc(fp)) != EOF)
        printf("%c", ch);
    fclose(fp);
}

void appendToFile(char fileName[MAX_LEN], char fileContent[MAX_LEN])
{
    FILE *fp;
    fp = fopen(fileName, "a");
    if (fp == NULL) {
        printf("Unable to append to file!\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END); // Set file pointer to end of file
    fputs(fileContent, fp);
    printf("Data written successfully.\n");
    fclose(fp);
}

int main()
{
    char fileName[MAX_LEN], fileContent[MAX_LEN], choice;
    printf("Enter file name: ");
    scanf("%s", fileName);
    printf("Enter file content: ");
    scanf(" %[^\n]", fileContent);
    createFile(fileName, fileContent);
    do {
        printf("\nSelect an option:\n");
        printf("1. Read file\n");
        printf("2. Append to file\n");
        printf("3. Exit\n");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                readFile(fileName);
                break;
            case '2':
                printf("Enter new data to append: ");
                scanf(" %[^\n]", fileContent);
                appendToFile(fileName, fileContent);
                break;
            case '3':
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != '3');
    return 0;
}