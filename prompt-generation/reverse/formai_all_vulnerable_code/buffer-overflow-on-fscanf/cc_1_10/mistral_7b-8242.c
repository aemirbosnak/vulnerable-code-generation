//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define SHIFT_SIZE 256
#define CHAR_SIZE 8
#define BUFFER_SIZE 1024

typedef struct {
    char shape[CHAR_SIZE];
    char character;
    int polarity;
} Shape;

Shape shapes[SHIFT_SIZE];

void load_shapes() {
    int i;
    FILE *fp;

    fp = fopen("shapes.txt", "r");
    if (fp == NULL) {
        perror("Error opening shapes file");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < SHIFT_SIZE; i++) {
        fscanf(fp, "%s %c %d", shapes[i].shape, &shapes[i].character, &shapes[i].polarity);
    }

    fclose(fp);
}

int analyze_sentiment(char *text) {
    int i, total_polarity = 0;
    char *token;

    token = strtok(text, " ");

    while (token != NULL) {
        for (i = 0; i < SHIFT_SIZE; i++) {
            if (tolower(token[0]) == shapes[i].character) {
                total_polarity += shapes[i].polarity;
                write(STDOUT_FILENO, shapes[i].shape, CHAR_SIZE);
                break;
            }
        }

        if (i == SHIFT_SIZE) {
            write(STDOUT_FILENO, token, 1);
        }

        token = strtok(NULL, " ");
    }

    return total_polarity;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    load_shapes();

    int sentiment = analyze_sentiment(argv[1]);

    printf("Sentiment: %d\n", sentiment);

    return 0;
}