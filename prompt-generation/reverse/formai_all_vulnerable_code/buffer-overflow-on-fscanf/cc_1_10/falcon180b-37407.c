//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_THREADS 10
#define MAX_LINE_LENGTH 80
#define ASCII_ART_FILE "ascii_art.txt"
#define OUTPUT_FILE "output.txt"

typedef struct {
    char *art;
    int length;
} AsciiArt;

void *generateAsciiArt(void *param);
void writeOutput(AsciiArt *art, FILE *output);

int main() {
    FILE *input, *output;
    AsciiArt art;
    pthread_t threads[MAX_THREADS];
    int i, numThreads = 0;

    input = fopen(ASCII_ART_FILE, "r");
    if (input == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fscanf(input, "%s", art.art)!= EOF) {
        art.length = strlen(art.art);
        if (art.length > MAX_LINE_LENGTH) {
            printf("Error: ASCII art line is too long.\n");
            exit(1);
        }
        numThreads++;
    }

    fclose(input);

    for (i = 0; i < numThreads; i++) {
        pthread_create(&threads[i], NULL, generateAsciiArt, (void *)&art);
    }

    for (i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    output = fopen(OUTPUT_FILE, "w");
    if (output == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    for (i = 0; i < numThreads; i++) {
        writeOutput(&art, output);
    }

    fclose(output);

    return 0;
}

void *generateAsciiArt(void *param) {
    AsciiArt *art = (AsciiArt *)param;
    int i, j;

    for (i = 0; i < art->length; i++) {
        for (j = 0; j < art->length; j++) {
            fprintf(stdout, "%c", art->art[j]);
        }
        fprintf(stdout, "\n");
    }

    return NULL;
}

void writeOutput(AsciiArt *art, FILE *output) {
    int i, j;

    for (i = 0; i < art->length; i++) {
        for (j = 0; j < art->length; j++) {
            fprintf(output, "%c", art->art[j]);
        }
        fprintf(output, "\n");
    }
}