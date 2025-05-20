//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct entry {
    char name[50];
    char number[20];
};

void add_entry(struct entry* book, int index) {
    printf("Enter name: ");
    scanf("%s", book[index].name);
    printf("Enter phone number: ");
    scanf("%s", book[index].number);
}

void display_entry(struct entry entry) {
    printf("%s: %s\n", entry.name, entry.number);
}

void search_entry(struct entry* book, char* name) {
    int i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (strcmp(book[i].name, name) == 0) {
            display_entry(book[i]);
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    struct entry phonebook[MAX_ENTRIES];
    int choice, index;

    while (1) {
        printf("Phone Book Menu:\n");
        printf("1. Add entry\n");
        printf("2. Display entry\n");
        printf("3. Search entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter index: ");
                scanf("%d", &index);
                add_entry(phonebook, index);
                break;
            case 2:
                printf("Enter index: ");
                scanf("%d", &index);
                display_entry(phonebook[index]);
                break;
            case 3:
                printf("Enter name: ");
                scanf("%s", phonebook[0].name);
                search_entry(phonebook, phonebook[0].name);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}