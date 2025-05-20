//FormAI DATASET v1.0 Category: Text processing ; Style: multiplayer
// Multiplayer style text processing game
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char player1[20], player2[20], input[100], output[100];
    int i, flag = 0;

    printf("Player 1, enter your name: ");
    scanf("%s", player1);
    printf("Player 2, enter your name: ");
    scanf("%s", player2);

    printf("Welcome %s and %s, let's play a text processing game!\n", player1, player2);
    printf("The game is simple, each player takes turns entering a word.\n");
    printf("The word must start with the last letter of the previous player's word.\n");
    printf("The game ends when a player cannot think of a word or the word is not a valid English word.\n");
    printf("Ready? Let's begin!\n\n");

    // Setting the first player
    printf("%s, enter a word: ", player1);
    scanf("%s", input);

    while (1) { // Loop to continue the game until a player loses

        for (i = 0; i < strlen(input); i++) { // Converting input to lowercase
            input[i] = tolower(input[i]);
        }

        if (flag == 0) { // Setting up output variables for input check
            strcpy(output, input);
            flag++;
        } else {
            output[0] = input[strlen(input) - 1];
            output[1] = '\0';
        }

        // Checking if input is a valid English word
        if (strcmp(input, "quit") == 0) {
            printf("Goodbye %s and %s, game over!", player1, player2);
            break;
        } else if (strlen(input) < 2) { // Input should at least have two characters
            printf("Sorry %s, your word is too short. ", (flag%2 == 1) ? player1 : player2);
            printf("%s wins!", (flag%2 == 1) ? player2 : player1);
            break;
        } else if (input[strlen(input) - 1] == 's') { // Input should not end with 's'
            printf("Sorry %s, your word cannot end with 's'. ", (flag%2 == 1) ? player1 : player2);
            printf("%s wins!", (flag%2 == 1) ? player2 : player1);
            break;
        } else {
            // Validating the input using a third party API call
            char validate[200], command[200], result[200];
            sprintf(command, "curl --silent https://api.dictionaryapi.dev/api/v2/entries/en/%s | jq -r '.[0].word'", input);
            FILE* output_file = popen(command, "r");
            fscanf(output_file, "%s", validate);
            pclose(output_file);

            if (strcmp(validate, input) != 0) { // If input is not a valid English word
                printf("Sorry %s, '%s' is not a valid English word. ", (flag%2 == 1) ? player1 : player2, input);
                printf("%s wins!", (flag%2 == 1) ? player2 : player1);
                break;
            } else if (strcmp(output, input) != 0) { // Input did not match output from previous input
                printf("Sorry %s, your word does not start with %c. ", (flag%2 == 1) ? player1 : player2, output[0]);
                printf("%s wins!", (flag%2 == 1) ? player2 : player1);
                break;
            } else { // If input passes all checks
                printf("Great job, %s!\n", (flag%2 == 1) ? player2 : player1);
                flag++;
            }
        }

        if (flag%2 == 1) { // Player 1's turn
            printf("%s, enter a word starting with %c: ", player1, output[0]);
        } else { // Player 2's turn
            printf("%s, enter a word starting with %c: ", player2, output[0]);
        }

        scanf("%s", input);
    }

    return 0;
}