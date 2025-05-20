//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define ENTRY_LENGTH 200

struct entry {
    char date[20];
    char time[20];
    char content[ENTRY_LENGTH];
};

int main() {
    struct entry diary[MAX_ENTRIES];
    int num_entries = 0;
    char choice;

    do {
        printf("Digital Diary\n");
        printf("1. Write an entry\n");
        printf("2. Read entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                if(num_entries >= MAX_ENTRIES) {
                    printf("Diary is full.\n");
                    break;
                }

                printf("Enter date (YYYY-MM-DD): ");
                scanf(" %19s", diary[num_entries].date);

                printf("Enter time (HH:MM:SS): ");
                scanf(" %19s", diary[num_entries].time);

                printf("Enter content:\n");
                scanf(" %199s", diary[num_entries].content);

                num_entries++;
                printf("Entry saved.\n");
                break;

            case '2':
                printf("Diary entries:\n");
                for(int i=0; i<num_entries; i++) {
                    printf("%s %s - %s\n", diary[i].date, diary[i].time, diary[i].content);
                }
                break;

            case '3':
                printf("Exiting Digital Diary.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice!= '3');

    return 0;
}