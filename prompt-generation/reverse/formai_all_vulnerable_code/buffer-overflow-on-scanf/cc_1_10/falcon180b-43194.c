//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define MAX_KEY_LENGTH 100

// Function to compare two strings
int compare_strings(char* str1, char* str2) {
    int length = strlen(str1);
    int i = 0;
    while (i < length) {
        if (str1[i]!= str2[i]) {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to search for a key in a string
int search_string(char* string, char* key) {
    int length = strlen(string);
    int key_length = strlen(key);
    int i = 0;
    while (i < length - key_length + 1) {
        if (compare_strings(string + i, key)) {
            return 1;
        }
        i++;
    }
    return 0;
}

// Function to find all occurrences of a key in a string
void find_all_occurrences(char* string, char* key) {
    int length = strlen(string);
    int key_length = strlen(key);
    int i = 0;
    while (i < length - key_length + 1) {
        if (compare_strings(string + i, key)) {
            printf("Found key at position %d\n", i);
        }
        i++;
    }
}

int main() {
    char string[MAX_STRING_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter a string: ");
    scanf("%s", string);

    printf("Enter a key to search for: ");
    scanf("%s", key);

    if (search_string(string, key)) {
        printf("Key found in string\n");
    } else {
        printf("Key not found in string\n");
    }

    find_all_occurrences(string, key);

    return 0;
}