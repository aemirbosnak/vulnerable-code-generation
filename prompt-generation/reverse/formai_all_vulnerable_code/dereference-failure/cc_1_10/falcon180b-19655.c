//Falcon-180B DATASET v1.0 Category: Memory management ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 10
#define NUM_STRINGS 5

// Struct to hold data for each string
typedef struct {
    char* data;
    int length;
} StringData;

// Function to initialize a string with a given value
void initString(StringData* str, char value) {
    str->data = (char*)malloc(LENGTH*sizeof(char));
    str->length = 0;

    // Fill the string with the given value
    for (int i = 0; i < LENGTH; i++) {
        str->data[i] = value;
        str->length++;
    }

    // Add a null terminator
    str->data[LENGTH-1] = '\0';
}

// Function to print a string
void printString(StringData* str) {
    printf("String: %s\n", str->data);
}

// Main function
int main() {
    // Initialize an array of strings
    StringData strings[NUM_STRINGS];

    // Initialize each string with a different value
    for (int i = 0; i < NUM_STRINGS; i++) {
        initString(&strings[i], 'A' + i);
    }

    // Print each string
    for (int i = 0; i < NUM_STRINGS; i++) {
        printString(&strings[i]);
    }

    // Free memory for each string
    for (int i = 0; i < NUM_STRINGS; i++) {
        free(strings[i].data);
    }

    return 0;
}