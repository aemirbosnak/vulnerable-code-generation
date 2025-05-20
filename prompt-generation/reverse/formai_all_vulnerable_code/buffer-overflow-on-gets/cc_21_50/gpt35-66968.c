//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* morse_code(char c);

int main()
{
    char input[1000];
    printf("Enter text to convert to Morse Code:\n");
    gets(input);
    int len = strlen(input);
    printf("\nMorse Code Output:\n");
    for(int i=0;i<len;i++)
    {
        char c = input[i];
        char* mc = morse_code(c);
        printf("%s", mc);
    }

    return 0;
}

char* morse_code(char c)
{
    if(c == 'A' || c == 'a')
        return ".- ";
    else if(c == 'B' || c == 'b')
        return "-... ";
    else if(c == 'C' || c == 'c')
        return "-.-. ";
    else if(c == 'D' || c == 'd')
        return "-.. ";
    else if(c == 'E' || c == 'e')
        return ". ";
    else if(c == 'F' || c == 'f')
        return "..-. ";
    else if(c == 'G' || c == 'g')
        return "--. ";
    else if(c == 'H' || c == 'h')
        return ".... ";
    else if(c == 'I' || c == 'i')
        return ".. ";
    else if(c == 'J' || c == 'j')
        return ".--- ";
    else if(c == 'K' || c == 'k')
        return "-.- ";
    else if(c == 'L' || c == 'l')
        return ".-.. ";
    else if(c == 'M' || c == 'm')
        return "-- ";
    else if(c == 'N' || c == 'n')
        return "-. ";
    else if(c == 'O' || c == 'o')
        return "--- ";
    else if(c == 'P' || c == 'p')
        return ".--. ";
    else if(c == 'Q' || c == 'q')
        return "--.- ";
    else if(c == 'R' || c == 'r')
        return ".-. ";
    else if(c == 'S' || c == 's')
        return "... ";
    else if(c == 'T' || c == 't')
        return "- ";
    else if(c == 'U' || c == 'u')
        return "..- ";
    else if(c == 'V' || c == 'v')
        return "...- ";
    else if(c == 'W' || c == 'w')
        return ".-- ";
    else if(c == 'X' || c == 'x')
        return "-..- ";
    else if(c == 'Y' || c == 'y')
        return "-.-- ";
    else if(c == 'Z' || c == 'z')
        return "--.. ";
    else if(c == ' ')
        return "/ ";
    else
        return "";
}