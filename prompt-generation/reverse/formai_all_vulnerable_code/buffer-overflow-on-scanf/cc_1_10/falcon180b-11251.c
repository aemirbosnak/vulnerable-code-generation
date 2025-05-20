//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct Entry {
    char date[20];
    char time[10];
    char content[MAX_ENTRY_LENGTH];
};

void addEntry(struct Entry* entries, int count, char* content) {
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", entries[count].date);
    printf("Enter time (HH:MM): ");
    scanf("%s", entries[count].time);
    printf("Enter content:\n");
    fgets(entries[count].content, MAX_ENTRY_LENGTH, stdin);
    entries[count].content[strcspn(entries[count].content, "\n")] = '\0';
}

void viewEntries(struct Entry* entries, int count) {
    printf("Your entries:\n");
    for (int i = 0; i < count; i++) {
        printf("%s %s\n%s\n\n", entries[i].date, entries[i].time, entries[i].content);
    }
}

void deleteEntry(struct Entry* entries, int count) {
    printf("Enter the date of the entry you want to delete (YYYY-MM-DD): ");
    char date[20];
    scanf("%s", date);
    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].date, date) == 0) {
            memset(&entries[i], 0, sizeof(struct Entry));
            printf("Entry deleted.\n");
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    struct Entry entries[MAX_ENTRIES];
    int count = 0;
    char choice;

    srand(time(NULL));
    printf("Welcome to your digital diary!\n\n");

    while (count < MAX_ENTRIES) {
        printf("What would you like to do?\n");
        printf("A - Add an entry\n");
        printf("V - View entries\n");
        printf("D - Delete an entry\n");
        printf("Q - Quit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
            case 'a':
                addEntry(entries, count, "");
                count++;
                break;
            case 'V':
            case 'v':
                viewEntries(entries, count);
                break;
            case 'D':
            case 'd':
                deleteEntry(entries, count);
                break;
            case 'Q':
            case 'q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}