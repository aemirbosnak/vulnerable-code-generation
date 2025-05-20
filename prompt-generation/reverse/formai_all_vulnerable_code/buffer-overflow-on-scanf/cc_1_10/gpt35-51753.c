//FormAI DATASET v1.0 Category: Password management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/************ Function declarations ************/
void showMenu();
void encryptPassword();
void decryptPassword();
void saveToFile();
void readFromFile();
void generateKey();
void keyToFile();
void readKeyFile();

/************ Global Variables ************/
char password[50], key[50], encrypted_password[50], decrypted_password[50];

/************ Main Function ************/
int main()
{
    int choice;
    while(1)
    {
        showMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the password: ");
                scanf("%s", password);
                encryptPassword();
                printf("\nThe encrypted password is: %s\n", encrypted_password);
                break;
            case 2:
                printf("\nEnter the encrypted password: ");
                scanf("%s", encrypted_password);
                decryptPassword();
                printf("\nThe decrypted password is: %s\n", decrypted_password);
                break;
            case 3:
                saveToFile();
                break;
            case 4:
                readFromFile();
                break;
            case 5:
                generateKey();
                break;
            case 6:
                keyToFile();
                break;
            case 7:
                readKeyFile();
                break;
            case 8:
                exit(0);
            default:
                printf("\nInvalid choice, please try again!\n");
        }
    }
    return 0;
}

/************ Function Definitions ************/

/* Function to display menu of password management program */
void showMenu()
{
    printf("\n**************************************************\n");
    printf("*            PASSWORD MANAGEMENT SYSTEM          *\n");
    printf("**************************************************\n\n");
    printf("1. Encrypt password\n");
    printf("2. Decrypt password\n");
    printf("3. Save encrypted password to file\n");
    printf("4. Read encrypted password from file\n");
    printf("5. Generate key\n");
    printf("6. Save key to file\n");
    printf("7. Read key from file\n");
    printf("8. Exit program\n\n");
}

/* Function to encrypt password using XOR operation */
void encryptPassword()
{
    int i, j = 0;
    int key_length = strlen(key);
    for(i = 0; i < strlen(password); i++)
    {
        if(j == key_length)
            j = 0;
        encrypted_password[i] = password[i] ^ key[j];
        j++;
    }
    encrypted_password[i] = '\0';
}

/* Function to decrypt encrypted password using XOR operation */
void decryptPassword()
{
    int i, j = 0;
    int key_length = strlen(key);
    for(i = 0; i < strlen(encrypted_password); i++)
    {
        if(j == key_length)
            j = 0;
        decrypted_password[i] = encrypted_password[i] ^ key[j];
        j++;
    }
    decrypted_password[i] = '\0';
}

/* Function to save encrypted password to file */
void saveToFile()
{
    FILE *fptr;
    char filename[20];
    printf("\nEnter the file name: ");
    scanf("%s", filename);
    fptr = fopen(filename, "w");
    fprintf(fptr, "%s", encrypted_password);
    fclose(fptr);
    printf("\nEncrypted password saved to file: %s\n", filename);
}

/* Function to read encrypted password from file */
void readFromFile()
{
    FILE *fptr;
    char filename[20];
    printf("\nEnter the file name: ");
    scanf("%s", filename);
    fptr = fopen(filename, "r");
    if(fptr == NULL)
    {
        printf("\nError: File not found or cannot open the file!\n");
        return;
    }
    fgets(encrypted_password, sizeof(encrypted_password), fptr);
    fclose(fptr);
    printf("\nEncrypted password read from file: %s\n", encrypted_password);
}

/* Function to generate random key */
void generateKey()
{
    int i;
    printf("\nGenerating key...\n");
    for(i = 0; i < 16; i++)
        key[i] = (char)(rand() % 256);
    printf("Key generated: ");
    for(i = 0; i < 16; i++)
        printf("%02X ", key[i]);
    printf("\n");
}

/* Function to save key to file */
void keyToFile()
{
    FILE *fptr;
    char filename[20];
    printf("\nEnter the file name: ");
    scanf("%s", filename);
    fptr = fopen(filename, "wb");
    fwrite(key, sizeof(char), 16, fptr);
    fclose(fptr);
    printf("\nKey saved to file: %s\n", filename);
}

/* Function to read key from file */
void readKeyFile()
{
    FILE *fptr;
    char filename[20];
    printf("\nEnter the file name: ");
    scanf("%s", filename);
    fptr = fopen(filename, "rb");
    if(fptr == NULL)
    {
        printf("\nError: File not found or cannot open the file!\n");
        return;
    }
    fread(key, sizeof(char), 16, fptr);
    fclose(fptr);
    printf("\nKey read from file: ");
    for(int i = 0; i < 16; i++)
        printf("%02X ", key[i]);
    printf("\n");
}