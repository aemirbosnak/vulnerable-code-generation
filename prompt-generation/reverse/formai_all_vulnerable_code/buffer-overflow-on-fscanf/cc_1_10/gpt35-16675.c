//FormAI DATASET v1.0 Category: Digital Diary ; Style: artistic
#include<stdio.h> 

/*
A unique digital diary program in C language 
Author: [Your name]
*/

int main()
{
    int choice;
    char password[25], title[50], content[500];

    printf("Welcome to your digital diary!\n\n");
    printf("Please enter a password to secure your diary: ");
    scanf("%s", password);

    // Adding a loop to allow the user to enter new entries into their diary
    while(1)
    {
        // Giving the user options to choose what they want to do with their digital diary
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new entry\n");
        printf("2. Read an entry\n");
        printf("3. Exit the program\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the title of your entry: ");
                scanf("%s", title);
                printf("Enter the content of your entry: ");
                scanf("%s", content);

                // Creating a file with the title as the name
                FILE *fp;
                fp = fopen(title, "w");
                fprintf(fp, "%s\n", content);
                fclose(fp);

                printf("\nEntry added successfully!\n");
                break;

            case 2:
                printf("\nEnter the title of the entry you want to read: ");
                scanf("%s", title);

                // Opening the file and printing the content
                fp = fopen(title, "r");
                if(fp == NULL)
                {
                    printf("\nSorry, no such entry found.\n");
                }
                else
                {
                    printf("\nHere is the content of your entry:\n");
                    fscanf(fp, "%s", content);
                    printf("%s\n", content);
                    fclose(fp);
                }
                break;

            case 3:
                printf("\nGoodbye!\n");
                return 0;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}