//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Radium-powered phone book to survive the wasteland

// Define the telephone directory
struct phonebook {
    char name[256];
    char number[128];
};

// Create an array of phonebook entries
struct phonebook entries[] = {
    {"Scavenger Joe", "555-1212"},
    {"Raider Rick", "555-1313"},
    {"Doc", "555-1414"},
    {"Trader Tom", "555-1515"},
    {"Mechanic Mary", "555-1616"},
    {"Wasteland Wanderer", "555-1717"},
    {"Gunsmith Gus", "555-1818"},
    {"Scientist Sarah", "555-1919"},
    {"Engineer Emily", "555-2020"},
    {"Survivor Sam", "555-2121"}
};

// Define the number of entries in the phone book
#define NUM_ENTRIES (sizeof(entries) / sizeof(entries[0]))

// Function to search the phone book for a name
int search_phonebook(char *name) {
    // Iterate over the entries in the phone book
    for (int i = 0; i < NUM_ENTRIES; i++) {
        // Compare the name to the name in the current entry
        if (strcmp(name, entries[i].name) == 0) {
            // If the names match, return the index of the entry
            return i;
        }
    }

    // If the name was not found, return -1
    return -1;
}

// Function to print the phone book
void print_phonebook() {
    // Iterate over the entries in the phone book
    for (int i = 0; i < NUM_ENTRIES; i++) {
        // Print the name and number of the current entry
        printf("%s: %s\n", entries[i].name, entries[i].number);
    }
}

// Main function
int main() {
    // Get the name to search for from the user
    char name[256];
    printf("Enter the name to search for: ");
    scanf("%s", name);

    // Search for the name in the phone book
    int index = search_phonebook(name);

    // If the name was found, print the number
    if (index != -1) {
        printf("The number for %s is %s\n", name, entries[index].number);
    } else {
        // If the name was not found, print an error message
        printf("The name %s was not found in the phone book\n", name);
    }

    // Print the entire phone book
    printf("\nEntire phone book:\n");
    print_phonebook();

    return 0;
}