//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define GlyphTableSize 1024

typedef struct {
    char alien_glyph;
    char terrestrial_char;
} Glyph;

Glyph glyph_table[GlyphTableSize];

int load_glyph_table_from_file(const char* filename) {
    FILE *file;
    int i = 0;

    file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return 1;
    }

    while (fscanf(file, "%c%c", &glyph_table[i].alien_glyph, &glyph_table[i].terrestrial_char) != EOF) {
        i++;
    }

    fclose(file);

    return 0;
}

void decode_alien_message(const char* alien_message) {
    int i;
    int message_length = strlen(alien_message);

    for (i = 0; i < message_length; i++) {
        if (isalnum(alien_message[i])) {
            putchar(tolower(glyph_table[(int)toupper(alien_message[i]) - 'A']
                                .terrestrial_char));
        } else {
            putchar(alien_message[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <glyph_table_file> <alien_message>\n", argv[0]);
        return 1;
    }

    if (load_glyph_table_from_file(argv[1])) {
        return 1;
    }

    decode_alien_message(argv[2]);

    return 0;
}

// Glyph table file example:
// Z Y
// X W
// A V
// B U
// C T
// D S
// E R
// F Q
// G P
// H O
// I N
// J M
// K L
// 1 K
// 2 J
// 3 I
// 4 H
// 5 G
// 6 F
// 7 E
// 8 D
// 9 C
// 0 B
// P Q
// R S
// T U
// V W
// W X
// X Y
// Y Z