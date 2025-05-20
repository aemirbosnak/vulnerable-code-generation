//FormAI DATASET v1.0 Category: Modern Encryption ; Style: careful
#include <stdio.h>
#include <string.h>

int main() {
    char message[100], key[100];
    int i, j, msg_len, key_len, choice;

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    msg_len = strlen(message);
    message[msg_len-1] = '\0';

    printf("Enter encryption key: ");
    fgets(key, sizeof(key), stdin);
    key_len = strlen(key);
    key[key_len-1] = '\0';

    printf("Choose encryption method:\n");
    printf("1. Caesar Cipher\n");
    printf("2. Vigenere Cipher\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            // Caesar Cipher
            for(i = 0; i < msg_len; i++) {
                if(message[i] >= 'a' && message[i] <= 'z') {
                    message[i] = (((message[i] - 'a') + (key[0] - 'a')) % 26) + 'a';
                } else if(message[i] >= 'A' && message[i] <= 'Z') {
                    message[i] = (((message[i] - 'A') + (key[0] - 'A')) % 26) + 'A';
                }
            }
            printf("Encrypted message: %s\n", message);
            break;
        case 2:
            // Vigenere Cipher
            for(i = 0, j = 0; i < msg_len; i++, j++) {
                if(j == key_len) {
                    j = 0;
                }
                if(message[i] >= 'a' && message[i] <= 'z') {
                    message[i] = (((message[i] - 'a') + (key[j] - 'a')) % 26) + 'a';
                } else if(message[i] >= 'A' && message[i] <= 'Z') {
                    message[i] = (((message[i] - 'A') + (key[j] - 'A')) % 26) + 'A';
                }
            }
            printf("Encrypted message: %s\n", message);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}