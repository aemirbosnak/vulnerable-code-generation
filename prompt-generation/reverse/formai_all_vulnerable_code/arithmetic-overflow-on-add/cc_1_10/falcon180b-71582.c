//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBERS_PER_ENTRY 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    char numbers[MAX_NUMBERS_PER_ENTRY][16];
    int num_entries;
} contact;

void add_contact(contact* book, int num_entries, char* name, char* number) {
    strcpy(book->name, name);
    strcpy(book->numbers[num_entries], number);
    book->num_entries++;
}

void display_contacts(contact* book, int num_entries) {
    printf("Name\t");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t", book->numbers[i]);
    }
    printf("\n");
}

int main() {
    contact book;
    int num_entries = 0;
    char input[100];
    char name[MAX_NAME_LENGTH];
    char number[16];

    printf("Enter the name of the contact:\n");
    scanf("%s", name);
    strcpy(book.name, name);

    while (1) {
        printf("Enter the phone number (or type 'done' to finish):\n");
        scanf("%s", input);
        if (strcmp(input, "done") == 0) {
            break;
        }
        strcpy(number, input);
        add_contact(&book, num_entries, name, number);
        num_entries++;
    }

    printf("Phone book:\n");
    display_contacts(&book, num_entries);

    return 0;
}