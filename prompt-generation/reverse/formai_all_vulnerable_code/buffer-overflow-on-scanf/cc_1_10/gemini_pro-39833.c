//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 31
#define MAX_PHONE_LEN 16
#define MAX_ENTRIES 100

typedef struct phone_entry {
    char name[MAX_NAME_LEN + 1];
    char phone[MAX_PHONE_LEN + 1];
} phone_entry_t;

typedef struct phone_book {
    phone_entry_t entries[MAX_ENTRIES];
    int num_entries;
} phone_book_t;

void init_phone_book(phone_book_t *book) {
    book->num_entries = 0;
}

int add_entry(phone_book_t *book, const char *name, const char *phone) {
    if (book->num_entries >= MAX_ENTRIES) {
        return -1;  // Phone book is full
    }

    strcpy(book->entries[book->num_entries].name, name);
    strcpy(book->entries[book->num_entries].phone, phone);
    book->num_entries++;

    return 0;
}

int delete_entry(phone_book_t *book, const char *name) {
    int i;

    for (i = 0; i < book->num_entries; i++) {
        if (strcmp(book->entries[i].name, name) == 0) {
            break;
        }
    }

    if (i == book->num_entries) {
        return -1;  // Entry not found
    }

    for (; i < book->num_entries - 1; i++) {
        book->entries[i] = book->entries[i + 1];
    }

    book->num_entries--;

    return 0;
}

int find_entry(phone_book_t *book, const char *name, char *phone) {
    int i;

    for (i = 0; i < book->num_entries; i++) {
        if (strcmp(book->entries[i].name, name) == 0) {
            strcpy(phone, book->entries[i].phone);
            return 0;
        }
    }

    return -1;  // Entry not found
}

void print_phone_book(phone_book_t *book) {
    int i;

    for (i = 0; i < book->num_entries; i++) {
        printf("%s: %s\n", book->entries[i].name, book->entries[i].phone);
    }
}

int main() {
    phone_book_t phone_book;
    char name[MAX_NAME_LEN + 1];
    char phone[MAX_PHONE_LEN + 1];
    int choice;

    init_phone_book(&phone_book);

    while (1) {
        printf("1. Add entry\n");
        printf("2. Delete entry\n");
        printf("3. Find entry\n");
        printf("4. Print phone book\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);
                if (add_entry(&phone_book, name, phone) == 0) {
                    printf("Entry added successfully\n");
                } else {
                    printf("Error adding entry\n");
                }
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                if (delete_entry(&phone_book, name) == 0) {
                    printf("Entry deleted successfully\n");
                } else {
                    printf("Error deleting entry\n");
                }
                break;
            case 3:
                printf("Enter name: ");
                scanf("%s", name);
                if (find_entry(&phone_book, name, phone) == 0) {
                    printf("Phone: %s\n", phone);
                } else {
                    printf("Entry not found\n");
                }
                break;
            case 4:
                print_phone_book(&phone_book);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}