//Falcon-180B DATASET v1.0 Category: Educational ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

// Function to check if a string is a palindrome
int is_palindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        if (tolower(str[i])!= tolower(str[len-i-1])) {
            return 0;
        }
    }
    return 1;
}

// Function to generate a random string of a given length
char* generate_random_string(int length) {
    char* str = malloc(length+1);
    for (int i = 0; i < length; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[length] = '\0';
    return str;
}

// Function to print a string in reverse
void reverse_string(char* str) {
    int len = strlen(str);
    for (int i = len-1; i >= 0; i--) {
        printf("%c", str[i]);
    }
}

int main() {
    srand(time(NULL));
    int length = 10;
    char* palindrome = generate_random_string(length);
    int is_pal = is_palindrome(palindrome);
    if (is_pal) {
        printf("Generated palindrome: %s\n", palindrome);
    } else {
        printf("Not a palindrome: %s\n", palindrome);
    }
    reverse_string(palindrome);
    printf("\n");
    return 0;
}