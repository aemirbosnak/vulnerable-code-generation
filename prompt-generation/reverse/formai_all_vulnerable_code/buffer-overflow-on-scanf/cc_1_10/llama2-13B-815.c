//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define PHONE_BOOK_SIZE 100
#define PHONE_NUMBER_SIZE 10

typedef struct phone_entry {
    char name[50];
    char number[PHONE_NUMBER_SIZE];
} phone_entry;

phone_entry phone_book[PHONE_BOOK_SIZE];
int num_entries = 0;

void add_entry(char *name, char *number) {
    if (num_entries == PHONE_BOOK_SIZE) {
        printf("Phone book is full! Please delete some entries first.\n");
        return;
    }

    strcpy(phone_book[num_entries].name, name);
    strcpy(phone_book[num_entries].number, number);
    num_entries++;
}

void delete_entry(char *name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            break;
        }
    }

    if (i < num_entries) {
        memset(&phone_book[i], 0, sizeof(phone_entry));
        num_entries--;
    } else {
        printf("Entry not found!\n");
    }
}

void print_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%d. %s %s\n", i + 1, phone_book[i].name, phone_book[i].number);
    }
}

int main() {
    srand(time(NULL));

    while (1) {
        char name[50];
        char number[PHONE_NUMBER_SIZE];
        int choice;

        printf("Welcome to the phone book!\n");

        printf("1. Add entry\n");
        printf("2. Delete entry\n");
        printf("3. Print all entries\n");
        printf("4. Quit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, 50, stdin);
                printf("Enter number: ");
                fgets(number, PHONE_NUMBER_SIZE, stdin);
                add_entry(name, number);
                break;

            case 2:
                printf("Enter name to delete: ");
                char *name_to_delete = stdin;
                delete_entry(name_to_delete);
                break;

            case 3:
                print_entries();
                break;

            case 4:
                printf("Goodbye!\n");
                return 0;
        }
    }

    return 0;
}