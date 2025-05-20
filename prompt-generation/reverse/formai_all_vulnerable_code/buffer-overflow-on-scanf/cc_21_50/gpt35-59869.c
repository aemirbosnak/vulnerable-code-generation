//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: authentic
#include <stdio.h>
#include <string.h>

// Function to convert character to morse code
char* charToMorse(char c) {
    if(c == 'a' || c == 'A')
        return ".-";
    else if(c == 'b' || c == 'B')
        return "-...";
    else if(c == 'c' || c == 'C')
        return "-.-.";
    else if(c == 'd' || c == 'D')
        return "-..";
    else if(c == 'e' || c == 'E')
        return ".";
    else if(c == 'f' || c == 'F')
        return "..-.";
    else if(c == 'g' || c == 'G')
        return "--.";
    else if(c == 'h' || c == 'H')
        return "....";
    else if(c == 'i' || c == 'I')
        return "..";
    else if(c == 'j' || c == 'J')
        return ".---";
    else if(c == 'k' || c == 'K')
        return "-.-";
    else if(c == 'l' || c == 'L')
        return ".-..";
    else if(c == 'm' || c == 'M')
        return "--";
    else if(c == 'n' || c == 'N')
        return "-.";
    else if(c == 'o' || c == 'O')
        return "---";
    else if(c == 'p' || c == 'P')
        return ".--.";
    else if(c == 'q' || c == 'Q')
        return "--.-";
    else if(c == 'r' || c == 'R')
        return ".-.";
    else if(c == 's' || c == 'S')
        return "...";
    else if(c == 't' || c == 'T')
        return "-";
    else if(c == 'u' || c == 'U')
        return "..-";
    else if(c == 'v' || c == 'V')
        return "...-";
    else if(c == 'w' || c == 'W')
        return ".--";
    else if(c == 'x' || c == 'X')
        return "-..-";
    else if(c == 'y' || c == 'Y')
        return "-.--";
    else if(c == 'z' || c == 'Z')
        return "--..";
    else if(c == '1')
        return ".----";
    else if(c == '2')
        return "..---";
    else if(c == '3')
        return "...--";
    else if(c == '4')
        return "....-";
    else if(c == '5')
        return ".....";
    else if(c == '6')
        return "-....";
    else if(c == '7')
        return "--...";
    else if(c == '8')
        return "---..";
    else if(c == '9')
        return "----.";
    else if(c == '0')
        return "-----";
    else
        return "";
}

// Function to convert text to morse code
void textToMorse(char* text) {
    int len = strlen(text);
    for(int i=0; i<len; i++) {
        char* morse = charToMorse(text[i]);
        printf("%s ", morse);
    }
}

int main() {
    printf("Enter the text to convert into Morse Code:\n");

    char text[100];
    scanf("%[^\n]", text); // Read the entire line

    printf("\nThe Morse Code is:\n");
    textToMorse(text);

    return 0;
}