//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the Morse code table */
const char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--.."
};

/* Function to convert a single character to Morse code */
char *char_to_morse(char c)
{
    /* Convert the character to upper case */
    c = toupper(c);
    
    /* Check if the character is a space */
    if (c == ' ') {
        return " ";
    }
    
    /* Check if the character is a valid letter */
    if (c < 'A' || c > 'Z') {
        printf("Invalid character: '%c'\n", c);
        exit(1);
    }
    
    /* Lookup the corresponding Morse code */
    return (char *) morse_table[c - 'A'];
}

/* Function to convert a string to Morse code */
char *string_to_morse(char *str)
{
    /* Get the length of the string */
    int len = strlen(str);
    
    /* Allocate memory for the result */
    char *res = (char *) malloc(len * 5 + 1);
    
    /* Iterate over the string and convert each character to Morse code */
    for (int i = 0; i < len; i++) {
        char *morse = char_to_morse(str[i]);
        
        /* Append the Morse code to the result */
        strcat(res, morse);
        
        /* Append a space between each character */
        if (i < len - 1) {
            strcat(res, " ");
        }
    }
    
    return res;
}

int main()
{
    /* Get a string from the user */
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    
    /* Remove the newline character from the end of the string */
    str[strlen(str) - 1] = '\0';
    
    /* Convert the string to Morse code */
    char *morse = string_to_morse(str);
    
    /* Print the Morse code */
    printf("\nMorse code: %s\n", morse);
    
    /* Free the memory for the Morse code */
    free(morse);
    
    return 0;
}