//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

struct entry {
    char date[20];
    char time[20];
    char content[500];
};

void add_entry(struct entry entries[], int num_entries, char* date, char* time, char* content) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].time, time);
    strcpy(entries[num_entries].content, content);

    num_entries++;
}

void display_entries(struct entry entries[], int num_entries) {
    printf("Digital Diary Entries:\n");
    printf("-----------------------\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s %s - %s\n", entries[i].date, entries[i].time, entries[i].content);
    }
}

int main() {
    srand(time(NULL));

    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    char* date_format = "dd/mm/yyyy";
    char* time_format = "hh:mm:ss";

    printf("Welcome to your Digital Diary!\n");
    printf("Please enter your name:\n");
    char name[50];
    scanf("%s", name);

    printf("Welcome, %s!\n", name);
    printf("Press any key to start...\n");
    getchar();

    while (1) {
        printf("Press 1 to add an entry\n");
        printf("Press 2 to display entries\n");
        printf("Press 3 to exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the date (dd/mm/yyyy):\n");
                char date[20];
                scanf("%s", date);

                printf("Enter the time (hh:mm:ss):\n");
                char time[20];
                scanf("%s", time);

                printf("Enter your entry:\n");
                char content[500];
                scanf("%[^\n]", content);

                add_entry(entries, num_entries, date, time, content);
                break;

            case 2:
                display_entries(entries, num_entries);
                break;

            case 3:
                printf("Thank you for using Digital Diary, %s!\n", name);
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}