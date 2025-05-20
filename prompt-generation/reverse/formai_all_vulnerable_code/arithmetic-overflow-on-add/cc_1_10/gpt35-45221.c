//FormAI DATASET v1.0 Category: Digital Diary ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t now;
    struct tm *current_time;
    int option, day, month, year;
    char entry[1000];
    FILE *fp;

    printf("Welcome to your Digital Diary!\n\n");
    printf("What would you like to do?\n");
    printf("1. Create a new entry\n");
    printf("2. View past entries\n");
    printf("3. Exit\n");
    printf("Enter your option: ");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("\nEnter today's date (dd mm yyyy): ");
            scanf("%d %d %d", &day, &month, &year);
            time(&now);
            current_time = localtime(&now);
            if (current_time->tm_mday != day || current_time->tm_mon+1 != month || current_time->tm_year+1900 != year) {
                printf("Error: Date is not today's date. Entry will not be created.\n");
                exit(0);
            }
            printf("Write your entry (maximum 1000 characters):\n");
            scanf(" %[^\n]s", entry);
            fp = fopen("diary.txt", "a");
            fprintf(fp, "Date: %02d-%02d-%d\n%s\n\n", day, month, year, entry);
            printf("\nNew diary entry created successfully!\n");
            fclose(fp);
            break;
        case 2:
            fp = fopen("diary.txt", "r");
            if (fp == NULL) {
                printf("Error: No entries found.\n");
                exit(0);
            }
            printf("Past diary entries:\n\n");
            while (fgets(entry, sizeof entry, fp) != NULL) {
                printf("%s", entry);
            }
            fclose(fp);
            break;
        case 3:
            printf("\nGoodbye!\n");
            exit(0);
        default:
            printf("\nError: Invalid option.\n");
            exit(0);
    }

    return 0;
}