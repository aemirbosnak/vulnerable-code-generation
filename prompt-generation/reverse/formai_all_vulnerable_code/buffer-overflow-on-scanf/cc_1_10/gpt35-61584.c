//FormAI DATASET v1.0 Category: File handling ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char file_name[25], ch, text[1000];
    int option, count = 0, i;

    printf("What operation do you want to perform?\n");
    printf("1. Write a file\n");
    printf("2. Read a file\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch (option)
    {
        case 1:
            printf("Enter the file name: ");
            scanf("%s", file_name);

            fp = fopen(file_name, "w");

            if (fp == NULL)
            {
                printf("Error opening file!\n");
                exit(1);
            }

            printf("Enter the text: ");
            scanf(" %[^\n]s", text);
            fprintf(fp, "%s", text);

            fclose(fp);
            break;

        case 2:
            printf("Enter the file name: ");
            scanf("%s", file_name);

            fp = fopen(file_name, "r");

            if (fp == NULL)
            {
                printf("Error opening file!\n");
                exit(1);
            }

            printf("\n\nContents of the file:\n");

            while ((ch = fgetc(fp)) != EOF)
            {
                printf("%c", ch);
                count++;
            }

            fclose(fp);

            printf("\n\nNumber of characters: %d", count);
            break;

        default:
            printf("Invalid option!");
            break;
    }

    return 0;
}