//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRY_LENGTH 1000
#define MAX_ENTRIES 1000

struct entry {
    char date[11];
    char time[9];
    char title[101];
    char content[MAX_ENTRY_LENGTH];
};

int num_entries = 0;
struct entry entries[MAX_ENTRIES];

void add_entry(char* date, char* time, char* title, char* content) {
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].time, time);
    strcpy(entries[num_entries].title, title);
    strcpy(entries[num_entries].content, content);
    num_entries++;
}

void print_entry(int index) {
    printf("Date: %s\n", entries[index].date);
    printf("Time: %s\n", entries[index].time);
    printf("Title: %s\n", entries[index].title);
    printf("Content:\n%s\n", entries[index].content);
}

void print_all_entries() {
    for (int i = 0; i < num_entries; i++) {
        print_entry(i);
    }
}

int main() {
    char entry_date[11];
    char entry_time[9];
    char entry_title[101];
    char entry_content[MAX_ENTRY_LENGTH];

    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", entry_date);
        printf("Enter time (HH:MM:SS): ");
        scanf("%s", entry_time);
        printf("Enter title: ");
        scanf("%s", entry_title);
        printf("Enter content:\n");
        fgets(entry_content, MAX_ENTRY_LENGTH, stdin);
        entry_content[strcspn(entry_content, "\n")] = '\0';
        add_entry(entry_date, entry_time, entry_title, entry_content);
    }

    return 0;
}