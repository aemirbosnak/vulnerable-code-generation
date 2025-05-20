//FormAI DATASET v1.0 Category: Encryption ; Style: mind-bending
#include <stdio.h>
#include <string.h>

#define ENCRYPTED_OUTPUT_FILE "encrypted_output.txt"

// Function to encrypt the message
void encrypt(char* message, char* encrypted_message) {
    int key = 3;
    int message_length = strlen(message);
    int i;

    for(i = 0; i < message_length; i++) {
        char character = message[i];
        // Encrypt only uppercase and lowercase English letters
        if((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')) {
            if(character >= 'a' && character <= 'z') {
                character = (((character - 'a') + key) % 26) + 'a';
            }
            else {
                character = (((character - 'A') + key) % 26) + 'A';
            }
        }
        encrypted_message[i] = character;
    }
    encrypted_message[i] = '\0';
}

int main() {
    char message[1000];
    char encrypted_message[1000];
    FILE* file_pointer;

    printf("|------------------- Welcome to the C Encryption program! -------------------|\n");
    printf("Enter the message you want to encrypt: ");
    scanf("%[^\n]", message);

    encrypt(message, encrypted_message);

    printf("Your encrypted message is: %s\n\nWriting encrypted message to file: %s\n", encrypted_message, ENCRYPTED_OUTPUT_FILE);
    
    file_pointer = fopen(ENCRYPTED_OUTPUT_FILE, "w");
    if(file_pointer == NULL) {
        printf("Error opening file!\n");
        return 0;
    }
    fputs(encrypted_message, file_pointer);
    fclose(file_pointer);
    
    printf("\nEncryption successful! The encrypted message is saved in '%s' file.\n", ENCRYPTED_OUTPUT_FILE);
    printf("|------------------------------------------------------------------------------|\n");
    return 0;
}