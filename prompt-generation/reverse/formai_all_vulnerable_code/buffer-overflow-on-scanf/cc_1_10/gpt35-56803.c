//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers
int randomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate uppercase letters
char randomUpper() {
    return (char)randomNumber(65, 90);
}

// Function to generate lowercase letters
char randomLower() {
    return (char)randomNumber(97, 122);
}

// Function to generate special characters
char randomSpecial() {
    char specials[10] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')'};
    return specials[randomNumber(0, 9)];
}

// Function to generate secure password
void generatePassword(int length) {
    int i, random;
    char password[length];
    srand(time(NULL));
    
    for(i = 0; i < length; i++) {
        random = randomNumber(1, 3);
        if(random == 1) {
            password[i] = randomUpper();
        } else if(random == 2) {
            password[i] = randomLower();
        } else {
            password[i] = randomSpecial();
        }
    }
    
    printf("Your secure password is: %s", password);
}

// Main function to call generatePassword() function
int main() {
    int length;
    printf("Enter the length of your password (minimum 8 characters): ");
    scanf("%d", &length);
    
    while(length < 8) {
        printf("Password length must be minimum 8 characters. Try again: ");
        scanf("%d", &length);
    }
    
    generatePassword(length);
    return 0;
}