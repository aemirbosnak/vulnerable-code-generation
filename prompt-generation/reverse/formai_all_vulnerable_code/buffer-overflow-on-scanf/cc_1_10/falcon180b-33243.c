//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} diary_entry;

diary_entry diary[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    strcpy(diary[num_entries].date, date);
    strcpy(diary[num_entries].entry, entry);
    num_entries++;
}

void view_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%s\n%s\n", diary[i].date, diary[i].entry);
    }
}

int main() {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
    char choice;

    time_t now = time(NULL);
    strftime(date, 20, "%Y-%m-%d", localtime(&now));

    while (1) {
        printf("Digital Diary\n");
        printf("Enter your entry for %s:\n", date);
        fgets(entry, MAX_ENTRY_LENGTH, stdin);
        entry[strcspn(entry, "\n")] = '\0'; // Remove newline character

        add_entry(date, entry);

        printf("Do you want to view your entries? (y/n)\n");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            view_entries();
        }
    }

    return 0;
}