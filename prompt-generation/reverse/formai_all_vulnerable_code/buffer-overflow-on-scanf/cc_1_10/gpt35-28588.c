//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert text to morse code
void text_to_morse(char* str);

int main()
{
    char input[100];

    // Cyberpunk UI
    printf("==============================\n");
    printf("|    Text To Morse Code      |\n");
    printf("==============================\n");

    printf("Enter the text to convert to morse code:\n");
    scanf("%[^\n]s", input);

    // Clear the input buffer
    while(getchar() != '\n');

    // Convert text to morse code
    text_to_morse(input);

    printf("\n");

    return 0;
}

void text_to_morse(char* str)
{
    // Define the morse code symbols
    char* morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
                            ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
                            "..-", "...-", ".--", "-..-", "-.--", "--.."};

    // Define the text alphabet symbols
    char* alphabet[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o",
                          "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

    printf("Generating Morse Code...\n");

    // Loop through each character in the input string
    for (int i = 0; i < strlen(str); i++)
    {
        // Convert character to lowercase
        char current_char = tolower(str[i]);

        // Check if the character is a space
        if (current_char == ' ')
        {
            printf(" / ");
        }
        // Check if the character is a letter
        else if (current_char >= 'a' && current_char <= 'z')
        {
            // Get the morse code symbol for the current character
            int index = current_char - 'a';
            char* morse_symbol = morse_code[index];

            // Print the morse code symbol
            printf("%s ", morse_symbol);
        }
        // If the character is not a letter or space, skip it
        else{
            continue;
        }
    }
    printf("\n");
}