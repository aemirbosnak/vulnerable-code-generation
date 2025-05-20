//FormAI DATASET v1.0 Category: Digital Diary ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000

struct entry {
    char date[20];
    char time[20];
    char message[200];
};

int main() {
    struct entry diary[MAX_ENTRIES];
    int num_entries = 0;

    while (1) {
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Exit\n");
        printf("Enter choice: ");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            if (num_entries == MAX_ENTRIES) {
                printf("Diary is full!\n");
                continue;
            }

            printf("Enter message: ");
            char message[200];
            scanf(" %[^\n]s", message);

            time_t now = time(NULL);
            struct tm *t = localtime(&now);

            strftime(diary[num_entries].date, 20, "%Y-%m-%d", t);
            strftime(diary[num_entries].time, 20, "%H:%M:%S", t);
            strncpy(diary[num_entries].message, message, 200);

            num_entries++;
        } else if (choice == 2) {
            printf("Date          Time          Message\n");
            for (int i = 0; i < num_entries; i++) {
                printf("%s  %s  %s\n", diary[i].date, diary[i].time, diary[i].message);
            }
        } else if (choice == 3) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}