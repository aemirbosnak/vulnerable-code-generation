//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000

typedef struct {
    int num_lines;
    char *lines[MAX_NUM_LINES];
} Ebook;

Ebook* create_ebook() {
    Ebook* ebook = (Ebook*)malloc(sizeof(Ebook));
    ebook->num_lines = 0;
    for (int i = 0; i < MAX_NUM_LINES; i++) {
        ebook->lines[i] = NULL;
    }
    return ebook;
}

void destroy_ebook(Ebook* ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        free(ebook->lines[i]);
    }
    free(ebook);
}

void read_ebook_file(Ebook* ebook, FILE* file) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        ebook->lines[ebook->num_lines] = strdup(line);
        ebook->num_lines++;
    }
}

void print_ebook(Ebook* ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        printf("%s\n", ebook->lines[i]);
    }
}

int main() {
    Ebook* ebook = create_ebook();
    FILE* file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    read_ebook_file(ebook, file);
    fclose(file);
    print_ebook(ebook);
    destroy_ebook(ebook);
    return 0;
}