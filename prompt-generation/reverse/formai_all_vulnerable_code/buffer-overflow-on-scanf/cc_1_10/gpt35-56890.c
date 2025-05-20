//FormAI DATASET v1.0 Category: Encryption ; Style: random
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

char password[MAX_LEN];
char encrypted[MAX_LEN];
char decrypted[MAX_LEN];

void encrypt(char* message);
void decrypt(char* message);
void printMenu();

int main()
{
    int choice;
    char message[MAX_LEN];

    printf("Welcome to the C Encryption program!\n\n");

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter a message to encrypt: ");
                scanf("%s", message);
                encrypt(message);
                printf("\nEncrypted message: %s\n\n", encrypted);
                break;
            case 2:
                printf("\nEnter a message to decrypt: ");
                scanf("%s", message);
                decrypt(message);
                printf("\nDecrypted message: %s\n\n", decrypted);
                break;
            case 3:
                printf("\nEnter new password: ");
                scanf("%s", password);
                printf("\nPassword changed successfully!\n\n");
                break;
            case 4: 
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n\n");
        }
    } while(choice != 4);

    return 0;
}

void encrypt(char* message)
{
    int i, len;

    len = strlen(message);

    for(i=0; i<len; i++)
    {
        encrypted[i] = message[i] + password[i%(strlen(password))];
    }

    encrypted[len] = '\0';
}

void decrypt(char* message)
{
    int i, len;

    len = strlen(message);

    for(i=0; i<len; i++)
    {
        decrypted[i] = message[i] - password[i%(strlen(password))];
    }

    decrypted[len] = '\0';
}

void printMenu()
{
    printf("Main Menu\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Change password\n");
    printf("4. Exit\n");
}