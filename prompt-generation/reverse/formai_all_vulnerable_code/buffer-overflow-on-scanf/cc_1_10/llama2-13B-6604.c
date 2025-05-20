//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PHONE_BOOK_SIZE 1000
#define MAX_NAME_LEN 255
#define MAX_PHONE_LEN 20

typedef struct phone_entry {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
} phone_entry_t;

phone_entry_t phone_book[PHONE_BOOK_SIZE];
int num_entries = 0;

void add_entry(char *name, char *phone) {
    if (num_entries == PHONE_BOOK_SIZE) {
        printf("Sorry, the phone book is full! Maybe you should try a different phone?\n");
        return;
    }

    strcpy(phone_book[num_entries].name, name);
    strcpy(phone_book[num_entries].phone, phone);
    num_entries++;
}

phone_entry_t *find_entry(char *name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(name, phone_book[i].name) == 0) {
            return &phone_book[i];
        }
    }
    return NULL;
}

void remove_entry(char *name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(name, phone_book[i].name) == 0) {
            memset(phone_book[i].name, 0, MAX_NAME_LEN);
            memset(phone_book[i].phone, 0, MAX_PHONE_LEN);
            num_entries--;
            break;
        }
    }
}

void print_phone_book() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%d: %s %s\n", i, phone_book[i].name, phone_book[i].phone);
    }
}

int main() {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    int choice;

    printf("Welcome to the Crazytopia Phone Book!\n");

    while (1) {
        printf("Menu:\n");
        printf("1. Add a new entry\n");
        printf("2. Find an entry\n");
        printf("3. Remove an entry\n");
        printf("4. Print the phone book\n");
        printf("5. Quit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name: ");
                fgets(name, MAX_NAME_LEN, stdin);
                printf("Enter the phone number: ");
                fgets(phone, MAX_PHONE_LEN, stdin);
                add_entry(name, phone);
                break;

            case 2:
                printf("Enter the name to find: ");
                char *name_to_find = strdup(stdin);
                phone_entry_t *found = find_entry(name_to_find);
                free(name_to_find);
                if (found) {
                    printf("%d: %s %s\n", found - phone_book, found->name, found->phone);
                } else {
                    printf("Sorry, no such entry!\n");
                }
                break;

            case 3:
                printf("Enter the name to remove: ");
                char *name_to_remove = strdup(stdin);
                remove_entry(name_to_remove);
                free(name_to_remove);
                break;

            case 4:
                print_phone_book();
                break;

            case 5:
                printf("Goodbye, Crazytopia!\n");
                return 0;
        }
    }

    return 0;
}