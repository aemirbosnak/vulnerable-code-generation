//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *text;
    int length;
} Line;

typedef struct {
    Line **lines;
    int num_lines;
} Ebook;

Ebook *ebook_create(void) {
    Ebook *ebook = (Ebook *)malloc(sizeof(Ebook));
    ebook->lines = NULL;
    ebook->num_lines = 0;
    return ebook;
}

void ebook_destroy(Ebook *ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        free(ebook->lines[i]->text);
        free(ebook->lines[i]);
    }
    free(ebook->lines);
    free(ebook);
}

void ebook_load_file(Ebook *ebook, FILE *file) {
    char line_buffer[MAX_LINE_LENGTH];
    while (fgets(line_buffer, MAX_LINE_LENGTH, file)!= NULL) {
        Line *line = (Line *)malloc(sizeof(Line));
        line->text = strdup(line_buffer);
        line->length = strlen(line->text);
        ebook->lines = (Line **)realloc(ebook->lines, sizeof(Line *) * (ebook->num_lines + 1));
        ebook->lines[ebook->num_lines] = line;
        ebook->num_lines++;
    }
}

int main(int argc, char *argv[]) {
    Ebook *ebook = ebook_create();
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    ebook_load_file(ebook, file);
    fclose(file);

    for (int i = 0; i < ebook->num_lines; i++) {
        printf("%d: %s\n", i + 1, ebook->lines[i]->text);
    }

    ebook_destroy(ebook);
    return 0;
}