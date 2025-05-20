//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_LENGTH 64

void hash(char *input, char *output) {
    char hash_string[HASH_LENGTH + 1] = {0};
    int i, j, k;
    unsigned long long int sum = 0;

    // Initialize the hash string with random characters
    for (i = 0; i < HASH_LENGTH; i++) {
        hash_string[i] = rand() % 26 + 'a';
    }

    // Convert the input string to lowercase
    for (i = 0; input[i]!= '\0'; i++) {
        input[i] = tolower(input[i]);
    }

    // Calculate the hash value
    for (i = 0, j = 0; input[i]!= '\0'; i++, j++) {
        if (j == HASH_LENGTH) {
            j = 0;
            sum += hash_string[i];
        } else {
            sum += (unsigned long long int)input[i] * hash_string[j];
            hash_string[j] = input[i];
        }
    }

    // Convert the hash value to a string
    for (i = 0; i < HASH_LENGTH; i++) {
        sprintf(&output[i * 2], "%02x", (unsigned int)(sum >> (8 * (HASH_LENGTH - i - 1))) & 0xff);
    }
}

int main() {
    char input[100], output[HASH_LENGTH * 2 + 1];

    printf("Enter a string to hash: ");
    scanf("%s", input);

    hash(input, output);

    printf("Hashed string: %s\n", output);

    return 0;
}