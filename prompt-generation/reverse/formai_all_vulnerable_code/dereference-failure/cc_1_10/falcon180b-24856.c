//Falcon-180B DATASET v1.0 Category: Text processing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

typedef struct {
    char *text;
    int length;
} Text;

Text *read_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    Text *text = malloc(sizeof(Text));
    text->text = NULL;
    text->length = 0;

    char *buffer = malloc(MAX_LINE_LEN);
    char *line = NULL;
    size_t len = 0;

    while ((line = fgets(buffer, MAX_LINE_LEN, fp))!= NULL) {
        len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }

        if (text->text == NULL) {
            text->text = strdup(line);
            text->length = len;
        } else {
            text->text = realloc(text->text, text->length + len + 1);
            strcat(text->text, line);
            text->length += len;
        }
    }

    free(buffer);
    fclose(fp);

    return text;
}

void process_text(Text *text) {
    char *word = strtok(text->text, " ");
    while (word!= NULL) {
        printf("%s\n", word);
        word = strtok(NULL, " ");
    }
}

void free_text(Text *text) {
    free(text->text);
    free(text);
}

int main() {
    Text *text = read_file("example.txt");
    process_text(text);
    free_text(text);

    return 0;
}