//FormAI DATASET v1.0 Category: modern Encryption ; Style: satisfied
#include <stdio.h>
#include <string.h>

void encrypt(char message[], int key) {
    int i;
    char encryptedMessage[1000];

    for(i=0; i<strlen(message); i++) {
        if(message[i]>='A' && message[i]<='Z') {
            encryptedMessage[i] = ((message[i]-'A'+key)%26)+'A';
        } else if(message[i]>='a' && message[i]<='z') {
            encryptedMessage[i] = ((message[i]-'a'+key)%26)+'a';
        } else {
            encryptedMessage[i] = message[i];
        }
    }
    encryptedMessage[i] = '\0';
    printf("\nEncrypted Message: %s\n", encryptedMessage);
}

void decrypt(char message[], int key) {
    int i;
    char decryptedMessage[1000];

    for(i=0; i<strlen(message); i++) {
        if(message[i]>='A' && message[i]<='Z') {
            decryptedMessage[i] = ((message[i]-'A'-key+26)%26)+'A';
        } else if(message[i]>='a' && message[i]<='z') {
            decryptedMessage[i] = ((message[i]-'a'-key+26)%26)+'a';
        } else {
            decryptedMessage[i] = message[i];
        }
    }
    decryptedMessage[i] = '\0';
    printf("\nDecrypted Message: %s\n", decryptedMessage);
}

int main() {
    char message[1000];
    int key;

    printf("Enter the message to be encrypted: ");
    scanf("%[^\n]s", message);

    printf("Enter the key: ");
    scanf("%d", &key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}