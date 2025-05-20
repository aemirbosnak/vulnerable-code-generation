//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096
#define LINE_SIZE 1024

int main(int argc, char **argv)
{
    FILE *file;
    char *buffer, *line, *line_start;
    size_t len = 0, file_size = 0;
    int ch;

    if (argc != 2) {
        printf("Usage: %s <ebook.txt>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "rb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer = malloc(BUFFER_SIZE);
    line = malloc(LINE_SIZE);

    while ((len = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        size_t i, pos = 0;

        while ((ch = buffer[pos]) != '\n' && pos < len) {
            if (ch == '\r') {
                if (buffer[pos + 1] == '\n') {
                    pos++;
                }
                continue;
            }
            if (pos + LINE_SIZE < len) {
                line_start = line;
                for (i = 0; i < LINE_SIZE - 1; i++) {
                    *line++ = ch;
                    if (ch == '\r' || ch == '\n') {
                        break;
                    }
                }
                *line = '\0';
                printf("%s\n", line_start);
                memmove(line, line_start, strlen(line_start) + 1);
            } else {
                size_t new_len = LINE_SIZE * 2;
                line = realloc(line, new_len);
                for (; pos < len; pos++) {
                    *line++ = buffer[pos];
                    if (buffer[pos] == '\n') {
                        *line++ = '\0';
                        printf("%s\n", line - LINE_SIZE);
                        memmove(line, line_start, strlen(line_start) + 1);
                        break;
                    }
                }
            }
            pos++;
        }
    }

    if (ferror(file)) {
        perror("Error reading file");
        return 1;
    }

    free(buffer);
    free(line);
    fclose(file);

    return 0;
}