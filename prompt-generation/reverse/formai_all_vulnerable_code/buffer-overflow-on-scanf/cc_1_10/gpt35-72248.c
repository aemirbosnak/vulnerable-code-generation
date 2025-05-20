//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16

// Function for generating a random integer between min and max (inclusive)
int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function for generating a random uppercase letter
char random_uppercase() {
    return (char) random_number(65, 90);
}

// Function for generating a random lowercase letter
char random_lowercase() {
    return (char) random_number(97, 122);
}

// Function for generating a random digit
char random_digit() {
    return (char) random_number(48, 57);
}

// Function for generating a random special character
char random_special() {
    char special_chars[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '='};
    int index = random_number(0, 13);
    return special_chars[index];
}

// Function for generating a random character (from any category)
char random_character() {
    int category = random_number(1, 4); // 1 = uppercase, 2 = lowercase, 3 = digit, 4 = special
    switch (category) {
        case 1:
            return random_uppercase();
        case 2:
            return random_lowercase();
        case 3:
            return random_digit();
        case 4:
            return random_special();
    }
}

// Function for generating a random password of length n
void generate_password(char* password, int n) {
    int i;
    for (i = 0; i < n; i++) {
        password[i] = random_character();
    }
    password[n] = '\0';
}

int main() {
    
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Get the desired length of the password from the user
    int length;
    printf("Enter the desired length of your password (between %d and %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);
    
    // Validate the length of the password (must be between MIN_LENGTH and MAX_LENGTH)
    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid password length. Please enter a number between %d and %d.\n", MIN_LENGTH, MAX_LENGTH);
        return 0;
    }
    
    // Generate the password and print it to the screen
    char password[length + 1];
    generate_password(password, length);
    printf("Your random password is: %s\n", password);
    
    return 0;
}