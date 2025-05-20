//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 100
#define MAX_CHARS 26

void generate_pattern(char* pattern, int size) {
    // Initialize the pattern with the first character
    strcpy(pattern, "A");

    // Generate the rest of the pattern
    int count = 1;
    for (int i = 1; i < size; i++) {
        if (count == MAX_CHARS) {
            count = 1;
        }
        char next_char = 'A' + count;
        strcat(pattern, &next_char);
        count++;
    }
}

void print_pattern(char* pattern) {
    int length = strlen(pattern);
    for (int i = 0; i < length; i++) {
        printf("%c", pattern[i]);
    }
}

int main() {
    int size;
    printf("Enter the size of the pattern: ");
    scanf("%d", &size);

    // Check if the size is valid
    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid size.\n");
        return 1;
    }

    // Generate the pattern
    char pattern[MAX_SIZE];
    generate_pattern(pattern, size);

    // Print the pattern
    printf("\nPattern:\n");
    print_pattern(pattern);

    return 0;
}