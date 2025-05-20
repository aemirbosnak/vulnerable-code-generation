//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void encrypt(char *msg);
void decrypt(char *msg);
void generate_key();

int main()
{
    char msg[100];
    int choice;

    generate_key();

    printf("Welcome to Cryptic Encryption Program\n");
    printf("------------------------------------\n");

    printf("\nEnter message to encrypt: ");
    gets(msg);

    printf("\nEncryption Options");
    printf("\n------------------");
    printf("\n1. Encrypt\n2. Decrypt\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            encrypt(msg);
            printf("\nEncrypted Message: %s\n", msg);
            break;
        case 2:
            decrypt(msg);
            printf("\nDecrypted Message: %s\n", msg);
            break;
        default:
            printf("\nInvalid Choice. Program Exiting...\n");
            exit(0);
    }

    return 0;
}

void encrypt(char *msg)
{
    int i, key = 3;
    for (i=0; msg[i] != '\0'; i++)
        msg[i] += key;
}

void decrypt(char *msg)
{
    int i, key = 3;
    for (i=0; msg[i] != '\0'; i++)
        msg[i] -= key;
}

void generate_key()
{
    srand(time(NULL));
    int key = rand() % 10 + 1;

    printf("Encryption Key: %d\n\n", key);
}