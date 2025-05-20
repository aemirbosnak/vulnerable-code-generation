//FormAI DATASET v1.0 Category: Browser Plugin ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program is a simple example of a browser plugin written in the programming language C.
The plugin allows users to encrypt and decrypt messages in their browser. */

/* Define the encryption function */
void encrypt(char message[], int key){
    int i;
    for(i = 0; i < strlen(message); i++){
        message[i] = message[i] + key;
    }
}

/* Define the decryption function */
void decrypt(char message[], int key){
    int i;
    for(i = 0; i < strlen(message); i++){
        message[i] = message[i] - key;
    }
}

/* Define the function that will execute the plugin's features */
void execute_plugin(char* mode){
    printf("Enter message: ");
    char message[100];
    scanf("%s", message);
    
    printf("Enter key: ");
    int key;
    scanf("%d", &key);
    
    if(strcmp(mode, "encrypt") == 0){
        encrypt(message, key);
        printf("Encrypted message: %s\n", message);
    }
    else if(strcmp(mode, "decrypt") == 0){
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    }
    else{
        printf("Invalid mode selected.\n");
    }
}

int main(){
    printf("Select mode ('encrypt' or 'decrypt'): ");
    char mode[10];
    scanf("%s", mode);

    execute_plugin(mode);

    return 0;
}