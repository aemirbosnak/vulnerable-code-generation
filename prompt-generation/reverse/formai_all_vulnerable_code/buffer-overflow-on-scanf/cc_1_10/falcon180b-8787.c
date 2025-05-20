//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct entry {
    char name[50];
    char phone[20];
};

void add_entry(struct entry *book, int count) {
    printf("Enter name: ");
    scanf("%s", book[count].name);
    printf("Enter phone number: ");
    scanf("%s", book[count].phone);
    count++;
}

void search_entry(struct entry *book, int count, char *name) {
    int i = 0;
    while (i < count) {
        if (strcmp(book[i].name, name) == 0) {
            printf("Name: %s\nPhone number: %s\n", book[i].name, book[i].phone);
            return;
        }
        i++;
    }
    printf("Entry not found.\n");
}

void print_entries(struct entry *book, int count) {
    int i = 0;
    while (i < count) {
        printf("Name: %s\nPhone number: %s\n", book[i].name, book[i].phone);
        i++;
    }
}

int main() {
    struct entry book[MAX_ENTRIES];
    int count = 0;
    char choice;
    
    do {
        printf("\nPhone Book\n");
        printf("1. Add entry\n2. Search entry\n3. Print all entries\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        
        switch (choice) {
            case '1':
                add_entry(book, count);
                break;
            case '2':
                printf("Enter name to search: ");
                char name[50];
                scanf("%s", name);
                search_entry(book, count, name);
                break;
            case '3':
                print_entries(book, count);
                break;
            case '4':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '4');
    
    return 0;
}