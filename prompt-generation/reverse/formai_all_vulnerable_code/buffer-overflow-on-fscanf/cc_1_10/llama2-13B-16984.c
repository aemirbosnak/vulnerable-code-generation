//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: shocked
// Shocking Phone Book Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store phone book entries
typedef struct {
    char name[50];
    char number[20];
} phone_entry;

// Function to read phone book entries from file
phone_entry* read_phone_book(char* file_name) {
    // File to store phone book entries
    FILE* file = fopen(file_name, "r");

    // Check if file open successfully
    if (file == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        return NULL;
    }

    // Array to store phone book entries
    phone_entry* entries = (phone_entry*) malloc(sizeof(phone_entry) * 10);

    // Read entries from file
    int i = 0;
    while (fscanf(file, "%s %s", entries[i].name, entries[i].number) == 2) {
        i++;
    }

    // Check if any entries were read
    if (i == 0) {
        printf("Error: No entries found in file %s\n", file_name);
        return NULL;
    }

    // Return phone book entries
    return entries;
}

// Function to write phone book entries to file
void write_phone_book(char* file_name, phone_entry* entries) {
    // File to store phone book entries
    FILE* file = fopen(file_name, "w");

    // Check if file open successfully
    if (file == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        return;
    }

    // Write entries to file
    int i = 0;
    while (entries[i].name != NULL) {
        fprintf(file, "%s %s\n", entries[i].name, entries[i].number);
        i++;
    }

    // Check if any entries were written
    if (i == 0) {
        printf("Error: No entries found to write to file %s\n", file_name);
    }

    // Close file
    fclose(file);
}

// Example program
int main() {
    // Phone book file name
    char file_name[] = "phone_book.txt";

    // Read phone book entries from file
    phone_entry* entries = read_phone_book(file_name);

    // Print phone book entries
    if (entries != NULL) {
        printf("Phone Book Entries:\n");
        int i = 0;
        while (entries[i].name != NULL) {
            printf("%d. %s %s\n", i + 1, entries[i].name, entries[i].number);
            i++;
        }
    } else {
        printf("Error: No entries found in file %s\n", file_name);
    }

    // Write phone book entries to file
    write_phone_book(file_name, entries);

    return 0;
}