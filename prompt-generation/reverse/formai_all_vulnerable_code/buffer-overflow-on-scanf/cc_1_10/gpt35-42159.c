//FormAI DATASET v1.0 Category: File Encyptor ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

void encrypt(char [], int);
void decrypt(char [], int);

int main()
{
    char message[MAX_LEN];
    int key, choice;

    printf("Enter a message to be encrypted/decrypted (max length: %d): ", MAX_LEN);
    fgets(message, MAX_LEN, stdin);

    printf("Enter the key (1-25): ");
    scanf("%d", &key);

    printf("\n1. Encrypt\n2. Decrypt\nEnter your choice (1/2): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            encrypt(message, key);
            printf("Encrypted message: %s\n", message);
            break;
        case 2:
            decrypt(message, key);
            printf("Decrypted message: %s\n", message);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}

void encrypt(char message[], int key)
{
    int i;
    char ch;
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        if (ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if (ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if (ch > 'Z'){
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
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;
            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }
            message[i] = ch;
        }
    }
}