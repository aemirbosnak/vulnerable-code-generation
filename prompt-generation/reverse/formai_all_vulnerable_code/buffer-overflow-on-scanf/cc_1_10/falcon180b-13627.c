//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of specified length
char* generateRandomString(int length) {
    char* result = (char*)malloc(length+1);
    if (result == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        result[i] = rand() % 26 + 'a';
    }
    result[length] = '\0';
    return result;
}

// Function to reverse a string
void reverseString(char* str) {
    int len = strlen(str);
    char* reversed = (char*)malloc(len+1);
    if (reversed == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    for (int i = 0; i < len; i++) {
        reversed[i] = str[len-1-i];
    }
    reversed[len] = '\0';
    printf("Reversed string: %s\n", reversed);
    free(reversed);
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        if (str[i]!= str[len-1-i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int length;
    printf("Enter the length of the string: ");
    scanf("%d", &length);
    char* str = generateRandomString(length);
    printf("Random string: %s\n", str);
    reverseString(str);
    if (isPalindrome(str)) {
        printf("The string is a palindrome\n");
    } else {
        printf("The string is not a palindrome\n");
    }
    free(str);
    return 0;
}