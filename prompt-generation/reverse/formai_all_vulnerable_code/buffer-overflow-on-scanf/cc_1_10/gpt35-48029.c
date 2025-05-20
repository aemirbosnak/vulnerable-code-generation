//FormAI DATASET v1.0 Category: Educational ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char*, char*);
void decrypt(char*, char*);

int main(){
    char message[100], key[100], choice;
    printf("Enter your message: ");
    fgets(message, 100, stdin);
    printf("Enter your key: ");
    fgets(key, 100, stdin);

    printf("What do you want to do? (E/D)");
    scanf("%c", &choice);

    if(choice == 'E'){
        encrypt(message, key);
        printf("Encrypted message: %s\n", message);
    }
    else if(choice == 'D'){
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    }

    return 0;
}

void encrypt(char* message, char* key){
    int m_len = strlen(message), k_len = strlen(key), i, j;
    char encrypted[100];

    for(i=0, j=0; i<m_len; i++, j++){
        if(j == k_len) j = 0;
        encrypted[i] = ((message[i] + key[j]) % 128);
    }
    encrypted[i] = '\0';
    strcpy(message, encrypted);
}

void decrypt(char* message, char* key){
    int m_len = strlen(message), k_len = strlen(key), i, j;
    char decrypted[100];

    for(i=0, j=0; i<m_len; i++, j++){
        if(j == k_len) j = 0;
        decrypted[i] = ((message[i] - key[j] + 128) % 128);
    }
    decrypted[i] = '\0';
    strcpy(message, decrypted);
}