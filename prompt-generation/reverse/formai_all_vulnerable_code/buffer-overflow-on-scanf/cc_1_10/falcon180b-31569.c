//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

struct entry {
    char date[20];
    char time[10];
    char content[MAX_ENTRY_LENGTH];
};

void add_entry(struct entry* diary, int num_entries, char* content) {
    time_t now = time(0);
    struct tm* timeinfo = localtime(&now);
    strftime(diary[num_entries].date, 20, "%Y-%m-%d", timeinfo);
    strftime(diary[num_entries].time, 10, "%H:%M:%S", timeinfo);
    strncpy(diary[num_entries].content, content, MAX_ENTRY_LENGTH);
}

void print_entries(struct entry* diary, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s - %s\n", diary[i].date, diary[i].time, diary[i].content);
    }
}

int main() {
    struct entry diary[MAX_ENTRIES];
    int num_entries = 0;

    printf("Welcome to your Digital Diary!\n");
    while (1) {
        printf("What would you like to do?\n1. Add an entry\n2. View entries\n3. Exit\n");
        char choice;
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter your entry:\n");
                char content[MAX_ENTRY_LENGTH];
                fgets(content, MAX_ENTRY_LENGTH, stdin);
                add_entry(diary, num_entries, content);
                num_entries++;
                printf("Entry added!\n");
                break;
            case '2':
                print_entries(diary, num_entries);
                break;
            case '3':
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}