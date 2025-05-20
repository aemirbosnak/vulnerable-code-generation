//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Fortress of Digital Resilience
// In this post-apocalyptic world, we arm ourselves with unbreakable passwords.

// Function to generate a secure password
void generate_password(char *password, int length) {
    const char *characters = "abcdefghijklmnopqrstuvwxyz"
                             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                             "0123456789"
                             "!@#$%^&*()-_=+<>?";
    int num_characters = strlen(characters);
    
    for (int i = 0; i < length; i++) {
        int index = rand() % num_characters; // Get random index
        password[i] = characters[index]; // Populate password
    }
    password[length] = '\0'; // Null-terminate the string
}

// Function to gather user input
void get_user_input(int *length) {
    printf("Welcome, Survivor! In these dark times, your digital refuge is paramount.\n");
    printf("Please enter the length of your desired password (minimum 8 characters): ");
    scanf("%d", length);
    
    // Input validation
    while (*length < 8) {
        printf("Weak passwords lead to swift defeats. Choose a length of at least 8: ");
        scanf("%d", length);
    }
}

// Function to print the password generation details
void print_password_info(const char *password, int length) {
    printf("\nGenerating your secure password...\n");
    printf("Safehouse Password: %s\n", password);
    printf("Remember, even in a world gone mad, strength lies in security.\n");
    printf("Use this password wisely, fellow survivor.\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    int length;
    char *password;

    // Gather user input
    get_user_input(&length);

    // Allocate memory for the password
    password = (char *)malloc((length + 1) * sizeof(char));
    if (password == NULL) {
        fprintf(stderr, "Failed to allocate memory for the password. A dark omen indeed.\n");
        return 1;
    }

    // Generate the password
    generate_password(password, length);
    
    // Print the password and its information
    print_password_info(password, length);

    // Clean up
    free(password);
    return 0;
}