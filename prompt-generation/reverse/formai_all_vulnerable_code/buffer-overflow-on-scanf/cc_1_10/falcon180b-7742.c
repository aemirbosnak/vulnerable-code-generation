//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_menu() {
    printf("\n");
    printf("=== Post-Apocalyptic Cryptography ===\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("3. Exit\n");
    printf("\n");
}

int main() {
    char choice;
    int len, i, key, j;
    char plaintext[1000], ciphertext[1000], decrypted_text[1000];

    do {
        print_menu();
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter plaintext: ");
                scanf("%s", plaintext);
                printf("Enter key (0-25): ");
                scanf("%d", &key);
                len = strlen(plaintext);

                for(i=0; i<len; i++) {
                    if(isalpha(plaintext[i])) {
                        if(isupper(plaintext[i])) {
                            ciphertext[i] = (char)((int)plaintext[i] + key - 65);
                        }
                        else {
                            ciphertext[i] = (char)((int)plaintext[i] + key - 97);
                        }
                    }
                    else {
                        ciphertext[i] = plaintext[i];
                    }
                }

                printf("Ciphertext: %s\n", ciphertext);
                break;

            case '2':
                printf("Enter ciphertext: ");
                scanf("%s", ciphertext);
                printf("Enter key (0-25): ");
                scanf("%d", &key);
                len = strlen(ciphertext);

                for(i=0; i<len; i++) {
                    if(isalpha(ciphertext[i])) {
                        if(isupper(ciphertext[i])) {
                            decrypted_text[i] = (char)((int)ciphertext[i] - key - 65);
                        }
                        else {
                            decrypted_text[i] = (char)((int)ciphertext[i] - key - 97);
                        }
                    }
                    else {
                        decrypted_text[i] = ciphertext[i];
                    }
                }

                printf("Decrypted text: %s\n", decrypted_text);
                break;

            case '3':
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= '3');

    return 0;
}