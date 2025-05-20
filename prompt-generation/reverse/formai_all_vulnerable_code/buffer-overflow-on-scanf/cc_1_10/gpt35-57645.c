//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: artistic
#include <stdio.h>
#include <string.h>

void convertToMorse(char *message, int *morse) {

    // Morse Code Array for each letter a-z and 0-9.
    const int morseCode[36][5] = {
    
        {1, 0, 2, 0, 0},   // A
        {2, 0, 1, 0, 1},   // B
        {2, 0, 1, 0, 2},   // C
        {2, 0, 1, 0, 0},   // D
        {1, 0, 0, 0, 0},   // E
        {1, 0, 1, 0, 2},   // F
        {2, 0, 2, 0, 1},   // G
        {1, 0, 1, 0, 1},   // H
        {1, 0, 0, 0, 0},   // I
        {1, 0, 2, 0, 2},   // J
        {2, 0, 1, 0, 1},   // K
        {1, 0, 2, 0, 1},   // L
        {2, 0, 2, 0, 0},   // M
        {2, 0, 1, 0, 0},   // N
        {2, 0, 2, 0, 2},   // O
        {1, 0, 2, 0, 1},   // P
        {2, 0, 2, 0, 1},   // Q
        {1, 0, 2, 0, 0},   // R
        {1, 0, 1, 0, 0},   // S
        {2, 0, 0, 0, 0},   // T
        {1, 0, 1, 0, 2},   // U
        {1, 0, 1, 0, 1},   // V
        {1, 0, 2, 0, 2},   // W
        {2, 0, 1, 0, 2},   // X
        {2, 0, 2, 0, 1},   // Y
        {2, 0, 1, 0, 1},   // Z
        {2, 2, 2, 2, 2},   // 0
        {1, 2, 2, 2, 2},   // 1
        {1, 1, 2, 2, 2},   // 2
        {1, 1, 1, 2, 2},   // 3
        {1, 1, 1, 1, 2},   // 4
        {1, 1, 1, 1, 1},   // 5
        {2, 1, 1, 1, 1},   // 6
        {2, 2, 1, 1, 1},   // 7
        {2, 2, 2, 1, 1},   // 8
        {2, 2, 2, 2, 1}    // 9
    
    };
    
    int i, j;
    for(i=0; i<strlen(message); i++) {
        
        int ascii = message[i];
        
        // Lower case to Upper case
        if(ascii >=97 && ascii <= 122)
            ascii -= 32;
        
        if(ascii >=65 && ascii <= 90) {
            
            // A=0, B=1...Z=25, Using ascii-65 index is best.
            int index = ascii - 65;
            
            // Morse code for each character is 5-bit.
            for(j=0; j<5; j++)
                morse[i*5+j] = morseCode[index][j];
            
        } else {
            // Numeric data.
            int index = ascii - 48 + 26;
            for(j=0; j<5; j++)
                morse[i*5+j] = morseCode[index][j];
        }
        
    }

}

void printMorse(int *morse, int len) {

    int i, j;
    for(i=0; i<len; i++) {
        
        if(morse[i] == 1)
            printf(".");
        else if(morse[i] == 2)
            printf("-");
        
        if((i+1) % 5 == 0)
            printf(" ");
        
    }

    printf("\n");

}

int main() {

    char message[100];
    int morse[500];
    
    printf("Enter a message to convert to Morse Code:\n");
    scanf("%[^\n]s", message);
    
    convertToMorse(message, morse);
    printMorse(morse, strlen(message)*5);
    
    return 0;
}