//FormAI DATASET v1.0 Category: File handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char filename[20], c, text[1000], search[20];
    int option, count = 0;

    printf("Welcome to Castle Files!\n");
    printf("What would you like to do?\n");
    printf("1. Write to a file\n2. Read from a file\n3. Search for a word in a file\n");
    scanf("%d", &option);

    switch(option) {
        case 1: // Writing to a file
            printf("\nEnter a filename: ");
            scanf("%s", filename);

            fp = fopen(filename, "w");

            printf("Enter your message: ");
            getchar();
            fgets(text, 1000, stdin);

            fprintf(fp, "%s", text);
            printf("\nYour message has been written to the file successfully.\n");
            fclose(fp);
            break;

        case 2: // Reading from a file
            printf("\nEnter a filename: ");
            scanf("%s", filename);

            fp = fopen(filename, "r");

            if(fp == NULL) {
                printf("Could not open the file. Please try again.\n");
                exit(0);
            }

            printf("\nThe contents of the file are: \n\n");

            while((c = fgetc(fp)) != EOF) {
                printf("%c", c);
            }

            fclose(fp);
            break;

        case 3: // Searching for a word in a file
            printf("\nEnter a filename: ");
            scanf("%s", filename);

            fp = fopen(filename, "r");

            if(fp == NULL) {
                printf("Could not open the file. Please try again.\n");
                exit(0);
            }

            printf("\nEnter the word you want to search: ");
            scanf("%s", search);

            while(fscanf(fp, "%s", text) != EOF) {
                if(strcmp(text, search) == 0) {
                    count++;
                }
            }

            printf("\nThe word '%s' appears %d times in the file.\n", search, count);

            fclose(fp);
            break;

        default:
            printf("\nInvalid choice.\n");
            break;
    }

    printf("\nThank you for using Castle Files! We hope to see you again soon.\n");

    return 0;
}