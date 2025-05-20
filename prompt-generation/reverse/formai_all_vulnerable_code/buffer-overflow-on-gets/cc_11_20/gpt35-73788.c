//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to convert a character to its Morse Code equivalent
char * charToMorse(char c)
{
    switch(c)
    {
        case 'a':
        case 'A':
            return ".-";
        case 'b':
        case 'B':
            return "-...";
        case 'c':
        case 'C':
            return "-.-.";
        case 'd':
        case 'D':
            return "-..";
        case 'e':
        case 'E':
            return ".";
        case 'f':
        case 'F':
            return "..-.";
        case 'g':
        case 'G':
            return "--.";
        case 'h':
        case 'H':
            return "....";
        case 'i':
        case 'I':
            return "..";
        case 'j':
        case 'J':
            return ".---";
        case 'k':
        case 'K':
            return "-.-";
        case 'l':
        case 'L':
            return ".-..";
        case 'm':
        case 'M':
            return "--";
        case 'n':
        case 'N':
            return "-.";
        case 'o':
        case 'O':
            return "---";
        case 'p':
        case 'P':
            return ".--.";
        case 'q':
        case 'Q':
            return "--.-";
        case 'r':
        case 'R':
            return ".-.";
        case 's':
        case 'S':
            return "...";
        case 't':
        case 'T':
            return "-";
        case 'u':
        case 'U':
            return "..-";
        case 'v':
        case 'V':
            return "...-";
        case 'w':
        case 'W':
            return ".--";
        case 'x':
        case 'X':
            return "-..-";
        case 'y':
        case 'Y':
            return "-.--";
        case 'z':
        case 'Z':
            return "--..";
        case ' ':
            return "/";
        default:
            return "";
    }
}

// Function to convert a string to its Morse Code equivalent
char * stringToMorse(char s[])
{
    int i, j;
    char *morse = (char*) malloc(sizeof(char) * 100);
    morse[0] = '\0';

    for(i = 0; i < strlen(s); i++)
    {
        char *temp = charToMorse(s[i]);
        strcat(morse, temp);
        free(temp);
        strcat(morse, " ");
    }

    return morse;
}

// Main function to test the program
int main()
{
    char s[50];

    printf("Enter a string: ");
    gets(s);

    char *morse = stringToMorse(s);

    printf("Morse Code of \"%s\" is: %s\n", s, morse);

    free(morse);

    return 0;
}