//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_CODE_LENGTH 6
#define DOT_DURATION 0.1
#define DASH_DURATION 0.3

void play_sound(int duration) {
    system("afplay /System/Library/Sounds/Sosumi.aiff");
}

void play_dot() {
    play_sound(DOT_DURATION);
}

void play_dash() {
    play_sound(DASH_DURATION);
}

void play_morse_code(char *code) {
    char *p = code;
    while (*p) {
        if (*p == '.') {
            play_dot();
        } else if (*p == '-') {
            play_dash();
        }
        p++;
    }
}

void convert_to_morse_code(char *input) {
    char *p = input;
    char *q = input;
    char morse_code[MAX_CODE_LENGTH];
    int i = 0;
    while (*p) {
        if (isalpha(*p)) {
            if (isupper(*p)) {
                *morse_code = 'A';
                p++;
            } else {
                *morse_code = 'a';
                p++;
            }
            while (isalpha(*p)) {
                p++;
            }
            if (i == 0) {
                strcat(morse_code, " ");
            }
            play_morse_code(morse_code);
            i++;
        } else {
            p++;
        }
    }
}

int main() {
    char input[1000];
    printf("Enter the text to convert to Morse code: ");
    scanf("%s", input);
    convert_to_morse_code(input);
    return 0;
}