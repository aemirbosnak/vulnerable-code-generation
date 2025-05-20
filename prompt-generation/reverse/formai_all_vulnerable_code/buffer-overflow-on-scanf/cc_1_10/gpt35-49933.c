//FormAI DATASET v1.0 Category: Digital Diary ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100

int main()
{
    FILE *fp;
    int option, num_entries = 0;
    char date[MAX_SIZE], entry[MAX_SIZE], buffer[MAX_SIZE];

    do
    {
        printf("\nWelcome to the Digital Diary\n\n");
        printf("1. Add an entry\n");
        printf("2. View all entries\n");
        printf("3. Exit\n");
        printf("What would you like to do? ");

        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\nEnter the date (DD/MM/YYYY): ");
                scanf("%s", date);

                fflush(stdin);

                printf("\nEnter your entry: ");
                fgets(entry, MAX_SIZE, stdin);

                fp = fopen("diary.txt", "a");

                if(fp == NULL)
                {
                    printf("\nCound not create file");
                    exit(1);
                }

                sprintf(buffer, "\nEntry %d", ++num_entries);
                fputs(buffer, fp);

                sprintf(buffer, "\nDate: %s", date);
                fputs(buffer, fp);

                fputs("\n", fp);

                fputs(entry, fp);

                fputs("\n", fp);

                fclose(fp);

                printf("\nEntry added successfully!");

                break;

            case 2:
                fp = fopen("diary.txt", "r");

                if(fp == NULL)
                {
                    printf("\nNo entries found");
                    break;
                }

                printf("\n%s\n", "Digital Diary Entries");
                printf("=========================");

                fgets(buffer, MAX_SIZE, fp);

                while(!feof(fp)) 
                {
                    printf("\n%s", buffer);
                    fgets(buffer, MAX_SIZE, fp);
                }

                fclose(fp);

                break;

            case 3:
                printf("\nGoodbye!\n\n");
                exit(0);

            default:
                printf("\nInvalid option. Please try again.\n");
        }
    }while(option != 3);

    return 0;
}