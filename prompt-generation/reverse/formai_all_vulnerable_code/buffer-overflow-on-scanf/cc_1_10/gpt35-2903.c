//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_LENGTH 256

char *generate_key(){
    static char key[KEY_LENGTH+1];
    int i;

    //Seed the random number generator with current time
    srand(time(NULL));

    //Generate a random key
    for(i = 0; i < KEY_LENGTH; i++){
        key[i] = rand() % 256 + 1;
    }

    key[i] = '\0';

    return key;
}

char *encrypt(char *plaintext, char *key){
    int i;
    int len = strlen(plaintext);
    static char ciphertext[KEY_LENGTH+1];

    //Encrypt the plaintext using the key
    for(i = 0; i < len; i++){
        ciphertext[i] = plaintext[i] ^ key[i % KEY_LENGTH];
    }
    ciphertext[i] = '\0';

    return ciphertext;
}

char *decrypt(char *ciphertext, char *key){
    int i;
    int len = strlen(ciphertext);
    static char plaintext[KEY_LENGTH+1];

    //Decrypt the ciphertext using the key
    for(i = 0; i < len; i++){
        plaintext[i] = ciphertext[i] ^ key[i % KEY_LENGTH];
    }
    plaintext[i] = '\0';

    return plaintext;
}

int main(){
    char plaintext[KEY_LENGTH+1];
    char *key;
    char *ciphertext;
    char *decrypted;

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    //Generate a key and encrypt the plaintext
    key = generate_key();
    ciphertext = encrypt(plaintext, key);

    printf("Ciphertext: %s\n", ciphertext);

    //Decrypt the ciphertext using the key
    decrypted = decrypt(ciphertext, key);

    printf("Decrypted: %s\n", decrypted);

    return 0;
}