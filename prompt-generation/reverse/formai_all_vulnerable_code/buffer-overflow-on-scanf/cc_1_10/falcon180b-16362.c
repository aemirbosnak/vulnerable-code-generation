//Falcon-180B DATASET v1.0 Category: Recursive ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

// Function to check if a string is a palindrome
bool is_palindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i]!= str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

// Function to print a string in reverse order
void reverse_string(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to generate a random string of given length
char* generate_random_string(int length) {
    char* str = (char*)malloc(length + 1);
    for (int i = 0; i < length; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[length] = '\0';
    return str;
}

// Function to recursively generate palindromic strings
void generate_palindromes(char* str, int length) {
    if (length == 0) {
        printf("%s\n", str);
        return;
    }
    char* random_str = generate_random_string(length);
    if (is_palindrome(random_str)) {
        printf("%s\n", random_str);
    }
    for (int i = 0; i < length; i++) {
        str[i] = tolower(random_str[i]);
    }
    generate_palindromes(str, length - 1);
}

int main() {
    int length;
    printf("Enter the length of the palindromic string: ");
    scanf("%d", &length);
    char* str = (char*)malloc(length + 1);
    for (int i = 0; i < length; i++) {
        str[i] = 'a';
    }
    str[length] = '\0';
    printf("Palindromic strings of length %d:\n", length);
    generate_palindromes(str, length);
    return 0;
}