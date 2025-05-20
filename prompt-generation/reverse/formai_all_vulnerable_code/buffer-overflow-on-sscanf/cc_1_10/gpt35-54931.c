//FormAI DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 50
#define MAX_BUFFER 1024

// Function to check if password is strong
int is_strong_password(char *password) {
    int upper = 0, lower = 0, digit = 0, special = 0;

    // Iterate through characters in password
    for(int i = 0; i < strlen(password); i++) {
        if(isupper(password[i]))
            upper++;
        else if(islower(password[i]))
            lower++;
        else if(isdigit(password[i]))
            digit++;
        else
            special++;
    }

    // Check if password meets criteria for strong password
    if(strlen(password) >= 8 && upper > 0 && lower > 0 && digit > 0 && special > 0)
        return 1;
    else
        return 0;
}

// Function to encrypt password
void encrypt_password(char *password, char *encrypted_password) {
    int sum = 0, ascii_value;

    // Calculate sum of ASCII values of password characters
    for(int i = 0; i < strlen(password); i++)
        sum += password[i];

    // Add sum to ASCII value of each character in password to create encrypted password
    for(int i = 0; i < strlen(password); i++) {
        ascii_value = password[i] + sum;
        if(ascii_value > 127)
            ascii_value = 32 + (ascii_value % 127);
        encrypted_password[i] = (char) ascii_value;
    }
}

// Function to decrypt password
void decrypt_password(char *encrypted_password, char *decrypted_password) {
    int sum = 0, ascii_value;

    // Calculate sum of ASCII values of encrypted password characters
    for(int i = 0; i < strlen(encrypted_password); i++)
        sum += encrypted_password[i];

    // Subtract sum from ASCII value of each character in encrypted password to create decrypted password
    for(int i = 0; i < strlen(encrypted_password); i++) {
        ascii_value = encrypted_password[i] - sum;
        if(ascii_value < 32)
            ascii_value = 127 - (32 - ascii_value);
        decrypted_password[i] = (char) ascii_value;
    }
}

int main() {
    char password[MAX_LEN], encrypted_password[MAX_LEN], decrypted_password[MAX_LEN];
    FILE *fp;
    char buffer[MAX_BUFFER];

    // Get password from user
    printf("Enter a password: ");
    fgets(password, MAX_LEN, stdin);
    password[strcspn(password, "\n")] = 0;

    // Check if password is strong
    if(!is_strong_password(password)) {
        printf("Password must be at least 8 characters long and contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
        exit(1);
    }

    // Encrypt password and write to file
    encrypt_password(password, encrypted_password);
    fp = fopen("password.txt", "w");
    fprintf(fp, "%s", encrypted_password);
    fclose(fp);

    // Read encrypted password from file and decrypt
    fp = fopen("password.txt", "r");
    fgets(buffer, MAX_BUFFER, fp);
    fclose(fp);
    sscanf(buffer, "%s", encrypted_password);

    decrypt_password(encrypted_password, decrypted_password);

    printf("Original password: %s\n", password);
    printf("Encrypted password: %s\n", encrypted_password);
    printf("Decrypted password: %s\n", decrypted_password);

    return 0;
}