//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 10000

typedef struct {
    char *text;
    int length;
} Text;

Text *read_ebook(FILE *file) {
    Text *ebook = malloc(sizeof(Text));
    if (ebook == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }

    ebook->text = malloc(MAX_CHARS * sizeof(char));
    if (ebook->text == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }

    ebook->length = 0;

    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (ebook->length >= MAX_CHARS - 1) {
            printf("Error: Ebook is too large\n");
            exit(1);
        }

        ebook->text[ebook->length++] = ch;
    }

    ebook->text[ebook->length] = '\0';

    return ebook;
}

void display_ebook(Text *ebook) {
    printf("%s", ebook->text);
}

int main() {
    FILE *file;
    file = fopen("ebook.txt", "r");

    if (file == NULL) {
        printf("Error: Ebook not found\n");
        exit(1);
    }

    Text *ebook = read_ebook(file);

    display_ebook(ebook);

    free(ebook->text);
    free(ebook);

    return 0;
}