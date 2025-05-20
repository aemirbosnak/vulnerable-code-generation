//FormAI DATASET v1.0 Category: Encryption ; Style: complete
#include<stdio.h>
#include<string.h>

void encrypt(char* message, int key){

    int i;
    char ch;
    
    for(i=0; message[i] != '\0'; i++){

        ch = message[i];

        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;

            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;

            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
    }

    printf("Encrypted message: %s\n", message);
}

void decrypt(char* message, int key){

    int i;
    char ch;

    for(i=0; message[i] != '\0'; i++){

        ch = message[i];

        if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;

            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }

            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;

            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }

            message[i] = ch;
        }
    }

    printf("Decrypted message: %s\n", message);
}

int main(){

    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter key: ");
    scanf("%d", &key);

    encrypt(message, key);
    decrypt(message, key);
    
    return 0;
}