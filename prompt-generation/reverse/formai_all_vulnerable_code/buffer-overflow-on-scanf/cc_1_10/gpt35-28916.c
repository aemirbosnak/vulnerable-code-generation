//FormAI DATASET v1.0 Category: Educational ; Style: minimalist
#include <stdio.h>

// Define the maximum size of the input string
#define MAX_SIZE 100

int main() {

    char input_string[MAX_SIZE];
    int i;

    // Get the input string from the user
    printf("Enter a string: ");
    scanf("%s", input_string);

    // Find the length of the input string
    int length = 0;
    for (i = 0; input_string[i] != '\0'; i++) {
        length++;
    }

    // Print the length of the input string
    printf("Length of the string: %d\n", length);

    // Find the frequency of each character in the string
    int frequency[26] = {0};
    for (i = 0; i < length; i++) {
        frequency[input_string[i] - 'a']++;
    }

    // Print the frequency of each character
    printf("Frequency of each character:\n");
    for (i = 0; i < 26; i++) {
        if (frequency[i] != 0) {
            printf("%c: %d\n", 'a' + i, frequency[i]);
        }
    }

    // Check if the input string is a palindrome
    int is_palindrome = 1;
    for (i = 0; i < length / 2; i++) {
        if (input_string[i] != input_string[length - i - 1]) {
            is_palindrome = 0;
            break;
        }
    }

    // Print whether the input string is a palindrome or not
    printf("Is the string a palindrome? %s\n", is_palindrome ? "Yes" : "No");

    return 0;
}