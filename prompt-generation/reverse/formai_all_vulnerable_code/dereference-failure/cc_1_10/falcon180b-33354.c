//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_BOOK_LENGTH 1000000

typedef struct {
    char* title;
    char* author;
    char* content;
    int length;
} Ebook;

void read_file(Ebook* ebook, FILE* file) {
    char line[MAX_LINE_LENGTH];
    int length = 0;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        length += strlen(line);
        if (length + 1 > MAX_BOOK_LENGTH) {
            printf("Error: book is too long.\n");
            exit(1);
        }
        ebook->content = realloc(ebook->content, length + 1);
        strcat(ebook->content, line);
    }
    ebook->length = length;
}

int main() {
    Ebook ebook;
    ebook.title = NULL;
    ebook.author = NULL;
    ebook.content = NULL;
    ebook.length = 0;

    FILE* file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    read_file(&ebook, file);

    fclose(file);

    printf("Title: %s\n", ebook.title);
    printf("Author: %s\n", ebook.author);
    printf("Content:\n%s", ebook.content);
    printf("Length: %d\n", ebook.length);

    return 0;
}