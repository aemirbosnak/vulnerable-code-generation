//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

int main() {
    // Initialize variables
    char str[MAX_STR_LEN];
    int len, i, j, count;

    // Get the input string from the user
    printf("Enter a string: ");
    fgets(str, MAX_STR_LEN, stdin);

    // Calculate the length of the string
    len = strlen(str);

    // Remove all spaces from the string
    for (i = 0; i < len; i++) {
        if (str[i] == ' ') {
            for (j = i; j < len; j++) {
                str[j] = str[j + 1];
            }
            len--;
            i--;
        }
    }

    // Convert the string to lowercase
    for (i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }

    // Count the occurrences of each character in the string
    int char_count[26] = {0};
    for (i = 0; i < len; i++) {
        char_count[str[i] - 'a']++;
    }

    // Find the most frequently occurring character
    int max_count = 0;
    char most_freq_char;
    for (i = 0; i < 26; i++) {
        if (char_count[i] > max_count) {
            max_count = char_count[i];
            most_freq_char = 'a' + i;
        }
    }

    // Print the results
    printf("The original string is: %s\n", str);
    printf("The length of the string is: %d\n", len);
    printf("The most frequently occurring character is: %c\n", most_freq_char);
    printf("The number of occurrences of the most frequently occurring character is: %d\n", max_count);

    return 0;
}