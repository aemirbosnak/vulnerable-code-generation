//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to check if a string is palindrome or not
int is_palindrome(char* str) {
    // Convert the string to lowercase to ignore case sensitivity
    char *str_lower = str;
    for(int i = 0; i < strlen(str_lower); i++) {
        str_lower[i] = tolower(str_lower[i]);
    }

    // Check if the string is palindrome or not
    int length = strlen(str_lower);
    for(int i = 0; i < length / 2; i++) {
        if(str_lower[i]!= str_lower[length - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

// Function to count number of palindromes in a string
int count_palindromes(char* str) {
    // Convert the string to lowercase to ignore case sensitivity
    char *str_lower = str;
    for(int i = 0; i < strlen(str_lower); i++) {
        str_lower[i] = tolower(str_lower[i]);
    }

    int count = 0;
    int length = strlen(str_lower);
    for(int i = 0; i < length; i++) {
        // Check if the substring is palindrome or not
        if(is_palindrome(str_lower + i)) {
            count++;
        }
    }
    return count;
}

int main() {
    char str[MAX_LENGTH];

    printf("Enter a string: ");
    scanf("%s", str);

    // Call the function to count number of palindromes
    int count = count_palindromes(str);

    printf("Number of palindromes in the string: %d\n", count);

    return 0;
}