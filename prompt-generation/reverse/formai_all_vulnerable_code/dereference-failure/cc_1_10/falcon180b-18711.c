//Falcon-180B DATASET v1.0 Category: Text processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *text;
    size_t length;
} Text;

void Text_init(Text *text) {
    text->text = NULL;
    text->length = 0;
}

void Text_append(Text *text, const char *str) {
    char *new_text = realloc(text->text, text->length + strlen(str) + 1);
    if (new_text == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }
    text->text = new_text;
    strcat(text->text, str);
    text->length += strlen(str);
}

void Text_print(const Text *text) {
    printf("%s", text->text);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: No input file specified\n");
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Could not open input file\n");
        return 1;
    }

    Text input_text = {NULL, 0};
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        Text_append(&input_text, line);
    }

    fclose(input_file);

    Text_print(&input_text);

    return 0;
}