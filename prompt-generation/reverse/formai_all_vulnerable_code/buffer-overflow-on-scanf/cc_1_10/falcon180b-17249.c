//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 200

struct entry {
    char date[20];
    char time[20];
    char content[ENTRY_LENGTH];
};

void add_entry(struct entry *diary, int index, char *date, char *time, char *content) {
    strncpy(diary[index].date, date, 20);
    strncpy(diary[index].time, time, 20);
    strncpy(diary[index].content, content, ENTRY_LENGTH);
}

void read_entry(struct entry entry) {
    printf("Date: %s\n", entry.date);
    printf("Time: %s\n", entry.time);
    printf("Content:\n%s", entry.content);
    printf("\n");
}

int main() {
    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);

    struct entry diary[MAX_ENTRIES];
    int entries = 0;

    srand(time(NULL));
    diary[entries].date[0] = '\0';
    diary[entries].time[0] = '\0';
    diary[entries].content[0] = '\0';

    while (entries < MAX_ENTRIES) {
        int choice;
        printf("\n%s's Digital Diary\n", name);
        printf("1. Add entry\n2. Read entry\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", diary[entries].date);
                printf("Enter time (HH:MM): ");
                scanf("%s", diary[entries].time);
                printf("Enter content:\n");
                fgets(diary[entries].content, ENTRY_LENGTH, stdin);
                add_entry(diary, entries, diary[entries].date, diary[entries].time, diary[entries].content);
                entries++;
                break;
            case 2:
                printf("Entries:\n");
                for (int i = 0; i < entries; i++) {
                    read_entry(diary[i]);
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}