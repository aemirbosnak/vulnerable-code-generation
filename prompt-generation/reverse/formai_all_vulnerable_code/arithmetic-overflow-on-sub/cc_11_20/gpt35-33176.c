//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int encrypt, decrypt, choice;
    char message[100], c;
    
    printf("Choose the operation you want to perform:\n");
    printf("1. Encrypt a message.\n");
    printf("2. Decrypt a message.\n");
    scanf("%d", &choice);
    
    switch(choice) {
        
        case 1:
            printf("Enter message to encrypt: ");
            scanf("%s", message);
            printf("Enter key to encrypt: ");
            scanf("%d", &encrypt);
            printf("Encrypted message: ");
            for(int i = 0; message[i] != '\0'; i++) {
                c = message[i];
                if(c >= 'a' && c <= 'z') {
                    c = c + encrypt;
                    if(c > 'z') {
                        c = c - 'z' + 'a' - 1;
                    }
                    message[i] = c;
                }
                else if(c >= 'A' && c <= 'Z') {
                    c = c + encrypt;
                    if(c > 'Z') {
                        c = c - 'Z' + 'A' - 1;
                    }
                    message[i] = c;
                }
            }
            printf("%s", message);
            break;
            
        case 2:
            printf("Enter message to decrypt: ");
            scanf("%s", message);
            printf("Enter key to decrypt: ");
            scanf("%d", &decrypt);
            printf("Decrypted message: ");
            for(int j = 0; message[j] != '\0'; j++) {
                c = message[j];
                if(c >= 'a' && c <= 'z') {
                    c = c - decrypt;
                    if(c < 'a') {
                        c = c + 'z' - 'a' + 1;
                    }
                    message[j] = c;
                }
                else if(c >= 'A' && c <= 'Z') {
                    c = c - decrypt;
                    if(c < 'A') {
                        c = c + 'Z' - 'A' + 1;
                    }
                    message[j] = c;
                }
            }
            printf("%s", message);
            break;
        
        default:
            printf("Invalid choice!");
    }
    
    return 0;
}