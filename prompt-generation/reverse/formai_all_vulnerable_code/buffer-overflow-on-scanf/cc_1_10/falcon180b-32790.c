//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} entry_t;

int main() {
    char filename[30];
    FILE *fp;
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;
    char search_date[20];
    char search_entry[MAX_ENTRY_LENGTH];
    int search_result = 0;

    printf("Welcome to Digital Diary!\n\n");

    do {
        printf("1. Create new entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", entries[num_entries].date);
                printf("Enter entry:\n");
                fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
                num_entries++;
                break;

            case '2':
                printf("\nDate\tEntry\n");
                for(int i=0; i<num_entries; i++) {
                    printf("%s\t%s\n", entries[i].date, entries[i].entry);
                }
                break;

            case '3':
                printf("\nEnter date to search (YYYY-MM-DD): ");
                scanf("%s", search_date);
                printf("Enter keyword to search: ");
                fgets(search_entry, MAX_ENTRY_LENGTH, stdin);
                search_result = search_entries(entries, num_entries, search_date, search_entry);
                if(search_result == 0) {
                    printf("\nNo entries found.\n");
                }
                break;

            case '4':
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    } while(choice!= '4');

    return 0;
}

int search_entries(entry_t entries[], int num_entries, char date[], char keyword[]) {
    int i;
    for(i=0; i<num_entries; i++) {
        if(strcmp(entries[i].date, date) == 0) {
            if(strstr(entries[i].entry, keyword)!= NULL) {
                printf("\n%s\n%s\n", entries[i].date, entries[i].entry);
                return 1;
            }
        }
    }
    return 0;
}