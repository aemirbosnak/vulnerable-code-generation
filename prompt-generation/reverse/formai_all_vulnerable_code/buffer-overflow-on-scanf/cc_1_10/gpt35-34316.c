//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Define function prototypes */
void encrypt(char* plainText, char* key);
void decrypt(char* cipherText, char* key);

int main(){
    /* Define variables */
    char message[100];
    char key[50];
    char choice;
    
    /* Get user input */
    printf("Enter your message: ");
    fgets(message,100,stdin);
    printf("Enter your key: ");
    fgets(key,50,stdin);
    
    /* Add null terminator to remove trailing white space */
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;
    
    /* Ask user for encryption or decryption */
    printf("Do you want to encrypt or decrypt this message? (E/D): ");
    scanf("%c",&choice);
    
    /* Apply encryption or decryption based on user's choice */
    switch(choice){
        case 'E':
        case 'e':
            encrypt(message,key);
            break;
        case 'D':
        case 'd':
            decrypt(message,key);
            break;
        default:
            printf("Invalid choice! Please choose either E or D.\n");
    }

    return 0;
}

/* Define encryption function */
void encrypt(char* plainText, char* key){
    /* Define variables */
    int i,j;
    char encrypted[100];
    
    /* Apply XOR operation to each character in the message with the corresponding character in the key */
    for(i=0,j=0; i<strlen(plainText); i++,j++){
        if(j==strlen(key)){
            j = 0;
        }
        encrypted[i] = plainText[i] ^ key[j];
    }
    
    /* Add null terminator to end of encrypted message */
    encrypted[i] = '\0';
    
    /* Print the encrypted message */
    printf("Your encrypted message is: %s\n",encrypted);
}

/* Define decryption function */
void decrypt(char* cipherText, char* key){
    /* Define variables */
    int i,j;
    char decrypted[100];
    
    /* Apply XOR operation to each character in the cipher text with the corresponding character in the key */
    for(i=0,j=0; i<strlen(cipherText); i++,j++){
        if(j==strlen(key)){
            j = 0;
        }
        decrypted[i] = cipherText[i] ^ key[j];
    }
    
    /* Add null terminator to end of decrypted message */
    decrypted[i] = '\0';
    
    /* Print the decrypted message */
    printf("Your decrypted message is: %s\n",decrypted);
}