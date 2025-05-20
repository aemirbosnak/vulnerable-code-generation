//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: innovative
/*
 * Text to ASCII Art Generator
 *
 * This program takes user input text and converts it to ASCII art.
 * The ASCII art generated is a combination of letters, numbers, and symbols.
 * The program uses the following ASCII art fonts:
 * - small
 * - medium
 * - small slant
 * - smshadow
 * - banner3-D
 *
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <string.h>

// Function prototypes
void printSmall(char letter);
void printMedium(char letter);
void printSmallSlant(char letter);
void printSmShadow(char letter);
void printBanner3D(char letter);

int main() {
    char text[100];
    int length;
    int i;

    // Get user input
    printf("Enter text to convert to ASCII art: ");
    fgets(text, sizeof(text), stdin);

    // Remove newline character from input
    length = strlen(text);
    if (text[length - 1] == '\n') {
        text[length - 1] = '\0';
    }

    // Iterate over each character in input and print
    for (i = 0; i < length; i++) {
        char letter = text[i];
        printf("\n");

        // Determine which ASCII art font to use based on character
        if (letter >= 'A' && letter <= 'Z') {
            printSmall(letter);
            printMedium(letter);
            printSmallSlant(letter);
            printSmShadow(letter);
            printBanner3D(letter);
        } else if (letter >= 'a' && letter <= 'z') {
            letter = letter - 'a' + 'A';
            printSmall(letter);
            printMedium(letter);
            printSmallSlant(letter);
            printSmShadow(letter);
            printBanner3D(letter);
        } else if (letter >= '0' && letter <= '9') {
            printSmall(letter);
            printMedium(letter);
            printSmallSlant(letter);
            printSmShadow(letter);
            printBanner3D(letter);
        } else if (letter == ' ') {
            printf("\n\n\n\n\n");  // add extra newlines for space character
        } else {
            printf(" ");  // print space for any other characters not supported
        }
    }

    return 0;
}

// Small ASCII art font
void printSmall(char letter) {
    switch (letter) {
        case 'A':
            printf("  __\n /_/\n \\ \\ \n  \\_\\\n");
            break;
        case 'B':
            printf("|---\\\n|___/\n|---\\\n|___/\n");
            break;
        // add more cases for other letters
    }
}

// Medium ASCII art font
void printMedium(char letter) {
    switch (letter) {
        case 'A':
            printf(" /\\ \n/__\\ \n/    \\\n\\    /\n \\/\\/ \n");
            break;
        case 'B':
            printf("|----\n|__--\n|----\n|__--\n");
            break;
        // add more cases for other letters
    }
}

// Small Slant ASCII art font
void printSmallSlant(char letter) {
    switch (letter) {
        case 'A':
            printf("  /\\\n /  \\ \n/___\\\n");
            break;
        case 'B':
            printf("\\--->\n|---/\n|---\\\n\\___/\n");
            break;
        // add more cases for other letters
    }
}

// SmShadow ASCII art font
void printSmShadow(char letter) {
    switch (letter) {
        case 'A':
            printf("  __\n /_/\\_\n/ / /\\\n\\_\\/_/\n");
            break;
        case 'B':
            printf("\\---->\n|---/\n|---\\\n\\---/\n");
            break;
        // add more cases for other letters
    }
}

// 3D Banner ASCII art font
void printBanner3D(char letter) {
    switch (letter) {
        case 'A':
            printf("  ___,---.___\n /____________\\\n[|_|_|_|_|_|_|]     \n   O   |   O   \n");
            break;
        case 'B':
            printf("[[[[[[[[[[[[[[[[[\n|||||]__--__| ||]\n\\____\\______/__/ \n");
            break;
        // add more cases for other letters
    }
}