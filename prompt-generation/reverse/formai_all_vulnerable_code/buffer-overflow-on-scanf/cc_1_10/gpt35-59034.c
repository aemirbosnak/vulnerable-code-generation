//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to convert text to Morse code
void textToMorse(char *text, char *morse) {
    char *alphabet[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
                        ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
                        "...","-","..-","...-",".--","-..-","-.--","--.."};
    char *numeric[10] = {"-----",".----","..---","...--","....-",".....","-....",
                        "--...","---..","----."};
    int i;

    // loop through each character of the text
    for (i = 0; text[i] != '\0'; i++) {
        // check for alphabets and convert to Morse code
        if (isalpha(text[i])) {
            morse = strcat(morse, alphabet[toupper(text[i]) - 65]);
        }
        // check for numbers and convert to Morse code
        else if (isdigit(text[i])) {
            morse = strcat(morse, numeric[text[i] - 48]);
        }
        // handle spaces in the text by inserting a slash (/) in the Morse code
        else if (isspace(text[i])) {
            morse = strcat(morse, "/");
        }
        // handle unsupported characters in the text by inserting a question mark (?) in the Morse code
        else {
            morse = strcat(morse, "?");
        }
        // insert a space between each Morse code character
        morse = strcat(morse, " ");
    }
}

int main() {
    char text[100], morse[500];
    int i, num_players;

    printf("Welcome to the Text-to-Morse code conversion game!\n\n");

    // get the text from the user
    printf("Enter the text to be converted to Morse code:\n");
    fgets(text, 100, stdin);

    // get the number of players for the game
    printf("\nEnter the number of players for the game: ");
    scanf("%d", &num_players);

    printf("\n\n");

    // loop through each player and display the converted Morse code
    for (i = 1; i <= num_players; i++) {
        // clear the Morse code string for each player
        memset(morse, 0, sizeof(morse));
        // convert the text to Morse code for each player
        textToMorse(text, morse);

        printf("Player %d: %s\n", i, morse);
    }

    printf("\nThanks for playing!\n");
    return 0;
}