//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

struct entry {
    char date[20];
    char time[10];
    char content[MAX_ENTRY_LENGTH];
};

void add_entry(struct entry *diary, int num_entries, char *date, char *time, char *content) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Sorry, you have reached the maximum number of entries.\n");
        return;
    }

    strcpy(diary[num_entries].date, date);
    strcpy(diary[num_entries].time, time);
    strcpy(diary[num_entries].content, content);

    num_entries++;
}

void view_entries(struct entry *diary, int num_entries) {
    printf("Your diary entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("Date: %s\nTime: %s\nEntry:\n%s\n\n", diary[i].date, diary[i].time, diary[i].content);
    }
}

int main() {
    struct entry diary[MAX_ENTRIES];
    int num_entries = 0;
    char username[20];

    printf("Welcome to your digital diary!\n");
    printf("Please enter your name:\n");
    scanf("%s", username);

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Add an entry\n");
        printf("2. View entries\n");
        printf("3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the date (YYYY-MM-DD):\n");
                scanf("%s", diary[num_entries].date);
                printf("Enter the time (HH:MM:SS):\n");
                scanf("%s", diary[num_entries].time);
                printf("Enter your entry:\n");
                fgets(diary[num_entries].content, MAX_ENTRY_LENGTH, stdin);
                add_entry(diary, num_entries, diary[num_entries].date, diary[num_entries].time, diary[num_entries].content);
                num_entries++;
                break;
            case 2:
                view_entries(diary, num_entries);
                break;
            case 3:
                printf("Goodbye, %s!\n", username);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}