//FormAI DATASET v1.0 Category: Encryption ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char* message, int key){
    int len = strlen(message);
    for(int i=0; i<len; i++){
        if(message[i] >= 'a' && message[i] <= 'z'){
            message[i] = (char)((int)message[i] + key);
            if(message[i] > 'z'){
                message[i] = (char)((int)message[i] - 26);
            }
        }
        else if(message[i] >= 'A' && message[i] <= 'Z'){
            message[i] = (char)((int)message[i] + key);
            if(message[i] > 'Z'){
                message[i] = (char)((int)message[i] - 26);
            }
        }
    }
}

void decrypt(char* message, int key){
    int len = strlen(message);
    for(int i=0; i<len; i++){
        if(message[i] >= 'a' && message[i] <= 'z'){
            message[i] = (char)((int)message[i] - key);
            if(message[i] < 'a'){
                message[i] = (char)((int)message[i] + 26);
            }
        }
        else if(message[i] >= 'A' && message[i] <= 'Z'){
            message[i] = (char)((int)message[i] - key);
            if(message[i] < 'A'){
                message[i] = (char)((int)message[i] + 26);
            }
        }
    }
}

int main(){
    char message[100];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = 0; //removes newline character from the string
    
    printf("Enter a key (between 1 and 25): ");
    scanf("%d", &key);
    
    if(key<1 || key>25){
        printf("Invalid key!\n");
        exit(0);
    }
    
    printf("Original Message: %s\n", message);
    encrypt(message, key);
    printf("Encrypted Message: %s\n", message);
    decrypt(message, key); //decrypting the message using the same key used to encrypt
    printf("Decrypted Message: %s\n", message);

    return 0;
}