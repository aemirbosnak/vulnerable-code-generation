//FormAI DATASET v1.0 Category: Ebook reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>

typedef struct Ebook {
   char title[50];
   char author[50];
   char subject[100];
   int book_id;
   int num_pages;
   char* content;
} Ebook;

Ebook* load_ebook(char* filename) {
   FILE* fp;
   Ebook* ebook;

   ebook = malloc(sizeof(Ebook));

   fp = fopen(filename, "r");
   if (fp == NULL) {
      free(ebook);
      return NULL;
   }

   fscanf(fp, "%s %s", ebook->title, ebook->author);
   fscanf(fp, "%s", ebook->subject);
   fscanf(fp, "%d %d", &ebook->book_id, &ebook->num_pages);

   ebook->content = malloc(sizeof(char) * ebook->num_pages * 1000);

   for (int i = 0; i < ebook->num_pages; i++) {
      fscanf(fp, "%s", ebook->content + i * 1000);
   }

   fclose(fp);

   return ebook;
}

void display_ebook_info(Ebook* ebook) {
   printf("Title: %s\nAuthor: %s\nSubject: %s\nID: %d\nNumber of Pages: %d\n", 
         ebook->title, ebook->author, ebook->subject, ebook->book_id, ebook->num_pages);
}

void display_ebook(Ebook* ebook, int page_num) {
   printf("%s\n", ebook->content + (page_num - 1) * 1000);
}

int main() {
   Ebook* ebook = load_ebook("book.txt");

   if (ebook == NULL) {
      printf("Error: Could not load ebook\n");
      return 1;
   }

   display_ebook_info(ebook);
   display_ebook(ebook, 1);

   free(ebook->content);
   free(ebook);

   return 0;
}