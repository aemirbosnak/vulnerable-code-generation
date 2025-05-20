//FormAI DATASET v1.0 Category: File handling ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[50], str[100], ch;
    int choice;
    FILE *fp;

    while(1) {
        printf("Choose an option:\n");
        printf("1. Create a file\n");
        printf("2. Write to a file\n");
        printf("3. Read from a file\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the filename to create: ");
                scanf("%s", filename);

                fp = fopen(filename, "w");

                if(fp == NULL) {
                    printf("Error in creating file.");
                    exit(0);
                }

                printf("File is created successfully.\n");

                fclose(fp);
                break;

            case 2:
                printf("Enter the filename to write to: ");
                scanf("%s", filename);

                fp = fopen(filename, "a");

                if(fp == NULL) {
                    printf("Error in opening file.");
                    exit(0);
                }

                printf("Enter the string to write: ");
                scanf("%s", str);

                fprintf(fp, "%s", str);
                printf("Text successfully written to file.\n");

                fclose(fp);
                break;

            case 3:
                printf("Enter the filename to read from: ");
                scanf("%s", filename);

                fp = fopen(filename, "r");

                if(fp == NULL) {
                    printf("Error in opening file.");
                    exit(0);
                }

                while((ch = fgetc(fp)) != EOF)
                    printf("%c", ch);

                printf("\n");

                fclose(fp);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid option.\n");
                break;
        }
    }

    return 0;
}