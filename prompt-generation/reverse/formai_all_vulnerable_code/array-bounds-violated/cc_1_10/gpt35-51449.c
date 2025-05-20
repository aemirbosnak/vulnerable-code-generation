//FormAI DATASET v1.0 Category: File Encyptor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_KEY_LENGTH 256
#define ENCRYPTION_KEY "MySecretKey"

int main()
{
    char filename[MAX_FILENAME_LENGTH];
    char key[MAX_KEY_LENGTH];
    char message[1000];
    char encrypted_message[1000];

    // Get filename from user
    printf("Enter filename: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    if (filename[strlen(filename) - 1] == '\n')
        filename[strlen(filename) - 1] = '\0';

    // Get key from user
    printf("Enter encryption key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    if (key[strlen(key) - 1] == '\n')
        key[strlen(key) - 1] = '\0';

    // Check if key matches
    if (strcmp(key, ENCRYPTION_KEY) != 0)
    {
        printf("Error: Invalid encryption key. Aborting program.\n");
        exit(1);
    }

    // Open file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    // Read message from file
    fgets(message, 1000, fp);

    // Close file
    fclose(fp);

    // Encrypt message
    for (int i = 0; i < strlen(message); i++)
    {
        encrypted_message[i] = message[i] ^ key[i % strlen(key)];
    }

    // Write encrypted message to file
    fp = fopen(filename, "w");
    fprintf(fp, "%s", encrypted_message);
    fclose(fp);

    printf("Encrypted message written to file %s.\n", filename);

    return 0;
}