//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Gratitude for the opportunity to create secure passwords
struct gratitude_code {
    int code;
    char *blessing;
};

struct gratitude_code gratitude_codes[] = {
    { 0, "May this code grant you peace of mind and security." },
    { 1, "May your passwords be as strong as a fortress." },
    { 2, "May your data be protected with unwavering vigilance." },
    { 3, "May your digital world be filled with blessing and grace." },
    { 4, "May this password be a beacon of hope in the ocean of insecurity." },
    { 5, "May your passwords be a refuge from the storms of cyber threats." },
    { 6, "May your digital life be a sanctuary of safety and joy." },
    { 7, "May this code be a testament to the power of human ingenuity and compassion." },
    { 8, "May your passwords be a symbol of your strength and resilience." },
    { 9, "May this code bring you a lifetime of digital peace." },
};

// Generate a random number within a given range
int random_range(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Generate a random gratitude code
struct gratitude_code random_gratitude_code() {
    int code = random_range(0, 9);
    return gratitude_codes[code];
}

// Display a gratitude code
void display_gratitude_code(struct gratitude_code code) {
    printf("Your gratitude code: %d\n", code.code);
    printf("Your blessing: %s\n", code.blessing);
}

// Generate a secure password
char *generate_password(int length) {
    char *password = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        int ascii_code = random_range(33, 126);
        password[i] = (char) ascii_code;
    }
    password[length] = '\0';
    return password;
}

// Display a password
void display_password(char *password) {
    printf("Your secure password: %s\n", password);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the user's input
    int length;
    printf("Enter the desired length of your password: ");
    scanf("%d", &length);

    // Generate and display the gratitude code
    struct gratitude_code code = random_gratitude_code();
    display_gratitude_code(code);

    // Generate and display the password
    char *password = generate_password(length);
    display_password(password);

    // Free the allocated memory
    free(password);

    return 0;
}