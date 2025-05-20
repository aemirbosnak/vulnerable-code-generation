//FormAI DATASET v1.0 Category: Password management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *encrypt(char *password, int key);
char *decrypt(char *password, int key);

int main() {
    FILE *file;
    char password[50];
    char *encryptedPassword, *decryptedPassword;
    int key;

    // Open the file for writing
    file = fopen("passwords.txt", "w");

    // Get the user input for the password and key
    printf("Enter the password you would like to store: ");
    scanf("%s", password);
    printf("Enter a key to encrypt your password: ");
    scanf("%d", &key);

    // Encrypt the password
    encryptedPassword = encrypt(password, key);

    // Write the encrypted password to the file
    fprintf(file, "%s\n", encryptedPassword);

    // Close the file
    fclose(file);

    // Reopen the file for reading
    file = fopen("passwords.txt", "r");

    // Read the encrypted password from the file
    fscanf(file, "%s", password);

    // Decrypt the password
    decryptedPassword = decrypt(password, key);

    // Print out the decrypted password
    printf("Your password is: %s", decryptedPassword);

    // Close the file
    fclose(file);

    return 0;
}

char *encrypt(char *password, int key) {
    char *encrypted = malloc(strlen(password) + 1);
    int i;

    // Loop through each character in the input string
    for (i = 0; i < strlen(password); i++) {
        // Shift the character by the key value
        encrypted[i] = toupper(password[i] + key);
    }

    // Add a null terminator
    encrypted[i] = '\0';

    return encrypted;
}

char *decrypt(char *password, int key) {
    char *decrypted = malloc(strlen(password) + 1);
    int i;

    // Loop through each character in the input string
    for (i = 0; i < strlen(password); i++) {
        // Shift the character back by the key value
        decrypted[i] = tolower(password[i] - key);
    }

    // Add a null terminator
    decrypted[i] = '\0';

    return decrypted;
}