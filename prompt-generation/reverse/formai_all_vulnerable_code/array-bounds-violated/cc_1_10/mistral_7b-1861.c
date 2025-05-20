//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_NUM_LINES 500

typedef struct {
    char title[100];
    char author[100];
    char** lines;
    int num_lines;
} eBook;

void read_file(FILE* file, eBook* ebook) {
    char line[MAX_LINE_LENGTH];
    int i = 0;

    strcpy(ebook->title, "");
    strcpy(ebook->author, "");

    fgets(line, MAX_LINE_LENGTH, file); // read title
    size_t title_len = strlen(line) - 1;
    if (line[title_len] == ':') title_len--;
    strncpy(ebook->title, line, title_len);

    fgets(line, MAX_LINE_LENGTH, file); // read author
    size_t author_len = strlen(line) - 1;
    if (line[author_len] == ':') author_len--;
    strncpy(ebook->author, line, author_len);

    ebook->num_lines = 0;

    ebook->lines = (char**)calloc(MAX_NUM_LINES, sizeof(char*));

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        if (ebook->num_lines >= MAX_NUM_LINES) {
            printf("Error: too many lines in eBook file.\n");
            exit(1);
        }
        ebook->lines[ebook->num_lines] = (char*)malloc(strlen(line) + 1);
        strcpy(ebook->lines[ebook->num_lines], line);
        ebook->num_lines++;
    }

    fclose(file);
}

void print_ebook(eBook ebook) {
    printf("\n%s by %s\n", ebook.title, ebook.author);

    for (int i = 0; i < ebook.num_lines; i++) {
        printf("%s", ebook.lines[i]);
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <path_to_ebook.txt>\n", argv[0]);
        return 1;
    }

    eBook ebook;
    FILE* file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    read_file(file, &ebook);
    print_ebook(ebook);

    for (int i = 0; i < ebook.num_lines; i++) {
        free(ebook.lines[i]);
    }
    free(ebook.lines);

    fclose(file);
    return 0;
}