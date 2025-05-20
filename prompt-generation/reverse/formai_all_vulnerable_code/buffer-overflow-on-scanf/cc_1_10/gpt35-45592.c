//FormAI DATASET v1.0 Category: Digital Diary ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20], date[15], entry[100];
    FILE *fp;
    int choice;

    printf("\n\nWelcome to My Digital Diary\n\n");
    printf("Enter Your Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    while (1)
    {
        printf("\n\nWhat Would You Like To Do?\n\n");
        printf("1. Create a New Entry\n");
        printf("2. Read Previous Entries\n");
        printf("3. Exit\n\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                printf("\nEnter Today's Date (DD/MM/YYYY): ");
                fgets(date, sizeof(date), stdin);
                date[strcspn(date, "\n")] = '\0';
                printf("Write Your Entry: ");
                fgets(entry, sizeof(entry), stdin);
                entry[strcspn(entry, "\n")] = '\0';

                fp = fopen(name, "a");
                fprintf(fp, "%s\n%s\n\n", date, entry);
                fclose(fp);
                printf("\nEntry Successfully Created!\n");
                break;

            case 2:
                fp = fopen(name, "r");
                if (fp == NULL)
                {
                    printf("\nNo Entries Found!\n");
                    break;
                }

                printf("\n\nPrevious Entries:\n\n");
                char temp[100];
                while (fgets(temp, sizeof(temp), fp) != NULL)
                    printf("%s", temp);
                fclose(fp);
                break;

            case 3:
                printf("\n\nExiting Digital Diary\n\n");
                exit(0);

            default:
                printf("\nInvalid Choice! Please Try Again.\n");
        }
    }
    return 0;
}