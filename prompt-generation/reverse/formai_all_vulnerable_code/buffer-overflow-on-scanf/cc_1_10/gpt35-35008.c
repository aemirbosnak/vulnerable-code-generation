//FormAI DATASET v1.0 Category: Modern Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *str) {
    if (*str != '\0') {
        *str = *str + 1;
        encrypt(str + 1);
    }
}

void decrypt(char *str) {
    if (*str != '\0') {
        *str = *str - 1;
        decrypt(str + 1);
    }
}

int main() {
    int choice = 0, len = 0;
    char str[100];

    do {
        printf("Enter a string: ");
        fgets(str, 100, stdin);
        len = strlen(str);

        printf("Menu:\n");
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                encrypt(str);
                printf("Encrypted string: %s\n", str);
                break;
            case 2:
                decrypt(str);
                printf("Decrypted string: %s\n", str);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        fflush(stdin); //Flush stdin buffer
    } while (1);

    return 0;
}