//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_POEMS 10

typedef struct {
    char *line;
    size_t len;
} Poem;

Poem poems[MAX_POEMS];
int curr_poem = 0;

void read_poems(void) {
    size_t i;
    char line[MAX_LINE_LENGTH];

    for (i = 0; i < MAX_POEMS; i++) {
        poems[i].line = NULL;
        poems[i].len = 0;
    }

    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        size_t line_len = strlen(line);
        if (line_len > 0 && line[line_len - 1] == '\n') {
            line[line_len - 1] = '\0';
            poems[curr_poem].line = line;
            poems[curr_poem].len = line_len;
            curr_poem++;
        }
    }
}

void print_poems(void) {
    size_t i;

    for (i = 0; i < curr_poem; i++) {
        printf("%s\n", poems[i].line);
    }
}

int main(void) {
    srand(time(NULL));

    read_poems();

    print_poems();

    return 0;
}