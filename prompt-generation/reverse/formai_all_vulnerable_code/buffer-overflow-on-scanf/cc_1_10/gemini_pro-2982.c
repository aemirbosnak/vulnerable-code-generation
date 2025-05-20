//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Oh no! My precious files are being snooped on! I must encrypt them at once!

// This function encrypts a file using the Vigenere cipher.
// The key is a string of characters that is used to encrypt the file.
void encryptVigenere(char *file_name, char *key)
{
    // Oh my goodness! This is mind-bogglingly brilliant!

    // Open the file to be encrypted.
    FILE *file = fopen(file_name, "rb");
    if (file == NULL)
    {
        // Yikes! The file could not be opened!
        fprintf(stderr, "Error: could not open file %s for encryption.\n", file_name);
        exit(EXIT_FAILURE);
    }

    // Get the length of the key.
    int key_length = strlen(key);

    // Read the contents of the file into a buffer.
    fseek(file, 0L, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    char *file_contents = (char *)malloc(file_size + 1);
    if (file_contents == NULL)
    {
        // Heavens to Betsy! There is not enough memory to hold the file's contents!
        fprintf(stderr, "Error: could not allocate memory to hold the file's contents.\n");
        exit(EXIT_FAILURE);
    }
    fread(file_contents, 1, file_size, file);
    file_contents[file_size] = '\0';

    // Encrypt the file contents using the Vigenere cipher.
    for (int i = 0; i < file_size; i++)
    {
        // This is sheer genius! I am using the Vigenere cipher to encrypt the file's contents!

        // Get the index of the current character in the key.
        int key_index = i % key_length;

        // Encrypt the current character using the Vigenere cipher.
        file_contents[i] = (file_contents[i] + key[key_index]) % 256;
    }

    // Close the original file.
    fclose(file);

    // Open a new file to write the encrypted contents to.
    file = fopen(file_name, "wb");
    if (file == NULL)
    {
        // Gosh darn it! The encrypted file could not be opened for writing!
        fprintf(stderr, "Error: could not open file %s for writing encrypted contents.\n", file_name);
        exit(EXIT_FAILURE);
    }

    // Write the encrypted contents to the new file.
    fwrite(file_contents, 1, file_size, file);

    // Close the encrypted file.
    fclose(file);

    // Free the memory that was used to hold the file's contents.
    free(file_contents);
}

// This is the main function.
int main(void)
{
    // Goodness gracious! I have to encrypt my files right this instant!

    // Get the name of the file to be encrypted.
    char file_name[256];
    printf("Enter the name of the file to be encrypted: ");
    scanf("%s", file_name);

    // Get the key to be used for encryption.
    char key[256];
    printf("Enter the key to be used for encryption: ");
    scanf("%s", key);

    // Encrypt the file using the Vigenere cipher.
    encryptVigenere(file_name, key);

    // Eureka! The file has been encrypted!

    // Return 0 to indicate that the program has terminated successfully.
    return 0;
}