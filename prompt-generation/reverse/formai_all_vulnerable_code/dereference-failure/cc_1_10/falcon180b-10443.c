//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to swap two integers without using a temporary variable
void swap(int* a, int* b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

// Function to reverse a string using bitwise operations
void reverse(char* str, int length) {
    char* start = str;
    char* end = str + length - 1;

    while (start < end) {
        swap(start, end);
        start++;
        end--;
    }
}

// Function to print a string in reverse order using bitwise operations
void print_reverse(char* str) {
    int length = strlen(str);
    reverse(str, length);
    printf("%s\n", str);
}

// Function to generate a random string of specified length
char* generate_random_string(int length) {
    char* str = (char*) malloc(length + 1);
    if (str == NULL) {
        fprintf(stderr, "Failed to allocate memory for random string.\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[length] = '\0';

    return str;
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <string_length>\n", argv[0]);
        return 1;
    }

    int length = atoi(argv[1]);
    if (length <= 0 || length > MAX_LINE_LENGTH) {
        fprintf(stderr, "Invalid string length.\n");
        return 1;
    }

    char* string = generate_random_string(length);
    print_reverse(string);

    free(string);
    return 0;
}