//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

struct entry {
    char name[50];
    char phone[15];
};

void add_entry(struct entry *book, int index) {
    printf("Enter name: ");
    scanf("%s", book[index].name);

    printf("Enter phone number: ");
    scanf("%s", book[index].phone);
}

void search_entry(struct entry *book, int size, char *name) {
    int i;

    for(i=0; i<size; i++) {
        if(strcmp(book[i].name, name) == 0) {
            printf("%s - %s\n", book[i].name, book[i].phone);
            return;
        }
    }

    printf("Entry not found.\n");
}

void delete_entry(struct entry *book, int size, char *name) {
    int i;

    for(i=0; i<size; i++) {
        if(strcmp(book[i].name, name) == 0) {
            printf("%s deleted.\n", name);
            memset(&book[i], 0, sizeof(struct entry));
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    struct entry book[MAX_ENTRIES];
    int size = 0;

    printf("Phone Book\n");
    printf("-----------\n");

    while(1) {
        printf("\n1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(size >= MAX_ENTRIES) {
                    printf("Phone book is full.\n");
                } else {
                    add_entry(book, size);
                    size++;
                }
                break;

            case 2:
                printf("Enter name to search: ");
                char name[50];
                scanf("%s", name);
                search_entry(book, size, name);
                break;

            case 3:
                printf("Enter name to delete: ");
                char name2[50];
                scanf("%s", name2);
                delete_entry(book, size, name2);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}