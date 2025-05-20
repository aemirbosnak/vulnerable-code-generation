//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_LINE_LENGTH 1000
#define INDENT_SIZE 4

typedef struct {
    char *line;
    int line_num;
} Line;

typedef struct {
    FILE *fp;
    int num_lines;
    Line **lines;
} FileData;

void *beautify_file(void *arg) {
    FileData *data = (FileData*) arg;
    int i;

    for (i = 0; i < data->num_lines; i++) {
        Line *line = data->lines[i];
        int j, k;

        // Indent the line
        for (j = 0, k = 0; j < line->line_num * INDENT_SIZE; j++) {
            fprintf(data->fp, " ");
        }

        // Print the line
        fprintf(data->fp, "%s\n", line->line);
    }

    return NULL;
}

void read_file(char *filename, FileData *data) {
    FILE *fp = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];
    int line_num = 1;

    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    data->fp = fp;
    data->num_lines = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        Line *new_line = (Line*) malloc(sizeof(Line));
        new_line->line = strdup(line);
        new_line->line_num = line_num;

        data->lines = (Line**) realloc(data->lines, sizeof(Line*) * ++data->num_lines);
        data->lines[data->num_lines - 1] = new_line;

        line_num++;
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    pthread_t threads[MAX_THREADS];
    FileData data;
    int i;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    read_file(argv[1], &data);

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, beautify_file, &data);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}