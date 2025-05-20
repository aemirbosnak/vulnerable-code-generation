//FormAI DATASET v1.0 Category: modern Encryption ; Style: creative
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* Function to encrypt the input string */
char* encrypt(char* input, int key) {

    int length = strlen(input);
    char* result = (char*) malloc(length + 1);

    // Iterate through all characters of the string
    for(int i = 0; i < length; i++) {

        // Add the key to the ASCII value of each character
        result[i] = input[i] + key;

        // If the resulting value is greater than 'z', wrap around to 'a'
        if(result[i] > 'z') {
            result[i] = result[i] - 26;
        }
    }

    // Add null character at the end of the result
    result[length] = '\0';

    return result;
}

int main() {

    char input[100];
    int key;

    // Get input string and key from user
    printf("Enter a string: ");
    scanf("%s", input);

    printf("Enter a key (integer): ");
    scanf("%d", &key);

    // Encrypt the input string using the key
    char* result = encrypt(input, key);

    // Display the encrypted string
    printf("Encrypted string: %s\n", result);

    // Free the memory allocated for the result string
    free(result);

    return 0;
}