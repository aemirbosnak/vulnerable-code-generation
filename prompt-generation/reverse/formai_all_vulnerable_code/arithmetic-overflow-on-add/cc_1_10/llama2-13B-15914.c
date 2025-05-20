//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRLEN 1024

// Function to reverse a string
void reverse_string(char *str) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to find the first duplicate in a string
int find_first_duplicate(char *str) {
    int i, j;
    char current, next;

    for (i = 0, j = 1; i < strlen(str); i++, j++) {
        current = str[i];
        next = str[j];
        if (current == next) {
            return i;
        }
    }
    return -1;
}

// Function to replace all duplicates in a string with a single copy
void replace_duplicates(char *str) {
    int i, j, k;
    char current, next;

    for (i = 0, j = 1; i < strlen(str); i++, j++) {
        current = str[i];
        next = str[j];
        if (current == next) {
            str[k] = current;
            k++;
        } else {
            str[k] = current;
            k++;
        }
    }
}

int main() {
    char str[] = "hello world hello world";

    // Reverse the string
    reverse_string(str);
    printf("Reversed string: %s\n", str);

    // Find the first duplicate in the string
    int index = find_first_duplicate(str);
    if (index != -1) {
        printf("First duplicate found at index %d\n", index);
    } else {
        printf("No duplicates found\n");
    }

    // Replace all duplicates with a single copy
    replace_duplicates(str);
    printf("String after replacing duplicates: %s\n", str);

    return 0;
}