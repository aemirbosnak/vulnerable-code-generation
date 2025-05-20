//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: rigorous
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
} Entry;

void add_entry(Entry* diary, int num_entries, char* date, char* entry) {
    strcpy(diary[num_entries].date, date);
    strcpy(diary[num_entries].entry, entry);
    num_entries++;
}

void print_entries(Entry* diary, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n%s\n", diary[i].date, diary[i].entry);
    }
}

int main() {
    Entry diary[MAX_ENTRIES];
    int num_entries = 0;
    char date[20];
    char entry[MAX_ENTRY_LENGTH];

    time_t now = time(NULL);
    strftime(date, 20, "%Y-%m-%d", localtime(&now));

    while (1) {
        printf("Enter your diary entry for %s:\n", date);
        fgets(entry, MAX_ENTRY_LENGTH, stdin);
        entry[strcspn(entry, "\n")] = '\0';

        add_entry(diary, num_entries, date, entry);
        num_entries++;

        char choice;
        printf("Do you want to add another entry? (y/n)\n");
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N') {
            break;
        }

        strcpy(date, "");
        strcat(date, date);
        strcat(date, " ");
        strcat(date, "00:00:00");
        time_t next_day = mktime(localtime(&now)) + 24*60*60;
        strftime(date, 20, "%Y-%m-%d", localtime(&next_day));
    }

    print_entries(diary, num_entries);

    return 0;
}