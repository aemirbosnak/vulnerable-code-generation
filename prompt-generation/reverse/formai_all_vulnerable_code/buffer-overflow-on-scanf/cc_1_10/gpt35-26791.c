//FormAI DATASET v1.0 Category: File handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Function to print the menu options
void printMenu() {
    printf("\n------- File Handling Program -------\n");
    printf("Select an option:\n");
    printf("1. Create a file\n");
    printf("2. Read from a file\n");
    printf("3. Write to a file\n");
    printf("4. Append to a file\n");
    printf("5. Delete a file\n");
    printf("6. Exit\n");
    printf("-------------------------------------\n");
}

int main() {
    int choice;
    char fileName[20], fileContent[100];

    while(1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter file name to create: ");
                scanf("%s", fileName);

                // Creating a file
                FILE *fp;
                fp = fopen(fileName, "w");
                if(fp == NULL) {
                    printf("Unable to create file %s\n", fileName);
                } else {
                    printf("File %s created successfully\n", fileName);
                    fclose(fp);
                }
                break;

            case 2:
                printf("Enter file name to read: ");
                scanf("%s", fileName);

                // Reading from a file
                fp = fopen(fileName, "r");
                if(fp == NULL) {
                    printf("Unable to open file %s\n", fileName);
                } else {
                    printf("File %s opened successfully\n", fileName);
                    char ch;
                    printf("File content:\n");
                    while((ch = fgetc(fp)) != EOF) {
                        printf("%c", ch);
                    }
                    fclose(fp);
                }
                break;

            case 3:
                printf("Enter file name to write to: ");
                scanf("%s", fileName);

                printf("Enter content to write: ");
                scanf("%s", fileContent);

                // Writing/Overwriting to a file
                fp = fopen(fileName, "w");
                if(fp == NULL) {
                    printf("Unable to open file %s\n", fileName);
                } else {
                    fputs(fileContent, fp);
                    printf("Content written to file %s successfully\n", fileName);
                    fclose(fp);
                }
                break;

            case 4:
                printf("Enter file name to append to: ");
                scanf("%s", fileName);

                printf("Enter content to append: ");
                scanf("%s", fileContent);

                // Appending to a file
                fp = fopen(fileName, "a");
                if(fp == NULL) {
                    printf("Unable to open file %s\n", fileName);
                } else {
                    fputs(fileContent, fp);
                    printf("Content appended to file %s successfully\n", fileName);
                    fclose(fp);
                }
                break;

            case 5:
                printf("Enter file name to delete: ");
                scanf("%s", fileName);

                // Deleting a file
                if(remove(fileName) == 0) {
                    printf("File %s deleted successfully\n", fileName);
                } else {
                    printf("Unable to delete file %s\n", fileName);
                }
                break;

            case 6:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}