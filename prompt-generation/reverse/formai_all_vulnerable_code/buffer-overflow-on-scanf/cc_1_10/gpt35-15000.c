//FormAI DATASET v1.0 Category: Phone Book ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure definition for phone book entry
typedef struct {
    char* name;
    char* number;
} PhonebookEntry;

// function prototypes
void addEntry(PhonebookEntry* book, int* size);
void searchEntry(PhonebookEntry* book, int size);
void printEntries(PhonebookEntry* book, int size);
void freeEntries(PhonebookEntry* book, int size);

int main() {
    PhonebookEntry* book = NULL;
    int size = 0;
    char input;

    printf("Welcome to your peaceful phone book program!\n");

    do {
        printf("\nPlease select an option:\n");
        printf("(a)dd an entry\n");
        printf("(s)earch for an entry\n");
        printf("(p)rint all entries\n");
        printf("(q)uit\n");
        printf(">> ");

        scanf(" %c", &input);

        switch (input) {
            case 'a':
                addEntry(book, &size);
                break;
            case 's':
                searchEntry(book, size);
                break;
            case 'p':
                printEntries(book, size);
                break;
            case 'q':
                break;
            default:
                printf("Invalid input.\n");
                break;
        }
    } while (input != 'q');

    freeEntries(book, size);

    printf("\nThank you for using your peaceful phone book program!\n");

    return 0;
}

// function to add a new entry to the phone book
void addEntry(PhonebookEntry* book, int* size) {
    char buffer[256];
    PhonebookEntry* temp;
    temp = realloc(book, (*size + 1) * sizeof(PhonebookEntry));

    if (temp == NULL) {
        printf("Error: failed to allocate memory.\n");
        return;
    }

    book = temp;

    printf("\nEnter contact name: ");
    scanf("%s", buffer);
    book[*size].name = malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(book[*size].name, buffer);

    printf("Enter phone number: ");
    scanf("%s", buffer);
    book[*size].number = malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(book[*size].number, buffer);

    (*size)++;

    printf("Entry added successfully!\n");
}

// function to search for an entry in the phone book
void searchEntry(PhonebookEntry* book, int size) {
    char buffer[256];
    int found = 0;

    printf("\nEnter name to search for: ");
    scanf("%s", buffer);

    for (int i = 0; i < size; i++) {
        if (strcmp(book[i].name, buffer) == 0) {
            printf("Found phone number: %s\n", book[i].number);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Entry not found.\n");
    }
}

// function to print all entries in the phone book
void printEntries(PhonebookEntry* book, int size) {
    printf("\nPhone Book Entries:\n");

    for (int i = 0; i < size; i++) {
        printf("%s: %s\n", book[i].name, book[i].number);
    }
}

// function to free memory allocated for entries in the phone book
void freeEntries(PhonebookEntry* book, int size) {
    for (int i = 0; i < size; i++) {
        free(book[i].name);
        free(book[i].number);
    }
    free(book);
}