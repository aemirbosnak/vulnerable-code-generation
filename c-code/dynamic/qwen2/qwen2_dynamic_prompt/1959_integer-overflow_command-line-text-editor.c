#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100

typedef struct {
    char *text;
    int length;
} Line;

void add_line(Line *lines, const char *line) {
    lines[lines->length].text = strdup(line);
    lines[lines->length].length = strlen(line);
    lines->length++;
}

void print_lines(Line *lines) {
    for (int i = 0; i < lines->length; i++) {
        printf("%s\n", lines[i].text);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    Line lines[MAX_LINES];
    lines->length = 0;

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        add_line(lines, buffer);
    }

    fclose(file);

    print_lines(lines);

    // Integer overflow vulnerability
    int index = lines->length;
    index += 1000000000; // This will cause an integer overflow

    if (index >= MAX_LINES) {
        printf("Buffer overflow detected!\n");
    } else {
        add_line(lines, "This line should not be added.");
    }

    for (int i = 0; i < lines->length; i++) {
        free(lines[i].text);
    }

    return 0;
}
