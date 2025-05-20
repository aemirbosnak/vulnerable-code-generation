//FormAI DATASET v1.0 Category: String manipulation ; Style: creative
#include <stdio.h>
#include <string.h>

// This program generates a unique password based on user input
// The password is created by manipulating the original string input by the user
// The final output password is a combination of upper and lower case letters, numbers and special characters

int main() {
    char inputString[100]; 
    char password[100] = "";
    int length, n;

    printf("Enter a string: ");
    scanf("%s", inputString);
    length = strlen(inputString);
    printf("Original string: %s\n", inputString);

    // The following code block manipulates the original input string
    for (int i = 0; i < length; i++) {
        if (inputString[i] >= 'a' && inputString[i] <= 'z') {
            password[i] = inputString[i] - 32; // converts lower case letters to upper case
        } else if (inputString[i] >= 'A' && inputString[i] <= 'Z') {
            password[i] = inputString[i] + 32; // converts upper case letters to lower case
        } else {
            password[i] = inputString[i];
        }
    }

    // The following code block adds random numbers and special characters to the password
    for (int i = length; i < 15; i++) {
        n = rand() % 3; // generate random number between 0 and 2
        switch(n) {
            case 0:
                password[i] = rand() % 10 + 48; // add random number (0-9)
                break;
            case 1:
                password[i] = rand() % 26 + 65; // add random upper case letter
                break;
            case 2:
                password[i] = rand() % 15 + 33; // add random special character
                break;
        }
    }

    password[15] = '\0'; // add null terminator to properly end the string

    printf("Generated Password: %s\n", password);

    return 0;
}