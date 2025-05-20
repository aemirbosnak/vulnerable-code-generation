//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PHONE_BOOK_SIZE 100
#define NAME_MAX_LENGTH 50
#define PHONE_NUMBER_MAX_LENGTH 20

typedef struct phone_book {
    char name[NAME_MAX_LENGTH];
    char phone_number[PHONE_NUMBER_MAX_LENGTH];
} phone_book;

phone_book phone_book_array[PHONE_BOOK_SIZE];
int current_size = 0;

void add_contact(char *name, char *phone_number) {
    if (current_size == PHONE_BOOK_SIZE) {
        printf("Phone book is full, cannot add any more contacts!\n");
        return;
    }

    strcpy(phone_book_array[current_size].name, name);
    strcpy(phone_book_array[current_size].phone_number, phone_number);
    current_size++;
}

void display_contacts() {
    int i;

    for (i = 0; i < current_size; i++) {
        printf("%d. %s %s\n", i + 1, phone_book_array[i].name, phone_book_array[i].phone_number);
    }
}

int search_contact(char *name) {
    int i;

    for (i = 0; i < current_size; i++) {
        if (strcmp(name, phone_book_array[i].name) == 0) {
            return i + 1;
        }
    }

    return -1;
}

int main() {
    char name[NAME_MAX_LENGTH];
    char phone_number[PHONE_NUMBER_MAX_LENGTH];

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        printf("Add contact (y/n)? ");
        scanf("%s", name);

        if (strcmp(name, "y") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter phone number: ");
            scanf("%s", phone_number);
            add_contact(name, phone_number);
        }
    }

    display_contacts();

    printf("Enter name to search: ");
    char search_name[NAME_MAX_LENGTH];
    scanf("%s", search_name);

    int found_index = search_contact(search_name);

    if (found_index != -1) {
        printf("Found contact %d: %s %s\n", found_index + 1, phone_book_array[found_index].name, phone_book_array[found_index].phone_number);
    } else {
        printf("No contact found\n");
    }

    return 0;
}