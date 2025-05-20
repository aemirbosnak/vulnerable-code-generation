//Falcon-180B DATASET v1.0 Category: Text processing ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

struct TextBlock {
    char *text;
    int length;
    struct TextBlock *next;
};

struct TextBlock *createTextBlock(char *text, int length) {
    struct TextBlock *block = (struct TextBlock *)malloc(sizeof(struct TextBlock));
    block->text = (char *)malloc(length + 1);
    strncpy(block->text, text, length);
    block->text[length] = '\0';
    block->length = length;
    block->next = NULL;
    return block;
}

void appendTextBlock(struct TextBlock **head, char *text, int length) {
    struct TextBlock *block = *head;
    while (block->next!= NULL) {
        block = block->next;
    }
    block->next = createTextBlock(text, length);
}

void printTextBlocks(struct TextBlock *head) {
    while (head!= NULL) {
        printf("%s\n", head->text);
        head = head->next;
    }
}

int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    struct TextBlock *head = NULL;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int length = strlen(line);
        if (length > 0 && line[length - 1] == '\n') {
            line[--length] = '\0';
        }
        appendTextBlock(&head, line, length);
    }

    fclose(file);

    printTextBlocks(head);

    return 0;
}