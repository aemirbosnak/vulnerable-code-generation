//Falcon-180B DATASET v1.0 Category: Encryption ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main() {
    char input[1000];
    char key[100];
    char encrypted[1000];
    char decrypted[1000];

    // Get input from user
    printf("Enter input to be encrypted: ");
    fgets(input, 1000, stdin);

    // Remove new line character from input
    int len = strlen(input);
    input[len-1] = '\0';

    // Get encryption key from user
    printf("Enter encryption key: ");
    fgets(key, 100, stdin);

    // Remove new line character from key
    len = strlen(key);
    key[len-1] = '\0';

    // Encrypt input using key
    strcpy(encrypted, "");
    int i, j;
    for (i = 0; i < strlen(input); i++) {
        char c = toupper(input[i]);
        char k = toupper(key[i % strlen(key)]);
        int sum = (int)c + (int)k - 65;
        if (sum > 25) {
            sum -= 26;
        }
        char e = sum + 65;
        strcat(encrypted, &e);
    }

    // Decrypt encrypted message using key
    strcpy(decrypted, "");
    for (i = 0; i < strlen(encrypted); i++) {
        char c = toupper(encrypted[i]);
        char k = toupper(key[i % strlen(key)]);
        int sum = (int)c - (int)k - 65;
        if (sum < 0) {
            sum += 26;
        }
        char e = sum + 65;
        strcat(decrypted, &e);
    }

    // Print encrypted and decrypted messages
    printf("Encrypted message: %s\n", encrypted);
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}