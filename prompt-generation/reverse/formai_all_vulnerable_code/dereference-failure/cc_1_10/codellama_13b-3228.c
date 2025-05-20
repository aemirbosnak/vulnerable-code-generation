//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: decentralized
/*
 * A decentralized phone book example program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a phone number
struct phone_number {
    char* name;
    char* number;
};

// Structure to represent a phone book
struct phone_book {
    int size;
    struct phone_number* numbers;
};

// Function to add a phone number to the phone book
void add_phone_number(struct phone_book* phone_book, char* name, char* number) {
    struct phone_number* new_number = malloc(sizeof(struct phone_number));
    new_number->name = strdup(name);
    new_number->number = strdup(number);

    phone_book->numbers = realloc(phone_book->numbers, (phone_book->size + 1) * sizeof(struct phone_number));
    phone_book->numbers[phone_book->size] = *new_number;
    phone_book->size++;
}

// Function to remove a phone number from the phone book
void remove_phone_number(struct phone_book* phone_book, char* name) {
    int i;
    for (i = 0; i < phone_book->size; i++) {
        if (strcmp(phone_book->numbers[i].name, name) == 0) {
            free(phone_book->numbers[i].name);
            free(phone_book->numbers[i].number);

            phone_book->numbers = realloc(phone_book->numbers, (phone_book->size - 1) * sizeof(struct phone_number));
            memmove(&phone_book->numbers[i], &phone_book->numbers[i + 1], (phone_book->size - i - 1) * sizeof(struct phone_number));
            phone_book->size--;
            break;
        }
    }
}

// Function to search for a phone number in the phone book
void search_phone_number(struct phone_book* phone_book, char* name) {
    int i;
    for (i = 0; i < phone_book->size; i++) {
        if (strcmp(phone_book->numbers[i].name, name) == 0) {
            printf("Found phone number %s for name %s\n", phone_book->numbers[i].number, phone_book->numbers[i].name);
            break;
        }
    }
}

// Function to display the contents of the phone book
void display_phone_book(struct phone_book* phone_book) {
    int i;
    for (i = 0; i < phone_book->size; i++) {
        printf("Name: %s\nNumber: %s\n\n", phone_book->numbers[i].name, phone_book->numbers[i].number);
    }
}

int main() {
    struct phone_book phone_book = {0};

    add_phone_number(&phone_book, "John Doe", "555-1234");
    add_phone_number(&phone_book, "Jane Doe", "555-5678");
    add_phone_number(&phone_book, "John Smith", "555-9012");

    remove_phone_number(&phone_book, "Jane Doe");

    search_phone_number(&phone_book, "John Doe");
    search_phone_number(&phone_book, "Jane Doe");

    display_phone_book(&phone_book);

    return 0;
}