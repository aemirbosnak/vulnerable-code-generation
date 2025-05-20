//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
/*
 * Cyberpunk Phone Book
 *
 * A simple phone book program for a Cyberpunk-themed future.
 */

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 32
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Entry;

void add_entry(Entry* entries, int* num_entries) {
    printf("Enter name: ");
    fgets(entries[*num_entries].name, MAX_NAME_LENGTH, stdin);
    printf("Enter phone: ");
    fgets(entries[*num_entries].phone, MAX_PHONE_LENGTH, stdin);
    (*num_entries)++;
}

void display_entry(Entry entry) {
    printf("%s: %s\n", entry.name, entry.phone);
}

void display_phone_book(Entry* entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        display_entry(entries[i]);
    }
}

int main() {
    Entry entries[100];
    int num_entries = 0;

    while (1) {
        printf("1. Add new entry\n");
        printf("2. Display phone book\n");
        printf("3. Quit\n");
        printf("Choose an option: ");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_entry(entries, &num_entries);
                break;
            case 2:
                display_phone_book(entries, num_entries);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid option\n");
                break;
        }
    }

    return 0;
}