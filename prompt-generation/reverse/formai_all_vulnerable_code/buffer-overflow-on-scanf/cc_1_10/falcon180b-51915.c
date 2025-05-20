//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

// Define the structure for each entry in the phone book
typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry;

// Function to compare two entries based on their names
int compare_entries(const void *a, const void *b) {
    entry *entry1 = (entry *) a;
    entry *entry2 = (entry *) b;
    return strcmp(entry1->name, entry2->name);
}

// Function to print the entire phone book
void print_phone_book(entry *phone_book, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", phone_book[i].name, phone_book[i].number);
    }
}

int main() {
    entry phone_book[MAX_ENTRIES];
    int num_entries = 0;

    // Read in entries from the user until the phone book is full
    while (num_entries < MAX_ENTRIES) {
        printf("Enter a name: ");
        scanf("%s", phone_book[num_entries].name);
        printf("Enter a number: ");
        scanf("%s", phone_book[num_entries].number);
        num_entries++;
    }

    // Sort the phone book alphabetically by name
    qsort(phone_book, num_entries, sizeof(entry), compare_entries);

    // Print the sorted phone book
    printf("Sorted phone book:\n");
    print_phone_book(phone_book, num_entries);

    return 0;
}