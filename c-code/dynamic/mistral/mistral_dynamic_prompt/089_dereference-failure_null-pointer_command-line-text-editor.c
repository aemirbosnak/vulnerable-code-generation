#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **lines;
int line_count = 0;
int current_line = 0;

void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        lines[line_count] = malloc(strlen(buffer) + 1);
        strcpy(lines[line_count], buffer);
        line_count++;
    }
    fclose(file);
}

void print_line() {
    if (current_line >= line_count) {
        printf("End of file\n");
        return;
    }
    printf("%s", lines[current_line]);
}

void next_line() {
    current_line++;
}

void previous_line() {
    current_line--;
}

void free_memory() {
    for (int i = 0; i < line_count; i++) {
        free(lines[i]);
    }
    free(lines);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: text_editor filename\n");
        return 1;
    }

    read_file(argv[1]);

    char command[10];
    while (1) {
        print_line();
        scanf("%s", command);
        if (strcmp(command, "q") == 0) {
            break;
        } else if (strcmp(command, "n") == 0) {
            next_line();
        } else if (strcmp(command, "p") == 0) {
            previous_line();
        }
    }

    free_memory();
    return 0;
}
