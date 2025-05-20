//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char morse[64][10] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", 
                      "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", 
                      ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----",
                      "--..--", ".-.-.-", "..--..", "-.-.--"};

char possibleChars[64] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 
                          'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', 
                          '3', '4', '5', '6', '7', '8', '9', '0', ',', '.', '?', '!'};

char* convertToMorse(char* text) {
    int textLength = strlen(text);
    char* output = malloc(4 * textLength);
    int j = 0;
    for(int i = 0; i < textLength; i++) {
        if(text[i] >= 'a' && text[i] <= 'z') {
            text[i] = text[i] - 'a' + 'A';
        }
        if(text[i] == ' ') {
            output[j++] = '/';
        } else {
            int index = -1;
            for(int k = 0; k < 64; k++) {
                if(text[i] == possibleChars[k]) {
                    index = k;
                    break;
                }
            }
            if(index != -1) {
                strcpy(&output[j], morse[index]);
                j += strlen(morse[index]);
            }
        }
        output[j++] = ' ';
    }
    output[j] = '\0';
    return output;
}

int main() {
    char input[200];
    printf("Enter the text: ");
    scanf("%[^\n]s", input);
    char* output = convertToMorse(input);
    printf("Morse code: %s\n", output);
    free(output);
    return 0;
}