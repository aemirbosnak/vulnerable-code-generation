//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: shocked
// **C Text to Morse Code Conversion** //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// **Morse Code Table** //
char morse_code[][7] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "-...", "-.-..", "--..", "-.--.",
    "...-", "....-", "..--", "..--.-", "---", "---.", "----", "-----", "..--..",
    "-..-.--", "..--.-.", ".---..-.--", ".-.-.-", "..--..--"
};

// **Text to Morse Code Conversion** //
void text_to_morse(char *text) {
    int i, j;
    for (i = 0; i < strlen(text); i++) {
        for (j = 0; j < 26; j++) {
            if (text[i] == 'a' + j || text[i] == 'A' + j) {
                printf("%s ", morse_code[j]);
            }
        }
    }
}

// **Main Function** //
int main() {
    // **Welcome Message** //
    printf("**Welcome to the C Text to Morse Code Converter**\n");
    printf("**Instructions:**\n");
    printf("1. Enter a text message.\n");
    printf("2. The program will convert the text to Morse code.\n");
    printf("**Example:**\n");
    printf("Text: HELLO\n");
    printf("Morse Code: .... . .-.. .-.. ---\n");
    printf("**Note:**\n");
    printf("The program supports both uppercase and lowercase letters.\n");

    // **Get User Input** //
    char text[100];
    printf("\n**Enter your text message:** ");
    scanf("%s", text);

    // **Convert Text to Morse Code** //
    text_to_morse(text);

    // **Closing Message** //
    printf("\n**Conversion complete!**\n");
    return 0;
}