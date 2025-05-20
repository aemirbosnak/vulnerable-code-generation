//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

struct entry {
    char name[50];
    char phone[20];
};

void add_entry(struct entry *book, int count) {
    printf("Enter name: ");
    scanf("%s", book[count].name);
    printf("Enter phone number: ");
    scanf("%s", book[count].phone);
}

void search_entry(struct entry *book, int count, char *name) {
    int i;
    for(i = 0; i < count; i++) {
        if(strcmp(book[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", book[i].name, book[i].phone);
            return;
        }
    }
    printf("Entry not found.\n");
}

void print_all_entries(struct entry *book, int count) {
    int i;
    for(i = 0; i < count; i++) {
        printf("Name: %s\nPhone: %s\n", book[i].name, book[i].phone);
    }
}

int main() {
    struct entry book[MAX_ENTRIES];
    int count = 0;

    printf("Phone Book\n");

    while(count < MAX_ENTRIES) {
        printf("1. Add entry\n2. Search entry\n3. Print all entries\n4. Exit\n");
        scanf("%d", &count);

        switch(count) {
            case 1:
                add_entry(book, count);
                break;
            case 2:
                printf("Enter name to search: ");
                char name[50];
                scanf("%s", name);
                search_entry(book, count, name);
                break;
            case 3:
                print_all_entries(book, count);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}