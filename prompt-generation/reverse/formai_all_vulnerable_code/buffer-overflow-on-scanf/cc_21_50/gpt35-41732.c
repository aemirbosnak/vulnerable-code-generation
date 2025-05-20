//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: energetic
#include <stdio.h>
#include <string.h>

void encodeToMorseCode(char* text){
    int len = strlen(text);
    char morseCode[100];
    for(int i = 0; i < len; i++){
        switch(text[i]){
            case 'a': case 'A':
                strcat(morseCode,".- ");
                break;
            case 'b': case 'B':
                strcat(morseCode,"-... ");
                break;
            case 'c': case 'C':
                strcat(morseCode,"-.-. ");
                break;
            case 'd': case 'D':
                strcat(morseCode,"-.. ");
                break;
            case 'e': case 'E':
                strcat(morseCode,". ");
                break;
            case 'f': case 'F':
                strcat(morseCode,"..-. ");
                break;
            case 'g': case 'G':
                strcat(morseCode,"--. ");
                break;
            case 'h': case 'H':
                strcat(morseCode,".... ");
                break;
            case 'i': case 'I':
                strcat(morseCode,".. ");
                break;
            case 'j': case 'J':
                strcat(morseCode,".--- ");
                break;
            case 'k': case 'K':
                strcat(morseCode,"-.- ");
                break;
            case 'l': case 'L':
                strcat(morseCode,".-.. ");
                break;
            case 'm': case 'M':
                strcat(morseCode,"-- ");
                break;
            case 'n': case 'N':
                strcat(morseCode,"-. ");
                break;
            case 'o': case 'O':
                strcat(morseCode,"--- ");
                break;
            case 'p': case 'P':
                strcat(morseCode,".--. ");
                break;
            case 'q': case 'Q':
                strcat(morseCode,"--.- ");
                break;
            case 'r': case 'R':
                strcat(morseCode,".-. ");
                break;
            case 's': case 'S':
                strcat(morseCode,"... ");
                break;
            case 't': case 'T':
                strcat(morseCode,"- ");
                break;
            case 'u': case 'U':
                strcat(morseCode,"..- ");
                break;
            case 'v': case 'V':
                strcat(morseCode,"...- ");
                break;
            case 'w': case 'W':
                strcat(morseCode,".-- ");
                break;
            case 'x': case 'X':
                strcat(morseCode,"-..- ");
                break;
            case 'y': case 'Y':
                strcat(morseCode,"-.-- ");
                break;
            case 'z': case 'Z':
                strcat(morseCode,"--.. ");
                break;
            case '0':
                strcat(morseCode,"----- ");
                break;
            case '1':
                strcat(morseCode,".---- ");
                break;
            case '2':
                strcat(morseCode,"..--- ");
                break;
            case '3':
                strcat(morseCode,"...-- ");
                break;
            case '4':
                strcat(morseCode,"....- ");
                break;
            case '5':
                strcat(morseCode,"..... ");
                break;
            case '6':
                strcat(morseCode,"-.... ");
                break;
            case '7':
                strcat(morseCode,"--... ");
                break;
            case '8':
                strcat(morseCode,"---.. ");
                break;
            case '9':
                strcat(morseCode,"----. ");
                break;
            case '.':
                strcat(morseCode,".-.-.- ");
                break;
            case ',':
                strcat(morseCode,"--..-- ");
                break;
            case '?':
                strcat(morseCode,"..--.. ");
                break;
            case ' ':
                strcat(morseCode,"/ ");
                break;
        }
    }
    printf("%s\n",morseCode);
}

int main(){
    char text[100];
    printf("Enter text to encode to Morse code: ");
    scanf("%[^\n]s",text);
    printf("\nEncoding to Morse code:\n");
    encodeToMorseCode(text);
    return 0;
}