//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: future-proof
#include <stdio.h>
#include <string.h>

// Function to translate input in Alien Language to English Language
void translateToEnglish(char input[]){
    // Declare variables
    int currentIndex = 0;
    int len = strlen(input);
    char output[50] = "";

    // Loop through the entire string until we've read all characters
    while (currentIndex < len) {
        char currentChar = input[currentIndex];

        // Handle special cases
        if (currentChar == '0') {
            strcat(output, "a");
        }
        else if (currentChar == '1') {
            strcat(output, "e");
        }
        else if (currentChar == '2') {
            strcat(output, "i");
        }
        else if (currentChar == '3') {
            strcat(output, "o");
        }
        else if (currentChar == '4') {
            strcat(output, "u");
        }
        // Handle regular case
        else {
            sprintf(output, "%s%c", output, currentChar);
        }

        currentIndex++;
    }

    // Print the translated output
    printf("Alien Language: %s\n", input);
    printf("English Translation: %s\n", output);
}

int main() {
    char input[50];

    printf("Please enter the Alien Language code to be translated to English Language: ");
    scanf("%s", input);

    translateToEnglish(input);

    return 0;
}