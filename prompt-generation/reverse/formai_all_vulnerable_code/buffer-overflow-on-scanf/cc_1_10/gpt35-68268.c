//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

//Function prototypes
void generate_key(char key[], int key_len);
void encrypt(char message[], char key[], char encrypted_message[], int message_len);
void decrypt(char encrypted_message[], char key[], char decrypted_message[], int message_len);

int main()
{
    char message[1000], key[1000], encrypted_message[1000], decrypted_message[1000];
    int key_len, message_len;

    printf("Enter the message to be encrypted: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; //Removing the trailing newline character

    message_len = strlen(message);

    printf("Enter the length of the key (maximum %d): ", message_len);
    scanf("%d", &key_len);

    generate_key(key, key_len);

    encrypt(message, key, encrypted_message, message_len);

    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key, decrypted_message, message_len);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}

/* Function to generate a key of specified length */
void generate_key(char key[], int key_len)
{
    int i;
    srand(time(NULL)); //Seeding the random number generator

    for(i=0;i<key_len;i++)
    {
        key[i] = (rand()%26)+97; //Generating a random lower case alphabet
    }

    key[key_len] = '\0'; //Adding the null terminator at the end of the key
}

/* Function to encrypt the message using the key */
void encrypt(char message[], char key[], char encrypted_message[], int message_len)
{
    int i;
    char c1, c2;

    for(i=0;i<message_len;i++)
    {
        c1 = tolower(message[i]); //Converting the character to lower case
        c2 = tolower(key[i%strlen(key)]); //Converting the character of key to lower case
        encrypted_message[i] = (((c1-97)+(c2-97))%26)+97; //Adding the corresponding alphabet of key to the message
    }

    encrypted_message[message_len] = '\0'; //Adding the null terminator at the end of the encrypted message
}

/* Function to decrypt the encrypted message using the key */
void decrypt(char encrypted_message[], char key[], char decrypted_message[], int message_len)
{
    int i;
    char c1, c2;

    for(i=0;i<message_len;i++)
    {
        c1 = tolower(encrypted_message[i]); //Converting the character to lower case
        c2 = tolower(key[i%strlen(key)]); //Converting the character of key to lower case
        decrypted_message[i] = (((c1-97)-(c2-97)+26)%26)+97; //Subtracting the corresponding alphabet of key from the encrypted message
    }

    decrypted_message[message_len] = '\0'; //Adding the null terminator at the end of the decrypted message
}