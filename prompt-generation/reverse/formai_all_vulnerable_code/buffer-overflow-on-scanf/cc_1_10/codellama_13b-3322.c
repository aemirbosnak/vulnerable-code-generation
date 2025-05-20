//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: immersive
/*
 *  C Phone Book Example Program
 *  Written in an immersive style
 *  By: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PHONE_BOOK_SIZE 100

typedef struct {
    char name[50];
    char phone_number[20];
} PhoneBookEntry;

void add_phone_book_entry(PhoneBookEntry* phone_book, int* num_entries, char* name, char* phone_number);
void search_phone_book(PhoneBookEntry* phone_book, int num_entries, char* name);
void print_phone_book(PhoneBookEntry* phone_book, int num_entries);

int main() {
    PhoneBookEntry phone_book[MAX_PHONE_BOOK_SIZE];
    int num_entries = 0;

    char name[50];
    char phone_number[20];

    while (1) {
        printf("Enter a name to add to the phone book: ");
        scanf("%s", name);

        if (strcmp(name, "quit") == 0) {
            break;
        }

        printf("Enter the phone number for %s: ", name);
        scanf("%s", phone_number);

        add_phone_book_entry(phone_book, &num_entries, name, phone_number);
    }

    printf("Enter a name to search for: ");
    scanf("%s", name);

    search_phone_book(phone_book, num_entries, name);

    print_phone_book(phone_book, num_entries);

    return 0;
}

void add_phone_book_entry(PhoneBookEntry* phone_book, int* num_entries, char* name, char* phone_number) {
    if (*num_entries >= MAX_PHONE_BOOK_SIZE) {
        printf("Phone book is full, unable to add new entry.\n");
        return;
    }

    strcpy(phone_book[*num_entries].name, name);
    strcpy(phone_book[*num_entries].phone_number, phone_number);
    (*num_entries)++;
}

void search_phone_book(PhoneBookEntry* phone_book, int num_entries, char* name) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            printf("Phone number for %s is %s\n", name, phone_book[i].phone_number);
            return;
        }
    }

    printf("Name %s not found in phone book.\n", name);
}

void print_phone_book(PhoneBookEntry* phone_book, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", phone_book[i].name, phone_book[i].phone_number);
    }
}