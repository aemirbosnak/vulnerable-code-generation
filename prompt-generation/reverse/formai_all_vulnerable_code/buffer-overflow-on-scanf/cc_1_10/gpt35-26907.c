//FormAI DATASET v1.0 Category: Digital Diary ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    FILE *fptr;
    int choice, day, month, year, i;
    char entry[500], ch;

    printf("\n***** Welcome to your Digital Diary! *****\n");

    printf("\nEnter the date of your entry (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);

    // Creating a file name with date as prefix
    char file_name[20];
    sprintf(file_name, "%02d%02d%d.txt", day, month, year);

    // Reading contents of existing file
    fptr = fopen(file_name, "r");
    if (fptr != NULL)
    {
        printf("\nExisting Entries:\n");
        while ((ch = fgetc(fptr)) != EOF)
        {
            printf("%c", ch);
        }
        fclose(fptr);
    }

    // Allowing user to choose an action
    printf("\n\nChoose an action:\n");
    printf("1. Add a new entry\n");
    printf("2. Exit the program\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        // Getting new entry from user
        printf("\nEnter your entry:\n");
        fflush(stdin);
        fgets(entry, 500, stdin);

        // Appending new entry to existing file or creating a new file
        fptr = fopen(file_name, "a");
        if (fptr == NULL)
        {
            printf("\nError creating file!");
            exit(1);
        }
        fprintf(fptr, "\n%s\n", entry);
        fclose(fptr);
        printf("\nEntry recorded successfully!\n");
        break;

    case 2:
        // Exiting program
        printf("\nThank you for using your Digital Diary!");
        exit(0);
        break;

    default:
        printf("\nInvalid choice! Please try again.");
        break;
    }

    return 0;
}