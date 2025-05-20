//FormAI DATASET v1.0 Category: Digital Diary ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void writeEntry(int day, int month, int year);

int main()
{
    int day, month, year, choice;
    printf("*** My Digital Diary ***\n");

    do {
        printf("\n1. Write a new entry\n");
        printf("2. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the date of your entry (dd/mm/yyyy): ");
                scanf("%d/%d/%d", &day, &month, &year);
                writeEntry(day, month, year);
                break;
            case 2:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid option. Try again.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}

void writeEntry(int day, int month, int year)
{
    char filename[100];
    sprintf(filename, "%d-%d-%d.txt", day, month, year);

    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("\nError opening file.\n");
        return;
    }

    char entry[500];
    printf("\nEnter your entry. Press Ctrl+D to save and exit.\n");
    while (fgets(entry, sizeof(entry), stdin) != NULL) {
        fputs(entry, file);
    }

    fclose(file);

    printf("\nEntry saved successfully!\n");
}