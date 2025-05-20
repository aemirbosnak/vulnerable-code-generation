//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 50

typedef struct TextBlock {
    char data[MAX_ROWS][MAX_COLS];
    size_t row_count;
} TextBlock;

void initTextBlock(TextBlock* tb) {
    tb->row_count = 0;
}

void appendLine(TextBlock* tb, const char* line) {
    size_t old_rows = tb->row_count;

    if (tb->row_count >= MAX_ROWS) {
        printf("Error: Maximum number of rows reached.\n");
        return;
    }

    TextBlock* new_tb = realloc(tb, sizeof(TextBlock) + (MAX_ROWS - old_rows) * sizeof(char[MAX_COLS]));
    if (new_tb == NULL) {
        printf("Error: Failed to reallocate memory.\n");
        free(tb);
        return;
    }

    tb = new_tb;

    strcpy(tb->data[tb->row_count], line);
    tb->row_count++;
}

void printTextBlock(const TextBlock* tb) {
    for (size_t i = 0; i < tb->row_count; ++i) {
        printf("%s\n", tb->data[i]);
    }
}

int main() {
    TextBlock text_editor;
    initTextBlock(&text_editor);

    char input[MAX_COLS];

    while (1) {
        printf("Enter a line (type 'quit' to exit): ");
        fgets(input, MAX_COLS, stdin);

        if (strchr(input, 'q') != NULL) {
            break;
        }

        input[strlen(input) - 1] = '\0'; // Remove newline character
        appendLine(&text_editor, input);
    }

    printTextBlock(&text_editor);

    free(text_editor.data);
    free(&text_editor);

    return 0;
}