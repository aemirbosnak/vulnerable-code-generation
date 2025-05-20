//FormAI DATASET v1.0 Category: Digital Diary ; Style: creative
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day;
    int month;
    int year;
    char content[500];
} DiaryEntry;

int main() {
    DiaryEntry *diary = malloc(sizeof(DiaryEntry) * 365);
    int numEntries = 0;
    int choice = 0;

    printf("Welcome to your Digital Diary!\n");

    while (1) {
        printf("\n");
        printf("1. Add Entry\n");
        printf("2. View All Entries\n");
        printf("3. View Entry by Date\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (numEntries == 365) {
                printf("Oops! Your diary is full. You cannot add more entries.\n");
            } else {
                DiaryEntry newEntry;
                printf("Enter today's date (DD MM YYYY): ");
                scanf("%d %d %d", &newEntry.day, &newEntry.month, &newEntry.year);

                printf("Enter your diary entry content:\n");
                fflush(stdin);
                gets(newEntry.content);

                diary[numEntries] = newEntry;
                numEntries++;

                printf("Your entry has been added successfully!\n");
            }
        } else if (choice == 2) {
            if (numEntries == 0) {
                printf("Your diary is empty.\n");
            } else {
                printf("Here are all your diary entries:\n");
                for (int i = 0; i < numEntries; i++) {
                    printf("[Entry %d | Date: %02d-%02d-%04d]\n", i+1, diary[i].day, diary[i].month, diary[i].year);
                    printf("------------------------------------\n");
                    printf("%s\n", diary[i].content);
                    printf("------------------------------------\n");
                }
            }
        } else if (choice == 3) {
            if (numEntries == 0) {
                printf("Your diary is empty.\n");
            } else {
                int day, month, year;
                int found = 0;

                printf("Enter the date of the entry you want to view (DD MM YYYY): ");
                scanf("%d %d %d", &day, &month, &year);

                for (int i = 0; i < numEntries; i++) {
                    if (diary[i].day == day && diary[i].month == month && diary[i].year == year) {
                        printf("[Entry | Date: %02d-%02d-%04d]\n", diary[i].day, diary[i].month, diary[i].year);
                        printf("------------------------------------\n");
                        printf("%s\n", diary[i].content);
                        printf("------------------------------------\n");

                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("No entry found for the specified date.\n");
                }
            }
        } else if (choice == 4) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    free(diary);
    return 0;
}