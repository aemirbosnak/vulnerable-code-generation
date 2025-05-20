//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PHONE_BOOK_SIZE 100

struct PhoneBookEntry {
    char name[20];
    char phone_number[20];
};

struct PhoneBook {
    struct PhoneBookEntry *entries;
    int size;
    int capacity;
};

void print_phone_book(struct PhoneBook *phone_book) {
    for (int i = 0; i < phone_book->size; i++) {
        printf("%s %s\n", phone_book->entries[i].name, phone_book->entries[i].phone_number);
    }
}

void add_entry(struct PhoneBook *phone_book, char *name, char *phone_number) {
    if (phone_book->size >= phone_book->capacity) {
        struct PhoneBookEntry *new_entries = (struct PhoneBookEntry *) realloc(phone_book->entries, (phone_book->capacity + 1) * sizeof(struct PhoneBookEntry));
        if (new_entries == NULL) {
            printf("Error: failed to allocate memory for phone book entry\n");
            return;
        }
        phone_book->entries = new_entries;
        phone_book->capacity++;
    }

    strcpy(phone_book->entries[phone_book->size].name, name);
    strcpy(phone_book->entries[phone_book->size].phone_number, phone_number);
    phone_book->size++;
}

void remove_entry(struct PhoneBook *phone_book, char *name) {
    int index = -1;
    for (int i = 0; i < phone_book->size; i++) {
        if (strcmp(phone_book->entries[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: entry not found\n");
        return;
    }

    for (int i = index; i < phone_book->size - 1; i++) {
        phone_book->entries[i] = phone_book->entries[i + 1];
    }

    phone_book->size--;
}

int main() {
    struct PhoneBook phone_book = {NULL, 0, 0};

    add_entry(&phone_book, "Alice", "555-1234");
    add_entry(&phone_book, "Bob", "555-5678");
    add_entry(&phone_book, "Charlie", "555-9012");

    print_phone_book(&phone_book);

    remove_entry(&phone_book, "Bob");

    print_phone_book(&phone_book);

    return 0;
}