//FormAI DATASET v1.0 Category: File handling ; Style: brave
#include <stdio.h>

#define MAX_FILE_NAME 100
#define MAX_FILE_SIZE 500

int main()
{
    char file_name[MAX_FILE_NAME];
    char file_contents[MAX_FILE_SIZE];
    FILE *fp;
    int choice;

    printf("Welcome to the Brave C File Handling Program!\n");
    printf("Please choose an option below:\n\n");
    printf("1. Create a new file\n");
    printf("2. Write to an existing file\n");
    printf("3. Read from an existing file\n");
    printf("4. Exit\n\n");

    printf("Choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\nEnter the name of the file to create: ");
            scanf("%s", file_name);
            fp = fopen(file_name, "w+");
            if(fp == NULL)
            {
                printf("\nError creating file!");
                return -1;
            }
            printf("\nFile %s has been created successfully!", file_name);
            break;

        case 2:
            printf("\nEnter the name of the file to write to: ");
            scanf("%s", file_name);
            fp = fopen(file_name, "a");
            if(fp == NULL)
            {
                printf("\nError opening file!");
                return -1;
            }
            printf("\nEnter contents to be written to %s: ", file_name);
            scanf(" %[^\n]s", file_contents);
            fprintf(fp, "%s\n", file_contents);
            printf("\nContents have been written to %s successfully!", file_name);
            break;

        case 3:
            printf("\nEnter the name of the file to read from: ");
            scanf("%s", file_name);
            fp = fopen(file_name, "r");
            if(fp == NULL)
            {
                printf("\nError opening file!");
                return -1;
            }
            printf("\nContents of %s:\n", file_name);
            while(fgets(file_contents, MAX_FILE_SIZE, fp) != NULL)
            {
                printf("%s", file_contents);
            }
            break;

        case 4:
            printf("\nGoodbye!");
            return 0;

        default:
            printf("\nInvalid choice! Please try again.");
            return -1;
    }

    fclose(fp);
    return 0;
}