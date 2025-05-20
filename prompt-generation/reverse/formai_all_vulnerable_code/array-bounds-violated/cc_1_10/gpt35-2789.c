//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char morseTable[27][5] = {
    {".-"}, {"-..."}, {"-.-."}, {"-.."},
    {"."}, {"..-."}, {"--."}, {"...."},
    {".."}, {".---"}, {"-.-"}, {".-.."},
    {"--"}, {"-."}, {"---"}, {".--."},
    {"--.-"}, {".-."}, {"..."}, {"-"},
    {"..-"}, {"...-"}, {".--"}, {"-..-"},
    {"-.--"}, {"--.."}
};

char* getMorse(char);

int main() {
    char message[200], ch, *morse;
    int i, j;

    printf("Enter a message: ");
    fgets(message, 200, stdin);

    // Replace any punctuation or extra spaces with a space
    for(i = 0; message[i] != '\0'; i++) {
        if(!isalpha(message[i]) && !isspace(message[i])) {
            message[i] = ' ';
        }

        if(isspace(message[i]) && isspace(message[i - 1])) {
            for(j = i; message[j] != '\0'; j++) {
                message[j] = message[j + 1];
            }
            i--;
        }
    }

    // Convert message to Morse code
    printf("\nMorse Code: ");
    for(i = 0; message[i] != '\0'; i++) {
        ch = toupper(message[i]);
        morse = getMorse(ch);
        printf("%s ", morse);
    }

    return 0;
}

char* getMorse(char ch) {
    if(ch >= 'A' && ch <= 'Z') {
        return morseTable[ch - 'A'];
    } else {
        return " ";
    }
}