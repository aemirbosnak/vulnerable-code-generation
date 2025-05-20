//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: romantic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void encrypt(char [], int);
void decrypt(char [], int);

int main()
{
    char message[1000], choice;
    int key;

    printf("Enter a message you want to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("\nEnter a key for encryption: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("\nThe encrypted message is: %s", message);
    printf("\nDo you want to decrypt the message? (Y/N) ");
    getchar();
    scanf("%c", &choice);

    if(toupper(choice) == 'Y') {
        decrypt(message, key);
        printf("\nThe decrypted message is: %s", message);
        printf("\nI hope this encrypted message can only be decrypted by the key of your heart.\n");
    }
    else {
        printf("\nWhy not? This message was encrypted just for you.\n");
    }
    
    return 0;
}

void encrypt(char message[], int key)
{
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        if(isalpha(ch)) {
            ch = toupper(ch);
            ch = ch + key;

            if(ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
    }
}

void decrypt(char message[], int key)
{
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        if(isalpha(ch)) {
            ch = toupper(ch);
            ch = ch - key;

            if(ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }

            message[i] = ch;
        }
    }
}