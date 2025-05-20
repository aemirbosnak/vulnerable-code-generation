//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: interoperable
/*
 * Phone Book Program
 *
 * This program stores phone numbers and names in a phone book.
 * The phone book is stored in a linked list.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for a phone number
typedef struct {
    char name[50];
    char number[10];
    struct PhoneNumber* next;
} PhoneNumber;

// Struct for a phone book
typedef struct {
    PhoneNumber* head;
    PhoneNumber* tail;
} PhoneBook;

// Function to create a new phone number
PhoneNumber* createPhoneNumber(const char* name, const char* number) {
    PhoneNumber* new_number = (PhoneNumber*)malloc(sizeof(PhoneNumber));
    if (new_number == NULL) {
        printf("Error: out of memory\n");
        return NULL;
    }
    strcpy(new_number->name, name);
    strcpy(new_number->number, number);
    new_number->next = NULL;
    return new_number;
}

// Function to add a phone number to a phone book
void addPhoneNumber(PhoneBook* phone_book, const char* name, const char* number) {
    PhoneNumber* new_number = createPhoneNumber(name, number);
    if (new_number == NULL) {
        return;
    }
    if (phone_book->head == NULL) {
        phone_book->head = new_number;
        phone_book->tail = new_number;
    } else {
        phone_book->tail->next = new_number;
        phone_book->tail = new_number;
    }
}

// Function to search for a phone number in a phone book
PhoneNumber* searchPhoneNumber(PhoneBook* phone_book, const char* name) {
    PhoneNumber* current = phone_book->head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to print all phone numbers in a phone book
void printPhoneBook(PhoneBook* phone_book) {
    PhoneNumber* current = phone_book->head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->number);
        current = current->next;
    }
}

int main() {
    PhoneBook* phone_book = (PhoneBook*)malloc(sizeof(PhoneBook));
    phone_book->head = NULL;
    phone_book->tail = NULL;

    addPhoneNumber(phone_book, "John", "555-1234");
    addPhoneNumber(phone_book, "Jane", "555-5678");
    addPhoneNumber(phone_book, "Bob", "555-9012");

    PhoneNumber* john = searchPhoneNumber(phone_book, "John");
    if (john != NULL) {
        printf("John's phone number is %s\n", john->number);
    }

    printPhoneBook(phone_book);

    return 0;
}