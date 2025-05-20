//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A curious way to define a struct
typedef struct {
    char *name;
    char *text;
    int length;
} TextProcessor;

// A curious way to define a function
void processText(TextProcessor *processor) {
    int i;
    for (i = 0; i < processor->length; i++) {
        if (processor->text[i] == ' ') {
            processor->text[i] = '\n';
        }
    }
}

// A curious way to define a main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <text file>\n", argv[0]);
        return 1;
    }

    // A curious way to read a text file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *text = malloc(length + 1);
    if (text == NULL) {
        printf("Error allocating memory for text\n");
        return 1;
    }

    fread(text, 1, length, file);
    fclose(file);

    // A curious way to create a TextProcessor
    TextProcessor processor = { .name = argv[1], .text = text, .length = length };

    // A curious way to call a function
    processText(&processor);

    // A curious way to print the processed text
    printf("%s", processor.text);

    free(text);

    return 0;
}