//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the character sets for generating passwords
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char digits[] = "0123456789";
char special[] = "!@#$%^&*()-+";

// Function to generate a random number between min and max
int randomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a random character from a given character set
char randomCharacter(char* set) {
    return set[randomNumber(0, strlen(set) - 1)];
}

// Function to generate a random password of a given length
char* generatePassword(int length) {
    // Allocate memory for the password
    char* password = malloc(length + 1);

    // Generate the password
    for (int i = 0; i < length; i++) {
        // Randomly choose a character set and generate a character
        int setIndex = randomNumber(0, 3);
        char* set;
        switch (setIndex) {
            case 0:
                set = lowercase;
                break;
            case 1:
                set = uppercase;
                break;
            case 2:
                set = digits;
                break;
            case 3:
                set = special;
                break;
        }
        password[i] = randomCharacter(set);
    }

    // Terminate the password with a null character
    password[length] = '\0';

    // Return the password
    return password;
}

// Function to print a heart-shaped border around a given string
void printHeartBorder(char* string) {
    // Get the length of the string
    int length = strlen(string);

    // Print the top half of the heart
    printf("   *         *    \n");
    printf("  .**        **.    \n");
    printf(" .*         *.     \n");
    printf("/          . \\  \n");
    printf("*********  () *********\n");

    // Print the string centered within the heart
    printf("*          %s          *    \n", string);

    // Print the bottom half of the heart
    printf(" \\         . /     \n");
    printf("  `.       .'  \n");
    printf("    `-.___.-'    \n");
    printf("      || ||        \n");
    printf("      || ||        \n");
    printf("      || ||        \n");
    printf("    =='   `==    \n");
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the desired password length from the user
    int length;
    printf("My dearest, how many characters should our secret password be? ");
    scanf("%d", &length);

    // Generate a random password
    char* password = generatePassword(length);

    // Print the password within a heart-shaped border
    printHeartBorder(password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}