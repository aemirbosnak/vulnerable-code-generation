//FormAI DATASET v1.0 Category: Modern Encryption ; Style: all-encompassing
#include<stdio.h>
#include<string.h>

void encrypt(char* str, int key)
{
    int len = strlen(str);
    char* cipher = (char*)malloc(len * sizeof(char));
    
    for(int i=0; i<len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            cipher[i] = (((str[i] - 'a') + key) % 26) + 'a';
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            cipher[i] = (((str[i] - 'A') + key) % 26) + 'A';
        }
        else
        {
            cipher[i] = str[i];
        }
    }
    
    printf("\nOriginal message : %s", str);
    printf("\nEncrypted message : %s\n", cipher);
    free(cipher);
}

void decrypt(char* cipher, int key)
{
    int len = strlen(cipher);
    char* str = (char*)malloc(len * sizeof(char));
    
    for(int i=0; i<len; i++)
    {
        if (cipher[i] >= 'a' && cipher[i] <= 'z')
        {
            str[i] = (((cipher[i] - 'a') - key + 26) % 26) + 'a';
        }
        else if (cipher[i] >= 'A' && cipher[i] <= 'Z')
        {
            str[i] = (((cipher[i] - 'A') - key + 26) % 26) + 'A';
        }
        else
        {
            str[i] = cipher[i];
        }
    }
    
    printf("Decrypted message : %s", str);
    free(str);
}

int main()
{
    char message[100];
    int key;
    int choice;
    
    printf("Enter the message to encrypt : ");
    gets(message);
    
    printf("\nEnter the key : ");
    scanf("%d", &key);
    
    do {
        printf("\nSelect the operation to perform : \n");
        printf("1. Encrypt the message\n");
        printf("2. Decrypt the message\n");
        printf("3. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: encrypt(message, key);
                    break;
            case 2: decrypt(message, key);
                    break;
            case 3: printf("Exiting...\n");
                    break;
            default: printf("Invalid choice, please try again\n");
        }
    }while(choice != 3);
    
    return 0;
}