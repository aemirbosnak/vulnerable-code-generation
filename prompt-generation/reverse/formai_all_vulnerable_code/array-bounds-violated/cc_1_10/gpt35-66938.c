//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: introspective
// As a chatbot, I have always been fascinated with the art of communication. 
// And Morse code, is one of the coolest ways of communicating via sound.
// In this program, I will convert a given text into Morse code using C language.
// Let's get started!

#include <stdio.h>
#include <string.h>

// First, let's define the Morse code table as an array of strings
// where each string represents a character in Morse code
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", "/", "--..--", ".-.-.-"
};

// We will also define a function to convert a given letter to Morse code
// which takes the letter as a char input and returns the corresponding Morse code as a string
char *char_to_morse(char letter) {
    if (letter >= 'a' && letter <= 'z') { // If it's a lowercase letter
        return morse_table[letter - 'a'];
    } else if (letter >= 'A' && letter <= 'Z') { // If it's an uppercase letter
        return morse_table[letter - 'A'];
    } else if (letter >= '0' && letter <= '9') { // If it's a number
        return morse_table[26 + (letter - '0')];
    } else if (letter == ' ') { // If it's a space
        return morse_table[27];
    } else if (letter == '.') { // If it's a period
        return morse_table[28];
    } else if (letter == ',') { // If it's a comma
        return morse_table[29];
    } else { // If it's an unknown character
        return NULL;
    }
}

// Now let's define the main function to take a string as input and convert it to Morse code
int main() {
    char input[100]; // Define a buffer to store the input string
    printf("Please enter the text to be converted to Morse code:\n");
    fgets(input, 100, stdin); // Get the input string from the user
    
    int length = strlen(input); // Get the length of the input string
    printf("The Morse code for the text is:\n");
    for (int i = 0; i < length; i++) { // Loop through each character in the input string
        char *morse_code = char_to_morse(input[i]); // Get the Morse code for the current character
        if (morse_code == NULL) { // If the character is unknown, print an error message
            printf("Unknown character: %c\n", input[i]);
        } else { // Otherwise, print the Morse code
            printf("%s ", morse_code);
        }
    }
    printf("\n"); // Print a newline at the end for readability
    
    return 0; // End the program
}