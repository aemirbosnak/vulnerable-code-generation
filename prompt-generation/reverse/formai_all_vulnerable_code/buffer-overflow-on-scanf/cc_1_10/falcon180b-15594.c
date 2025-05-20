//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_LENGTH 1000000
#define MAX_CHARS 256
#define MAX_PASSWORDS 1000

typedef struct {
    char *password;
    int length;
} Password;

typedef struct {
    char *message;
    int length;
} Message;

typedef struct {
    char *filename;
    char *message;
    int length;
} FileMessage;

char *generate_password(int length) {
    char *password = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        password[i] = rand() % MAX_CHARS + 'a';
    }
    password[length] = '\0';
    return password;
}

char *encrypt_message(char *message, char *password, int length) {
    char *encrypted_message = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        encrypted_message[i] = message[i] ^ password[i % strlen(password)];
    }
    encrypted_message[length] = '\0';
    return encrypted_message;
}

char *decrypt_message(char *message, char *password, int length) {
    char *decrypted_message = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        decrypted_message[i] = message[i] ^ password[i % strlen(password)];
    }
    decrypted_message[length] = '\0';
    return decrypted_message;
}

int main() {
    srand(time(NULL));
    int length;
    char *message, *password;
    printf("Enter message length: ");
    scanf("%d", &length);
    message = malloc(length + 1);
    printf("Enter message: ");
    scanf("%s", message);
    printf("Enter password length: ");
    scanf("%d", &length);
    password = generate_password(length);
    char *encrypted_message = encrypt_message(message, password, length);
    char *decrypted_message = decrypt_message(encrypted_message, password, length);
    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);
    free(message);
    free(password);
    free(encrypted_message);
    free(decrypted_message);
    return 0;
}