//Falcon2-11B DATASET v1.0 Category: Alien Language Translator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to translate alien language
void translateAlienLanguage(char* input) {
    char* output = (char*)malloc(strlen(input) + 1);
    int i;
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == 'A') {
            output[i] = 'B';
        } else if (input[i] == 'B') {
            output[i] = 'C';
        } else if (input[i] == 'C') {
            output[i] = 'D';
        } else if (input[i] == 'D') {
            output[i] = 'E';
        } else if (input[i] == 'E') {
            output[i] = 'F';
        } else if (input[i] == 'F') {
            output[i] = 'G';
        } else if (input[i] == 'G') {
            output[i] = 'H';
        } else if (input[i] == 'H') {
            output[i] = 'I';
        } else if (input[i] == 'I') {
            output[i] = 'J';
        } else if (input[i] == 'J') {
            output[i] = 'K';
        } else if (input[i] == 'K') {
            output[i] = 'L';
        } else if (input[i] == 'L') {
            output[i] = 'M';
        } else if (input[i] == 'M') {
            output[i] = 'N';
        } else if (input[i] == 'N') {
            output[i] = 'O';
        } else if (input[i] == 'O') {
            output[i] = 'P';
        } else if (input[i] == 'P') {
            output[i] = 'Q';
        } else if (input[i] == 'Q') {
            output[i] = 'R';
        } else if (input[i] == 'R') {
            output[i] = 'S';
        } else if (input[i] == 'S') {
            output[i] = 'T';
        } else if (input[i] == 'T') {
            output[i] = 'U';
        } else if (input[i] == 'U') {
            output[i] = 'V';
        } else if (input[i] == 'V') {
            output[i] = 'W';
        } else if (input[i] == 'W') {
            output[i] = 'X';
        } else if (input[i] == 'X') {
            output[i] = 'Y';
        } else if (input[i] == 'Y') {
            output[i] = 'Z';
        } else {
            output[i] = input[i];
        }
    }
    output[strlen(input)] = '\0';
    printf("Translated output: %s\n", output);
    free(output);
}

int main() {
    char input[100];
    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);
    translateAlienLanguage(input);
    return 0;
}