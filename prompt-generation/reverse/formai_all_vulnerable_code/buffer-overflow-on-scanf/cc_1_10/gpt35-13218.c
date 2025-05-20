//FormAI DATASET v1.0 Category: File handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main()
{
    char file_name[MAX_SIZE];
    char file_content[MAX_SIZE];
    char new_file_name[MAX_SIZE];
    char decision[MAX_SIZE];
    FILE *fp;

    printf("Enter the name of the file: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "r");

    if (fp == NULL)
    {
        printf("The file does not exist.\n");
        return 1;
    }

    printf("The contents of the file are:\n");
    while (fgets(file_content, MAX_SIZE, fp) != NULL)
    {
        printf("%s", file_content);
    }

    fclose(fp);

    printf("\nDo you want to create a new file? (yes or no): ");
    scanf("%s", decision);

    if (strcmp(decision, "yes") == 0)
    {
        printf("Enter the name of the new file: ");
        scanf("%s", new_file_name);

        fp = fopen(new_file_name, "w");

        if (fp == NULL)
        {
            printf("Could not create the new file.\n");
            return 1;
        }

        printf("Enter the contents of the new file (max 100 characters):\n");
        scanf("%s", file_content);

        fprintf(fp, "%s\n", file_content);

        fclose(fp);

        printf("The new file has been created.\n");
    }
    else
    {
        printf("Program terminated.\n");
    }

    return 0;
}