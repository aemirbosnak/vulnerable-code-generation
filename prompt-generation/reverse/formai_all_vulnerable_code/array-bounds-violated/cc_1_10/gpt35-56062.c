//FormAI DATASET v1.0 Category: Encryption ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the key used to encrypt the message
#define KEY 8

// Define the size of the message buffer
#define MAX_MESSAGE_SIZE 1000

// Define the character set used to encrypt the message
static const char charset[] =
    "abcdefghijklmnopqrstuvwxyz"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "0123456789";

// Function to encrypt the message using the key and character set
void encrypt(char *message)
{
    int i, j;
    int message_length = strlen(message);

    // Generate a random seed based on the current time
    srand(time(NULL));

    // Loop through each character in the message
    for (i = 0; i < message_length; i++)
    {
        // Find the index of the current character in the character set
        int current_index = strchr(charset, message[i]) - charset;

        // Generate a random offset based on the key
        int offset = rand() % KEY;

        // Add the offset to the index of the character in the character set
        int encrypted_index = (current_index + offset) % strlen(charset);

        // Replace the current character with the encrypted character
        message[i] = charset[encrypted_index];

        // Randomly insert a random character from the character set at
        // a random position in the message
        for (j = 0; j < offset; j++)
        {
            int random_character_index = rand() % strlen(charset);
            int random_position = rand() % message_length;
            memmove(message + random_position + 1, message + random_position, strlen(message) - random_position + 1);
            message[random_position] = charset[random_character_index];
            message_length++;
        }
    }
}

int main()
{
    char message[MAX_MESSAGE_SIZE];

    // Get the message from the user
    printf("Enter the message to encrypt: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    // Remove the newline character from the end of the message (added by fgets)
    if (message[strlen(message) - 1] == '\n')
    {
        message[strlen(message) - 1] = '\0';
    }

    // Encrypt the message
    encrypt(message);

    // Display the encrypted message
    printf("Encrypted message: %s\n", message);

    return 0;
}