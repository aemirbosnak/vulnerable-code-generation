//Falcon-180B DATASET v1.0 Category: Recursive ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STR_LEN 50

typedef struct {
    char str[MAX_STR_LEN];
    int len;
} string_t;

// Function to generate a random string of given length
void generate_random_string(string_t *str, int len) {
    const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        str->str[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    str->len = len;
}

// Function to reverse a string
void reverse_string(string_t *str) {
    int start = 0;
    int end = str->len - 1;
    char temp;

    while (start < end) {
        temp = str->str[start];
        str->str[start] = str->str[end];
        str->str[end] = temp;
        start++;
        end--;
    }
}

// Recursive function to generate all possible permutations of a string
void generate_permutations(string_t *str, int start, int end) {
    if (start == end) {
        printf("%s\n", str->str);
        return;
    }

    for (int i = start; i <= end; i++) {
        strcpy(str->str + start, str->str + i);
        generate_permutations(str, start + 1, end);
    }
}

// Main function
int main() {
    string_t str;
    int len;

    // Get user input for string length
    printf("Enter the length of the string: ");
    scanf("%d", &len);

    // Generate a random string of given length
    generate_random_string(&str, len);

    // Reverse the string
    reverse_string(&str);

    // Print the original string and its reverse
    printf("Original string: %s\n", str.str);
    printf("Reverse string: %s\n", str.str);

    // Generate all possible permutations of the string
    printf("Generating all possible permutations...\n");
    generate_permutations(&str, 0, len - 1);

    return 0;
}