//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: multiplayer
#include <stdio.h>
#include <string.h>

// Function prototype
void textToMorse(char message[], char morse[]);

// Main function
int main(void)
{
    // Initialize variables
    char message[100], morse[400];
    int players, i;

    // Get input
    printf("Enter the message to convert to Morse code:\n");
    fgets(message, 100, stdin);

    printf("Enter the number of players (2-4):\n");
    scanf("%d", &players);

    // Check for valid number of players
    if(players < 2 || players > 4)
    {
        printf("Invalid number of players. Exiting program...\n");
        return 0;
    }

    // Call textToMorse function to convert message to Morse code
    textToMorse(message, morse);

    // Initialize arrays for each player's converted message
    char player1[400], player2[400], player3[400], player4[400];

    // Divide the Morse code into groups for each player
    int morse_length = strlen(morse);
    int group_length = morse_length / players;

    // Divide the Morse code and assign each group to the corresponding player
    for(i = 0; i < morse_length; i += group_length)
    {
        strncpy(player1 + strlen(player1), morse + i, group_length);
        strncpy(player2 + strlen(player2), morse + i + group_length, group_length);
        strncpy(player3 + strlen(player3), morse + i + (2 * group_length), group_length);
        strncpy(player4 + strlen(player4), morse + i + (3 * group_length), group_length);
    }

    // Display each player's converted message
    printf("\nPlayer 1's converted message:\n%s", player1);
    printf("\nPlayer 2's converted message:\n%s", player2);

    if(players > 2)
    {
        printf("\nPlayer 3's converted message:\n%s", player3);
    }

    if(players > 3)
    {
        printf("\nPlayer 4's converted message:\n%s", player4);
    }

    return 0;
}

// Function definition
void textToMorse(char message[], char morse[])
{
    // Initialize Morse code array
    char *morse_array[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", 
                        "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    // Initialize variables
    int i, j;

    // Convert each character to Morse code and append to morse array
    for(i = 0; i < strlen(message); i++)
    {
        if(message[i] == ' ')
        {
            strcat(morse, " ");
        }
        else
        {
            for(j = 0; j < 26; j++)
            {
                if(message[i] == toupper((char)(j + 65)))
                {
                    strcat(morse, morse_array[j]);
                    strcat(morse, " ");
                    break;
                }
            }
        }
    }
}