//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: synchronous
#include <stdio.h>
#include <string.h>

/* Define the Morse code table */
char *morse_table[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

/* Define the corresponding alphabet table */
char *alphabet_table[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

/* Define a function to convert a single character to Morse code */
char *char_to_morse(char c) {
    char *morse = NULL;
    int index = c - 'A';
    if (index >= 0 && index <= 25) {
        morse = morse_table[index];
    }
    return morse;
}

/* Define a function to convert a string to Morse code */
char *string_to_morse(char *str) {
    char *morse = NULL;
    int str_len = strlen(str);
    if (str_len > 0) {
        morse = (char*)malloc(str_len*5*sizeof(char)); // Allocate enough memory for the longest Morse sequence
        char *morse_ptr = morse;
        for (int i = 0; i < str_len; i++) {
            // Convert each character to Morse code and append to the output string
            char *char_morse = char_to_morse(str[i]);
            if (char_morse != NULL) {
                strcpy(morse_ptr, char_morse);
                morse_ptr += strlen(char_morse);
                if (i < str_len-1) {
                    *morse_ptr = ' '; // Add a space between each character in the output string
                    morse_ptr++;
                }
            }
        }
    }
    return morse;
}

/* Define the main function to convert user input to Morse code */
int main() {
    char input[100];
    printf("Enter the string you want to convert to Morse code:\n");
    fgets(input, 100, stdin); // Read user input
    input[strlen(input)-1] = '\0'; // Remove trailing newline character
    char *morse = string_to_morse(input);
    if (morse != NULL) {
        printf("The Morse code equivalent of '%s' is:\n%s\n", input, morse);
        free(morse); // Free the memory allocated for the Morse code string
    }
    else {
        printf("Invalid input. Please enter a string containing only capital letters from A-Z.\n");
    }
    return 0;
}