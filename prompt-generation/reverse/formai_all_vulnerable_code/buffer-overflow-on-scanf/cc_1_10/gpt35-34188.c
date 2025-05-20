//FormAI DATASET v1.0 Category: File Encyptor ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 100

//Function declarations
void encrypt(char *filename, int key);
void decrypt(char *filename, int key);
void clear_input_buffer();
int get_key();

int main()
{
    int choice, key;
    char filename[MAX_LENGTH];

    while(1)
    {
        printf("----File Encryption/Decryption Program----\n");
        printf("1. Encrypt a File\n");
        printf("2. Decrypt a File\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        //Clear the input buffer
        clear_input_buffer();

        switch(choice)
        {
            case 1:
                printf("Enter the filename to encrypt: ");
                fgets(filename, MAX_LENGTH, stdin);
                filename[strcspn(filename, "\n")] = 0;
                key = get_key();
                encrypt(filename, key);
                printf("File Encryption Successful!\n");
                break;

            case 2:
                printf("Enter the filename to decrypt: ");
                fgets(filename, MAX_LENGTH, stdin);
                filename[strcspn(filename, "\n")] = 0;
                key = get_key();
                decrypt(filename, key);
                printf("File Decryption Successful!\n");
                break;

            case 3:
                printf("Exiting program...");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

//Function to encrypt a file
void encrypt(char *filename, int key)
{
    FILE *fp_read, *fp_write;
    int ch;

    fp_read = fopen(filename, "r");

    if(fp_read == NULL)
    {
        perror("Error opening file for reading");
        exit(1);
    }

    fp_write = fopen(strcat(filename,".enc"), "w");

    if(fp_write == NULL)
    {
        perror("Error opening file for writing");
        fclose(fp_read);
        exit(1);
    }

    //Read from the input file and encrypt the characters using the key
    while((ch = fgetc(fp_read)) != EOF)
    {
        ch = ch + key;
        fputc(ch, fp_write);
    }

    //Close the files
    fclose(fp_read);
    fclose(fp_write);
}

//Function to decrypt a file
void decrypt(char *filename, int key)
{
    FILE *fp_read, *fp_write;
    int ch;

    fp_read = fopen(filename, "r");

    if(fp_read == NULL)
    {
        perror("Error opening file for reading");
        exit(1);
    }

    fp_write = fopen(strcat(filename,".dec"), "w");

    if(fp_write == NULL)
    {
        perror("Error opening file for writing");
        fclose(fp_read);
        exit(1);
    }

    //Read from the input file and decrypt the characters using the key
    while((ch = fgetc(fp_read)) != EOF)
    {
        ch = ch - key;
        fputc(ch, fp_write);
    }

    //Close the files
    fclose(fp_read);
    fclose(fp_write);
}

//Function to clear the input buffer
void clear_input_buffer()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

//Function to get the key from the user
int get_key()
{
    int key;

    printf("Enter the key (0-255): ");
    scanf("%d", &key);

    //Clear the input buffer
    clear_input_buffer();

    if(key < 0 || key > 255)
    {
        printf("Invalid key. Please enter a value between 0 and 255.\n");
        get_key();
    }

    return key;
}