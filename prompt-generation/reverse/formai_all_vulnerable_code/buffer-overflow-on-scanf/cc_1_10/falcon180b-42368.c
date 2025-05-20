//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

struct entry {
    char date[20];
    char time[20];
    char content[MAX_ENTRY_LENGTH];
};

struct entry diary[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *date, char *time, char *content) {
    strcpy(diary[num_entries].date, date);
    strcpy(diary[num_entries].time, time);
    strcpy(diary[num_entries].content, content);
    num_entries++;
}

void view_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%s %s\n%s\n\n", diary[i].date, diary[i].time, diary[i].content);
    }
}

void search_entries(char *keyword) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strstr(diary[i].content, keyword)!= NULL) {
            printf("%s %s\n%s\n\n", diary[i].date, diary[i].time, diary[i].content);
        }
    }
}

int main() {
    srand(time(NULL));

    int choice;
    char date[20];
    char time[20];
    char content[MAX_ENTRY_LENGTH];

    while (1) {
        printf("1. Add entry\n2. View entries\n3. Search entries\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter time (HH:MM:SS): ");
                scanf("%s", time);
                printf("Enter content:\n");
                fgets(content, MAX_ENTRY_LENGTH, stdin);
                content[strcspn(content, "\n")] = '\0';
                add_entry(date, time, content);
                break;
            case 2:
                view_entries();
                break;
            case 3:
                printf("Enter keyword to search: ");
                scanf("%s", content);
                search_entries(content);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}