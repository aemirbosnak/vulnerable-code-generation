//FormAI DATASET v1.0 Category: Ebook reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    char author[50];
    char publisher[50];
    int pages;
};

struct Ebook {
    struct Book book;
    int fileSize;
    char* fileData;
};

void readEbook(struct Ebook* ebook) {
    char title[100];
    char author[50];
    char publisher[50];
    int pages;
    int fileSize;
    char* fileData;

    printf("Enter title: ");
    scanf("%s", title);
    printf("Enter author: ");
    scanf("%s", author);
    printf("Enter publisher: ");
    scanf("%s", publisher);
    printf("Enter number of pages: ");
    scanf("%d", &pages);
    printf("Enter file size in KB: ");
    scanf("%d", &fileSize);

    ebook->book.pages = pages;
    ebook->fileSize = fileSize;

    strcpy(ebook->book.title, title);
    strcpy(ebook->book.author, author);
    strcpy(ebook->book.publisher, publisher);

    ebook->fileData = (char*)malloc(fileSize * sizeof(char));
    printf("Enter file data: ");
    getchar();
    fgets(ebook->fileData, fileSize, stdin);
}

void displayEbook(struct Ebook ebook) {
    printf("\nTitle: %s\nAuthor: %s\nPublisher: %s\nNumber of Pages: %d\nFile Size: %d KB\nFile Data: %s", ebook.book.title, ebook.book.author, ebook.book.publisher, ebook.book.pages, ebook.fileSize, ebook.fileData);
}

int main() {
    struct Ebook ebook;

    readEbook(&ebook);
    displayEbook(ebook);

    return 0;
}