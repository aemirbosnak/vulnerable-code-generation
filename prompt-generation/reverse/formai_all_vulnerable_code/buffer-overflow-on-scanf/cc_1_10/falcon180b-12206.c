//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct entry {
    char date[20];
    char time[20];
    char content[MAX_ENTRY_LENGTH];
};

void print_entry(struct entry entry) {
    printf("%s %s\n%s\n", entry.date, entry.time, entry.content);
}

int main() {
    char input[MAX_ENTRY_LENGTH];
    struct entry diary[MAX_ENTRIES];
    int num_entries = 0;
    char choice;
    time_t now;

    do {
        printf("Welcome to your digital diary!\n");
        printf("What would you like to do?\n");
        printf("1. Write a new entry\n");
        printf("2. View previous entries\n");
        printf("3. Exit\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter your entry:\n");
                fgets(input, MAX_ENTRY_LENGTH, stdin);
                strcpy(diary[num_entries].content, input);
                time(&now);
                strftime(diary[num_entries].date, 20, "%Y-%m-%d", localtime(&now));
                strftime(diary[num_entries].time, 20, "%H:%M:%S", localtime(&now));
                num_entries++;
                break;
            case '2':
                printf("Previous entries:\n");
                for(int i = 0; i < num_entries; i++) {
                    print_entry(diary[i]);
                }
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while(choice!= '3');

    return 0;
}