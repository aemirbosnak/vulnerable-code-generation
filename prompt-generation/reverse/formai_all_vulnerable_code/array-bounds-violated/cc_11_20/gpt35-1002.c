//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 7
#define COLS 100
#define MAX_LEN 100

void convertToAsciiArt(char inputText[]);
void printAsciiArt(char asciiArt[ROWS][COLS]);

int main() 
{
    char inputText[MAX_LEN];
    printf("Enter some text to convert into ASCII art:\n");
    fgets(inputText, sizeof(inputText), stdin);

    convertToAsciiArt(inputText);
  
    return 0;
}

void convertToAsciiArt(char inputText[]) 
{
    char asciiArt[ROWS][COLS] = {0};
    int index = 0;

    for (int row = 0; row < ROWS; row++) 
    {
        for (int col = 0; col < COLS; col++) 
        {
            if (isspace(inputText[index])) 
            {
                index++;
            }

            if (index >= strlen(inputText)) 
            {
                printAsciiArt(asciiArt);
                return;
            }

            switch(inputText[index]) 
            {
                case 'a':
                    asciiArt[row][col] = '|';
                    asciiArt[row+1][col-1] = '/';
                    asciiArt[row+1][col+1] = '\\';
                    asciiArt[row+2][col] = '_';
                    index++;
                    break;
                case 'b':
                    asciiArt[row][col] = '|';
                    asciiArt[row+1][col] = '_';
                    asciiArt[row+2][col] = '|';
                    asciiArt[row+3][col] = '|';
                    asciiArt[row+4][col] = '|';
                    asciiArt[row+5][col] = '_';
                    index++;
                    break;
                case 'c':
                    asciiArt[row][col] = ' ';
                    asciiArt[row+1][col] = '_';
                    asciiArt[row+2][col] = '|';
                    asciiArt[row+3][col] = '|';
                    asciiArt[row+4][col] = '|';
                    asciiArt[row+5][col] = '_';
                    index++;
                    break;
                case 'd':
                    asciiArt[row][col] = '|';
                    asciiArt[row+1][col] = '_';
                    asciiArt[row+2][col] = '|';
                    asciiArt[row+3][col] = '|';
                    asciiArt[row+4][col] = '|';
                    asciiArt[row+5][col] = '_';
                    index++;
                    break;
                case 'e':
                    asciiArt[row][col] = ' ';
                    asciiArt[row+1][col] = '_';
                    asciiArt[row+2][col] = '|';
                    asciiArt[row+3][col] = '_';
                    asciiArt[row+4][col] = '|';
                    asciiArt[row+5][col] = '_';
                    index++;
                    break;
                case 'f':
                    asciiArt[row][col] = ' ';
                    asciiArt[row+1][col] = '_';
                    asciiArt[row+2][col] = '|';
                    asciiArt[row+3][col] = '_';
                    asciiArt[row+4][col] = '|';
                    asciiArt[row+5][col] = '|';
                    index++;
                    break;
                case 'g':
                    asciiArt[row][col] = ' ';
                    asciiArt[row+1][col] = '_';
                    asciiArt[row+2][col+1] = '|';
                    asciiArt[row+3][col] = '|';
                    asciiArt[row+4][col] = '|';
                    asciiArt[row+5][col+1] = '_';
                    index++;
                    break;
                case 'h':
                    asciiArt[row][col] = '|';
                    asciiArt[row+1][col] = '_';
                    asciiArt[row+2][col] = '|';
                    asciiArt[row+3][col] = '|';
                    asciiArt[row+4][col] = '|';
                    asciiArt[row+5][col] = '|';
                    index++;
                    break;
                case 'i':
                    asciiArt[row][col] = ' ';
                    asciiArt[row+1][col] = '|';
                    asciiArt[row+2][col] = ' ';
                    asciiArt[row+3][col] = '|';
                    asciiArt[row+4][col] = '|';
                    asciiArt[row+5][col] = '_';
                    index++;
                    break;
                case 'j':
                    asciiArt[row][col] = ' ';
                    asciiArt[row+1][col] = '|';
                    asciiArt[row+2][col+1] = '|';
                    asciiArt[row+3][col+1] = '|';
                    asciiArt[row+4][col+1] = '|';
                    asciiArt[row+5][col] = '_';
                    index++;
                    break;
                case 'k':
                    asciiArt[row][col] = '|';
                    asciiArt[row+1][col] = '_';
                    asciiArt[row+2][col] = '|';
                    asciiArt[row+3][col+1] = '|';
                    asciiArt[row+4][col] = '|';
                    asciiArt[row+5][col] = '|';
                    index++;
                    break;
                case 'l':
                    asciiArt[row][col] = '|';
                    asciiArt[row+1][col] = '|';
                    asciiArt[row+2][col] = ' ';
                    asciiArt[row+3][col] = ' ';
                    asciiArt[row+4][col] = ' ';
                    asciiArt[row+5][col] = '_';
                    index++;
                    break;
                case 'm':
                    asciiArt[row][col] = '\\';
                    asciiArt[row][col+2] = '/';
                    asciiArt[row+1][col+1] = '\\';
                    asciiArt[row+1][col+3] = '/';
                    asciiArt[row+2][col] = '|';
                    asciiArt[row+2][col+4] = '|';
                    asciiArt[row+3][col] = '|';
                    asciiArt[row+3][col+4] = '|';
                    asciiArt[row+4][col] = '|';
                    asciiArt[row+5][col] = '|';
                    index++;
                    break;
                case 'n':
                    asciiArt[row][col] = '|';
                    asciiArt[row+1][col] = '\\';
                    asciiArt[row+1][col+1] = '\\';
                    asciiArt[row+2][col] = '|';
                    asciiArt[row+3][col] = '|';
                    asciiArt[row+4][col] = '|';
                    asciiArt[row+5][col] = '|';
                    index++;
                    break;
                case 'o':
                    asciiArt[row][col] = ' ';
                    asciiArt[row+1][col] = '_';
                    asciiArt[row+2][col] = '|';
                    asciiArt[row+3][col] = '|';
                    asciiArt[row+4][col] = '|';
                    asciiArt[row+5][col] = '_';
                    index++;
                    break;
                case 'p':
                    asciiArt[row][col] = '|';
                    asciiArt[row+1][col] = '_';
                    asciiArt[row+2][col] = '|';
                    asciiArt[row+3][col] = '|';
                    asciiArt[row+4][col] = '_';
                    asciiArt[row+5][col] = '|';
                    index++;
                    break;
                case 'q':
                    asciiArt[row][col+1] = '_';
                    asciiArt[row+1][col] = '|';
                    asciiArt[row+2][col] = '|';
                    asciiArt[row+3][col] = '|';
                    asciiArt[row+4][col+1] = '_';
                    asciiArt[row+5][col+1] = '\\';
                    index++;
                    break;
                case 'r':
                    asciiArt[row][col] = '|';
                    asciiArt[row+1][col] = '_';
                    asciiArt[row+2][col] = '|';
                    asciiArt[row+3][col] = '|';
                    asciiArt[row+4][col] = '|';
                    asciiArt[row+5][col] = '|';
                    asciiArt[row+4][col+1] = '\\';
                    index++;
                    break;
                case 's':
                    asciiArt[row][col] = ' ';
                    asciiArt[row+1][col] = '_';
                    asciiArt[row+2][col] = '|';
                    asciiArt[row+3][col+1] = '_';
                    asciiArt[row+4][col+1] = '|';
                    asciiArt[row+5][col] = '_';
                    index++;
                    break;
                case 't':
                    asciiArt[row][col] = '_';
                    asciiArt[row+1][col+1] = '|';
                    asciiArt[row+2][col+1] = '|';
                    asciiArt[row+3][col+1] = '|';
                    asciiArt[row+4][col+1] = '|';
                    asciiArt[row+5][col+1] = '|';
                    index++;
                    break;
                case 'u':
                    asciiArt[row][col] = '|';
                    asciiArt[row+1][col] = '|';
                    asciiArt[row+2][col] = '|';
                    asciiArt[row+3][col] = '|';
                    asciiArt[row+4][col+1] = '_';
                    asciiArt[row+5][col] = '_';
                    index++;
                    break;
                case 'v':
                    asciiArt[row][col] = '\\';
                    asciiArt[row+1][col] = '\\';
                    asciiArt[row+2][col] = '|';
                    asciiArt[row+3][col] = '|';
                    asciiArt[row+4][col+1] = '/';
                    asciiArt[row+5][col+1] = '/';
                    index++;
                    break;
                case 'w':
                    asciiArt[row][col] = '\\';
                    asciiArt[row][col+2] = '/';
                    asciiArt[row+1][col+1] = '/';
                    asciiArt[row+1][col+3] = '\\';
                    asciiArt[row+2][col] = '|';
                    asciiArt[row+2][col+4] = '|';
                    asciiArt[row+3][col] = '|';
                    asciiArt[row+3][col+4] = '|';
                    asciiArt[row+4][col+1] = '|';
                    asciiArt[row+5][col+1] = '|';
                    index++;
                    break;
                case 'x':
                    asciiArt[row][col] = '\\';
                    asciiArt[row][col+2] = '/';
                    asciiArt[row+1][col+1] = '|';
                    asciiArt[row+2][col] = '|';
                    asciiArt[row+3][col+1] = '|';
                    asciiArt[row+4][col+2] = '|';
                    asciiArt[row+5][col] = '\\';
                    asciiArt[row+5][col+2] = '/';
                    index++;
                    break;
                case 'y':
                    asciiArt[row][col] = '\\';
                    asciiArt[row+1][col] = '\\';
                    asciiArt[row+2][col+1] = '|';
                    asciiArt[row+3][col+1] = '|';
                    asciiArt[row+4][col+1] = '|';
                    asciiArt[row+5][col+1] = '|';
                    asciiArt[row+4][col] = '/';
                    index++;
                    break;
                case 'z':
                    asciiArt[row][col] = '_';
                    asciiArt[row][col+1] = '_';
                    asciiArt[row][col+2] = '_';
                    asciiArt[row+1][col+2] = '|';
                    asciiArt[row+2][col+1] = '|';
                    asciiArt[row+3][col] = '|';
                    asciiArt[row+4][col] = '|';
                    asciiArt[row+5][col] = '_';
                    asciiArt[row+5][col+1] = '_';
                    asciiArt[row+5][col+2] = '_';
                    index++;
                    break;
                default:
                    index++;
                    break;
            }
        }
    }
    printAsciiArt(asciiArt);
}

void printAsciiArt(char asciiArt[ROWS][COLS]) 
{
    for (int i = 0; i < ROWS; i++) 
    {
        printf("%s\n", asciiArt[i]);
    }
}