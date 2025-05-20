//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to convert a character to Morse code
char* toMorse(char ch)
{
    switch(toupper(ch))
    {
        case 'A': return ".-";
        case 'B': return "-...";
        case 'C': return "-.-.";
        case 'D': return "-..";
        case 'E': return ".";
        case 'F': return "..-.";
        case 'G': return "--.";
        case 'H': return "....";
        case 'I': return "..";
        case 'J': return ".---";
        case 'K': return "-.-";
        case 'L': return ".-..";
        case 'M': return "--";
        case 'N': return "-.";
        case 'O': return "---";
        case 'P': return ".--.";
        case 'Q': return "--.-";
        case 'R': return ".-.";
        case 'S': return "...";
        case 'T': return "-";
        case 'U': return "..-";
        case 'V': return "...-";
        case 'W': return ".--";
        case 'X': return "-..-";
        case 'Y': return "-.--";
        case 'Z': return "--..";
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
        default: return "";
    }
}

// Function to convert a string to Morse code
char* convertToMorse(char* str)
{
    // Allocate an initial buffer to hold the converted Morse code string
    int maxLen = strlen(str) * 5 + 1;
    char* morseStr = malloc(maxLen);
    morseStr[0] = '\0';
    
    // Loop through each character in the input string
    int i;
    for (i = 0; i < strlen(str); i++)
    {
        // Convert the current character to Morse code
        char* morse = toMorse(str[i]);
        
        // If the conversion was successful, append the Morse code to the output string
        if (strlen(morse) > 0)
        {
            strcat(morseStr, morse);
            strcat(morseStr, " ");
        }
    }
    
    // Remove trailing space
    if (strlen(morseStr) > 0 && morseStr[strlen(morseStr) - 1] == ' ')
    {
        morseStr[strlen(morseStr) - 1] = '\0';
    }
    
    return morseStr;
}

int main()
{
    // Get user input
    char input[101];
    printf("Enter a string to convert to Morse code: ");
    fgets(input, 100, stdin);
    
    // Convert the input string to Morse code
    char* morseStr = convertToMorse(input);
    
    // Display the converted Morse code
    if (strlen(morseStr) > 0)
    {
        printf("Morse code: %s\n", morseStr);
    }
    else
    {
        printf("Error: Invalid input\n");
    }
    
    // Free memory
    free(morseStr);
    
    return 0;
}