//FormAI DATASET v1.0 Category: Modern Encryption ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(char *str, int key)
{
    if (*str == '\0')
    {
        return;
    }
    else
    {
        encrypt(str + 1, key); // recursive call to the next character in the string
        if (*str >= 'A' && *str <= 'Z')
        {
            *str = ((*str - 'A' + key) % 26) + 'A'; // encrypt uppercase letters
        }
        else if (*str >= 'a' && *str <= 'z')
        {
            *str = ((*str - 'a' + key) % 26) + 'a'; // encrypt lowercase letters
        }
    }
}

void decrypt(char *str, int key)
{
    if (*str == '\0')
    {
        return;
    }
    else
    {
        decrypt(str + 1, key); // recursive call to the next character in the string
        if (*str >= 'A' && *str <= 'Z')
        {
            *str = ((*str - 'A' - key + 26) % 26) + 'A'; // decrypt uppercase letters
        }
        else if (*str >= 'a' && *str <= 'z')
        {
            *str = ((*str - 'a' - key + 26) % 26) + 'a'; // decrypt lowercase letters
        }
    }
}

int main()
{
    char str[1000];
    int key, choice;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // input a string

    printf("Enter a key (1-25): ");
    scanf("%d", &key); // input a key
    
    do {
        printf("\nChoose Operation:\n1. Encrypt\n2. Decrypt\n3. Exit\nOption: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                encrypt(str, key); // call encrypt function
                printf("Encrypted string: %s\n", str); // output the encrypted string
                decrypt(str, key); // decrypt the string back to normal
                break;
            case 2:
                decrypt(str, key); // call decrypt function
                printf("Decrypted string: %s\n", str); // output the decrypted string
                encrypt(str, key); // encrypt the string back to normal
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Try again.\n");
        }
    } while(choice != 3);

    return 0;
}