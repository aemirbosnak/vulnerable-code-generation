//FormAI DATASET v1.0 Category: Image Editor ; Style: Cryptic
#include<stdio.h>
#include<string.h>

#define MAX_SIZE 100

void encrypt(char str[MAX_SIZE]); // Function to encrypt the image
void decrypt(char str[MAX_SIZE]); // Function to decrypt the image

int main()
{
    char str[MAX_SIZE];
    int choice, flag = 1;

    printf("W3LC0M3 T0 CRYPTIC IMAGE EDITOR\n\n");

    while(flag) // Main loop to run the program until user exits
    {
        printf("Choose an operation:\n\n");
        printf("1. Encrypt the image\n");
        printf("2. Decrypt the image\n");
        printf("3. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the image file name: ");
                scanf("%s", str);
                encrypt(str); // Encrypt the image

                printf("Image %s encrypted successfully.\n\n", str);
                break;

            case 2:
                printf("Enter the encrypted image file name: ");
                scanf("%s", str);
                decrypt(str); // Decrypt the image

                printf("Image %s decrypted successfully.\n\n", str);
                break;

            case 3:
                flag = 0; // Set flag to 0 to exit program
                break;

            default:
                printf("Invalid choice, try again.\n\n");
                break;
        }
    }

    printf("Thank you for using Cryptic Image Editor!\n");

    return 0;
}

void encrypt(char str[MAX_SIZE])
{
    int i, len = strlen(str);

    for(i = 0; i < len; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z') // Convert uppercase letters to lowercase
            str[i] += 32;
        else if(str[i] >= 'a' && str[i] <= 'z') // Convert lowercase letters to uppercase
            str[i] -= 32;
    }
}

void decrypt(char str[MAX_SIZE])
{
    int i, len = strlen(str);

    for(i = 0; i < len; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z') // Convert uppercase letters to lowercase
            str[i] += 32;
        else if(str[i] >= 'a' && str[i] <= 'z') // Convert lowercase letters to uppercase
            str[i] -= 32;
    }
}