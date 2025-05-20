//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

#define MAX_THREADS 10
#define MAX_LINE_LENGTH 80

typedef struct {
    char *text;
    int start_row;
    int end_row;
} TextBlock;

void *draw_ascii_art(void *arg) {
    TextBlock *block = (TextBlock *) arg;
    int start_row = block->start_row;
    int end_row = block->end_row;
    char *text = block->text;

    for (int i = start_row; i <= end_row; i++) {
        for (int j = 0; j < strlen(text); j++) {
            if (isalpha(text[j])) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return NULL;
}

void split_text(char *text, int num_threads, TextBlock blocks[]) {
    int block_size = strlen(text) / num_threads;
    int remainder = strlen(text) % num_threads;

    for (int i = 0; i < num_threads; i++) {
        blocks[i].text = &text[i * block_size];
        blocks[i].start_row = i * MAX_LINE_LENGTH;
        blocks[i].end_row = (i == num_threads - 1)? MAX_LINE_LENGTH * (i + 1) : MAX_LINE_LENGTH * (i + 1) - remainder;
    }
}

int main() {
    char input_text[1000];
    printf("Enter the text to convert to ASCII art: ");
    scanf("%[^\n]", input_text);

    int num_threads = 4;
    pthread_t threads[MAX_THREADS];
    TextBlock blocks[MAX_THREADS];

    split_text(input_text, num_threads, blocks);

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, draw_ascii_art, (void *) &blocks[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}