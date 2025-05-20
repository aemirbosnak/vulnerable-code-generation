//FormAI DATASET v1.0 Category: Ebook reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   char title[100];
   char author[50];
   char content[10000];
} Book;

int main() {
   char filename[100];
   char choice;
   Book book;
   
   printf("Enter the name of the book file: ");
   scanf("%s", filename);
   
   FILE *file = fopen(filename, "rb");
   if (file == NULL) {
      printf("Error opening file. Exiting program.\n");
      return 1;
   }
   
   printf("File opened successfully.\n");
   
   while (1) {
      printf("\n");
      printf("Choose an option:\n");
      printf(" 1. Display book details\n");
      printf(" 2. Display full content\n");
      printf(" 3. Exit program\n");
      scanf(" %c", &choice);
      
      switch (choice) {
         case '1':
            fseek(file, 0, SEEK_SET);
            fread(&book, sizeof(Book), 1, file);
            printf("\n");
            printf("Title: %s\n", book.title);
            printf("Author: %s\n", book.author);
            break;
            
         case '2':
            fseek(file, 0, SEEK_SET);
            fread(&book, sizeof(Book), 1, file);
            printf("\n");
            printf("%s\n", book.content);
            break;
            
         case '3':
            printf("Exiting program.\n");
            fclose(file);
            return 0;
            
         default:
            printf("Invalid choice. Please try again.\n");
            break;
      }
   }
   
   return 0;
}