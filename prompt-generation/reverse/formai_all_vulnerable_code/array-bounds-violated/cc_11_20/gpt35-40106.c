//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: puzzling
#include <stdio.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

int main()
{
    char input[256];
    int lines = 0;

    printf("Enter some text to generate ASCII art: ");
    fgets(input, 256, stdin);
    printf("\n");

    // Remove newline from input
    if(input[strlen(input) - 1] == '\n')
        input[strlen(input) - 1] = '\0';

    // Check if input is less than 50 characters
    if(strlen(input) < 50)
    {
        printf("Input is too short! Must be at least 50 characters.\n");
        return 0;
    }

    // Calculate number of lines needed for output
    lines = strlen(input) / WIDTH;
    if(strlen(input) % WIDTH != 0)
        lines++;

    // Declare 2D array for output
    char output[HEIGHT][WIDTH + 1];

    // Initialize array to blank spaces
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            output[i][j] = ' ';
        }

        output[i][WIDTH] = '\0';
    }

    // Build output array
    int input_index = 0;
    int row = 0;
    int col = 0;

    while(input_index < strlen(input))
    {
        char c = input[input_index];

        // Convert character to ASCII value
        int ascii_value = (int)c;

        // Convert ASCII value to binary string
        char binary_string[9];
        int remainder;
        int quotient = ascii_value;
        for(int i = 7; i >= 0; i--)
        {
            remainder = quotient % 2;
            quotient = quotient / 2;
            binary_string[i] = remainder + '0';
        }

        binary_string[8] = '\0';
        
        // Insert binary values into output array
        for(int i = 0; i < strlen(binary_string); i++)
        {
            if(binary_string[i] == '1')
            {
                output[row][col + i] = '*';
            }
        }

        // Increment row and column counters
        row++;
        if(row == HEIGHT)
        {
            row = 0;
            col += 8;
        }

        input_index++;
    }

    // Print output array
    for(int i = 0; i < HEIGHT; i++)
    {
        printf("%s\n", output[i]);
    }

    return 0;
}