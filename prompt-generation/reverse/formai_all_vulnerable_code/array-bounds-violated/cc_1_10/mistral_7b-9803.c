//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 26
char *morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

void morse_encode(char input[], char output[]) {
    int i = 0, j = 0;

    while (input[i] != '\0') {
        if (isalpha(input[i])) {
            i++;
            if (tolower(input[i - 1]) == 'j') {
                strcat(output, morse[4]); // J
                i--;
            }
            strcat(output, morse[input[i] - 'a']); // A to Z
        } else if (input[i] == ' ') {
            strcat(output, "/");
        }
        if (input[i + 1] != '\0')
            strcat(output, " ");
    }
}

int main() {
    char text[100], morse_text[100];

    printf("Enter a text: ");
    fgets(text, sizeof(text), stdin);
    text[strlen(text)] = '\0';

    morse_encode(text, morse_text);

    printf("\nMorse Code:\n%s\n", morse_text);

    printf("\nRomeo: %s\n", morse[12]); // Love
    printf("Juliet: %s\n", morse[10]); // How
    printf("Romeo: %s\n", morse[15]); // Art
    printf("Juliet: %s\n", morse[17]); // Thou
    printf("Romeo: %s\n", morse[1]); // I
    printf("Juliet: %s\n", morse[19]); // Will
    printf("Romeo: %s\n", morse[4]); // J
    printf("Juliet: %s\n", morse[10]); // Love
    printf("Romeo: %s\n", morse[26]); // You
    printf("Juliet: %s\n", morse[15]); // Art
    printf("Romeo: %s\n", morse[1]); // I
    printf("Juliet: %s\n", morse[19]); // Will
    printf("Romeo: %s\n", morse[22]); // Kiss

    return 0;
}