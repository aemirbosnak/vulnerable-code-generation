//FormAI DATASET v1.0 Category: Digital Diary ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the structure diary
struct diary
{
    char date[20];
    char content[300];
};

// Function to create a new entry in diary
void new_entry(void)
{
    struct diary entry;
    FILE *file;
    char filename[50];

    // Getting the filename
    printf("Enter the filename (with .txt extension) where you want to create a new entry:\n");
    scanf("%s", filename);

    // Opening file in append mode
    file = fopen(filename, "a+");

    if(file == NULL)
    {
        printf("Error in opening the file.\n");
        exit(1);
    }

    // Getting the date
    printf("Enter the date for the entry (DD/MM/YYYY format):\n");
    scanf(" %[^\n]%*c", entry.date);

    // Getting the content of the entry
    printf("Enter the content for the entry:\n");
    scanf(" %[^\n]%*c", entry.content);

    // Writing the entry in the file
    fprintf(file, "Date: %s\nContent: %s\n\n", entry.date, entry.content);

    printf("Entry created successfully!\n");

    // Closing the file
    fclose(file);
}

// Function to display all the entries in diary
void display_entries(void)
{
    FILE *file;
    char filename[50];
    char line[500];

    // Getting the filename
    printf("Enter the filename (with .txt extension) which contains the entries:\n");
    scanf("%s", filename);

    // Opening the file in read mode
    file = fopen(filename, "r");

    if(file == NULL)
    {
        printf("Error in opening the file.\n");
        exit(1);
    }

    // Reading the file line by line and displaying each entry
    while(fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }

    // Closing the file
    fclose(file);
}

int main()
{
    printf("Welcome to Digital Diary in C!\n");
    printf("1. New Entry\n");
    printf("2. Display Entries\n");
    printf("3. Exit\n");

    int choice;

    do
    {
        printf("\nEnter your choice (1/2/3):\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                new_entry();
                break;
            case 2:
                display_entries();
                break;
            case 3:
                printf("Thank you for using Digital Diary in C!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}