//Code Llama-13B DATASET v1.0 Category: HTML beautifier ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void beautify_html(const char *html_code, size_t html_code_len) {
    char buffer[BUFFER_SIZE];
    size_t buffer_index = 0;

    for (size_t i = 0; i < html_code_len; i++) {
        if (html_code[i] == '<') {
            buffer[buffer_index++] = html_code[i];
            buffer[buffer_index++] = '\n';
        } else if (html_code[i] == '>') {
            buffer[buffer_index++] = '\n';
            buffer[buffer_index++] = html_code[i];
        } else {
            buffer[buffer_index++] = html_code[i];
        }
    }

    buffer[buffer_index] = '\0';

    printf("%s\n", buffer);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <html_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    size_t html_code_len = ftell(fp);
    rewind(fp);

    char *html_code = malloc(html_code_len);
    if (html_code == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        return 1;
    }

    size_t bytes_read = fread(html_code, sizeof(char), html_code_len, fp);
    if (bytes_read < html_code_len) {
        fprintf(stderr, "Error reading file\n");
        return 1;
    }

    fclose(fp);

    beautify_html(html_code, html_code_len);

    free(html_code);

    return 0;
}