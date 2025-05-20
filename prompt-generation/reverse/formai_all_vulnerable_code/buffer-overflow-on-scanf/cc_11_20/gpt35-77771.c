//FormAI DATASET v1.0 Category: File handling ; Style: curious
#include<stdio.h>
#include<stdlib.h>

int main()
{
    char fileName[20], ch;
    int choice, count = 0;

    printf("What do you want to do?\n");
    printf("1. Create a new file\n");
    printf("2. Read an existing file\n");
    printf("3. Write to a file\n");
    printf("4. Append to a file\n");
    printf("5. Delete a file\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
        {
            printf("Enter the file name: ");
            scanf("%s", fileName);

            FILE *fp = fopen(fileName, "w");

            if(fp == NULL)
            {
                printf("Unable to create file\n");
                exit(0);
            }

            printf("File created successfully\n");
            fclose(fp);
        }
        break;

        case 2:
        {
            printf("Enter the file name: ");
            scanf("%s", fileName);

            FILE *fp = fopen(fileName, "r");

            if(fp == NULL)
            {
                printf("Unable to open file\n");
                exit(0);
            }

            printf("File contents: \n");

            while((ch = fgetc(fp)) != EOF)
            {
                putchar(ch);
                count++;
            }

            fclose(fp);
        }
        break;

        case 3:
        {
            printf("Enter the file name: ");
            scanf("%s", fileName);

            FILE *fp = fopen(fileName, "w");

            if(fp == NULL)
            {
                printf("Unable to open file\n");
                exit(0);
            }

            printf("Enter the data to write: \n");
            scanf(" %[^\n]s", fileName);

            fprintf(fp, "%s", fileName);
            fclose(fp);
        }
        break;

        case 4:
        {
            printf("Enter the file name: ");
            scanf("%s", fileName);

            FILE *fp = fopen(fileName, "a");

            if(fp == NULL)
            {
                printf("Unable to open file\n");
                exit(0);
            }

            printf("Enter the data to append: \n");
            scanf(" %[^\n]s", fileName);

            fprintf(fp, "%s", fileName);
            fclose(fp);
        }
        break;

        case 5:
        {
            printf("Enter the file name: ");
            scanf("%s", fileName);

            if(remove(fileName) == 0)
            {
                printf("File deleted successfully\n");
            }
            else
            {
                printf("Unable to delete file\n");
            }
        }
        break;

        default:
        {
            printf("Invalid choice\n");
            exit(0);
        }
    }

    printf("Number of characters: %d", count);

    return 0;
}