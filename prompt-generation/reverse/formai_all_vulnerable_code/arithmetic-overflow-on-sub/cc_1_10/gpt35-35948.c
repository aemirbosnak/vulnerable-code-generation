//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <termios.h>
#include <fcntl.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

struct termios orig_termios;

char *ascii_art[94][8] = {
    { // ' '
        "        ",
        "        ",
        "        ",
        "        ",
        "        ",
        "        ",
        "        ",
        "        "
    },
    { // '!'
        "  ██    ",
        "  ██    ",
        "  ██    ",
        "  ██    ",
        "  ██    ",
        "        ",
        "  ██    ",
        "        "
    },
    { // '\"'
        " ██ ██  ",
        " ██ ██  ",
        "        ",
        "        ",
        "        ",
        "        ",
        "        ",
        "        "
    },
    // more character mappings
};

void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawMode);

    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON | ISIG);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void printArt(char *art[8]) {
    for (int i = 0; i < 8; i++) {
        printf("%s\n", art[i]);
    }
}

void sleep_ms(int milliseconds) {
    usleep(milliseconds * 1000); // usleep takes microseconds
}

int main() {
    enableRawMode();

    while (true) {
        int c = getchar();
        if (c == '\x1b') { // escape character
            break;
        }

        int index = c - 32;
        if (index < 0 || index >= 94) {
            continue;
        }

        char **art = ascii_art[index];
        printArt(art);
        sleep_ms(100);
        printf("\033[8A"); // move cursor up
    }

    return 0;
}