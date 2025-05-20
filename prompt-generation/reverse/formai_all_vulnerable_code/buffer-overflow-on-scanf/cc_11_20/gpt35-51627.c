//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

char* morse(char c);
void convertToMorse(char *text);

int main(){
    char text[100];
    printf("Enter the text: ");
    scanf("%[^\n]", text);

    convertToMorse(text);

    return 0;
}

char* morse(char c){
    switch(c)
    {
        case 'A':
        case 'a':
            return ".-";
            break;
        case 'B':
        case 'b':
            return "-...";
            break;
        case 'C':
        case 'c':
            return "-.-.";
            break;
        case 'D':
        case 'd':
            return "-..";
            break;
        case 'E':
        case 'e':
            return ".";
            break;
        case 'F':
        case 'f':
            return "..-.";
            break;
        case 'G':
        case 'g':
            return "--.";
            break;
        case 'H':
        case 'h':
            return "....";
            break;
        case 'I':
        case 'i':
            return "..";
            break;
        case 'J':
        case 'j':
            return ".---";
            break;
        case 'K':
        case 'k':
            return "-.-";
            break;
        case 'L':
        case 'l':
            return ".-..";
            break;
        case 'M':
        case 'm':
            return "--";
            break;
        case 'N':
        case 'n':
            return "-.";
            break;
        case 'O':
        case 'o':
            return "---";
            break;
        case 'P':
        case 'p':
            return ".--.";
            break;
        case 'Q':
        case 'q':
            return "--.-";
            break;
        case 'R':
        case 'r':
            return ".-.";
            break;
        case 'S':
        case 's':
            return "...";
            break;
        case 'T':
        case 't':
            return "-";
            break;
        case 'U':
        case 'u':
            return "..-";
            break;
        case 'V':
        case 'v':
            return "...-";
            break;
        case 'W':
        case 'w':
            return ".--";
            break;
        case 'X':
        case 'x':
            return "-..-";
            break;
        case 'Y':
        case 'y':
            return "-.--";
            break;
        case 'Z':
        case 'z':
            return "--..";
            break;
        case ' ':
            return "/";
            break;
        default:
            return "";
            break;
    }
}

void convertToMorse(char *text){
    int i;
    char morseCode[1000] = "";

    for(i = 0; i < strlen(text); i++){
        strcat(morseCode, morse(text[i]));
        strcat(morseCode, " ");
    }

    printf("Morse Code: %s", morseCode);
}