//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: accurate
#include<stdio.h>
#include<string.h>

// Morse Code Structure
struct MorseCode{
    char letter;
    char code[6];
}morseCodeArr[]={
    {'a',".-"},
    {'b',"-..."},
    {'c',"-.-."},
    {'d',"-.."},
    {'e',"."},
    {'f',"..-."},
    {'g',"--."},
    {'h',"...."},
    {'i',".."},
    {'j',".---"},
    {'k',"-.-"},
    {'l',".-.."},
    {'m',"--"},
    {'n',"-."},
    {'o',"---"},
    {'p',".--."},
    {'q',"--.-"},
    {'r',".-."},
    {'s',"..."},
    {'t',"-"},
    {'u',"..-"},
    {'v',"...-"},
    {'w',".--"},
    {'x',"-..-"},
    {'y',"-.--"},
    {'z',"--.."},
    {'0',"-----"},
    {'1',".----"},
    {'2',"..---"},
    {'3',"...--"},
    {'4',"....-"},
    {'5',"....."},
    {'6',"-...."},
    {'7',"--..."},
    {'8',"---.."},
    {'9',"----."},
    {' '," "}
};

const int MorseCodeArraySize = sizeof(morseCodeArr)/sizeof(morseCodeArr[0]);

// Function to convert text to morse code
void textToMorseCode(char* text, char* morseCode){
    int i, j, k;
    for(i=0; text[i]!='\0'; i++){
        if(text[i]>='A'&&text[i]<='Z'){
            text[i] = text[i] + 32;
        }
        for(j=0; j<MorseCodeArraySize; j++){
            if(text[i] == morseCodeArr[j].letter){
                for(k=0; morseCodeArr[j].code[k]!='\0'; k++){
                    strcat(morseCode, " ");
                    strcat(morseCode, morseCodeArr[j].code);
                }
                strcat(morseCode, "  ");
                break;
            }
        }
    }
}

// Sample client code
int main(){
    char text[1000], morseCode[5000]="";
    printf("Enter the text to convert to Morse code\n");
    gets(text);
    textToMorseCode(text, morseCode);
    printf("Morse code of given text:\n\n%s", morseCode);
    return 0;
}