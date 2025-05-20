//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: real-life
// Phone Book Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_PHONE_NUMBER_LENGTH 15

struct phone_book_entry {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
};

void add_entry(struct phone_book_entry *phone_book, int index) {
    printf("Enter name: ");
    scanf("%s", &phone_book[index].name);
    printf("Enter phone number: ");
    scanf("%s", &phone_book[index].phone_number);
}

void search_entry(struct phone_book_entry *phone_book, int index) {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", &search_name);
    for (int i = 0; i < index; i++) {
        if (strcmp(phone_book[i].name, search_name) == 0) {
            printf("Name: %s\nPhone Number: %s\n", phone_book[i].name, phone_book[i].phone_number);
            break;
        }
    }
}

void delete_entry(struct phone_book_entry *phone_book, int index) {
    char delete_name[MAX_NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", &delete_name);
    for (int i = 0; i < index; i++) {
        if (strcmp(phone_book[i].name, delete_name) == 0) {
            for (int j = i; j < index - 1; j++) {
                phone_book[j] = phone_book[j + 1];
            }
            break;
        }
    }
}

int main() {
    struct phone_book_entry phone_book[100];
    int index = 0;
    char option;
    do {
        printf("Enter option:\n");
        printf("a - Add entry\n");
        printf("s - Search entry\n");
        printf("d - Delete entry\n");
        printf("q - Quit\n");
        scanf(" %c", &option);
        switch (option) {
            case 'a':
                add_entry(phone_book, index);
                index++;
                break;
            case 's':
                search_entry(phone_book, index);
                break;
            case 'd':
                delete_entry(phone_book, index);
                break;
            case 'q':
                printf("Quitting...\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while (option != 'q');
    return 0;
}