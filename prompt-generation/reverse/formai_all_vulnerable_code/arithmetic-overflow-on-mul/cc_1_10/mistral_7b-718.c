//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct {
    char filename[256];
    int pages;
    char *content;
} book;

book *loadBook(char *path) {
    struct stat st;
    int fd;
    book *b;

    fd = open(path, O_RDONLY);
    if (fd < 0) {
        printf("Error opening file: %s\n", path);
        return NULL;
    }

    fstat(fd, &st);
    close(fd);

    b = (book *) malloc(sizeof(book));
    strcpy(b->filename, path);
    b->pages = st.st_size / 25; // assume 50 chars per line and 72 lines per page
    b->content = (char *) malloc(b->pages * 25 * sizeof(char));

    fd = open(path, O_RDONLY);
    for (int i = 0; i < b->pages; i++) {
        read(fd, b->content + i * 25, 25);
    }

    close(fd);

    return b;
}

void printPage(book *b, int page) {
    if (page < 0 || page >= b->pages) {
        printf("Invalid page number: %d\n", page);
        return;
    }

    printf("\nPage %d of %s\n", page + 1, b->filename);
    printf("%s\n", b->content + page * 25);
}

void freeBook(book *b) {
    free(b->content);
    free(b);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <path to book>\n", argv[0]);
        return 1;
    }

    book *b = loadBook(argv[1]);
    if (!b) {
        return 1;
    }

    int choice;
    while (1) {
        printf("\n1. Read page\n2. Quit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int page;
            printf("Enter page number: ");
            scanf("%d", &page);
            printPage(b, page);
        } else if (choice == 2) {
            freeBook(b);
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}