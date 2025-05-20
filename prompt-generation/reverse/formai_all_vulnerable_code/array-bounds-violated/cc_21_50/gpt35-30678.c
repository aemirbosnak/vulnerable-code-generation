//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARACTERS 1000
#define MAX_WIDTH 80

int main()
{
    char input[MAX_CHARACTERS];
    printf("Enter text to convert to ASCII art: ");
    fgets(input, MAX_CHARACTERS, stdin);

    int length = strlen(input);
    if (input[length - 1] == '\n')
    {
        input[length - 1] = '\0';
    }

    int num_rows = (length / MAX_WIDTH) + 1;
    char ascii_art[num_rows][MAX_WIDTH];
    int current_row = 0;
    int current_col = 0;

    for (int i = 0; i < length; i++)
    {
        char current_char = input[i];

        if (isalpha(current_char) || isspace(current_char))
        {
            char *ascii = NULL;
            switch (tolower(current_char))
            {
            case 'a':
                ascii = ".XXXX."
                        "X....X"
                        "XXXXXX"
                        "X....X"
                        "X....X";
                break;
            case 'b':
                ascii = "XXXXX."
                        "X....X"
                        "XXXXX."
                        "X....X"
                        "XXXXX.";
                break;
            case 'c':
                ascii = ".XXXXX"
                        "X....."
                        "X....."
                        "X....."
                        ".XXXXX";
                break;
            case 'd':
                ascii = "XXXXX."
                        "X....X"
                        "X....X"
                        "X....X"
                        "XXXXX.";
                break;
            case 'e':
                ascii = "XXXXXX"
                        "X....."
                        "XXXXX."
                        "X....."
                        "XXXXXX";
                break;
            case 'f':
                ascii = "XXXXXX"
                        "X....."
                        "XXXXX."
                        "X....."
                        "X.....";
                break;
            case 'g':
                ascii = ".XXXXX"
                        "X....."
                        "X..XXX"
                        "X....X"
                        ".XXXXX";
                break;
            case 'h':
                ascii = "X....X"
                        "X....X"
                        "XXXXXX"
                        "X....X"
                        "X....X";
                break;
            case 'i':
                ascii = ".XXXX."
                        "...X..."
                        "...X..."
                        "...X..."
                        ".XXXX.";
                break;
            case 'j':
                ascii = "...XXX"
                        ".....X"
                        ".....X"
                        "X....X"
                        ".XXXX.";
                break;
            case 'k':
                ascii = "X....X"
                        "X...X."
                        "XXXX.."
                        "X...X."
                        "X....X";
                break;
            case 'l':
                ascii = "X....."
                        "X....."
                        "X....."
                        "X....."
                        "XXXXXX";
                break;
            case 'm':
                ascii = "X....X"
                        "XX..XX"
                        "X.X.X."
                        "X...X."
                        "X...X.";
                break;
            case 'n':
                ascii = "X....X"
                        "XX...X"
                        "X.X..X"
                        "X..X.X"
                        "X...XX";
                break;
            case 'o':
                ascii = ".XXXX."
                        "X....X"
                        "X....X"
                        "X....X"
                        ".XXXX.";
                break;
            case 'p':
                ascii = "XXXXX."
                        "X....X"
                        "XXXXX."
                        "X....."
                        "X.....";
                break;
            case 'q':
                ascii = ".XXXX."
                        "X....X"
                        "X....X"
                        ".XXXX."
                        ".....X";
                break;
            case 'r':
                ascii = "XXXXX."
                        "X....X"
                        "XXXXX."
                        "X...X."
                        "X....X";
                break;
            case 's':
                ascii = ".XXXXX"
                        "X....."
                        ".XXXX."
                        ".....X"
                        "XXXXX.";
                break;
            case 't':
                ascii = "XXXXXX"
                        "...X..."
                        "...X..."
                        "...X..."
                        "...X...";
                break;
            case 'u':
                ascii = "X....X"
                        "X....X"
                        "X....X"
                        "X....X"
                        ".XXXX.";
                break;
            case 'v':
                ascii = "X....X"
                        "X....X"
                        "X....X"
                        ".X..X."
                        "..XX...";
                break;
            case 'w':
                ascii = "X...X."
                        "X...X."
                        "X.X.X."
                        "X.X.X."
                        ".X.X...";
                break;
            case 'x':
                ascii = "X....X"
                        ".X..X."
                        "..XX.."
                        ".X..X."
                        "X....X";
                break;
            case 'y':
                ascii = "X....X"
                        ".X..X."
                        "..XX.."
                        "...X..."
                        "...X...";
                break;
            case 'z':
                ascii = "XXXXXX"
                        "....X."
                        "...X.."
                        "..X..."
                        "XXXXXX";
                break;
            case ' ':
                ascii = "......"
                        "......"
                        "......"
                        "......"
                        "......";
                break;
            }

            if (ascii != NULL)
            {
                int ascii_len = strlen(ascii);
                for (int j = 0; j < ascii_len; j++)
                {
                    if (ascii[j] == 'X')
                    {
                        ascii_art[current_row][current_col] = '#';
                    }
                    else
                    {
                        ascii_art[current_row][current_col] = ' ';
                    }

                    current_col++;
                    if (current_col == MAX_WIDTH)
                    {
                        current_col = 0;
                        current_row++;
                    }
                }
            }
        }
    }

    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < MAX_WIDTH; j++)
        {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }

    return 0;
}