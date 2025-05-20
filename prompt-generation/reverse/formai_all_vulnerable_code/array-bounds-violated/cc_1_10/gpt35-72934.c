//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert text to Morse code
int text_to_morse(const char *text, char *morse)
{
    int i, j, len;
    char c;

    // Morse code table
    char *morse_table[26] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
        "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
        "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
        "-.--", "--.."
    };

    len = strlen(text);
    for (i = 0, j = 0; i < len; i++) {
        c = toupper(text[i]);
        if (c >= 'A' && c <= 'Z') {
            strcat(morse + j, morse_table[c - 'A']);
            j += strlen(morse_table[c - 'A']);
        }
        if (c == ' ') {
            strcat(morse + j, " ");
            j++;
        }
    }

    return j;
}

int main()
{
    char text[100], morse[1000];
    int len;

    printf("Enter text to be converted to Morse code:\n");
    fgets(text, 100, stdin);
    len = strlen(text);
    if (text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }

    len = text_to_morse(text, morse);
    printf("Morse code: %s\n", morse);

    return 0;
}