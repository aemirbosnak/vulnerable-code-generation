//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int file_name;
    int line_number;
    char* text;
} Ebook;

Ebook* create_ebook(int file_name, int line_number, char* text) {
    Ebook* ebook = (Ebook*) malloc(sizeof(Ebook));
    ebook->file_name = file_name;
    ebook->line_number = line_number;
    ebook->text = text;
    return ebook;
}

void read_ebook(Ebook* ebook, char* file_name) {
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'", file_name);
        return;
    }
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);

    ebook->text = (char*) malloc(file_size + 1);
    fread(ebook->text, file_size, 1, file);
    ebook->text[file_size] = '\0';

    fclose(file);
}

void print_ebook(Ebook* ebook) {
    printf("File name: %d\n", ebook->file_name);
    printf("Line number: %d\n", ebook->line_number);
    printf("Text:\n%s\n", ebook->text);
}

int main() {
    int file_name = 1;
    int line_number = 2;
    char* text = "Hello, World!";

    Ebook* ebook = create_ebook(file_name, line_number, text);
    read_ebook(ebook, "example.txt");
    print_ebook(ebook);

    free(ebook->text);
    free(ebook);

    return 0;
}