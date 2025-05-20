//FormAI DATASET v1.0 Category: Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Caesar 1
#define Vigenere 2
#define Size 1000

int main()
{
    int choice = 0;
    char key[Size], input[Size], output[Size];
    int i, j = 0, k;
 
    printf("Please choose the encryption mode:\n");
    printf("1. Caesar Cipher\n");
    printf("2. Vigenere Cipher\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
 
    if (choice == Caesar)
    {
        int shift;
        printf("Enter the shift amount (1-25): ");
        scanf("%d", &shift);
 
        printf("Enter the message to be encrypted: ");
        scanf(" %[^\n]s", input);
   
        for(i = 0; i < strlen(input); ++i){
            if(input[i] >= 'a' && input[i] <= 'z'){
                output[j] = (input[i] - 'a' + shift) % 26 + 'a';
                j++;
            }
            else if(input[i] >= 'A' && input[i] <= 'Z'){
                output[j] = (input[i] - 'A' + shift) % 26 + 'A';
                j++;
            }
            else{
                output[j] = input[i];
                j++;
            }
        }
        output[j] = '\0';
 
        printf("Encrypted message: %s\n", output);
    }
    else if (choice == Vigenere)
    {
        printf("Enter the key: ");
        scanf(" %[^\n]s", key);
 
        printf("Enter the message to be encrypted: ");
        scanf(" %[^\n]s", input);
 
        for(i = 0, k = 0; i < strlen(input); ++i){
            if(input[i] >= 'a' && input[i] <= 'z'){
                output[j] = (input[i] - 'a' + key[k] - 'a') % 26 + 'a';
                j++;
                k = (k + 1) % strlen(key);
            }
            else if(input[i] >= 'A' && input[i] <= 'Z'){
                output[j] = (input[i] - 'A' + key[k] - 'a') % 26 + 'A';
                j++;
                k = (k + 1) % strlen(key);
            }
            else{
                output[j] = input[i];
                j++;
            }
        }
        output[j] = '\0';
 
        printf("Encrypted message: %s\n", output);
    }
    else{
        printf("Invalid Choice!\n");
    }
    return 0;
}