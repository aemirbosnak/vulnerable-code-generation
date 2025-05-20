//FormAI DATASET v1.0 Category: Digital Diary ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

void displayMenu();
void addEntry();
void viewEntry();
int count_lines(FILE *);

int main()
{
    int choice;
    displayMenu();
    scanf("%d", &choice);
    while (choice != 3)
    {
        switch (choice)
        {
        case 1:
            addEntry();
            displayMenu();
            scanf("%d", &choice);
            break;
        case 2:
            viewEntry();
            displayMenu();
            scanf("%d", &choice);
            break;
        default:
            printf("Invalid choice, try again.\n");
            displayMenu();
            scanf("%d", &choice);
            break;
        }
    }
    printf("Exiting program.\n");
    return 0;
}

void displayMenu()
{
    printf("Welcome to your digital diary.\n");
    printf("1. Add an entry\n");
    printf("2. View all entries\n");
    printf("3. Exit program\n");
    printf("Enter your choice:\n");
}

void addEntry()
{
    char entry[MAX], file_name[20];
    printf("Enter your diary entry:\n");
    scanf("%s", entry);
    // Generate a unique file name
    srand(time(0));
    sprintf(file_name, "entry_%d.txt", rand() % 1000);
    FILE *fptr = fopen(file_name, "w");
    if (fptr == NULL)
    {
        printf("Error opening file.\n");
    }
    else
    {
        fprintf(fptr, "%s\n", entry);
        printf("Entry added successfully.\n");
    }
    fclose(fptr);
}

void viewEntry()
{
    char file_name[20], ch;
    int lines = 0;
    FILE *fptr;
    printf("Your diary entries:\n");
    for (int i = 0; i < 1000; i++)
    {
        sprintf(file_name, "entry_%d.txt", i);
        fptr = fopen(file_name, "r");
        if (fptr != NULL)
        {
            lines += count_lines(fptr);
            rewind(fptr);
            printf("From %s:\n", file_name);
            while ((ch = fgetc(fptr)) != EOF)
            {
                printf("%c", ch);
            }
            fclose(fptr);
        }
    }
    if (lines == 0)
    {
        printf("No entries found.\n");
    }
}

int count_lines(FILE *fptr)
{
    int lines = 0;
    char ch;
    while ((ch = fgetc(fptr)) != EOF)
    {
        if (ch == '\n')
        {
            lines++;
        }
    }
    return lines;
}