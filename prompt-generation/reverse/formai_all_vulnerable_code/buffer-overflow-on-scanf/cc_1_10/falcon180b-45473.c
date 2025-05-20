//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[20];
    char time[20];
    char entry[200];
} Entry;

int main() {
    FILE *diary;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[100];
    int choice;
    time_t now;

    printf("Welcome to the Digital Diary!\n");

    do {
        system("clear");
        printf("1. Write a new entry\n");
        printf("2. Read previous entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your entry:\n");
                fflush(stdin);
                fgets(entries[num_entries].entry, 200, stdin);
                strftime(entries[num_entries].date, 20, "%Y-%m-%d", localtime(&now));
                strftime(entries[num_entries].time, 20, "%H:%M:%S", localtime(&now));
                num_entries++;
                break;
            case 2:
                if (num_entries == 0) {
                    printf("No entries found.\n");
                } else {
                    for (int i = 0; i < num_entries; i++) {
                        printf("%s - %s\n%s\n", entries[i].date, entries[i].time, entries[i].entry);
                    }
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice!= 3);

    return 0;
}