//FormAI DATASET v1.0 Category: Digital Diary ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

struct DiaryEntry {
    char date[20];
    char time[20];
    char description[200];
};

struct Diary {
    int num_entries;
    struct DiaryEntry entries[MAX_ENTRIES];
};

void printEntry(struct DiaryEntry entry) {
    printf("\nDate: %s", entry.date);
    printf("\nTime: %s", entry.time);
    printf("\nDescription: %s\n", entry.description);
}

void printDiary(struct Diary diary) {
    printf("\n--------------------------\n");
    printf("       DIGITAL DIARY       ");
    printf("\n--------------------------\n");
    for(int i = 0; i < diary.num_entries; i++) {
        printEntry(diary.entries[i]);
    }
    printf("\n--------------------------\n");
}

int main() {

    struct Diary diary;
    diary.num_entries = 0;

    char password[20], actual_pass[20] = "mysecretpassword";

    printf("Enter password to access your diary: ");
    scanf("%s", password);
    
    if(strcmp(password, actual_pass) != 0) {
        printf("Incorrect password. Access denied.");
        exit(0);
    }

    printf("Access granted...\n");

    while(1) {
        printf("\n1. Add an entry\n");
        printf("2. View all entries\n");
        printf("3. Quit\n");

        int selection;
        printf("\nEnter your choice: ");
        scanf("%d", &selection);

        switch(selection) {
            case 1: {
                struct DiaryEntry new_entry;

                time_t now = time(NULL);

                struct tm *t = localtime(&now);
                sprintf(new_entry.date, "%d/%d/%d", t->tm_mday, t->tm_mon + 1, t->tm_year + 1900);
                sprintf(new_entry.time, "%d:%d:%d", t->tm_hour, t->tm_min, t->tm_sec);
                
                printf("Enter the description of the entry (max 200 characters): ");
                getchar();
                fgets(new_entry.description, 200, stdin);

                if(diary.num_entries == MAX_ENTRIES) {
                    printf("Diary is full! Cannot add more entries.");
                } else {
                    diary.entries[diary.num_entries++] = new_entry;
                    printf("Entry added successfully!");
                }
                break;
            }

            case 2: {
                if(diary.num_entries == 0) {
                    printf("No entries in diary!");
                } else {
                    printDiary(diary);
                }
                break;
            }

            case 3: {
                printf("Exiting diary...\n");
                exit(0);
            }

            default: {
                printf("Invalid selection!");
            }
        }
    }

    return 0;
}