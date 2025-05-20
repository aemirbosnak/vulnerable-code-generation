//FormAI DATASET v1.0 Category: Image Steganography ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAX_FILENAME_SIZE 100
#define MAX_USERNAME_SIZE 50
#define MAX_MSG_LENGTH 500

void hideMessageInImage(char *filename, char *username, char *message);
void revealMessageFromImage(char *filename, char *username);

int main()
{
    char filename[MAX_FILENAME_SIZE];
    char username[MAX_USERNAME_SIZE];
    char message[MAX_MSG_LENGTH];

    printf("Enter the filename (including extension): ");
    scanf("%s", filename);

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter the message to hide: ");
    getchar(); // Clear buffer
    fgets(message, MAX_MSG_LENGTH, stdin);

    hideMessageInImage(filename, username, message);

    printf("Message hidden in image successfully!\n");

    printf("Do you want to reveal the hidden message? (Y/N)");
    char ans = getchar();
    if (ans == 'Y' || ans == 'y')
    {
        revealMessageFromImage(filename, username);
    }

    return 0;
}

void hideMessageInImage(char *filename, char *username, char *message)
{
    FILE *fp = fopen(filename, "ab+");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    // Hide username length
    char len = strlen(username);
    fwrite(&len, sizeof(char), 1, fp);

    // Hide username
    for (int i = 0; i < len; i++)
    {
        char ch = username[i];
        ch ^= 0xFF; // XOR operation
        fwrite(&ch, sizeof(char), 1, fp);
    }

    // Hide message
    int len_msg = strlen(message);
    for (int i = 0; i < len_msg; i++)
    {
        char ch = message[i];
        ch ^= 0xFF;
        fwrite(&ch, sizeof(char), 1, fp);
    }

    fclose(fp);
}

void revealMessageFromImage(char *filename, char *username)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    // Read username length
    char len;
    fread(&len, sizeof(char), 1, fp);

    // Read username
    char username_in_file[MAX_USERNAME_SIZE];
    fread(username_in_file, sizeof(char), len, fp);
    for (int i = 0; i < len; i++)
    {
        username_in_file[i] ^= 0xFF;
    }

    // Read message
    char message[MAX_MSG_LENGTH];
    int len_msg = 0;
    while (fread(&message[len_msg], sizeof(char), 1, fp) == 1)
    {
        message[len_msg] ^= 0xFF;
        len_msg++;
    }

    fclose(fp);

    // Check if username matches
    if (strcmp(username, username_in_file) != 0)
    {
        printf("Username does not match!\n");
        return;
    }

    // Print message
    printf("The hidden message is: %s\n", message);
}