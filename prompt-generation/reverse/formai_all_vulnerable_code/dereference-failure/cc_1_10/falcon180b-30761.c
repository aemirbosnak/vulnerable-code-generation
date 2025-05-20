//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_SIZE 1000
#define KEY_SIZE 20

void generate_key(char *key) {
    int i;
    for(i=0; i<KEY_SIZE; i++) {
        key[i] = rand()%26 + 'a';
    }
    key[KEY_SIZE] = '\0';
}

void encrypt(char *message, char *key, char *encrypted_message) {
    int i, j, shift;
    for(i=0, j=0; i<strlen(message); i++) {
        if(isalpha(message[i])) {
            shift = (int)key[j%KEY_SIZE] - 'a';
            encrypted_message[i] = ((message[i] - 'a' + shift)%26) + 'a';
            j++;
        } else {
            encrypted_message[i] = message[i];
        }
    }
    encrypted_message[strlen(message)] = '\0';
}

void decrypt(char *encrypted_message, char *key, char *decrypted_message) {
    int i, j, shift;
    for(i=0, j=0; i<strlen(encrypted_message); i++) {
        if(isalpha(encrypted_message[i])) {
            shift = (int)key[j%KEY_SIZE] - 'a';
            decrypted_message[i] = ((encrypted_message[i] - 'a' - shift + 26)%26) + 'a';
            j++;
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }
    decrypted_message[strlen(encrypted_message)] = '\0';
}

int main() {
    char message[MAX_SIZE];
    char encrypted_message[MAX_SIZE];
    char decrypted_message[MAX_SIZE];
    char key[KEY_SIZE];
    int choice;

    srand(time(NULL));
    generate_key(key);

    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    encrypt(message, key, encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    printf("Enter 1 to decrypt the message or any other key to exit: ");
    scanf("%d", &choice);

    if(choice == 1) {
        decrypt(encrypted_message, key, decrypted_message);
        printf("Decrypted message: %s\n", decrypted_message);
    } else {
        printf("Exiting program...\n");
    }

    return 0;
}