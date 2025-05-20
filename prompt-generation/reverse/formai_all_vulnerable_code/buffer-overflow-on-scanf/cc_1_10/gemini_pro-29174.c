//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the character sets for the password.
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char digits[] = "0123456789";
char symbols[] = "!@#$%^&*()_+";

// Generate a random integer between min and max.
int rand_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Generate a random character from a given character set.
char rand_char(char *set) {
    return set[rand_int(0, strlen(set) - 1)];
}

// Generate a random password of a given length.
char *generate_password(int length) {
    // Allocate memory for the password.
    char *password = malloc(length + 1);
    if (password == NULL) {
        return NULL;
    }

    // Generate a random character from each character set.
    password[0] = rand_char(lowercase);
    password[1] = rand_char(uppercase);
    password[2] = rand_char(digits);
    password[3] = rand_char(symbols);

    // Generate the remaining characters randomly.
    for (int i = 4; i < length; i++) {
        password[i] = rand_char(lowercase);
    }

    // Terminate the password with a null character.
    password[length] = '\0';

    // Return the password.
    return password;
}

// Print the generated password.
void print_password(char *password) {
    printf("Your new password is: %s\n", password);
}

int main() {
    // Seed the random number generator.
    srand(time(NULL));

    // Get the length of the password from the user.
    int length;
    printf("Enter the length of the password you want: ");
    scanf("%d", &length);

    // Generate a random password.
    char *password = generate_password(length);

    // Print the generated password.
    print_password(password);

    // Free the memory allocated for the password.
    free(password);

    return 0;
}