//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char time[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* time, char* entry) {
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].time, time);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

void display_entries() {
    printf("Digital Diary Entries:\n");
    for(int i=0; i<num_entries; i++) {
        printf("Date: %s\n", entries[i].date);
        printf("Time: %s\n", entries[i].time);
        printf("Entry: %s\n\n", entries[i].entry);
    }
}

void delete_entry(int index) {
    for(int i=index; i<num_entries-1; i++) {
        strcpy(entries[i].date, entries[i+1].date);
        strcpy(entries[i].time, entries[i+1].time);
        strcpy(entries[i].entry, entries[i+1].entry);
    }
    num_entries--;
}

int main() {
    srand(time(NULL));
    int choice;
    char date[20];
    char time[20];
    char entry[MAX_ENTRY_LENGTH];

    do {
        printf("Digital Diary Menu:\n");
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter date (dd/mm/yyyy): ");
                scanf("%s", date);
                printf("Enter time (hh:mm:ss): ");
                scanf("%s", time);
                printf("Enter your entry:\n");
                fgets(entry, MAX_ENTRY_LENGTH, stdin);
                entry[strcspn(entry, "\n")] = '\0';
                add_entry(date, time, entry);
                break;
            case 2:
                display_entries();
                break;
            case 3:
                printf("Enter index of entry to delete: ");
                scanf("%d", &choice);
                delete_entry(choice-1);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 4);

    return 0;
}