//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Ken Thompson
#include <stdio.h>

/* Ken Thompson-inspired Bitwise Operations Example */
/* Purpose: Demonstrate bit operations using Morse code */

/* Morse code table */
const char *morse_table[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                              "....", "..", ".---", "-.-", ".-..", "--", "-.",
                              "---", ".--.", "--.-", ".-.", "...", "-", "..-",
                              "...-", ".--", "-..-", "-.--", "--..", "-----",
                              ".----", "..---", "...--", "....-", ".....",
                              "-....", "--...", "---..", "----.", "/", ""};

int main() {
    char input[20];
    int i;

    printf("Enter a word to convert to Morse code: ");
    scanf("%s", input);

    /* Convert to uppercase */
    for (i = 0; input[i]; i++) {
        input[i] = toupper(input[i]);
    }

    /* Iterate over each character in the input */
    for (i = 0; input[i]; i++) {
        char curr = input[i];
        int j;
        
        /* Iterate over each bit in the current character */
        for (j = 7; j >= 0; j--) {
            int bit = (curr >> j) & 1; /* Get the jth bit of curr */

            /* Convert the bit to Morse code */
            const char *morse = morse_table[bit];

            /* Print the Morse code for this bit */
            while (*morse) {
                printf("%c", *morse);
                morse++;
            }

            /* Separate bits within the same character with a space */
            if (j > 0) {
                printf(" ");
            }
        }

        /* Separate Morse code for different characters with a slash */
        printf("/");
    }

    printf("\n");

    return 0;
}