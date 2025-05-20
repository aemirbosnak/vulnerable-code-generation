//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} entry_t;

int main() {
    FILE *fp;
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    strftime(entries[num_entries].date, 20, "%Y-%m-%d %H:%M:%S", tm);
    printf("Welcome to the Digital Diary!\n\n");
    while(1) {
        printf("Enter your entry for %s:\n", entries[num_entries].date);
        fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
        if(num_entries == MAX_ENTRIES - 1) {
            printf("Diary is full. Please delete an entry to make space.\n");
        } else {
            num_entries++;
        }
        printf("\nWould you like to:\nA - Add another entry\nD - Delete an entry\nQ - Quit\n");
        scanf(" %c", &choice);
        if(choice == 'A' || choice == 'a') {
            continue;
        } else if(choice == 'D' || choice == 'd') {
            int index;
            printf("Enter the index of the entry you want to delete:\n");
            scanf("%d", &index);
            if(index >= 0 && index < num_entries) {
                memset(entries[index].entry, 0, MAX_ENTRY_LENGTH);
            }
        } else if(choice == 'Q' || choice == 'q') {
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
    printf("\nGoodbye!\n");
    return 0;
}