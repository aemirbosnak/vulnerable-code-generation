//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 256
#define MAX_NUMBER_LENGTH 16
#define MAX_PHONE_BOOK_SIZE 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} PhoneBookEntry;

void print_phone_book(PhoneBookEntry phone_book[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%s: %s\n", phone_book[i].name, phone_book[i].number);
    }
}

void add_phone_book_entry(PhoneBookEntry phone_book[], int *size) {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter number: ");
    scanf("%s", number);

    strcpy(phone_book[*size].name, name);
    strcpy(phone_book[*size].number, number);
    *size = *size + 1;
}

void remove_phone_book_entry(PhoneBookEntry phone_book[], int *size) {
    int index;
    printf("Enter index to remove: ");
    scanf("%d", &index);

    if (index < 0 || index >= *size) {
        printf("Invalid index\n");
        return;
    }

    for (int i = index; i < *size - 1; i++) {
        strcpy(phone_book[i].name, phone_book[i + 1].name);
        strcpy(phone_book[i].number, phone_book[i + 1].number);
    }

    *size = *size - 1;
}

int main() {
    PhoneBookEntry phone_book[MAX_PHONE_BOOK_SIZE];
    int size = 0;

    add_phone_book_entry(phone_book, &size);
    add_phone_book_entry(phone_book, &size);
    add_phone_book_entry(phone_book, &size);

    print_phone_book(phone_book, size);

    remove_phone_book_entry(phone_book, &size);

    print_phone_book(phone_book, size);

    return 0;
}