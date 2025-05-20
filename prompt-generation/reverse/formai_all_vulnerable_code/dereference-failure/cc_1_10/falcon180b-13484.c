//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1024
#define PRIME_NUMBER 17

typedef struct{
    char *message;
    int message_size;
    int *public_key;
    int *private_key;
} KeyPair;

void generate_keys(KeyPair *key_pair){
    srand(time(NULL));
    key_pair->public_key = (int *)malloc(MAX_SIZE * sizeof(int));
    key_pair->private_key = (int *)malloc(MAX_SIZE * sizeof(int));
    for(int i = 0; i < MAX_SIZE; i++){
        key_pair->public_key[i] = rand() % PRIME_NUMBER;
        key_pair->private_key[i] = rand() % PRIME_NUMBER;
    }
}

void encrypt_message(char *message, int message_size, int *public_key, int *encrypted_message){
    for(int i = 0; i < message_size; i++){
        encrypted_message[i] = (int)message[i] ^ public_key[i % MAX_SIZE];
    }
}

void decrypt_message(int *encrypted_message, int message_size, int *private_key, char *decrypted_message){
    for(int i = 0; i < message_size; i++){
        decrypted_message[i] = (char)(encrypted_message[i] ^ private_key[i % MAX_SIZE]);
    }
    decrypted_message[message_size] = '\0';
}

int main(){
    KeyPair key_pair;
    generate_keys(&key_pair);

    char message[] = "Hello, World!";
    int message_size = strlen(message);

    int encrypted_message[MAX_SIZE];
    encrypt_message(message, message_size, key_pair.public_key, encrypted_message);

    char decrypted_message[MAX_SIZE];
    decrypt_message(encrypted_message, message_size, key_pair.private_key, decrypted_message);

    printf("Original message: %s\n", message);
    printf("Encrypted message: ");
    for(int i = 0; i < message_size; i++){
        printf("%d ", encrypted_message[i]);
    }
    printf("\n");

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}