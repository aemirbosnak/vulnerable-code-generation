//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototypes for helper functions
char *morse(char ch);
char *str_to_morse(char *str);

int main(void)
{
    // Variables to hold user input and Morse code string
    char input[100];
    char *output;

    // Prompt user for input string
    printf("Enter a string to convert to Morse code: ");
    fgets(input, sizeof(input), stdin);

    // Remove trailing newline character from input string
    input[strcspn(input, "\n")] = '\0';

    // Convert input string to Morse code and store in output
    output = str_to_morse(input);

    // Print the Morse code string
    printf("Morse code: %s\n", output);

    // Free the memory allocated for the Morse code string
    free(output);

    return 0;
}

// Helper function to convert individual characters to Morse code
char *morse(char ch)
{
    switch(ch)
    {
        case 'a': return ".-";
        case 'b': return "-...";
        case 'c': return "-.-.";
        case 'd': return "-..";
        case 'e': return ".";
        case 'f': return "..-.";
        case 'g': return "--.";
        case 'h': return "....";
        case 'i': return "..";
        case 'j': return ".---";
        case 'k': return "-.-";
        case 'l': return ".-..";
        case 'm': return "--";
        case 'n': return "-.";
        case 'o': return "---";
        case 'p': return ".--.";
        case 'q': return "--.-";
        case 'r': return ".-.";
        case 's': return "...";
        case 't': return "-";
        case 'u': return "..-";
        case 'v': return "...-";
        case 'w': return ".--";
        case 'x': return "-..-";
        case 'y': return "-.--";
        case 'z': return "--..";
        case '0': return "-----";
        case '1': return ".----";
        case '2': return "..---";
        case '3': return "...--";
        case '4': return "....-";
        case '5': return ".....";
        case '6': return "-....";
        case '7': return "--...";
        case '8': return "---..";
        case '9': return "----.";
        case ' ': return " ";
        default: return "";
    }
}

// Helper function to convert entire string to Morse code
char *str_to_morse(char *str)
{
    // Allocate enough memory to hold the Morse code string
    char *output = malloc(sizeof(char) * (strlen(str) * 5 + 1));
    output[0] = '\0';

    // Loop through each character in the string and convert to Morse code
    for(int i = 0; i < strlen(str); i++)
    {
        // Call morse() function to get Morse code representation of current character
        char *morse_code = morse(tolower(str[i]));

        // Append Morse code to output string
        strcat(output, morse_code);
        strcat(output, " ");
    }

    // Remove trailing space from output string
    output[strlen(output) - 1] = '\0';

    return output;
}