//FormAI DATASET v1.0 Category: Digital Diary ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_ENTRIES 100
#define MAX_TITLE_SIZE 100
#define MAX_CONTENT_SIZE 1000

struct entry {
    char title[MAX_TITLE_SIZE];
    char content[MAX_CONTENT_SIZE];
    int day, month, year;
};

int num_entries = 0;  // Number of entries
struct entry diary_entries[MAX_ENTRIES];

void add_entry() {
    if(num_entries >= MAX_ENTRIES) {
        printf("Error: diary is full, cannot add more entries.\n");
        return;
    }
    struct entry new_entry;
    printf("Enter the title of the entry:\n");
    fgets(new_entry.title, MAX_TITLE_SIZE, stdin);
    printf("Enter the content of the entry:\n");
    fgets(new_entry.content, MAX_CONTENT_SIZE, stdin);
    printf("Enter the date (dd/mm/yyyy):\n");
    scanf("%d/%d/%d", &new_entry.day, &new_entry.month, &new_entry.year);
    getchar(); // Consume the '\n' character left in input buffer

    diary_entries[num_entries++] = new_entry;
    printf("New entry added to diary.\n");
}

void search_entries() {
    char query[MAX_TITLE_SIZE];
    printf("Enter the search query:\n");
    fgets(query, MAX_TITLE_SIZE, stdin);

    int found = 0;
    for(int i=0; i<num_entries; i++) {
        if(strstr(diary_entries[i].title, query)) {
            printf("Found match for '%s'\n", query);
            printf("Title: %s", diary_entries[i].title);
            printf("Content: %s", diary_entries[i].content);
            printf("Date: %02d/%02d/%4d\n", diary_entries[i].day, diary_entries[i].month, diary_entries[i].year);
            found = 1;
        }
    }
    if(!found) printf("No match found for '%s'\n", query); 
}

void print_entries() {
    printf("Printing diary entries:\n");
    for(int i=0; i<num_entries; i++) {
        printf("Title: %s", diary_entries[i].title);
        printf("Content: %s", diary_entries[i].content);
        printf("Date: %02d/%02d/%4d\n", diary_entries[i].day, diary_entries[i].month, diary_entries[i].year);
    }
}

int main() {
    int choice;
    while(1) {
        printf("\n");
        printf("1. Add a new diary entry\n");
        printf("2. Search diary entries by title\n");
        printf("3. Print all diary entries\n");
        printf("4. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        getchar(); // Consume the '\n' character left in input buffer
        switch(choice) {
            case 1: add_entry(); break;
            case 2: search_entries(); break;
            case 3: print_entries(); break;
            case 4: printf("Exiting..."); exit(0);
            default: printf("Error: invalid choice.\n"); break;
        }
    }
    return 0;
}