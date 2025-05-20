//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 512

typedef struct TextBlock {
    char *text;
    int length;
} TextBlock;

void textBlock_init(TextBlock *block, int size) {
    block->text = malloc(size);
    block->length = 0;
}

void textBlock_append(TextBlock *block, char *str, int len) {
    block->text = realloc(block->text, block->length + len + 1);
    memcpy(block->text + block->length, str, len);
    block->length += len;
}

void textBlock_summary(TextBlock *block) {
    char *summary = malloc(block->length / 4);
    int i = 0;
    for (i = 0; i < block->length; i++) {
        if (block->text[i] != ' ') {
            summary[i] = block->text[i];
        } else {
            summary[i] = '\0';
        }
    }
    printf("%s", summary);
    free(summary);
}

int main() {
    TextBlock *block = NULL;
    textBlock_init(block, MAX_BUFFER_SIZE);

    textBlock_append(block, "This is a text block.", 20);
    textBlock_append(block, "It has been appended with a string.", 30);

    textBlock_summary(block);

    free(block->text);
    free(block);

    return 0;
}