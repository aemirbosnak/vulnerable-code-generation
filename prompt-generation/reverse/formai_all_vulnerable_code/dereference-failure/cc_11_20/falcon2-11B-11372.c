//Falcon2-11B DATASET v1.0 Category: Cat Language Translator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void translate(char* input) {
    char* translated = (char*) malloc(strlen(input) * sizeof(char));
    strcpy(translated, input);

    char* cat_language = "meow";
    int length = strlen(cat_language);

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == 'a') {
            translated[i] = cat_language[0];
        } else if (input[i] == 'b') {
            translated[i] = cat_language[1];
        } else if (input[i] == 'c') {
            translated[i] = cat_language[2];
        } else if (input[i] == 'd') {
            translated[i] = cat_language[3];
        } else if (input[i] == 'e') {
            translated[i] = cat_language[4];
        } else if (input[i] == 'f') {
            translated[i] = cat_language[5];
        } else if (input[i] == 'g') {
            translated[i] = cat_language[6];
        } else if (input[i] == 'h') {
            translated[i] = cat_language[7];
        } else if (input[i] == 'i') {
            translated[i] = cat_language[8];
        } else if (input[i] == 'j') {
            translated[i] = cat_language[9];
        } else if (input[i] == 'k') {
            translated[i] = cat_language[10];
        } else if (input[i] == 'l') {
            translated[i] = cat_language[11];
        } else if (input[i] =='m') {
            translated[i] = cat_language[12];
        } else if (input[i] == 'n') {
            translated[i] = cat_language[13];
        } else if (input[i] == 'o') {
            translated[i] = cat_language[14];
        } else if (input[i] == 'p') {
            translated[i] = cat_language[15];
        } else if (input[i] == 'q') {
            translated[i] = cat_language[16];
        } else if (input[i] == 'r') {
            translated[i] = cat_language[17];
        } else if (input[i] =='s') {
            translated[i] = cat_language[18];
        } else if (input[i] == 't') {
            translated[i] = cat_language[19];
        } else if (input[i] == 'u') {
            translated[i] = cat_language[20];
        } else if (input[i] == 'v') {
            translated[i] = cat_language[21];
        } else if (input[i] == 'w') {
            translated[i] = cat_language[22];
        } else if (input[i] == 'x') {
            translated[i] = cat_language[23];
        } else if (input[i] == 'y') {
            translated[i] = cat_language[24];
        } else if (input[i] == 'z') {
            translated[i] = cat_language[25];
        }
    }

    printf("%s\n", translated);
}

int main() {
    char input[100];
    printf("Enter a word: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline

    translate(input);

    return 0;
}