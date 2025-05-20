//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *data;
    size_t size;
} string_t;

// Allocate a new string with the given size, and initialize it with zeros
string_t *string_new(size_t size) {
    string_t *str = malloc(sizeof(string_t));
    str->data = malloc(size);
    str->size = size;
    memset(str->data, 0, size);
    return str;
}

// Copy the contents of the source string to the destination string
void string_copy(string_t *dest, const string_t *src) {
    dest->size = src->size;
    dest->data = malloc(dest->size);
    memcpy(dest->data, src->data, dest->size);
}

// Append the contents of the source string to the destination string
void string_append(string_t *dest, const string_t *src) {
    dest->size += src->size;
    dest->data = realloc(dest->data, dest->size);
    memcpy(dest->data + dest->size - src->size, src->data, src->size);
}

// Free the memory allocated for the string
void string_free(string_t *str) {
    free(str->data);
    free(str);
}

// Main function
int main() {
    srand(time(NULL));

    // Allocate two strings with random sizes
    string_t *str1 = string_new(rand() % 100);
    string_t *str2 = string_new(rand() % 100);

    // Initialize the strings with random data
    for (int i = 0; i < str1->size; i++) {
        str1->data[i] = rand() % 26 + 'a';
    }
    for (int i = 0; i < str2->size; i++) {
        str2->data[i] = rand() % 26 + 'a';
    }

    // Copy the contents of str1 to str2
    string_copy(str2, str1);

    // Append the contents of str1 to str2
    string_append(str2, str1);

    // Print the contents of str2
    printf("str2: %s\n", str2->data);

    // Free the memory allocated for the strings
    string_free(str1);
    string_free(str2);

    return 0;
}