//FormAI DATASET v1.0 Category: Modern Encryption ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void encryption(char *message, int key) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] + key - 'a') % 26 + 'a';
        }
        else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] + key - 'A') % 26 + 'A';
        }
    }
}

void decryption(char *message, int key) {
    int i, j, k, n=0;
    char sub[26], rand_sub[26];
    srand(time(0));
    for (i = 0; i < 26; i++) {
        sub[i] = i + 'a';
        rand_sub[i] = i + 'a';
    }
    for (i = 0; i < 26; i++) {
        j = rand() % 26;
        char temp = rand_sub[i];
        rand_sub[i] = rand_sub[j];
        rand_sub[j] = temp;
    }
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            for (j = 0; j < 26; j++) {
                if (sub[j] == message[i]) {
                    message[i] = rand_sub[j];
                    break;
                }
            }
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            for (j = 0; j < 26; j++) {
                if (sub[j] == message[i] + 32) {
                    message[i] = rand_sub[j] - 32;
                    break;
                }
            }
        }
    }
}

int main() {
    char message[100], choice;
    int key;
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter an integer key: ");
    scanf("%d", &key);
    printf("Would you like to encrypt or decrypt the message? (e/d) ");
    scanf(" %c", &choice);
    switch (choice) {
        case 'e':
            encryption(message, key);
            printf("Encrypted message: %s\n", message);
            break;
        case 'd':
            decryption(message, key);
            printf("Decrypted message: %s\n", message);
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}