//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 100

// Function to reverse a string
void reverse_str(char *str) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to find the longest common substring between two strings
void find_lcs(char *str1, char *str2) {
    int i, j, k;
    char temp[100];

    // Initialize the length of the longest common substring as 0
    int lcs_len = 0;

    // Loop through the characters of the first string
    for (i = 0; str1[i] != '\0'; i++) {
        // Check if the character is present in the second string
        for (j = 0; str2[j] != '\0'; j++) {
            if (str1[i] == str2[j]) {
                // If the character is present, increment the length of the
                // longest common substring and store the current index
                // of the second string in a temporary array
                lcs_len++;
                temp[lcs_len - 1] = str2[j];
            }
        }
    }

    // Print the longest common substring
    printf("Longest common substring: %s\n", temp);
}

int main() {
    char str1[MAX_STR_LEN] = "Gratitude is the heart of all virtue.";
    char str2[MAX_STR_LEN] = "Attitude is the heart of all success.";

    // Reverse the first string
    reverse_str(str1);

    // Find the longest common substring between the two strings
    find_lcs(str1, str2);

    return 0;
}