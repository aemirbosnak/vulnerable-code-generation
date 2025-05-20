//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LEN 256

typedef struct {
    char name[20];
    int age;
} Person;

typedef struct {
    char key[32];
    int shift;
} Key;

void generateKey(Key* key) {
    int i;
    srand(time(NULL));

    for (i = 0; i < 32; i++) {
        key->key[i] = 'A' + (rand() % 26);
    }

    key->shift = rand() % 26;
}

void encryptString(char* message, Key* key) {
    int i, j;
    char encryptedMessage[MAX_LEN];

    for (i = 0; message[i] != '\0'; i++) {
        j = (message[i] + key->shift - 'A') % 26;

        if (message[i] >= 'A' && message[i] <= 'Z') {
            encryptedMessage[i] = 'A' + j;
        } else {
            encryptedMessage[i] = message[i];
        }
    }

    encryptedMessage[i] = '\0';
    strcpy(message, encryptedMessage);
}

int main() {
    Person author;
    Key secretKey;
    char message[MAX_LEN];

    printf("Hail, wanderer, and welcome to The Enchanted Quill!\n");
    printf("Please enter thy name:\n");
    scanf("%s", author.name);

    generateKey(&secretKey);

    printf("Enter the message thou art about to encrypt:\n");
    scanf("%s", message);

    encryptString(message, &secretKey);

    printf("Message encrypted with the magic of %s:\n", secretKey.key);
    printf("%s\n", message);

    printf("May the enchantment of the words protect thy secrets.\n");

    return 0;
}