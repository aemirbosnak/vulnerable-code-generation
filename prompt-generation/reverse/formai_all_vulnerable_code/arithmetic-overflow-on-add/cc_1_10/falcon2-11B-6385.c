//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a string using a simple substitution algorithm
void compress(char *str, int *len) {
    int i, j, k, count = 1;
    char ch1, ch2;

    // Initialize variables
    i = 0;
    j = 0;
    k = 0;

    // Iterate over the string and compress it
    while (i < *len) {
        // If the current character is the same as the next character,
        // replace the next character with the current character
        if (str[i] == str[i+1]) {
            count++;
            j++;
        } else {
            // Otherwise, store the current character and its count,
            // and replace the next character with the current character
            str[k++] = str[j];
            str[k++] = (count > 1)? (char) ('0' + count) : (char) ('0');
            count = 1;
            j++;
        }
        i++;
    }

    // Update the length of the compressed string
    *len = k;
}

// Function to decompress a string using the same substitution algorithm
void decompress(char *str, int len) {
    int i, j, count, ch;

    // Iterate over the compressed string and decompress it
    for (i = 0; i < len; i += 2) {
        // If the current character is a digit, read it as a number
        if (str[i] >= '0' && str[i] <= '9') {
            count = str[i] - '0';
        } else {
            // Otherwise, use the current character as the count
            count = 1;
        }

        // If the current character is a character, store it in the output string
        if (str[i+1] >= '0' && str[i+1] <= '9') {
            ch = str[i+1] - '0';
        } else {
            // Otherwise, use the current character as the character
            ch = str[i+1];
        }

        // Replace the current character in the output string with the decomposed character
        str[j++] = ch;
        count--;

        // Repeat the process until the count reaches 0
        while (count > 0) {
            str[j++] = str[i];
            count--;
            i++;
        }
    }
}

// Main function
int main() {
    char str[100];
    int len;

    // Get a string from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Get the length of the string
    len = strlen(str);

    // Compress the string
    compress(str, &len);

    // Print the compressed string
    printf("Compressed string: ");
    for (int i = 0; i < len; i++) {
        printf("%c", str[i]);
    }
    printf("\n");

    // Decompress the string
    decompress(str, len);

    // Print the decompressed string
    printf("Decompressed string: ");
    for (int i = 0; i < len; i++) {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}