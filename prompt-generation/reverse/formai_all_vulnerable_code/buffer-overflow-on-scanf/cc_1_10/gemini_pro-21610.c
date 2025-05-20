//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Function to convert a character to ASCII art
char* char_to_ascii(char ch) {
    // Allocate memory for the ASCII art
    char* ascii = malloc(9 * sizeof(char));

    // Convert the character to ASCII art
    switch (ch) {
        case 'A':
            ascii = "  ___   \n"
                    " / _ \  \n"
                    "| | | | \n"
                    "| |_| | \n"
                    " \___/  ";
            break;
        case 'B':
            ascii = " ____  \n"
                    "| __ ) \n"
                    "|  _ \ \n"
                    "| |_) | \n"
                    "|____/  ";
            break;
        case 'C':
            ascii = "  ___   \n"
                    " / _ \  \n"
                    "| | | | \n"
                    "| |_| | \n"
                    " \__/   ";
            break;
        case 'D':
            ascii = " ____  \n"
                    "| __ ) \n"
                    "|  _ \ \n"
                    "| |_) | \n"
                    "|____/  ";
            break;
        case 'E':
            ascii = " _____  \n"
                    "| ____| \n"
                    "|  _|   \n"
                    "| |___  \n"
                    "|_____| ";
            break;
        case 'F':
            ascii = " _____  \n"
                    "| ____| \n"
                    "|  _|   \n"
                    "| |___  \n"
                    "|_____| ";
            break;
        case 'G':
            ascii = "  ___   \n"
                    " / _ \  \n"
                    "| | | | \n"
                    "| |_| | \n"
                    " \___/   ";
            break;
        case 'H':
            ascii = " ____  \n"
                    "|  _ \ \n"
                    "| |_) | \n"
                    "|  __/  \n"
                    "|_|     ";
            break;
        case 'I':
            ascii = " _____  \n"
                    "| ____| \n"
                    "|  _|   \n"
                    "| |___  \n"
                    "|_____| ";
            break;
        case 'J':
            ascii = " _____  \n"
                    "| ____| \n"
                    "|  _|   \n"
                    "| |___  \n"
                    " \_____| ";
            break;
        case 'K':
            ascii = " ____  \n"
                    "| __ ) \n"
                    "|  _ \ \n"
                    "| |_) | \n"
                    "|____/  ";
            break;
        case 'L':
            ascii = " ____  \n"
                    "|  _ \ \n"
                    "| |_) | \n"
                    "|  __/  \n"
                    "|_|     ";
            break;
        case 'M':
            ascii = " ____  \n"
                    "|  _ \ \n"
                    "| |_) | \n"
                    "|  __/  \n"
                    "|_|     ";
            break;
        case 'N':
            ascii = " ____  \n"
                    "|  _ \ \n"
                    "| |_) | \n"
                    "|  __/  \n"
                    "|_|     ";
            break;
        case 'O':
            ascii = "  ___   \n"
                    " / _ \  \n"
                    "| | | | \n"
                    "| |_| | \n"
                    " \___/   ";
            break;
        case 'P':
            ascii = " _____  \n"
                    "| ____| \n"
                    "|  _|   \n"
                    "| |___  \n"
                    "|_____| ";
            break;
        case 'Q':
            ascii = "  ___   \n"
                    " / _ \  \n"
                    "| | | | \n"
                    "| |_| | \n"
                    " \___/   ";
            break;
        case 'R':
            ascii = " _____  \n"
                    "| ____| \n"
                    "|  _|   \n"
                    "| |___  \n"
                    "|_____| ";
            break;
        case 'S':
            ascii = "  ___   \n"
                    " / _ \  \n"
                    "| | | | \n"
                    "| |_| | \n"
                    " \___/   ";
            break;
        case 'T':
            ascii = " _____  \n"
                    "| ____| \n"
                    "|  _|   \n"
                    "| |___  \n"
                    "|_____| ";
            break;
        case 'U':
            ascii = " ____  \n"
                    "|  _ \ \n"
                    "| |_) | \n"
                    "|  __/  \n"
                    "|_|     ";
            break;
        case 'V':
            ascii = " ____  \n"
                    "|  _ \ \n"
                    "| |_) | \n"
                    "|  __/  \n"
                    "|_|     ";
            break;
        case 'W':
            ascii = " ____  \n"
                    "|  _ \ \n"
                    "| |_) | \n"
                    "|  __/  \n"
                    "|_|     ";
            break;
        case 'X':
            ascii = " ____  \n"
                    "|  _ \ \n"
                    "| |_) | \n"
                    "|  __/  \n"
                    "|_|     ";
            break;
        case 'Y':
            ascii = " ____  \n"
                    "|  _ \ \n"
                    "| |_) | \n"
                    "|  __/  \n"
                    "|_|     ";
            break;
        case 'Z':
            ascii = " ____  \n"
                    "|  _ \ \n"
                    "| |_) | \n"
                    "|  __/  \n"
                    "|_|     ";
            break;
        default:
            ascii = " ";
            break;
    }

    // Return the ASCII art
    return ascii;
}

// Function to print the ASCII art of a string
void print_ascii_art(char* str) {
    // Iterate over the string
    for (int i = 0; i < strlen(str); i++) {
        // Convert the character to ASCII art
        char* ascii = char_to_ascii(str[i]);

        // Print the ASCII art
        printf("%s", ascii);
    }

    // Print a newline character
    printf("\n");
}

// Main function
int main() {
    // Get the input string from the user
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Print the ASCII art of the string
    print_ascii_art(str);

    return 0;
}