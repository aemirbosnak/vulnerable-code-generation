//FormAI DATASET v1.0 Category: Digital Diary ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ENTRIES 100

struct date {
    int day;
    int month;
    int year;
};

struct entry {
    struct date entry_date;
    char title[50];
    char description[500];
};

struct diary {
    struct entry entries[MAX_ENTRIES];
    int num_entries;
};

void create_entry(struct diary *my_diary);
void print_all_entries(struct diary my_diary);
void search_entries(struct diary my_diary, char* search_query);

int main() {
    struct diary my_diary;
    my_diary.num_entries = 0;
    int option;
    while(1) {
        printf("Digital Diary\n");
        printf("1. Create an entry\n");
        printf("2. Print all entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        getchar(); //To clear the newline character from input buffer
        switch(option) {
            case 1:
                create_entry(&my_diary);
                break;
            case 2:
                print_all_entries(my_diary);
                break;
            case 3:
                printf("Enter your search query: ");
                char search_query[50];
                fgets(search_query, 50, stdin);
                //Removing the newline character from search query string
                search_query[strcspn(search_query, "\n")] = 0;
                search_entries(my_diary, search_query);
                break;
            case 4:
                printf("Thank you for using Digital Diary. Bye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

void create_entry(struct diary *my_diary) {
    struct entry new_entry;
    printf("Enter date of entry (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &new_entry.entry_date.day, &new_entry.entry_date.month, &new_entry.entry_date.year);
    getchar(); //To clear the newline character from input buffer
    printf("Enter title of entry: ");
    fgets(new_entry.title, 50, stdin);
    //Removing the newline character from the title string
    new_entry.title[strcspn(new_entry.title, "\n")] = 0;
    printf("Enter description of entry: ");
    fgets(new_entry.description, 500, stdin);
    //Removing the newline character from the description string
    new_entry.description[strcspn(new_entry.description, "\n")] = 0;
    if(my_diary->num_entries == MAX_ENTRIES) {
        printf("Digital Diary is full. Cannot add more entries.\n");
        return;
    }
    my_diary->entries[my_diary->num_entries++] = new_entry;
    printf("Entry created successfully!\n");
}

void print_all_entries(struct diary my_diary) {
    if(my_diary.num_entries == 0) {
        printf("Digital Diary is empty. No entries to print.\n");
        return;
    }
    printf("All Entries:\n");
    for(int i=0; i<my_diary.num_entries; i++) {
        printf("Date: %02d/%02d/%04d\n", my_diary.entries[i].entry_date.day, my_diary.entries[i].entry_date.month, my_diary.entries[i].entry_date.year);
        printf("Title: %s\n", my_diary.entries[i].title);
        printf("Description: %s\n", my_diary.entries[i].description);
    }
}

void search_entries(struct diary my_diary, char* search_query) {
    if(my_diary.num_entries == 0) {
        printf("Digital Diary is empty. No entries to search.\n");
        return;
    }
    printf("Search Results:\n");
    for(int i=0; i<my_diary.num_entries; i++) {
        if(strstr(my_diary.entries[i].title, search_query) != NULL || strstr(my_diary.entries[i].description, search_query) != NULL) {
            printf("Date: %02d/%02d/%04d\n", my_diary.entries[i].entry_date.day, my_diary.entries[i].entry_date.month, my_diary.entries[i].entry_date.year);
            printf("Title: %s\n", my_diary.entries[i].title);
            printf("Description: %s\n", my_diary.entries[i].description);
        }
    }
}