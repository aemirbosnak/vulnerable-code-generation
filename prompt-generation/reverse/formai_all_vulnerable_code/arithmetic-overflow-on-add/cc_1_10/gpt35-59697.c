//FormAI DATASET v1.0 Category: Modern Encryption ; Style: light-weight
#include <stdio.h>
#include <string.h>

void encrypt(char[], int);
void decrypt(char[], int);

int main()
{
    char message[100];
    int shift;

    printf("Enter message to encrypt: ");
    gets(message);

    printf("Enter shift value: ");
    scanf("%d", &shift);

    encrypt(message, shift);
    printf("Encrypted message: %s\n", message);

    decrypt(message, shift);
    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char message[], int shift)
{
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];

        if(ch >= 'a' && ch <= 'z'){
            ch = ch + shift;

            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + shift;

            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
    }
}

void decrypt(char message[], int shift)
{
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];

        if(ch >= 'a' && ch <= 'z'){
            ch = ch - shift;

            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }

            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - shift;

            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }

            message[i] = ch;
        }
    }
}