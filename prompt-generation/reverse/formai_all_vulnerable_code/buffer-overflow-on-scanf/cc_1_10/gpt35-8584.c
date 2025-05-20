//FormAI DATASET v1.0 Category: File Encyptor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void encrypt(char *text, int key);
void decrypt(char *text, int key);

int main()
{
    char text[MAX_LEN], choice;
    int key;

    printf("Enter the text to encrypt/decrypt: ");
    fgets(text, MAX_LEN, stdin);
    text[strcspn(text, "\n")] = 0;

    printf("Enter the key: ");
    scanf("%d", &key);
    getchar();

    printf("Enter 'e' to encrypt or 'd' to decrypt: ");
    scanf("%c", &choice);
    getchar();
    
    switch(choice)
    {
        case 'e':
            encrypt(text, key);
            printf("Encrypted text: %s\n", text);
            break;
        
        case 'd':
            decrypt(text, key);
            printf("Decrypted text: %s\n", text);
            break;
        
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}

void encrypt(char *text, int key)
{
    int i;
    for(i=0; text[i]!='\0'; i++)
    {
        if(text[i]>='a' && text[i]<='z')
        {
            text[i] = (text[i]-'a'+key)%26 + 'a';
        }
        else if(text[i]>='A' && text[i]<='Z')
        {
            text[i] = (text[i]-'A'+key)%26 + 'A';
        }
    }
}

void decrypt(char *text, int key)
{
    int i;
    for(i=0; text[i]!='\0'; i++)
    {
        if(text[i]>='a' && text[i]<='z')
        {
            text[i] = (text[i]-'a'-key+26)%26 + 'a';
        }
        else if(text[i]>='A' && text[i]<='Z')
        {
            text[i] = (text[i]-'A'-key+26)%26 + 'A';
        }
    }
}