//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random number between min and max */
int generateRandomNumber(int min, int max) {
    int randomNumber = rand() % (max - min + 1) + min;
    return randomNumber;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int length; // Length of the password
    printf("Enter the length of the password: ");
    scanf("%d", &length);

    /* Define the range of characters to use in the password */
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*()_+-=[]{}\\|;:'\",./<>?";

    /* Create an array to hold the chosen characters for the password */
    char password[length + 1];

    /* Choose a random lowercase character for the first character of the password */
    password[0] = lowercase[generateRandomNumber(0, 25)];

    /* Choose a random uppercase character for the second character of the password */
    password[1] = uppercase[generateRandomNumber(0, 25)];

    /* Choose a random number for the third character of the password */
    password[2] = numbers[generateRandomNumber(0, 9)];

    /* Choose a random symbol for the fourth character of the password */
    password[3] = symbols[generateRandomNumber(0, 27)];

    /* Fill the rest of the password with a random selection of characters*/
    for (int i = 4; i < length; i++) {
        int selection = generateRandomNumber(0, 3);
        if (selection == 0) {
            password[i] = lowercase[generateRandomNumber(0, 25)];
        } else if (selection == 1) {
            password[i] = uppercase[generateRandomNumber(0, 25)];
        } else if (selection == 2) {
            password[i] = numbers[generateRandomNumber(0, 9)];
        } else {
            password[i] = symbols[generateRandomNumber(0, 27)];
        }
    }

    /* Add the null terminator to the end of the password */
    password[length] = '\0';

    printf("Your password is: %s", password);

    return 0;
}