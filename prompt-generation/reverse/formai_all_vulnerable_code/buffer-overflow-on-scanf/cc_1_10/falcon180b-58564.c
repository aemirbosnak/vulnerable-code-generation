//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[20];
    char entry[500];
} diary_entry;

void add_entry(diary_entry* entries, int count, char* date, char* entry) {
    if (count >= MAX_ENTRIES) {
        printf("Sorry, you've reached the maximum number of entries!\n");
        return;
    }
    strcpy(entries[count].date, date);
    strcpy(entries[count].entry, entry);
    count++;
}

void display_entries(diary_entry* entries, int count) {
    printf("Digital Diary:\n");
    printf("-----------------\n");
    for (int i = 0; i < count; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    srand(time(0));
    diary_entry entries[MAX_ENTRIES];
    int count = 0;

    while (1) {
        printf("Welcome to your Digital Diary!\n");
        printf("-----------------\n");
        printf("1. Add an entry\n");
        printf("2. Display entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &count);

        switch(count) {
            case 1:
                printf("Enter the date (dd/mm/yyyy): ");
                scanf("%s", entries[count].date);
                printf("Enter your entry: ");
                scanf("%s", entries[count].entry);
                printf("Entry added successfully!\n");
                break;
            case 2:
                display_entries(entries, count);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}