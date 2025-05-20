//FormAI DATASET v1.0 Category: Ebook reader ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

struct Book {
   char title[50];
   char author[50];
   int year;
   char type[50];
   int pages;
};

typedef struct Book book;

void displayBook(book b) {
   printf("\n**********************************\n");
   printf("Title: %s\n", b.title);
   printf("Author: %s\n", b.author);
   printf("Year of Publication: %d\n", b.year);
   printf("Type: %s\n", b.type);
   printf("Number of Pages: %d\n", b.pages);
   printf("\n**********************************\n");
}

void readBookData(book *b) {
   printf("Enter Title: ");
   gets(b->title);
   printf("Enter Author: ");
   gets(b->author);
   printf("Enter Year of Publication: ");
   scanf("%d", &b->year);
   printf("Enter Type: ");
   scanf("%s", b->type);
   printf("Enter Number of Pages: ");
   scanf("%d", &b->pages);
}

void readEbookData(book *b) {
   readBookData(b);
   printf("Enter File Format (PDF, EPUB, MOBI etc.): ");
   scanf("%s", b->type);
   printf("Enter File Size (in MB): ");
   scanf("%d", &b->pages);
}

int main() {
   book myBook;
   readEbookData(&myBook);
   displayBook(myBook);
   return 0;
}