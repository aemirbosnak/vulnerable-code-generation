//Falcon-180B DATASET v1.0 Category: Encryption ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

// Function to encrypt the given string
void encrypt(char *str) {
    int len = strlen(str);
    char *new_str = malloc(len * 2 + 1);
    int j = 0;

    // Iterate through each character in the string
    for (int i = 0; i < len; i++) {
        // Convert uppercase characters to lowercase
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }

        // Add the character to the new string
        if (str[i] >= 'a' && str[i] <= 'z') {
            new_str[j++] = str[i];
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            new_str[j++] = str[i] - 32;
        } else {
            new_str[j++] = str[i];
        }
    }

    // Add a null terminator to the end of the new string
    new_str[j] = '\0';

    // Print the encrypted string
    printf("Encrypted string: %s\n", new_str);

    // Free the memory used by the new string
    free(new_str);
}

int main() {
    char str[MAX_LEN];

    // Get the input string from the user
    printf("Enter a string to encrypt: ");
    scanf("%s", str);

    // Encrypt the string
    encrypt(str);

    return 0;
}