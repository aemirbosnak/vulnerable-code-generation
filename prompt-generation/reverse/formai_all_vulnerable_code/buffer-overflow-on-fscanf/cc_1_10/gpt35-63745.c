//FormAI DATASET v1.0 Category: Ebook reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

/* 
    Program to read and display contents
    of a unique Ebook file format
    called "C Ebook (.cebook)"
*/

typedef struct {
    char title[100];
    char author[100];
    int num_chapters;
} Ebook;

typedef struct {
    int chapter_num;
    char title[100];
    char content[500];
} Chapter;

Ebook load_ebook(char* filename);
Chapter load_chapter(FILE* fp);

int main()
{
    Ebook mybook;
    char filename[100];
    FILE* fp;
    Chapter cur_chapter;
    int i;

    printf("Enter the filename of the C Ebook (.cebook) you want to read: ");
    scanf("%s", filename);

    mybook = load_ebook(filename);

    printf("Title: %s\nAuthor: %s\nNumber of chapters: %d\n", mybook.title, mybook.author, mybook.num_chapters);

    for (i = 1; i <= mybook.num_chapters; i++) {
        sprintf(filename, "%s_chapter%d.txt", mybook.title, i);
        fp = fopen(filename, "r");
        if (fp == NULL) {
            printf("Error: Could not open chapter file %s\n", filename);
            exit(EXIT_FAILURE);
        }
        cur_chapter = load_chapter(fp);
        printf("\nChapter %d: %s\n\n%s\n", cur_chapter.chapter_num, cur_chapter.title, cur_chapter.content);
        fclose(fp);
    }

    return 0;
}

Ebook load_ebook(char* filename) {
    Ebook book;
    FILE* fp;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open ebook file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%s", book.title);
    fscanf(fp, "%s", book.author);
    fscanf(fp, "%d", &book.num_chapters);

    fclose(fp);

    return book;
}

Chapter load_chapter(FILE* fp) {
    Chapter c;

    fscanf(fp, "%d", &c.chapter_num);
    fscanf(fp, "%s", c.title);
    fgets(c.content, 500, fp);

    return c;
}