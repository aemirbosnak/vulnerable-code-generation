//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct entry {
    char date[20];
    char time[10];
    char content[MAX_ENTRY_LENGTH];
};

void add_entry(struct entry* diary, int num_entries, char* date, char* time, char* content) {
    strncpy(diary[num_entries].date, date, 20);
    strncpy(diary[num_entries].time, time, 10);
    strncpy(diary[num_entries].content, content, MAX_ENTRY_LENGTH);
}

void print_entries(struct entry* diary, int num_entries) {
    for(int i = 0; i < num_entries; i++) {
        printf("%s %s - %s\n", diary[i].date, diary[i].time, diary[i].content);
    }
}

int main() {
    struct entry diary[MAX_ENTRIES];
    int num_entries = 0;

    printf("Sherlock Holmes' Digital Diary\n");

    while(1) {
        printf("\n");
        printf("1. Add Entry\n");
        printf("2. Print Entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        char choice;
        scanf("%c", &choice);

        switch(choice) {
            case '1': {
                printf("\n");
                printf("Enter Date (DD/MM/YYYY): ");
                char date[20];
                scanf("%s", date);

                printf("Enter Time (HH:MM): ");
                char time[10];
                scanf("%s", time);

                printf("Enter Content:\n");
                char content[MAX_ENTRY_LENGTH];
                scanf("%[^\n]", content);

                add_entry(diary, num_entries, date, time, content);
                num_entries++;

                printf("\nEntry Added Successfully!\n");
                break;
            }

            case '2': {
                if(num_entries == 0) {
                    printf("No Entries Found!\n");
                } else {
                    printf("\n");
                    print_entries(diary, num_entries);
                }
                break;
            }

            case '3': {
                printf("\nExiting...\n");
                exit(0);
            }

            default: {
                printf("\nInvalid Choice!\n");
            }
        }
    }

    return 0;
}