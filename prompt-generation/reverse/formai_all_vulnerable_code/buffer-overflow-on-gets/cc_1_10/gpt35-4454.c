//FormAI DATASET v1.0 Category: Database querying ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
   int id;
   char title[50];
   char author[50];
   float price;
} Book;

int main() {
   FILE *fp;
   int n, i;
   char searchTitle[50];
   int found = 0;

   fp = fopen("books.dat", "rb");
   if (fp == NULL) {
      printf("Error opening file!\n");
      exit(1);
   }

   printf("Enter the title of the book you want to search for: ");
   gets(searchTitle);

   fseek(fp, 0, SEEK_END);
   n = ftell(fp) / sizeof(Book);
   rewind(fp);

   Book *books = (Book*)malloc(n*sizeof(Book));

   fread(books, sizeof(Book), n, fp);

   for (i = 0; i < n; i++) {
      if (strcmp(searchTitle, books[i].title) == 0) {
         printf("Book Found\n");
         printf("ID: %d\n", books[i].id);
         printf("Title: %s\n", books[i].title);
         printf("Author: %s\n", books[i].author);
         printf("Price: %.2f\n", books[i].price);
         found = 1;
      }
   }

   if (!found) {
      printf("Book not found!\n");
   }

   free(books);
   fclose(fp);

   return 0;
}