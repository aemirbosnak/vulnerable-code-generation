//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a struct for a phone book entry
struct phone_book_entry {
    char name[50];  // Name of the person
    char phone_number[20];  // Phone number of the person
};

// Define a function to read a phone book entry from the user
void read_entry(struct phone_book_entry *entry) {
    printf("Enter name: ");
    fgets(entry->name, 50, stdin);
    printf("Enter phone number: ");
    fgets(entry->phone_number, 20, stdin);
}

// Define a function to print the phone book
void print_phone_book(struct phone_book_entry *phone_book, int num_entries) {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%d. %s\n", i + 1, phone_book[i].name);
    }
}

int main() {
    // Create an empty phone book
    struct phone_book_entry phone_book[10];
    int num_entries = 0;

    // Read entries from the user until they say "stop"
    while (1) {
        // Read a new entry
        struct phone_book_entry new_entry;
        read_entry(&new_entry);

        // Check if the user wants to add the entry to the phone book
        printf("Do you want to add %s to the phone book? (y/n): ", new_entry.name);
        char response;
        scanf("%c", &response);
        if (response == 'y') {
            // Add the entry to the phone book
            phone_book[num_entries] = new_entry;
            num_entries++;
        }
    }

    // Print the phone book
    print_phone_book(phone_book, num_entries);

    return 0;
}