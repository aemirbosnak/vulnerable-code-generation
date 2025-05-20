//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

void shift_left(unsigned char *data, int key) {
    int i;
    for (i = 0; data[i] != '\0'; i++) {
        if (isalpha(data[i])) {
            data[i] = (char)(((isupper(data[i]) ? 'A' : 'a') + key - 'A') % 26 + 'A');
        }
    }
}

void shift_right(unsigned char *data, int key) {
    int i;
    for (i = 0; data[i] != '\0'; i++) {
        if (isalpha(data[i])) {
            data[i] = (char)(((isupper(data[i]) ? 'A' : 'a') + 26 - key) % 26 + 'A');
        }
    }
}

int main() {
    char input[SIZE], encrypted[SIZE], decrypted[SIZE];
    int key, choice;

    printf("Welcome to the Caesar Cipher Encryption Program!\n");
    printf("Please enter a message (up to 100 characters): ");
    fgets(input, SIZE, stdin);
    input[strcspn(input, "\n")] = '\0';

    printf("Please enter the shift value (1-25): ");
    scanf("%d", &key);

    strcpy(encrypted, input);
    shift_left(encrypted, key);

    printf("Encrypted message: %s\n", encrypted);

    shift_right(decrypted, key);

    printf("Decrypted message: %s\n", decrypted);

    printf("Do you want to encrypt another message? (1 for Yes, 0 for No): ");
    scanf("%d", &choice);

    if (choice == 1) {
        system("clear");
        main();
    }

    return 0;
}