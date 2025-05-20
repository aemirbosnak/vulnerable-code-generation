#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
} Book;

int main(int argc, char *argv[]) {
    FILE *file;
    Book books[100];
    int num_books = 0;
    char title[MAX_TITLE_LENGTH];

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 2;
    }

    while (fscanf(file, "%s%s", books[num_books].title, books[num_books].author) == 2) {
        num_books++;
    }

    fclose(file);

    printf("Enter the title to search for: ");
    scanf("%s", title);

    for (int i = 0; i < num_books; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("Found book: %s by %s\n", books[i].title, books[i].author);
            break;
        }
    }

    return 0;
}
