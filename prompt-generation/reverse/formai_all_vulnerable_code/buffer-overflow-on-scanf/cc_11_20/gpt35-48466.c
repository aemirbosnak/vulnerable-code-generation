//FormAI DATASET v1.0 Category: Digital Diary ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 200

char diary[MAX_ENTRIES][MAX_ENTRY_LENGTH];
int num_entries = 0;

int main() {
    printf("Welcome to Your Digital Diary\n\n");

    while (1) {
        char choice;

        printf("Do you want to (A)dd an entry, (L)ist all entries, or (Q)uit? ");
        scanf(" %c", &choice);

        if (choice == 'A' || choice == 'a') {
            printf("Enter your entry (maximum %d characters):\n", MAX_ENTRY_LENGTH);
            scanf(" %[^\n]%*c", diary[num_entries]);
            num_entries++;
            if (num_entries >= MAX_ENTRIES) {
                printf("Reached maximum number of entries.\n");
                break;
            }
            printf("Entry added!\n\n");
        }
        else if (choice == 'L' || choice == 'l') {
            if (num_entries == 0) {
                printf("No entries found.\n\n");
            }
            else {
                printf("Your Entries:\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("%d. %s\n",i+1, diary[i]);
                }
                printf("\n");
            }
        }
        else if (choice == 'Q' || choice == 'q') {
            printf("Goodbye! Your entries have been saved.\n");
            break;
        }
        else {
            printf("Invalid choice.\n\n");
        }
    }

    return 0;
}