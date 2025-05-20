//FormAI DATASET v1.0 Category: File Encyptor ; Style: relaxed
#include <stdio.h>
#include <string.h>

#define KEY_LEN 16 // define key length
#define MAX_LEN 1000 // define maximum length of the file

// Function to encrypt the file
void encrypt(char *file_name, char key[])
{
    FILE *file;
    char buffer[MAX_LEN];
    int i, j = 0, len;
    
    file = fopen(file_name, "r+"); // open file in read mode
    
    if (file == NULL) // check if file is empty
    {
        printf("Error opening file!\n");
        return;
    }
    
    len = strlen(key); // get the length of key
    
    while (fgets(buffer, sizeof(buffer), file))
    {
        for (i = 0; i < strlen(buffer); i++)
        {
            buffer[i] = buffer[i] ^ key[j]; // XOR operation
            j++;
            if (j == len)
            {
                j = 0;
            }
        }
        fseek(file, -strlen(buffer), SEEK_CUR);
        fputs(buffer, file); // write encrypted data to file
    }
    fclose(file); // close file
}

// Function to decrypt the file
void decrypt(char *file_name, char key[])
{
    encrypt(file_name, key); // reuse encrypt function to decrypt
}

// Main function
int main()
{
    char file_name[50], key[KEY_LEN];
    int choice;
    
    printf("\nEnter file name: ");
    fgets(file_name, 50, stdin); // get input from user
    
    file_name[strcspn(file_name, "\n")] = 0; // remove the newline character
    
    printf("\nEnter key: ");
    fgets(key, KEY_LEN, stdin);
    
    key[strcspn(key, "\n")] = 0;
    
    printf("\n1 - Encrypt file\n2 - Decrypt file\nEnter choice: ");
    scanf("%d", &choice);
    
    if (choice == 1)
        encrypt(file_name, key);
    else if (choice == 2)
        decrypt(file_name, key);
    else
        printf("\nInvalid choice!\n");
    
    return 0;
}