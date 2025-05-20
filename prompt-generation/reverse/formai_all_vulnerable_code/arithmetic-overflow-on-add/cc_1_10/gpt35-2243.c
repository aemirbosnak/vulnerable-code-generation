//FormAI DATASET v1.0 Category: Ebook reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num_of_books, num_of_chapters, num_of_pages;
   printf("Enter the number of books: ");
   scanf("%d", &num_of_books);
   
   printf("Enter the number of chapters: ");
   scanf("%d", &num_of_chapters);
   
   printf("Enter the number of pages: ");
   scanf("%d", &num_of_pages);
   
   int total_pages = num_of_books * num_of_chapters * num_of_pages;
   
   if(total_pages < 500) {
      printf("This Ebook reader can only hold 500 pages. Please reduce your input.\n");
      exit(1); // terminate the program
   }
   
   int book_index, chapter_index, page_index;
   
   do {
      printf("Enter the book index: ");
      scanf("%d", &book_index);
      if(book_index > num_of_books) {
         printf("Out of range. Try again.\n");
      }
   } while(book_index > num_of_books);
   
   do {
      printf("Enter the chapter index: ");
      scanf("%d", &chapter_index);
      if(chapter_index > num_of_chapters) {
         printf("Out of range. Try again.\n");
      }
   } while(chapter_index > num_of_chapters);
   
   do {
      printf("Enter the page index: ");
      scanf("%d", &page_index);
      if(page_index > num_of_pages) {
         printf("Out of range. Try again.\n");
      }
   } while(page_index > num_of_pages);
   
   int current_page_index = (book_index-1)*num_of_chapters*num_of_pages + (chapter_index-1)*num_of_pages + page_index;
   
   printf("You are currently on page %d out of %d total pages.\n", current_page_index, total_pages);
   
   return 0;
}