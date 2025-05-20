//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *data;
    size_t size;
} String;

String *read_line(FILE *file) {
    char buffer[MAX_LINE_SIZE];
    String *line = malloc(sizeof(String));
    line->data = malloc(MAX_LINE_SIZE);
    line->size = 0;

    while (fgets(buffer, MAX_LINE_SIZE, file)) {
        if (line->size + strlen(buffer) >= MAX_LINE_SIZE) {
            fprintf(stderr, "Line too long, truncating.\n");
            break;
        }
        strcat(line->data, buffer);
        line->size += strlen(buffer);
    }

    if (feof(file)) {
        line->data[line->size] = '\0';
    } else {
        line->data[line->size] = '\n';
        line->size++;
    }

    return line;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 2;
    }

    String *header = read_line(file);
    String *row;
    while ((row = read_line(file))!= NULL) {
        int i;
        for (i = 0; i < strlen(header->data); i++) {
            if (header->data[i] == ',') {
                printf("%s\n", row->data);
                break;
            }
        }
        free(row->data);
        free(row);
    }
    free(header->data);
    free(header);

    fclose(file);
    return 0;
}