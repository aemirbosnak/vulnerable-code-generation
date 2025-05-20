//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 30

struct Ebook {
    char title[MAX_LINE_LENGTH];
    char author[MAX_LINE_LENGTH];
    char genre[MAX_LINE_LENGTH];
    int num_pages;
    int num_chapters;
};

void read_ebook(struct Ebook* ebook);
void display_ebook(struct Ebook* ebook);

int main() {
    struct Ebook ebook;
    read_ebook(&ebook);
    display_ebook(&ebook);

    return 0;
}

void read_ebook(struct Ebook* ebook) {
    char line[MAX_LINE_LENGTH];
    char* token;

    printf("Enter the title of the ebook: ");
    fgets(line, MAX_LINE_LENGTH, stdin);
    strcpy(ebook->title, line);

    printf("Enter the author of the ebook: ");
    fgets(line, MAX_LINE_LENGTH, stdin);
    strcpy(ebook->author, line);

    printf("Enter the genre of the ebook: ");
    fgets(line, MAX_LINE_LENGTH, stdin);
    strcpy(ebook->genre, line);

    printf("Enter the number of pages: ");
    scanf("%d", &ebook->num_pages);

    printf("Enter the number of chapters: ");
    scanf("%d", &ebook->num_chapters);
}

void display_ebook(struct Ebook* ebook) {
    printf("Title: %s\n", ebook->title);
    printf("Author: %s\n", ebook->author);
    printf("Genre: %s\n", ebook->genre);
    printf("Number of pages: %d\n", ebook->num_pages);
    printf("Number of chapters: %d\n", ebook->num_chapters);
}