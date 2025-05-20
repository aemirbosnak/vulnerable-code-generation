//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 20

typedef struct {
    char *title;
    char *author;
    char *content;
    int length;
} Ebook;

Ebook createEbook(char *title, char *author, char *content) {
    Ebook ebook = {
       .title = title,
       .author = author,
       .content = content,
       .length = strlen(content)
    };
    return ebook;
}

void printEbook(Ebook ebook) {
    printf("Title: %s\n", ebook.title);
    printf("Author: %s\n", ebook.author);
    printf("Content:\n%s\n", ebook.content);
}

int main() {
    char title[MAX_WORD_LENGTH];
    char author[MAX_WORD_LENGTH];
    char content[MAX_WORD_LENGTH * 1000];
    int length;

    printf("Enter title: ");
    scanf("%s", title);

    printf("Enter author: ");
    scanf("%s", author);

    printf("Enter content:\n");
    while ((length = fread(content, sizeof(char), MAX_WORD_LENGTH * 1000, stdin))!= 0) {
        content[length - 1] = '\0';
        printf("Content:\n%s\n", content);
        printf("Enter more content? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'n') {
            break;
        }
    }

    Ebook ebook = createEbook(title, author, content);
    printEbook(ebook);

    return 0;
}