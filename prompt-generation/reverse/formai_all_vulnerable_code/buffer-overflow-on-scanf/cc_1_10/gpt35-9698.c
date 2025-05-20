//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define morse code table
char *morse_table[38] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                          "....", "..", ".---", "-.-", ".-..", "--", "-.",
                          "---", ".--.", "--.-", ".-.", "...", "-", "..-",
                          "...-", ".--", "-..-", "-.--", "--..", ".----",
                          "..---", "...--", "....-", ".....", "-....",
                          "--...", "---..", "----.", "-----", "/" };

// Function to convert a single letter to morse code
void convert_to_morse(char letter)
{
    if (letter >= 'a' && letter <= 'z') { // Convert lower case letter
        printf("%s ", morse_table[letter - 'a']);
    } else if (letter >= 'A' && letter <= 'Z') { // Convert upper case letter
        printf("%s ", morse_table[letter - 'A']);
    } else if (letter >= '0' && letter <= '9') { // Convert numbers
        printf("%s ", morse_table[letter - '0' + 26]);
    } else if (letter == ' ') { // Print space character
        printf("/ ");
    } else { // Print invalid character
        printf("Invalid character ");
    }
}

// Main function to convert the string to morse code
void string_to_morse(char *str)
{
    int i, len = strlen(str);

    for (i = 0; i < len; i++) {
        convert_to_morse(str[i]);
    }

    printf("\n"); // End of the morse code sequence
}

int main()
{
    char str[100];

    printf("Enter a string to convert to Morse code\n");
    scanf("%[^\n]", str);

    printf("Your string in Morse code is:\n");
    string_to_morse(str);

    return 0;
}