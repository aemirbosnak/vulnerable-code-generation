//FormAI DATASET v1.0 Category: File handling ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CRYPTIC_KEY 13   // Arbitrary numerical key

// Function prototypes
void cryptic(char *message);
void decrypt(char *message);

int main()
{
    // File pointers
    FILE *fp_read, *fp_write;
    
    // File name and sizes
    char read_file_name[20], write_file_name[20];
    long int original_size, encrypted_size;
    
    // Message and key variables
    char message[100], encrypted_message[100];
    
    // Prompt the user to enter the name of the file to read from and write to
    printf("Enter the name of the file to read from: ");
    scanf("%s", read_file_name);
    printf("Enter the name of the file to write to: ");
    scanf("%s", write_file_name);
    
    // Open the appropriate files
    fp_read = fopen(read_file_name, "r");
    fp_write = fopen(write_file_name, "w+");
    
    if(fp_read == NULL || fp_write == NULL)
    {
        printf("Error: Unable to open file!");
        exit(1);
    }
    
    // Read the contents of the file into a string
    fseek(fp_read, 0L, SEEK_END);
    original_size = ftell(fp_read);
    fseek(fp_read, 0L, SEEK_SET);
    
    char ch;
    int i = 0;
    
    while((ch = fgetc(fp_read)) != EOF)
    {
        message[i] = ch;
        i++;
    }
    
    message[i++] = '\0';
    
    // Encrypt the message
    cryptic(message);
    strcpy(encrypted_message, message);
    
    // Write the encrypted contents to the file
    fputs(encrypted_message, fp_write);
    
    // Close the files
    fclose(fp_read);
    fclose(fp_write);
    
    // Reopen the file for decryption
    fp_read = fopen(write_file_name, "r");
    
    // Read the encrypted contents into a string
    fseek(fp_read, 0L, SEEK_END);
    encrypted_size = ftell(fp_read);
    fseek(fp_read, 0L, SEEK_SET);
    
    i = 0;
    
    while((ch = fgetc(fp_read)) != EOF)
    {
        message[i] = ch;
        i++;
    }
    
    message[i++] = '\0';
    
    // Decrypt the message
    decrypt(message);
    
    // Display the decrypted message
    printf("Original message: %s\n", message);

    return 0;
}

// Function to encrypt a message using a Caesar cipher
void cryptic(char *message)
{
    int i;
    
    for(i = 0; message[i] != '\0'; i++)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = ((message[i] - 'a') + CRYPTIC_KEY) % 26 + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = ((message[i] - 'A') + CRYPTIC_KEY) % 26 + 'A';
        }
    }
}

// Function to decrypt a message encrypted using a Caesar cipher
void decrypt(char *message)
{
    int i;
    
    for(i = 0; message[i] != '\0'; i++)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = ((message[i] - 'a') - CRYPTIC_KEY + 26) % 26 + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = ((message[i] - 'A') - CRYPTIC_KEY + 26) % 26 + 'A';
        }
    }
}