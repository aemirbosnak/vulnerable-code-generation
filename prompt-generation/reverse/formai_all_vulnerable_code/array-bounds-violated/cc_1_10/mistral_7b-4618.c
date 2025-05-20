//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <stdlib.h>

#define MAX_SIZE 1024

// Morse code lookup table
const char *morse[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."
};

void init_serial() {
    struct termios options;
    tcgetattr(STDIN_FILENO, &options);

    options.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &options);
}

void print_morse(char c) {
    if (isalpha(c) || isdigit(c) || c == ' ') {
        printf("%s ", morse[c - 'A' + 26 * (isdigit(c) ? (c - '0') : 0)]);
    } else if (c == '.') {
        printf(".");
    } else if (c == '-') {
        printf("-");
    } else if (c == ' ') {
        printf("/");
    } else {
        printf("%c", c);
    }
}

int main() {
    init_serial();

    while (1) {
        char input;
        input = getchar();
        if (feof(stdin)) {
            break;
        }
        print_morse(input);
    }

    init_serial();
    return 0;
}