//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *text;
    int len;
} Text;

Text load_text(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int len = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *text = malloc(len + 1);
    if (text == NULL) {
        perror("malloc");
        exit(1);
    }

    fread(text, 1, len, fp);
    text[len] = '\0';

    fclose(fp);

    return (Text) {
        .text = text,
        .len = len
    };
}

void free_text(Text text) {
    free(text.text);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    Text text = load_text(argv[1]);

    printf("Type the following text as quickly as possible:\n\n");
    printf("%s\n", text.text);

    clock_t start = clock();

    char *input = malloc(text.len + 1);
    if (input == NULL) {
        perror("malloc");
        exit(1);
    }

    scanf("%s", input);

    clock_t end = clock();

    free(input);

    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    double speed = (double)text.len / elapsed;

    printf("\nTime taken: %.2f seconds\n", elapsed);
    printf("Typing speed: %.2f characters per second\n", speed);

    free_text(text);

    return 0;
}