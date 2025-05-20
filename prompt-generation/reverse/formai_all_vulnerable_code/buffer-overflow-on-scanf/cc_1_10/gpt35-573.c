//FormAI DATASET v1.0 Category: File handling ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int choice;
    char filename[20];
    FILE *fp=NULL;

    printf("Enter the name of the file you want to open: ");
    scanf("%s", filename);

    while(1)
    {
        printf("\n\nPlease choose an option: \n\n1. Write to the file\n2. Read from the file\n3. Close the file and exit\n\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                fp = fopen(filename, "a");

                char text[100];
                printf("\nEnter the text you want to append to the file: ");
                getchar();
                fgets(text, 100, stdin);

                fprintf(fp, "%s", text);

                printf("\nSuccessfully written to file!\n");

                fclose(fp);

                break;
            }
            case 2:
            {
                fp = fopen(filename, "r");

                if(fp == NULL)
                {
                    printf("\nError: Could not open file!\n");
                    break;
                }

                char line[100];

                printf("\nContents of file:\n\n");

                while(fgets(line, 100, fp) != NULL)
                {
                    printf("%s", line);
                }

                fclose(fp);

                break;
            }
            case 3:
            {
                if(fp != NULL)
                {
                    fclose(fp);
                }

                printf("\nGoodbye!\n");
                exit(0);

                break;
            }
            default:
            {
                printf("\nInvalid choice! Please choose again.\n");
                break;
            }
        }
    }

    return 0;
}