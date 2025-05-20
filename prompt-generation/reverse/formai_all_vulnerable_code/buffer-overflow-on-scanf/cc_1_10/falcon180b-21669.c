//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100

struct {
    char date[20];
    char time[20];
    char entry[200];
} diary_entries[MAX_ENTRIES];

int num_entries = 0;

void add_entry(char date[], char time[], char entry[]) {
    strcpy(diary_entries[num_entries].date, date);
    strcpy(diary_entries[num_entries].time, time);
    strcpy(diary_entries[num_entries].entry, entry);
    num_entries++;
}

void display_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%s %s\n%s\n\n", diary_entries[i].date, diary_entries[i].time, diary_entries[i].entry);
    }
}

int main() {
    char date[20], time[20];
    char entry[200];
    int choice;
    do {
        printf("Digital Diary\n");
        printf("1. Add entry\n2. Display entries\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter date (dd/mm/yyyy): ");
            scanf("%s", date);
            printf("Enter time (hh:mm:ss): ");
            scanf("%s", time);
            printf("Enter entry:\n");
            fgets(entry, 200, stdin);
            add_entry(date, time, entry);
            break;
        case 2:
            display_entries();
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 3);
    return 0;
}