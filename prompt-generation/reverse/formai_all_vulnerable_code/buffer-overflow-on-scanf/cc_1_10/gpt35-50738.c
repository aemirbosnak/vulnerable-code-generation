//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random lowercase letter
char rand_lower() {
    return (rand() % 26) + 'a';
}

// Function to generate a random uppercase letter
char rand_upper() {
    return (rand() % 26) + 'A';
}

// Function to generate a random digit
char rand_digit() {
    return (rand() % 10) + '0';
}

// Function to generate a random special character
char rand_special() {
    char specials[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+', '=', '[', ']', '{', '}', ';', ':', ',', '.', '/', '?'};
    return specials[rand() % 22];
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Prompt the user for desired password length
    int length;
    printf("Please enter the desired password length: ");
    scanf("%d", &length);
    
    // Check for valid password length
    if (length < 8 || length > 16) {
        printf("Error: Password length must be between 8 and 16 characters.\n");
        return 1;
    }
    
    // Determine number of each character type needed for the password
    int num_lower = length / 4;
    int num_upper = length / 4;
    int num_digit = length / 4;
    int num_special = length - num_lower - num_upper - num_digit;
    
    // Generate password
    char password[length+1];
    int i;
    for (i = 0; i < num_lower; i++) {
        password[i] = rand_lower();
    }
    for (i = num_lower; i < num_lower+num_upper; i++) {
        password[i] = rand_upper();
    }
    for (i = num_lower+num_upper; i < num_lower+num_upper+num_digit; i++) {
        password[i] = rand_digit();
    }
    for (i = num_lower+num_upper+num_digit; i < length; i++) {
        password[i] = rand_special();
    }
    password[length] = '\0';
    
    // Shuffle password characters using Fisher-Yates algorithm
    for (i = length-1; i > 0; i--) {
        int j = rand() % (i+1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
    
    // Print password
    printf("Your secure password is: %s\n", password);
    
    return 0;
}