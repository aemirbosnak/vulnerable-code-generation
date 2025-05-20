//FormAI DATASET v1.0 Category: File Encyptor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, int key1, int key2) {
    int len = strlen(message);
    for(int i = 0; i < len; i++) {
        message[i] = ((message[i] * key1) + key2) % 128;
    }
}

void decrypt(char *message, int key1, int key2) {
    int len = strlen(message);
    for(int i = 0; i < len; i++) {
        message[i] = (((message[i] - key2) * modular_inverse(key1, 128)) % 128);
    }
}

int modular_inverse(int a, int m) {
    a %= m;
    for(int i = 1; i < m; i++) {
        if((a * i) % m == 1) return i;
    }
    return -1;
}

int main() {
    char message[100];
    int key1, key2, choice;

    printf("-----------------------------\n");
    printf("   C File Encryptor Example  \n");
    printf("-----------------------------\n\n");

    do {
        printf("1. Encrypt a file\n");
        printf("2. Decrypt a file\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the message to be encrypted: ");
                scanf(" %[^\n]s", message);
                printf("Enter the first key: ");
                scanf("%d", &key1);
                printf("Enter the second key: ");
                scanf("%d", &key2);
                encrypt(message, key1, key2);
                printf("\nThe encrypted message is: %s\n\n", message);
                break;
            case 2:
                printf("\nEnter the message to be decrypted: ");
                scanf(" %[^\n]s", message);
                printf("Enter the first key: ");
                scanf("%d", &key1);
                printf("Enter the second key: ");
                scanf("%d", &key2);
                decrypt(message, key1, key2);
                printf("\nThe decrypted message is: %s\n\n", message);
                break;
            case 3:
                printf("\nExiting program!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter again.\n\n");
        }
    } while(choice != 3);

    return 0;
}