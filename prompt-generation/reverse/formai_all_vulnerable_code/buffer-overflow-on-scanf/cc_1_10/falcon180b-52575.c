//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *title;
    char *author;
    char *content;
    int length;
} Ebook;

Ebook *create_ebook(char *title, char *author, char *content, int length) {
    Ebook *ebook = (Ebook *) malloc(sizeof(Ebook));
    ebook->title = title;
    ebook->author = author;
    ebook->content = content;
    ebook->length = length;
    return ebook;
}

void display_ebook(Ebook *ebook) {
    printf("Title: %s\n", ebook->title);
    printf("Author: %s\n", ebook->author);
    printf("Length: %d\n", ebook->length);
    printf("Content:\n%s\n", ebook->content);
}

int main() {
    char title[50];
    char author[50];
    char content[500];
    int length;

    // User input for ebook details
    printf("Enter ebook title: ");
    scanf("%s", title);
    printf("Enter ebook author: ");
    scanf("%s", author);
    printf("Enter ebook content:\n");
    fgets(content, sizeof(content), stdin);
    length = strlen(content);

    // Create ebook object
    Ebook *ebook = create_ebook(title, author, content, length);

    // Display ebook details
    display_ebook(ebook);

    // Free ebook object memory
    free(ebook);

    return 0;
}