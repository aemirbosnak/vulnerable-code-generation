//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: puzzling
#include <stdio.h>
#include <string.h>

char* to_morse(char c){
    switch(c){
        case 'A': return ".-";
        case 'B': return "-...";
        case 'C': return "-.-.";
        case 'D': return "-..";
        case 'E': return ".";
        case 'F': return "..-.";
        case 'G': return "--.";
        case 'H': return "....";
        case 'I': return "..";
        case 'J': return ".---";
        case 'K': return "-.-";
        case 'L': return ".-..";
        case 'M': return "--";
        case 'N': return "-.";
        case 'O': return "---";
        case 'P': return ".--.";
        case 'Q': return "--.-";
        case 'R': return ".-.";
        case 'S': return "...";
        case 'T': return "-";
        case 'U': return "..-";
        case 'V': return "...-";
        case 'W': return ".--";
        case 'X': return "-..-";
        case 'Y': return "-.--";
        case 'Z': return "--..";
        case '0': return "-----";
        case '1': return ".----";
        case '2': return "..---";
        case '3': return "...--";
        case '4': return "....-";
        case '5': return ".....";
        case '6': return "-....";
        case '7': return "--...";
        case '8': return "---..";
        case '9': return "----.";
        case ' ': return "/";
        default: return "";
    }
}

void convert_to_morse(const char* s){
    int len = strlen(s);
    printf("Morse code of \"%s\":\n", s);
    for(int i = 0; i < len; i++){
        char c = s[i];
        char* morse = to_morse(c);
        printf("%s ", morse);
    }
    printf("\n");
}

void puzzler(){
    printf("What is the message you want to encode in Morse code? ");
    char s[100];
    scanf("%[^\n]", s);
    convert_to_morse(s);
    printf("Did you solve the puzzle? Type the Morse code to find out.\n");
    printf("Morse code: ");
    scanf(" %[^\n]", s);
    printf("Decoded message: ");
    int len = strlen(s);
    char code[6];
    int j = 0;
    for(int i = 0; i < len; i++){
        if(s[i] == ' ' || i == len - 1){
            if(i == len - 1) code[j] = s[i];
            j++;
            code[j] = '\0';
            for(int k = 0; k < 36; k++){
                char* morse = to_morse('A' + k);
                if(strcmp(morse, code) == 0){
                    printf("%c", 'A' + k);
                    break;
                }
            }
            j = 0;
        }
        else{
            code[j] = s[i];
            j++;
        }
    }
    printf("\n");
}

int main(){
    printf("Welcome to the Morse Code Puzzler!\n");
    printf("Can you solve this puzzle and decode the message?\n");
    puzzler();
    printf("Thanks for playing the Morse Code Puzzler!\n");
    return 0;
}