//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: grateful
#include <stdio.h>
#include <string.h>

char *toMorseCode(char letter)
{
    switch(letter)
    {
        case 'a':
        case 'A':
            return ".-";
            break;
        case 'b':
        case 'B':
            return "-...";
            break;
        case 'c':
        case 'C':
            return "-.-.";
            break;
        case 'd':
        case 'D':
            return "-..";
            break;
        case 'e':
        case 'E':
            return ".";
            break;
        case 'f':
        case 'F':
            return "..-.";
            break;
        case 'g':
        case 'G':
            return "--.";
            break;
        case 'h':
        case 'H':
            return "....";
            break;
        case 'i':
        case 'I':
            return "..";
            break;
        case 'j':
        case 'J':
            return ".---";
            break;
        case 'k':
        case 'K':
            return "-.-";
            break;
        case 'l':
        case 'L':
            return ".-..";
            break;
        case 'm':
        case 'M':
            return "--";
            break;
        case 'n':
        case 'N':
            return "-.";
            break;
        case 'o':
        case 'O':
            return "---";
            break;
        case 'p':
        case 'P':
            return ".--.";
            break;
        case 'q':
        case 'Q':
            return "--.-";
            break;
        case 'r':
        case 'R':
            return ".-.";
            break;
        case 's':
        case 'S':
            return "...";
            break;
        case 't':
        case 'T':
            return "-";
            break;
        case 'u':
        case 'U':
            return "..-";
            break;
        case 'v':
        case 'V':
            return "...-";
            break;
        case 'w':
        case 'W':
            return ".--";
            break;
        case 'x':
        case 'X':
            return "-..-";
            break;
        case 'y':
        case 'Y':
            return "-.--";
            break;
        case 'z':
        case 'Z':
            return "--..";
            break;
        default:
            return "";
            break;
    }
}

int main()
{
    char message[100], morseCode[1000], temp[10];
    int i, j, k;

    printf("Enter a message to convert to Morse Code:\n");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = '\0'; // remove newline character

    printf("\nYour message in Morse Code is:\n");

    for(i=0, k=0; i<strlen(message); i++, k++)
    {
        // convert each character to Morse Code and add to morseCode string
        if(message[i] == ' ')
        {
            strcat(morseCode, "/ "); // add slash separator for words
            k = k + 1;
        }
        else
        {
            strcpy(temp, toMorseCode(message[i]));
            for(j=0; j<strlen(temp); j++)
            {
                morseCode[k] = temp[j];
                k++;
            }
            morseCode[k] = ' '; // add space separator for letters
        }
    }
    morseCode[k-1] = '\0'; // remove extra space at the end

    printf("%s\n", morseCode);

    return 0;
}