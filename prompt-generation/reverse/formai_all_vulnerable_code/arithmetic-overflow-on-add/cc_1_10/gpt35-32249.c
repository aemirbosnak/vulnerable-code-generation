//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char generateRandomChar() {
    int option = rand() % 3; // choose a random option to generate a random character
    switch(option) {
        case 0:
            return 'a' + rand() % 26; // generate a lower case alphabet
        case 1:
            return 'A' + rand() % 26; // generate an upper case alphabet
        case 2:
            return '0' + rand() % 10; // generate a digit
        default:
            return 'x'; // this should never happen
    }
}

char* generateSecurePassword(int length) {
    // allocate memory for the password
    char* password = (char*) malloc((length + 1) * sizeof(char)); // add 1 for the null terminator
    
    // generate a random password
    for(int i = 0; i < length; i++) {
        password[i] = generateRandomChar();
    }
    password[length] = '\0'; // add the null terminator
    
    // return the password
    return password;
}

int main() {
    // seed the random number generator
    srand(time(NULL));
    
    // get the desired password length from the user
    int length;
    printf("Enter the desired length of the secure password: ");
    scanf("%d", &length);
    
    // generate a secure password
    char* password = generateSecurePassword(length);
    
    // print the secure password
    printf("Your secure password is: %s\n", password);
    
    // free the memory allocated for the password
    free(password);
    
    return 0;
}