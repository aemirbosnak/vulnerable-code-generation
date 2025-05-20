//FormAI DATASET v1.0 Category: Digital Diary ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int choice;
    char entry[1000], date[30];
    FILE *fp;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    sprintf(date, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    // Create a new entry or view previous entry
    printf("Welcome to your Digital Diary!\n\n");
    printf("1. Create a new entry\n2. View previous entry\n\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("\nEnter your thoughts:\n");
        getchar(); // to clear input buffer
        fgets(entry, 1000, stdin);

        fp = fopen(date, "a");
        if (fp == NULL)
        {
            printf("Unable to open file.\n");
            exit(1);
        }

        fprintf(fp, "%s", entry);
        fclose(fp);

        printf("\nEntry saved successfully!\n");
        break;

    case 2:
        printf("\nPrevious entry:\n");

        fp = fopen(date, "r");
        if (fp == NULL)
        {
            printf("\nNo entry found for this date.\n");
            exit(1);
        }

        while (!feof(fp))
        {
            fgets(entry, 1000, fp);
            printf("%s", entry);
        }

        fclose(fp);
        break;

    default:
        printf("\nInvalid choice.\n");
        break;
    }

    return 0;
}