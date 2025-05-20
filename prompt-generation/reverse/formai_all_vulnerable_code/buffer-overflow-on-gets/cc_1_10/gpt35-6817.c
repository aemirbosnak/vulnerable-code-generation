//FormAI DATASET v1.0 Category: Encryption ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Declare global variables for encryption
char key = 'K';
char text[100];
int encrypted_text[100];
int decrypted_text[100];

// Function to encrypt and decrypt text
void *encrypt_decrypt(void *arg)
{
    int *op = (int *)arg;
    int i;
    if (*op == 1) // Encryption
    {
        for (i = 0; i < strlen(text); i++)
        {
            encrypted_text[i] = (text[i] + key) % 26;
        }
        printf("Encrypted Text: ");
        for (i = 0; i < strlen(text); i++)
        {
            printf("%c", encrypted_text[i] + 'A');
        }
        printf("\n");
    }
    else if (*op == 2) // Decryption
    {
        for (i = 0; i < strlen(text); i++)
        {
            decrypted_text[i] = (encrypted_text[i] - key + 26) % 26;
        }
        printf("Decrypted Text: ");
        for (i = 0; i < strlen(text); i++)
        {
            printf("%c", decrypted_text[i] + 'A');
        }
        printf("\n");
    }
    else
    {
        printf("Invalid option!");
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t tid;
    printf("Enter a text to encrypt: ");
    gets(text);
    int option;
    printf("Choose an option:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &option);
    pthread_create(&tid, NULL, encrypt_decrypt, &option);
    pthread_join(tid, NULL);
    return 0;
}