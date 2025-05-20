//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LEN 1000

typedef struct {
    char date[20];
    char time[20];
    char entry[MAX_ENTRY_LEN];
} Entry;

Entry entries[MAX_ENTRIES];

int num_entries = 0;

void add_entry(char* date, char* time, char* entry) {
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].time, time);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

void print_entry(int index) {
    printf("%s %s:\n%s\n", entries[index].date, entries[index].time, entries[index].entry);
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        print_entry(i);
    }
}

int main() {
    srand(time(NULL));
    printf("Welcome to the Digital Diary!\n");
    while (1) {
        printf("Enter a date (YYYY-MM-DD): ");
        char date[20];
        scanf("%s", date);
        printf("Enter a time (HH:MM:SS): ");
        char time[20];
        scanf("%s", time);
        printf("Enter your entry:\n");
        char entry[MAX_ENTRY_LEN];
        fgets(entry, MAX_ENTRY_LEN, stdin);
        entry[strcspn(entry, "\n")] = '\0';
        add_entry(date, time, entry);
        printf("Entry added!\n");
        print_entries();
    }
    return 0;
}