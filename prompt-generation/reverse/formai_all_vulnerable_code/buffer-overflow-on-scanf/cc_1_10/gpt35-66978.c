//FormAI DATASET v1.0 Category: Digital Diary ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char date[20], time[10], entry[1000];
    FILE *fp;
    int choice;

    printf("Welcome to your Digital Diary!\n");

    while (1)
    {
        printf("\nEnter\n1 to create a new entry\n2 to view previous entries\n3 to exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the date of your entry (MM/DD/YYYY): ");
            scanf("%s", date);
            printf("Enter the time of your entry (HH:MM AM/PM): ");
            scanf("%s", time);
            printf("Write your entry (maximum 1000 characters):\n");
            fflush(stdin);
            fgets(entry, sizeof(entry), stdin);
            fp = fopen("diary.txt", "a");
            if (fp == NULL)
            {
                printf("Error creating entry\n");
                exit(1);
            }
            fprintf(fp, "%s - %s:\n%s\n\n", date, time, entry);
            fclose(fp);
            printf("Entry added successfully!\n");
            break;

        case 2:
            printf("\nReading previous entries...\n\n");
            fp = fopen("diary.txt", "r");
            if (fp == NULL)
            {
                printf("No entries found\n");
                break;
            }
            char c;
            while ((c = getc(fp)) != EOF)
            {
                printf("%c", c);
            }
            fclose(fp);
            break;

        case 3:
            printf("\nGoodbye!\n");
            exit(0);
            break;

        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}