//FormAI DATASET v1.0 Category: Encryption ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input, char *output, char *key) {
    int len_input = strlen(input);
    int len_key = strlen(key);
    int i, j;
    
    for(i = 0, j = 0; i < len_input; i++, j++) {
        if(j >= len_key) {
            j = 0;
        }
        
        output[i] = (input[i] + key[j]) % 256;
    }
}

void decrypt(char *input, char *output, char *key) {
    int len_input = strlen(input);
    int len_key = strlen(key);
    int i, j;
    
    for(i = 0, j = 0; i < len_input; i++, j++) {
        if(j >= len_key) {
            j = 0;
        }
        
        output[i] = (input[i] - key[j] + 256) % 256;
    }
}

int main() {
    char input[1000];
    char output[1000];
    char key[100];
    int option, success;
    
    printf("Welcome to the puzzle encryption program!\n\n");
    
    while(1) {
        printf("Choose an option from the menu:\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Exit\n");
        
        success = scanf("%d", &option);
        if(success != 1) {
            printf("Invalid input. Please try again.\n\n");
            while(getchar() != '\n');
            continue;
        }
        
        if(option == 1) {
            printf("\nEnter the message you want to encrypt:\n");
            scanf(" %[^\n]", input);
            
            printf("\nEnter the key you want to use for encryption:\n");
            scanf(" %[^\n]", key);
            
            encrypt(input, output, key);
            
            printf("\nYour encrypted message is:\n");
            int i;
            for(i = 0; i < strlen(input); i++) {
                printf("%02X", output[i]);
            }
            printf("\n\n");
        }
        else if(option == 2) {
            printf("\nEnter the message you want to decrypt:\n");
            scanf(" %[^\n]", input);
            
            printf("\nEnter the key you want to use for decryption:\n");
            scanf(" %[^\n]", key);
            
            int i;
            for(i = 0; i < strlen(input); i += 2) {
                sscanf(input + i, "%2X", output + i/2);
            }
            output[i/2] = '\0';
            
            decrypt(output, input, key);
            
            printf("\nYour decrypted message is:\n%s\n\n", input);
        }
        else if(option == 3) {
            printf("\nThank you for using the puzzle encryption program!\n");
            break;
        }
        else {
            printf("Invalid option. Please try again.\n\n");
        }
    }
    
    return 0;
}