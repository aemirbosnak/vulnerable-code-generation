//Falcon-180B DATASET v1.0 Category: Text processing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *text;
    int length;
} Text;

Text *create_text(char *text) {
    Text *new_text = malloc(sizeof(Text));
    new_text->text = strdup(text);
    new_text->length = strlen(text);
    return new_text;
}

void destroy_text(Text *text) {
    free(text->text);
    free(text);
}

void print_text(Text *text) {
    printf("%s\n", text->text);
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    Text *text = NULL;

    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (text == NULL) {
            text = create_text(line);
        } else {
            Text *new_text = create_text(line);
            text->length += new_text->length + 1; // +1 for newline character
            text->text = realloc(text->text, text->length + 1);
            strcat(text->text, new_text->text);
            destroy_text(new_text);
        }
    }

    fclose(file);

    if (text!= NULL) {
        print_text(text);
        destroy_text(text);
    }

    return 0;
}