//FormAI DATASET v1.0 Category: Encryption ; Style: visionary
#include<stdio.h>
#include<string.h>

void encrypt(char* msg, int key){
    int i, j;
    char cipher[100];

    for(i = 0; msg[i] != '\0'; ++i){
        if(msg[i] >= 'a' && msg[i] <= 'z'){
            cipher[i] = (char)(((msg[i] - 'a' + key) % 26) + 'a');
        }
        else if(msg[i] >= 'A' && msg[i] <= 'Z'){
            cipher[i] = (char)(((msg[i] - 'A' + key) % 26) + 'A');
        }
        else{
            cipher[i] = msg[i];
        }
    }

    cipher[i] = '\0';

    printf("\nEncrypted message: %s\n", cipher);
}

void decrypt(char* cipher, int key){
    int i, j;
    char msg[100];

    for(i = 0; cipher[i] != '\0'; ++i){
        if(cipher[i] >= 'a' && cipher[i] <= 'z'){
            msg[i] = (char)(((cipher[i] - 'a' - key + 26) % 26) + 'a');
        }
        else if(cipher[i] >= 'A' && cipher[i] <= 'Z'){
            msg[i] = (char)(((cipher[i] - 'A' - key + 26) % 26) + 'A');
        }
        else{
            msg[i] = cipher[i];
        }
    }

    msg[i] = '\0';

    printf("\nDecrypted message: %s\n", msg);
}

int main(){
    char message[100];
    int key;

    printf("Enter a message: ");
    scanf("%s", message);

    printf("\nEnter a key: ");
    scanf("%d", &key);

    encrypt(message, key);

    decrypt(message, key);

    return 0;
}