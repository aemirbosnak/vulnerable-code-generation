//FormAI DATASET v1.0 Category: Ebook reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BOOKS 100

typedef struct {
   char title[50];
   char author[50];
   char format[10];
   double size_MB;
   int year_published;
} book;

int main() {
   book books[MAX_BOOKS];
   int num_books = 0;
   bool exit_program = false;
   char choice;

   while (!exit_program) {
      printf("\nC EBOOK READER\n");
      printf("1. Add a book\n");
      printf("2. Display books\n");
      printf("3. Quit\n");
      printf("Enter choice: ");
      scanf(" %c", &choice);

      if (choice == '1') {
         if (num_books < MAX_BOOKS) {
            printf("\nEnter book title: ");
            scanf("%s", books[num_books].title);
            printf("Enter author: ");
            scanf("%s", books[num_books].author);
            printf("Enter format (PDF, EPUB, MOBI, etc.): ");
            scanf("%s", books[num_books].format);
            printf("Enter size in MB: ");
            scanf("%lf", &books[num_books].size_MB);
            printf("Enter year published: ");
            scanf("%d", &books[num_books].year_published);
            num_books++;
         }
         else {
            printf("\nMaximum number of books reached.\n");
         }
      }
      else if (choice == '2') {
         if (num_books > 0) {
            printf("\n%-20s %-20s %-10s %-10s %-10s\n", "Title", "Author", "Format", "Size(MB)", "Year Published");
            for (int i = 0; i < num_books; i++) {
               printf("%-20s %-20s %-10s %-10.2f %-10d\n", books[i].title, books[i].author, books[i].format, books[i].size_MB, books[i].year_published);
            }
         }
         else {
            printf("\nNo books to display.\n");
         }
      }
      else if (choice == '3') {
         printf("\nExiting program...\n");
         exit_program = true;
      }
      else {
         printf("\nInvalid choice. Please try again.\n");
      }
   }

   return 0;
}