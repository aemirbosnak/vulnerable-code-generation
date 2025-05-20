//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone_number[15];
} entry_t;

entry_t phone_book[MAX_ENTRIES];
int num_entries = 0;

void display_menu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add Entry\n");
    printf("2. Search Entry\n");
    printf("3. Display All Entries\n");
    printf("4. Exit\n");
}

void add_entry() {
    if(num_entries >= MAX_ENTRIES) {
        printf("\nPhone book is full. Cannot add more entries.\n");
        return;
    }
    printf("\nEnter name: ");
    scanf("%s", phone_book[num_entries].name);
    printf("Enter phone number: ");
    scanf("%s", phone_book[num_entries].phone_number);
    num_entries++;
    printf("\nEntry added successfully.\n");
}

void search_entry() {
    char name[50];
    printf("\nEnter name to search: ");
    scanf("%s", name);
    int i;
    for(i=0; i<num_entries; i++) {
        if(strcmp(phone_book[i].name, name) == 0) {
            printf("\nName: %s\nPhone Number: %s\n", phone_book[i].name, phone_book[i].phone_number);
            return;
        }
    }
    printf("\nEntry not found.\n");
}

void display_all_entries() {
    int i;
    for(i=0; i<num_entries; i++) {
        printf("\nName: %s\nPhone Number: %s\n", phone_book[i].name, phone_book[i].phone_number);
    }
}

int main() {
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_entry();
                break;
            case 2:
                search_entry();
                break;
            case 3:
                display_all_entries();
                break;
            case 4:
                printf("\nExiting Phone Book...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice!= 4);
    return 0;
}