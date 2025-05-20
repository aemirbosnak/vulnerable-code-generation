//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} entry_t;

void add_entry(entry_t* diary, int num_entries, char* date, char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: maximum number of entries reached.\n");
        return;
    }

    strcpy(diary[num_entries].date, date);
    strcpy(diary[num_entries].entry, entry);

    num_entries++;
}

void display_entries(entry_t* diary, int num_entries) {
    printf("Diary entries:\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", diary[i].date, diary[i].entry);
    }
}

int main() {
    entry_t diary[MAX_ENTRIES];
    int num_entries = 0;

    char date[20];
    time_t now = time(NULL);
    strftime(date, sizeof(date), "%Y-%m-%d", localtime(&now));

    while (1) {
        printf("Enter diary entry for %s:\n", date);
        fgets(diary[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
        diary[num_entries].entry[strcspn(diary[num_entries].entry, "\n")] = '\0';

        add_entry(diary, num_entries, date, diary[num_entries].entry);

        printf("Entry added.\n");

        if (num_entries == 1) {
            printf("This is your first diary entry! Welcome to digital diary.\n");
        }

        if (num_entries % 10 == 0) {
            printf("You have written %d diary entries so far. Keep it up!\n", num_entries);
        }

        display_entries(diary, num_entries);

        char choice;
        printf("Press 'q' to quit or any other key to continue writing:\n");
        scanf(" %c", &choice);

        if (choice == 'q') {
            break;
        }
    }

    return 0;
}