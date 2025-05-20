//LLAMA2-13B DATASET v1.0 Category: Database querying ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAGIC_CONSTANT 42

struct Genius {
    int i;
    char magic[MAGIC_CONSTANT];
};

void initGenius(struct Genius *g) {
    g->i = 0;
    memset(g->magic, 0, MAGIC_CONSTANT);
}

void addMagic(struct Genius *g, char c) {
    if (g->i == MAGIC_CONSTANT) {
        printf("Maximum magic reached!\n");
        return;
    }
    g->magic[g->i++] = c;
    if (c == 'a') {
        g->magic[g->i++] = 'b';
        g->magic[g->i++] = 'c';
    } else if (c == 'b') {
        g->magic[g->i++] = 'c';
        g->magic[g->i++] = 'd';
    } else if (c == 'c') {
        g->magic[g->i++] = 'd';
        g->magic[g->i++] = 'e';
    } else if (c == 'd') {
        g->magic[g->i++] = 'e';
        g->magic[g->i++] = 'f';
    }
}

void printMagic(struct Genius *g) {
    printf("Magic: %s\n", g->magic);
}

int main() {
    struct Genius g;
    initGenius(&g);

    char c;
    do {
        printf("Enter a character (a-f): ");
        scanf(" %c", &c);
        addMagic(&g, c);
    } while (c != 'f');

    printMagic(&g);

    return 0;
}