//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: relaxed
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 26
char symbols[SIZE][5] = {
    {'#', '#', '#', '#', '#'},
    {'^', '^', '^', '^', '^'},
    {'*', '*', '*', '*', '*'},
    {'&', '&', '&', '&', '&'},
    {'%', '%', '%', '%', '%'},
    {'@', '@', '@', '@', '@'},
    {'+', '+', '+', '+', '+'},
    {'=', '=', '=', '=', '='},
    {'!', '!', '!', '!', '!'},
    {'$', '$', '$', '$', '$'},
    {'%', '%', '%', '%', '%'},
    {'&', '&', '&', '&', '&'},
    {'*', '*', '*', '*', '*'},
    {'^', '^', '^', '^', '^'},
    {'#', '#', '#', '#', '#'},
    {'?', '?', '?', '?', '?'},
    {'_', '_', '_', '_', '_'},
    {'~', '~', '~', '~', '~'},
    {'`', '`', '`', '`', '`'},
    {'|', '|', '|', '|', '|'},
    {'(', '(', '(', '(', '('},
    {')', ')', ')', ')', ')', ')'}
};

int main() {
    char c;

    printf("Enter a character: ");
    scanf("%c", &c);

    if (isalpha(c))
        c += toupper(c) - 'A'; // ASCII values of uppercase letters are contiguous

    int row = (c - 'A') % SIZE;
    int col = (c - 'A') / 5;

    printf("\nASCII Art:\n");

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            putchar(symbols[row][j]);
        }
        putchar('\n');
    }

    return 0;
}