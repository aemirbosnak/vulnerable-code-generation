//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512

void print_banner() {
    printf("======================================\n");
    printf("=      RETRO CRYPTOGRAPHY PROGRAM    =\n");
    printf("======================================\n");
}

void cleanup(char* buffer_A, char* buffer_B) {
    memset(buffer_A, 0, BUFFER_SIZE);
    memset(buffer_B, 0, BUFFER_SIZE);
}

void encryption(char* message, char* key) {
    char c;
    int i, j = 0;
    int message_len = strlen(message);
    int key_len = strlen(key);

    for(i = 0; i < message_len; ++i) {
        c = message[i] ^ key[j];
        printf("%02X ", c);
        j = (j + 1) % key_len;
    }
}

void decryption(char* message, char* key) {
    unsigned char c;
    int i, j = 0;
    int message_len = strlen(message);
    int key_len = strlen(key);

    for(i = 0; i < message_len; ++i) {
        sscanf(message + i*2, "%02X", &c);
        printf("%c", c ^ key[j]);
        j = (j + 1) % key_len;
    }
}

int main(int argc, char** argv) {
    char buffer_A[BUFFER_SIZE];
    char buffer_B[BUFFER_SIZE];
    char message[BUFFER_SIZE];
    char key[BUFFER_SIZE];
    int option;

    print_banner();
    while(1) {
        printf("\nPlease choose an option:\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Exit\n");
        printf("\nOption: ");
        scanf("%d", &option);
        getchar();

        switch(option) {
            case 1:
                printf("\nEnter the message: ");
                fgets(message, BUFFER_SIZE, stdin);
                printf("Enter the key: ");
                fgets(key, BUFFER_SIZE, stdin);
                printf("Encrypted message: ");
                encryption(message, key);
                cleanup(buffer_A, buffer_B);
                break;
            case 2:
                printf("\nEnter the message in hex format: ");
                fgets(buffer_A, BUFFER_SIZE, stdin);
                printf("Enter the key: ");
                fgets(key, BUFFER_SIZE, stdin);
                printf("Decrypted message: ");
                decryption(buffer_A, key);
                cleanup(buffer_A, buffer_B);
                break;
            case 3:
                printf("\nThank you for using the Retro Cryptography Program!\n");
                exit(0);
            default: 
                printf("Invalid option! Try again...\n");
                break;
        }
    }

    return 0;
}