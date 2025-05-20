//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: invasive
#include<stdio.h>
#include<string.h>

// Function to convert text to Morse code
void toMorseCode(char text[]) {
    int i, j;
    char morse[36][10] = {  // Morse code conversion table
        {".-"}, {"-..."}, {"-.-."}, {"-.."},
        {"."}, {"..-."}, {"--."}, {"...."},
        {".."}, {".---"}, {"-.-"}, {".-.."},
        {"--"}, {"-."}, {"---"}, {".--."},
        {"--.-"}, {".-."}, {"..."}, {"-"},
        {"..-"}, {"...-"}, {".--"}, {"-..-"},
        {"-.--"}, {"--.."}, {".----"}, {"..---"},
        {"...--"}, {"....-"}, {"....."},
        {"-...."}, {"--..."}, {"---.."}, {"----."},
        {"-----"}
    };
    char morseCode[500] = "";
    int morseCodeIndex = 0;
    int textLength = strlen(text);

    for (i = 0; i < textLength; i++) {
        if (text[i] == ' ') {  // If space add "  " to Morse code
            strcat(morseCode, "  ");
        } else {
            for (j = 0; j < 36; j++) {
                if (text[i] == 'A' && j == 0) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == 'B' && j == 1) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == 'C' && j == 2) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == 'D' && j == 3) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == 'E' && j == 4) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == 'F' && j == 5) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == 'G' && j == 6) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == 'H' && j == 7) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == 'I' && j == 8) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == 'J' && j == 9) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == 'K' && j == 10) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == 'L' && j == 11) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == 'M' && j == 12) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == 'N' && j == 13) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == 'O' && j == 14) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == 'P' && j == 15) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == 'Q' && j == 16) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == 'R' && j == 17) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == 'S' && j == 18) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == 'T' && j == 19) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == 'U' && j == 20) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == 'V' && j == 21) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == 'W' && j == 22) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == 'X' && j == 23) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == 'Y' && j == 24) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == 'Z' && j == 25) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == '1' && j == 26) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == '2' && j == 27) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == '3' && j == 28) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == '4' && j == 29) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == '5' && j == 30) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == '6' && j == 31) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == '7' && j == 32) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == '8' && j == 33) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == '9' && j == 34) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                } else if (text[i] == '0' && j == 35) {
                    strcat(morseCode, morse[j]);
                    strcat(morseCode, " ");
                    break;
                }
            }
        }
    }

    printf("The Morse code for \"%s\" is:\n%s", text, morseCode);
}

int main() {
    char text[1000];

    // Asking user to type a statement
    printf("Type a statement to convert it into Morse code:\n");
    gets(text);

    // Converting text to Morse code
    toMorseCode(text);

    return 0;
}