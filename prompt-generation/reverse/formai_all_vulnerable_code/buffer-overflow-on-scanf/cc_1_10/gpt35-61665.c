//FormAI DATASET v1.0 Category: Digital Diary ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct entry {
    char time[20];
    char date[20];
    char content[100];
} diary_entry[MAX_ENTRIES];

int num_entries = 0;

void add_entry() {
    if(num_entries >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add any more entries.\n");
        return;
    }

    printf("Enter the time (hh:mm:ss): ");
    scanf("%s", diary_entry[num_entries].time);

    printf("Enter the date (mm/dd/yyyy): ");
    scanf("%s", diary_entry[num_entries].date);

    printf("Enter the content (max 100 characters): ");
    scanf("%s", diary_entry[num_entries].content);

    num_entries++;
    printf("Entry added successfully.\n");
}

void list_entries() {
    if(num_entries == 0) {
        printf("Diary is empty.\n");
        return;
    }

    printf("Time\t\tDate\t\tContent\n");
    printf("------------------------------------------------------------\n");

    for(int i=0; i<num_entries; i++) {
        printf("%s\t%s\t%s\n", diary_entry[i].time, diary_entry[i].date, diary_entry[i].content);
    }
}

void search_entries() {
    if(num_entries == 0) {
        printf("Diary is empty.\n");
        return;
    }

    char query[100];
    int matches = 0;

    printf("Enter search query (max 100 characters): ");
    scanf("%s", query);

    printf("Time\t\tDate\t\tContent\n");
    printf("------------------------------------------------------------\n");

    for(int i=0; i<num_entries; i++) {
        if(strstr(diary_entry[i].content, query) != NULL) {
            printf("%s\t%s\t%s\n", diary_entry[i].time, diary_entry[i].date, diary_entry[i].content);
            matches++;
        }
    }

    if(matches == 0) {
        printf("No matches found.\n");
    }
}

int main() {
    int option;

    printf("CYBERPUNK DIGITAL DIARY 2077\n");
    printf("============================\n");

    while(1) {
        printf("1. Add an entry\n");
        printf("2. List all entries\n");
        printf("3. Search for an entry\n");
        printf("4. Quit\n");
        printf("Enter your option: ");

        scanf("%d", &option);

        switch(option) {
            case 1:
                add_entry();
                break;

            case 2:
                list_entries();
                break;

            case 3:
                search_entries();
                break;

            case 4:
                printf("Exiting CYBERPUNK DIGITAL DIARY 2077. Goodbye.\n");
                exit(0);

            default:
                printf("Invalid option. Please enter a valid option.\n");
        }

        printf("\n");
    }

    return 0;
}