//FormAI DATASET v1.0 Category: Digital Diary ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100

struct diary_entry {
    time_t timestamp;
    char title[255];
    char body[1024];
};

int main(void) {
    struct diary_entry entries[MAX_ENTRIES];
    int num_entries = 0, i, choice;
    char buffer[1024];

    while (1) {
        printf("Welcome to your Digital Diary:\n");
        printf("1. Add an entry\n");
        printf("2. View all entries\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_entries > MAX_ENTRIES) {
                printf("Sorry, maximum entries reached.\n");
                break;
            }

            time_t now = time(NULL);
            entries[num_entries].timestamp = now;

            printf("Enter title: ");
            scanf("%s", entries[num_entries].title);

            printf("Enter body: ");
            fgets(buffer, sizeof(buffer), stdin);
            fgets(buffer, sizeof(buffer), stdin);
            strncpy(entries[num_entries].body, buffer, sizeof(entries[num_entries].body));

            num_entries++;
            printf("Entry added!\n");
            break;

        case 2:
            if (num_entries == 0) {
                printf("No entries found.\n");
                break;
            }

            for (i = 0; i < num_entries; i++) {
                struct tm *entrytime = localtime(&entries[i].timestamp);
                char timestamp[80];
                strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", entrytime);
                printf("Entry #%d\n", i+1);
                printf("Title: %s\n", entries[i].title);
                printf("Body: %s", entries[i].body);
                printf("Date: %s\n\n", timestamp);
            }
            break;

        case 3:
            printf("Goodbye!\n");
            exit(0);
            break;

        default:
            printf("Invalid choice.\n");
            break;
        }
    }

    return 0;
}