//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_CHAPTERS 100
#define MAX_CHAPTER_LENGTH 1000

struct book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int num_chapters;
    struct chapter *chapters;
};

struct chapter {
    char title[MAX_CHAPTER_LENGTH];
    char content[MAX_CHAPTER_LENGTH];
};

int main() {
    struct book *books = (struct book *)malloc(MAX_BOOKS * sizeof(struct book));
    int num_books = 0;

    char input[MAX_TITLE_LENGTH];
    while (1) {
        printf("Enter title of book (or 'done' to finish): ");
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }

        struct book *current_book = &books[num_books];
        strcpy(current_book->title, input);

        printf("Enter author of book: ");
        scanf("%s", current_book->author);

        printf("Enter number of chapters: ");
        scanf("%d", &current_book->num_chapters);

        current_book->chapters = (struct chapter *)malloc(current_book->num_chapters * sizeof(struct chapter));

        int chapter_num = 1;
        while (chapter_num <= current_book->num_chapters) {
            printf("Enter title of chapter %d: ", chapter_num);
            scanf("%s", current_book->chapters[chapter_num - 1].title);

            printf("Enter content of chapter %d: ", chapter_num);
            scanf("%s", current_book->chapters[chapter_num - 1].content);

            chapter_num++;
        }

        num_books++;
    }

    printf("List of books:\n");
    for (int i = 0; i < num_books; i++) {
        printf("Title: %s\nAuthor: %s\nNumber of chapters: %d\n", books[i].title, books[i].author, books[i].num_chapters);

        printf("Chapters:\n");
        for (int j = 0; j < books[i].num_chapters; j++) {
            printf("Chapter %d: %s\n", j + 1, books[i].chapters[j].title);
            printf("%s\n", books[i].chapters[j].content);
        }
    }

    free(books);
    return 0;
}