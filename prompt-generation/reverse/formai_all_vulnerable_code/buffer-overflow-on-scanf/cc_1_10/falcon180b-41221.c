//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    strncpy(entries[num_entries].date, date, 19);
    strncpy(entries[num_entries].entry, entry, MAX_ENTRY_LENGTH-1);
    num_entries++;
}

void print_entries() {
    printf("Digital Diary\n");
    printf("=================\n");
    for(int i=0; i<num_entries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    srand(time(NULL));
    printf("Welcome to your digital diary!\n\n");
    char username[20];
    printf("Please enter your name: ");
    scanf("%s", username);
    add_entry(username, "Created digital diary account.");
    int choice;
    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add entry\n2. View entries\n3. Exit\n");
        scanf("%d", &choice);
        if(choice == 1) {
            char date[20];
            char entry[MAX_ENTRY_LENGTH];
            printf("Enter date (YYYY-MM-DD): ");
            scanf("%s", date);
            printf("Enter entry: ");
            scanf("%[^\n]", entry);
            add_entry(date, entry);
        } else if(choice == 2) {
            print_entries();
        } else if(choice == 3) {
            printf("Goodbye, %s!\n", username);
            break;
        }
    }
    return 0;
}