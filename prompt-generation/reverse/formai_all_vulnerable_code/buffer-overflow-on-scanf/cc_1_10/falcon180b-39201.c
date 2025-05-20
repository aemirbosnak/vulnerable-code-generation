//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 32
#define MIN_PASSWORD_LENGTH 8
#define PASSWORD_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
#define PASSWORD_CHARS_LENGTH strlen(PASSWORD_CHARS)

int main() {
    int password_length = 0;
    char password[MAX_PASSWORD_LENGTH] = {0};
    char *chars = (char *)malloc(sizeof(char) * MAX_PASSWORD_LENGTH);
    srand(time(NULL));

    // Prompt the user for the desired password length
    printf("Enter the desired password length (between %d and %d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &password_length);

    // Ensure the password length is within the allowed range
    if (password_length < MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH) {
        printf("Invalid password length. Please enter a value between %d and %d.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        return 1;
    }

    // Generate the password
    for (int i = 0; i < password_length; i++) {
        int random_index = rand() % PASSWORD_CHARS_LENGTH;
        password[i] = PASSWORD_CHARS[random_index];
        chars[i] = PASSWORD_CHARS[random_index];
    }

    // Print the generated password
    printf("Generated password: %s\n", password);

    // Prompt the user if they want to save the password to a file
    printf("Do you want to save the password to a file? (y/n): ");
    char save_choice;
    scanf(" %c", &save_choice);

    if (save_choice == 'y' || save_choice == 'Y') {
        printf("Enter the file name: ");
        char file_name[100];
        scanf("%s", file_name);

        // Open the file for writing
        FILE *file = fopen(file_name, "w");
        if (file == NULL) {
            printf("Error opening file. Please try again.\n");
            return 1;
        }

        // Write the password to the file
        fprintf(file, "Password: %s\n", password);

        // Close the file
        fclose(file);
        printf("Password saved to file %s.\n", file_name);
    }

    free(chars);
    return 0;
}