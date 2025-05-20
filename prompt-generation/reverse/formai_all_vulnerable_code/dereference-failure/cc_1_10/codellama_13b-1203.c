//Code Llama-13B DATASET v1.0 Category: Text to Morse code conversion ; Style: light-weight
/*
 * Text to Morse code conversion example program
 *
 * Usage:
 *  $ ./text_to_morse <text>
 *
 * where <text> is the text to be converted
 *
 * Example:
 *  $ ./text_to_morse "Hello, World!"
 *  ... --- ... / .-.. .-.. --- / --..-- / .-- --- .-. .-.. -..
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MORSE_DOT "."
#define MORSE_DASH "-"
#define MORSE_SPACE " "

const char* morse_table[128] = {
    ['.'] = MORSE_DOT,
    ['-'] = MORSE_DASH,
    [' '] = MORSE_SPACE,
    ['a'] = ".-",
    ['b'] = "-...",
    ['c'] = "-.-.",
    ['d'] = "-..",
    ['e'] = ".",
    ['f'] = "..-.",
    ['g'] = "--.",
    ['h'] = "....",
    ['i'] = "..",
    ['j'] = ".---",
    ['k'] = "-.-",
    ['l'] = ".-..",
    ['m'] = "--",
    ['n'] = "-.",
    ['o'] = "---",
    ['p'] = ".--.",
    ['q'] = "--.-",
    ['r'] = ".-.",
    ['s'] = "...",
    ['t'] = "-",
    ['u'] = "..-",
    ['v'] = "...-",
    ['w'] = ".--",
    ['x'] = "-..-",
    ['y'] = "-.--",
    ['z'] = "--..",
    ['A'] = ".-.-",
    ['B'] = "-..-.",
    ['C'] = "-.-..",
    ['D'] = "-..",
    ['E'] = ".",
    ['F'] = "..-.",
    ['G'] = "--.",
    ['H'] = "....",
    ['I'] = "..",
    ['J'] = ".---",
    ['K'] = "-.-",
    ['L'] = ".-..",
    ['M'] = "--",
    ['N'] = "-.",
    ['O'] = "---",
    ['P'] = ".--.",
    ['Q'] = "--.-",
    ['R'] = ".-.",
    ['S'] = "...",
    ['T'] = "-",
    ['U'] = "..-",
    ['V'] = "...-",
    ['W'] = ".--",
    ['X'] = "-..-",
    ['Y'] = "-.--",
    ['Z'] = "--.."
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char* text = argv[1];
    size_t len = strlen(text);

    for (size_t i = 0; i < len; i++) {
        char c = toupper(text[i]);
        if (isalpha(c)) {
            printf("%s ", morse_table[c]);
        } else if (isspace(c)) {
            printf(" ");
        } else {
            printf(" ");
        }
    }

    return 0;
}