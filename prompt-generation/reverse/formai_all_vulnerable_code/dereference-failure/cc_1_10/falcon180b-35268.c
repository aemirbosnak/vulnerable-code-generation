//Falcon-180B DATASET v1.0 Category: Memory management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define INITIAL_SIZE 10

typedef struct {
    char *data;
    int size;
    int capacity;
} String;

// Function to create a new empty string
String *create_string() {
    String *string = (String *) malloc(sizeof(String));
    if (string == NULL) {
        printf("Error: Memory could not be allocated\n");
        exit(1);
    }
    string->data = (char *) malloc(INITIAL_SIZE * sizeof(char));
    if (string->data == NULL) {
        printf("Error: Memory could not be allocated\n");
        exit(1);
    }
    string->size = 0;
    string->capacity = INITIAL_SIZE;
    return string;
}

// Function to append a character to a string
void append_character(String *string, char c) {
    if (string->size == string->capacity) {
        string->capacity += INITIAL_SIZE;
        string->data = (char *) realloc(string->data, string->capacity * sizeof(char));
        if (string->data == NULL) {
            printf("Error: Memory could not be reallocated\n");
            exit(1);
        }
    }
    string->data[string->size] = c;
    string->size++;
}

// Function to append a string to another string
void append_string(String *string1, String *string2) {
    int i = 0;
    while (i < string2->size) {
        append_character(string1, string2->data[i]);
        i++;
    }
}

// Function to free the memory allocated to a string
void free_string(String *string) {
    free(string->data);
    free(string);
}

// Function to concatenate two strings
String *concatenate_strings(String *string1, String *string2) {
    String *result = create_string();
    int i = 0;
    while (i < string1->size) {
        append_character(result, string1->data[i]);
        i++;
    }
    while (i < string2->size) {
        append_character(result, string2->data[i]);
        i++;
    }
    free_string(string1);
    free_string(string2);
    return result;
}

int main() {
    String *string1 = create_string();
    String *string2 = create_string();
    String *string3 = concatenate_strings(string1, string2);
    printf("String 1: %s\n", string1->data);
    printf("String 2: %s\n", string2->data);
    printf("Concatenated string: %s\n", string3->data);
    free_string(string3);
    return 0;
}