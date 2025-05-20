//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_SIZE 500

struct entry {
    char date[20];
    char time[20];
    char text[MAX_ENTRY_SIZE];
};

int main() {
    char choice;
    int num_entries = 0;
    struct entry diary[MAX_ENTRIES];

    do {
        printf("Welcome to Romeo and Juliet's Digital Diary!\n\n");
        printf("Please choose an option:\n");
        printf("1. Write a new entry\n");
        printf("2. Read entries\n");
        printf("3. Exit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                if (num_entries >= MAX_ENTRIES) {
                    printf("Diary is full. Please delete an entry to make space.\n");
                } else {
                    printf("Enter the date (YYYY-MM-DD): ");
                    scanf("%s", diary[num_entries].date);
                    printf("Enter the time (HH:MM:SS): ");
                    scanf("%s", diary[num_entries].time);
                    printf("Enter your entry:\n");
                    fgets(diary[num_entries].text, MAX_ENTRY_SIZE, stdin);
                    num_entries++;
                    printf("Entry saved.\n");
                }
                break;
            case '2':
                if (num_entries == 0) {
                    printf("No entries found.\n");
                } else {
                    printf("Select an entry to read:\n");
                    for (int i = 0; i < num_entries; i++) {
                        printf("%d. %s %s\n", i + 1, diary[i].date, diary[i].time);
                    }
                    scanf(" %d", &choice);
                    printf("\n%s %s\n", diary[choice - 1].date, diary[choice - 1].time);
                    printf("%s\n", diary[choice - 1].text);
                }
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice!= '3');

    return 0;
}