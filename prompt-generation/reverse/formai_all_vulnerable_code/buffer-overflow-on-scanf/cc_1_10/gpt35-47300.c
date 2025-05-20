//FormAI DATASET v1.0 Category: File Encyptor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

char* encrypt(char* plaintext, int key);
char* decrypt(char* ciphertext, int key);

int main()
{
    char filename[MAX_BUFFER_SIZE];
    int key;

    printf("Enter the name of the file to encrypt: ");
    scanf("%s", filename);

    printf("Enter a key value to encrypt the file: ");
    scanf("%d", &key);

    FILE *file_ptr = fopen(filename, "r");
    if(file_ptr == NULL)
    {
        printf("Could not open file %s", filename);
        return 1;
    }

    char buffer[MAX_BUFFER_SIZE];
    char* encrypted_buffer;
    size_t bytes_read = 0;

    while((bytes_read = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, file_ptr)) > 0)
    {
        // Encrypt the buffer
        encrypted_buffer = encrypt(buffer, key);

        // Write the encrypted buffer to the file
        fwrite(encrypted_buffer, sizeof(char), bytes_read, file_ptr);

        free(encrypted_buffer);
    }

    fclose(file_ptr);

    printf("\nThe file %s has been encrypted with key value %d.\n\n", filename, key);

    return 0;
}

char* encrypt(char* plaintext, int key)
{
    int length = strlen(plaintext);

    // Allocate space for the encrypted buffer
    char* encrypted_buffer = (char*)malloc(length + 1);

    for(int i = 0; i < length; i++)
    {
        encrypted_buffer[i] = plaintext[i] + key;
    }

    encrypted_buffer[length] = '\0';

    return encrypted_buffer;
}

char* decrypt(char* ciphertext, int key)
{
    int length = strlen(ciphertext);

    // Allocate space for the decrypted buffer
    char* decrypted_buffer = (char*)malloc(length + 1);

    for(int i = 0; i < length; i++)
    {
        decrypted_buffer[i] = ciphertext[i] - key;
    }

    decrypted_buffer[length] = '\0';

    return decrypted_buffer;
}