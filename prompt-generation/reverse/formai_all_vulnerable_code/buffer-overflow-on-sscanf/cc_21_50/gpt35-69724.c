//FormAI DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

struct DiaryEntry {
    char date[11];
    char content[1000];
};

int main() {
    struct DiaryEntry entries[MAX_ENTRIES];
    int numEntries = 0;
    char input[100];
    char date[11];
    char content[1000];
    int day, month, year;
    time_t now;
    struct tm *current_time;

    printf("Welcome to your Digital Diary!\n\n");

    while (1) {
        printf("Enter 'a' to add a new entry, 'v' to view previous entries, or 'q' to quit: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "a") == 0) {
            printf("Enter date in format 'dd-mm-yyyy': ");
            fgets(date, sizeof(date), stdin);
            date[strcspn(date, "\n")] = 0;

            if (sscanf(date, "%d-%d-%d", &day, &month, &year) != 3) {
                printf("Invalid date format. Entry not added.\n");
                continue;
            }

            if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 9999) {
                printf("Invalid date. Entry not added.\n");
                continue;
            }

            printf("Enter content (max 1000 characters):\n");
            fgets(content, sizeof(content), stdin);
            content[strcspn(content, "\n")] = 0;

            strcpy(entries[numEntries].date, date);
            strcpy(entries[numEntries].content, content);
            numEntries++;

            printf("Entry added!\n");

        } else if (strcmp(input, "v") == 0) {
            if (numEntries == 0) {
                printf("No entries found.\n");
                continue;
            }

            printf("Enter date in format 'dd-mm-yyyy': ");
            fgets(date, sizeof(date), stdin);
            date[strcspn(date, "\n")] = 0;

            if (sscanf(date, "%d-%d-%d", &day, &month, &year) != 3) {
                printf("Invalid date format. No entries found.\n");
                continue;
            }

            if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 9999) {
                printf("Invalid date. No entries found.\n");
                continue;
            }

            int found = 0;
            for (int i = 0; i < numEntries; i++) {
                if (strcmp(entries[i].date, date) == 0) {
                    printf("%s\n", entries[i].content);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("No entries found for that date.\n");
            }

        } else if (strcmp(input, "q") == 0) {
            printf("Exiting Digital Diary...\n");
            break;

        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}