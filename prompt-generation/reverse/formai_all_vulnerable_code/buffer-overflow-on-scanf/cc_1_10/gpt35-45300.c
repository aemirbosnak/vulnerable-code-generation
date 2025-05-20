//FormAI DATASET v1.0 Category: Digital Diary ; Style: shape shifting
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_SIZE 1000

typedef struct entry {
    char date[11];
    char time[6];
    char content[MAX_ENTRY_SIZE];
} Entry;

void add_entry(Entry *entries, int *num_entries) {
    if(*num_entries == MAX_ENTRIES) {
        printf("Sorry, you have reached the maximum number of entries.\n");
        return;
    }

    printf("Enter the date (MM/DD/YYYY): ");
    scanf("%s", entries[*num_entries].date);

    printf("Enter the time (HH:MM): ");
    scanf("%s", entries[*num_entries].time);
    
    printf("Enter the contents of your diary entry (max %d characters):\n", MAX_ENTRY_SIZE);
    getchar(); //To clear the newline character left in the buffer after scanf
    fgets(entries[*num_entries].content, MAX_ENTRY_SIZE, stdin);

    (*num_entries)++;
    printf("Entry added successfully.\n");
}

void view_entries(Entry *entries, int num_entries) {
    if(num_entries == 0) {
        printf("No entries to display.\n");
        return;
    }

    printf("Date       Time   Content\n");
    printf("----------------------------\n");

    for(int i=0; i<num_entries; i++) {
        printf("%s %s %s", entries[i].date, entries[i].time, entries[i].content);
        printf("----------------------------\n");
    }
}

void search_entries(Entry *entries, int num_entries) {
    if(num_entries == 0) {
        printf("No entries to search for.\n");
        return;
    }

    char search_term[MAX_ENTRY_SIZE];
    printf("Enter search term: ");
    getchar(); //To clear the newline character left in the buffer after scanf
    fgets(search_term, MAX_ENTRY_SIZE, stdin);
    int found = 0;

    for(int i=0; i<num_entries; i++) {
        if(strstr(entries[i].content, search_term) != NULL) {
            printf("%s %s %s", entries[i].date, entries[i].time, entries[i].content);
            found = 1;
        }
    }

    if(!found) {
        printf("No entries found matching search term.\n");
    }
}

int main() {
    int num_entries = 0;
    Entry entries[MAX_ENTRIES];
    int choice;

    printf("Welcome to your digital diary!\n");

    while(1) {
        printf("\nPlease select an option:\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_entry(entries, &num_entries);
                break;
            case 2:
                view_entries(entries, num_entries);
                break;
            case 3:
                search_entries(entries, num_entries);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}