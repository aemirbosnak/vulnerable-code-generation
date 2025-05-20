//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: romantic
#include <stdio.h>
#include <string.h>

//Function to convert character to Morse code
char* charToMorse(char c)
{
    switch(c)
    {
        case 'a': return ".-";
        case 'b': return "-...";
        case 'c': return "-.-.";
        case 'd': return "-..";
        case 'e': return ".";
        case 'f': return "..-.";
        case 'g': return "--.";
        case 'h': return "....";
        case 'i': return "..";
        case 'j': return ".---";
        case 'k': return "-.-";
        case 'l': return ".-..";
        case 'm': return "--";
        case 'n': return "-.";
        case 'o': return "---";
        case 'p': return ".--.";
        case 'q': return "--.-";
        case 'r': return ".-.";
        case 's': return "...";
        case 't': return "-";
        case 'u': return "..-";
        case 'v': return "...-";
        case 'w': return ".--";
        case 'x': return "-..-";
        case 'y': return "-.--";
        case 'z': return "--..";
        case ' ': return " ";
        default: return "";
    }
}

int main()
{
    char input[100]; //Declare an array to store user input
    
    printf("Convert your romantic message to Morse code: ");
    scanf("%[^\n]", input); //Read input from user until newline
    
    //Loop through each character in input string and convert to Morse code
    for(int i=0; i<strlen(input); i++)
    {
        printf("%s ", charToMorse(tolower(input[i]))); //tolower() function converts uppercase to lowercase before converting to Morse code
    }
    
    printf("\n");
    
    return 0;
}