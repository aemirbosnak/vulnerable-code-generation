//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define WIDTH 32
#define HEIGHT 16
#define FONT_FILE "font.txt"

typedef struct {
    char ch;
    unsigned char *data;
} Char;

Char font[95];

void init_font() {
    FILE *fp = fopen(FONT_FILE, "r");

    int i = 0;
    Char c;
    while (fscanf(fp, "%c %[^\n]", &c.ch, &c.data) != EOF) {
        font[i++] = c;
    }

    fclose(fp);
}

void print_ascii(char *text) {
    for (int i = 0; i < strlen(text); i++) {
        for (int j = 0; j < 8; j++) {
            putchar(font[(int)text[i]].data[j]);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    init_font();

    print_ascii(argv[1]);

    return 0;
}

// font.txt format:
// C character
// 8 ASCII codes
// ...
// ....
// ....
// ....
// C character
// 8 ASCII codes
// ...