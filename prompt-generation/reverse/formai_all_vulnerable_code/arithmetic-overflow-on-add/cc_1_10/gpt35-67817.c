//FormAI DATASET v1.0 Category: modern Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

void encrypt(char *msg, int key) {
    char c;
    int i;
    for (i = 0; msg[i] != '\0'; ++i) {
        c = msg[i];
        if (isalpha(c)) {
            if (islower(c))
                c = toupper(c);
            c -= 'A';
            c = (c + key) % 26;
            c += 'A';
            if (islower(msg[i]))
                msg[i] = tolower(c);
            else
                msg[i] = c;
        }
    }
}

void decrypt(char *msg, int key) {
    char c;
    int i;
    for (i = 0; msg[i] != '\0'; ++i) {
        c = msg[i];
        if (isalpha(c)) {
            if (islower(c))
                c = toupper(c);
            c -= 'A';
            c = (c - key + 26) % 26;
            c += 'A';
            if (islower(msg[i]))
                msg[i] = tolower(c);
            else
                msg[i] = c;
        }
    }
}

int main() {
    char msg[MAX_SIZE];
    int choice, key;

    printf("Enter message to encrypt: ");
    fgets(msg, MAX_SIZE, stdin);

    do {
        printf("Select an option:\n");
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                encrypt(msg, key);
                printf("Encrypted message: %s\n", msg);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                decrypt(msg, key);
                printf("Decrypted message: %s\n", msg);
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}