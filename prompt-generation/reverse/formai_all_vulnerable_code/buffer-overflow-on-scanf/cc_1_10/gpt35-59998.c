//FormAI DATASET v1.0 Category: Ebook reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_PAGES 1000

typedef struct Book {
  char name[MAX_LENGTH];
  char author[MAX_LENGTH];
  int pages;
  char* content[MAX_PAGES];
} book_t;

void add_page(book_t* book, char* content, int page_num);
void print_page(book_t* book, int page_num);
void print_book(book_t* book);
void remove_book(book_t* book);

int main()
{
  int choice;
  book_t* my_book;
  
  do {
    printf("\n1. Add book\n");
    printf("2. Read book\n");
    printf("3. Remove book\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &choice);
    
    switch(choice) {
      case 1:
        my_book = (book_t*) malloc(sizeof(book_t));
      
        printf("Enter book name: ");
        scanf("%s", my_book->name);
      
        printf("Enter author name: ");
        scanf("%s", my_book->author);
      
        printf("Enter number of pages: ");
        scanf("%d", &my_book->pages);
        
        for (int i = 0; i < my_book->pages; i++) {
          char* page_content = (char*) malloc(sizeof(char) * MAX_LENGTH);
          printf("Enter content for page %d: ", i + 1);
          scanf("%s", page_content);
          add_page(my_book, page_content, i);
        }
        break;
      
      case 2:
        if (my_book == NULL) {
          printf("No book exists\n");
          break;
        }

        int page_num;
        do {
          printf("Enter page number to view (1 - %d): ", my_book->pages);
          scanf("%d", &page_num);
        } while (page_num < 1 || page_num > my_book->pages);
        
        print_page(my_book, page_num);
        break;
      
      case 3:
        if (my_book == NULL) {
          printf("No book exists\n");
          break;
        }
        remove_book(my_book);
        my_book = NULL;
        break;
      
      case 4:
        if (my_book != NULL) {
          remove_book(my_book);
          my_book = NULL;
        }
        break;
      
      default:
        printf("Invalid choice\n");
        break;
    }
  } while (choice != 4);
  
  return 0;
}

void add_page(book_t* book, char* content, int page_num)
{
  int content_length = strlen(content);
  book->content[page_num] = (char*) malloc(sizeof(char) * content_length);
  strcpy(book->content[page_num], content);
}

void print_page(book_t* book, int page_num)
{
  printf("\nPage %d:\n\n%s\n", page_num, book->content[page_num-1]);
}

void print_book(book_t* book)
{
  printf("\nName: %s\n", book->name);
  printf("Author: %s\n", book->author);
  printf("Number of pages: %d", book->pages);
  for (int i = 0; i < book->pages; i++) {
    printf("\nPage %d:\n\n%s\n", i+1, book->content[i]);
  }
}

void remove_book(book_t* book)
{
  for (int i = 0; i < book->pages; i++) {
    free(book->content[i]);
  }
  free(book);
}