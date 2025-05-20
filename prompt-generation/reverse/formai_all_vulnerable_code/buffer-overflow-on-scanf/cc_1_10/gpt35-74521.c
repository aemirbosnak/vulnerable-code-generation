//FormAI DATASET v1.0 Category: Password management ; Style: Romeo and Juliet
// Scene: The Password Keeper

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a string using Caesar Cipher method
char *encrypt(char *text, int shift) {
    int length = strlen(text);
    char *encrypted = malloc(length + 1); // Allocate memory for the encrypted string
    strcpy(encrypted, text); // Copy the original string to encrypted string
    for (int i = 0; i < length; i++) {
        int ascii = (int) encrypted[i]; // Get ASCII value of the current character
        // Handle uppercase letters
        if (ascii >= 65 && ascii <= 90) {
            ascii = ((ascii + shift - 65) % 26) + 65;
        }
        // Handle lowercase letters
        else if (ascii >= 97 && ascii <= 122) {
            ascii = ((ascii + shift - 97) % 26) + 97;
        }
        encrypted[i] = (char) ascii; // Convert ASCII value back to character
    }
    return encrypted;
}

// Function to decrypt a string using Caesar Cipher method
char *decrypt(char *text, int shift) {
    return encrypt(text, 26 - shift); // Decrypting is just reversing the shift
}

int main() {
    // Enter the password
    printf("Enter your password: ");
    char password[50];
    scanf("%s", password);

    // Encrypt the password with Caesar Cipher
    char *encrypted_password = encrypt(password, 3);

    // Save the encrypted password to a file
    FILE *file = fopen("passwords.txt", "a"); // Opening the file in append mode
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(file, "%s\n", encrypted_password);
    fclose(file); // Close the file

    // Show confirmation message
    printf("Your password has been saved!\n");

    // User wants to retrieve a password
    printf("Do you want to retrieve a password? (Y/N) ");
    char answer[2];
    scanf("%s", answer);
    if (strcmp(answer, "Y") == 0) {
        // Open the passwords file
        FILE *file = fopen("passwords.txt", "r");
        if (file == NULL) {
            printf("Error opening file!\n");
            return 1;
        }

        // Display the list of all passwords
        printf("Here are all the saved passwords:\n");
        char line[50];
        while (fgets(line, sizeof(line), file)) {
            printf("%s", decrypt(line, 3));
        }
        fclose(file); // Close the file
    }
    else {
        printf("Goodbye!\n");
    }
    return 0;
}