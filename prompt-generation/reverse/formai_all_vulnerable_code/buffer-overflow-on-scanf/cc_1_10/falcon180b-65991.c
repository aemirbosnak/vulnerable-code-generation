//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 16

// Function to generate a random password
char *generate_password(int length) {
    char *password = (char *)malloc(length + 1);
    if (password == NULL) {
        printf("Error: Unable to allocate memory for password.\n");
        exit(1);
    }
    srand(time(NULL));
    char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+~`|}{[]\:;?><,./-=";
    for (int i = 0; i < length; i++) {
        password[i] = chars[rand() % (sizeof(chars) - 1)];
    }
    password[length] = '\0';
    return password;
}

int main() {
    int password_length = 0;

    // Prompt user for password length
    while (password_length < MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH) {
        printf("Enter password length (between %d and %d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        scanf("%d", &password_length);
        if (password_length < MIN_PASSWORD_LENGTH) {
            printf("Password length must be at least %d characters.\n", MIN_PASSWORD_LENGTH);
        } else if (password_length > MAX_PASSWORD_LENGTH) {
            printf("Password length must be no more than %d characters.\n", MAX_PASSWORD_LENGTH);
        }
    }

    // Generate password
    char *password = generate_password(password_length);
    printf("Generated password: %s\n", password);

    // Prompt user to save password to file
    char file_name[100];
    printf("Do you want to save the password to a file? (y/n) ");
    scanf(" %c", &file_name[0]);
    if (file_name[0] == 'y' || file_name[0] == 'Y') {
        printf("Enter file name: ");
        scanf("%s", file_name);
        FILE *file = fopen(file_name, "w");
        if (file == NULL) {
            printf("Error: Unable to open file '%s' for writing.\n", file_name);
        } else {
            fprintf(file, "%s", password);
            fclose(file);
            printf("Password saved to file '%s'.\n", file_name);
        }
    }

    free(password);
    return 0;
}