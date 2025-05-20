#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 256

typedef struct {
    char title[MAX_LINE_LENGTH];
    char author[MAX_LINE_LENGTH];
    int year;
} Book;

void readBooks(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    Book books[100]; // Assuming max 100 books for simplicity
    int count = 0;

    while (count < 100 && fgets(books[count].title, MAX_LINE_LENGTH, file)) {
        if (fgets(books[count].author, MAX_LINE_LENGTH, file) != NULL) {
            fscanf(file, "%d", &books[count].year);
            count++;
        }
    }

    fclose(file);

    printf("Read %d books.\n", count);
}

int main() {
    const char* filename = "books.txt";
    readBooks(filename);
    return 0;
}
