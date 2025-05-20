//FormAI DATASET v1.0 Category: Database Indexing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100 // maximum number of entries in the database

struct Entry {
    int index;
    char name[50];
    int age;
    char address[100];
};

// global variables
struct Entry database[MAX_ENTRIES]; // the database array
int index_count = 0; // number of entries currently in the database

// function prototypes
void add_entry();
void search_entry();
void print_database();

int main() {
    int choice = 0;
    do {
        // display menu
        printf("\nDatabase Indexing System\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Print database\n");
        printf("4. Quit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        // process user's choice
        switch(choice) {
            case 1:
                add_entry();
                break;
            case 2:
                search_entry();
                break;
            case 3:
                print_database();
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    } while(choice != 4);

    return 0;
}

void add_entry() {
    // make sure database is not full
    if(index_count >= MAX_ENTRIES) {
        printf("\nDatabase is full.\n");
        return;
    }

    // get user's input
    struct Entry new_entry;
    printf("\nEnter name: ");
    scanf("%s", new_entry.name);
    printf("Enter age: ");
    scanf("%d", &new_entry.age);
    printf("Enter address: ");
    scanf("%s", new_entry.address);

    // add entry to database
    new_entry.index = index_count;
    database[index_count] = new_entry;
    index_count++;

    printf("\nEntry added.\n");
}

void search_entry() {
    // make sure database is not empty
    if(index_count == 0) {
        printf("\nDatabase is empty.\n");
        return;
    }

    // get user's input
    int search_index;
    printf("\nEnter index of entry to search: ");
    scanf("%d", &search_index);

    // search for entry in database
    int i;
    for(i=0; i<index_count; i++) {
        if(database[i].index == search_index) {
            printf("\nEntry found.\n");
            printf("Name: %s\n", database[i].name);
            printf("Age: %d\n", database[i].age);
            printf("Address: %s\n", database[i].address);
            return;
        }
    }

    printf("\nEntry not found.\n");
}

void print_database() {
    // make sure database is not empty
    if(index_count == 0) {
        printf("\nDatabase is empty.\n");
        return;
    }

    int i;
    for(i=0; i<index_count; i++) {
        printf("\nEntry %d\n", database[i].index);
        printf("Name: %s\n", database[i].name);
        printf("Age: %d\n", database[i].age);
        printf("Address: %s\n", database[i].address);
    }
}