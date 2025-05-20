//FormAI DATASET v1.0 Category: Ebook reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100 // Maximum number of books in the library
#define MAX_TITLE 50 // Maximum length of book titles
#define MAX_AUTHOR 30 // Maximum length of author names
#define MAX_PAGES 1000 // Maximum number of pages in a book
#define MAX_REVIEWS 100 // Maximum number of reviews per book

typedef struct {
  char title[MAX_TITLE];
  char author[MAX_AUTHOR];
  int num_pages;
  char reviews[MAX_REVIEWS][50];
} Ebook;

int main() {
  Ebook library[MAX_BOOKS]; // Array of Ebook structs to hold library
  
  int num_books = 0; // Number of books currently in library
  int choice; // User choice from menu
  int i, j; // Loop counters
  
  do {
    // Print menu options and get user choice
    printf("\nEBOOK READER MENU\n");
    printf("---------------------\n");
    printf("1. Add a book to the library\n");
    printf("2. Display all books in the library\n");
    printf("3. Search for a book by title\n");
    printf("4. Search for a book by author\n");
    printf("5. Exit the program\n");
    printf("\nPlease enter your choice (1-5): ");
    scanf("%d", &choice);
    
    switch (choice) {
      case 1: // Add a book to the library
        if (num_books == MAX_BOOKS) {
          printf("\nThe library is full. No more books can be added\n");
          break;
        }
        
        printf("\n");
        printf("Enter the book title: ");
        scanf(" %[^\n]", library[num_books].title);
        printf("Enter the author's name: ");
        scanf(" %[^\n]", library[num_books].author);
        printf("Enter the number of pages: ");
        scanf("%d", &library[num_books].num_pages);
        
        for (i = 0; i < MAX_REVIEWS; i++) {
          library[num_books].reviews[i][0] = '\0'; // Initialize all reviews to empty strings
        }
        
        printf("\nBook successfully added to the library!\n");
        num_books++;
        break;
        
      case 2: // Display all books in the library
        if (num_books == 0) {
          printf("\nThe library is empty. No books to display\n");
          break;
        }
        
        printf("\nLIST OF BOOKS IN THE LIBRARY\n");
        printf("---------------------\n");
        for (i = 0; i < num_books; i++) {
          printf("Title: %s\n", library[i].title);
          printf("Author: %s\n", library[i].author);
          printf("Number of Pages: %d\n", library[i].num_pages);
          
          if (library[i].reviews[0][0] == '\0') {
            printf("No reviews yet\n");
          } else {
            printf("Reviews:\n");
            for (j = 0; j < MAX_REVIEWS; j++) {
              if (library[i].reviews[j][0] != '\0') {
                printf("%s\n", library[i].reviews[j]);
              }
            }
          }
          
          printf("\n");
        }
        break;
        
      case 3: // Search for a book by title
        if (num_books == 0) {
          printf("\nThe library is empty. No books to search\n");
          break;
        }
        
        char search_title[MAX_TITLE];
        printf("\nEnter the title to search for: ");
        scanf(" %[^\n]", search_title);
        
        for (i = 0; i < num_books; i++) {
          if (strcmp(search_title, library[i].title) == 0) {
            printf("\nMATCH FOUND\n");
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Number of Pages: %d\n", library[i].num_pages);
            
            if (library[i].reviews[0][0] == '\0') {
              printf("No reviews yet\n");
            } else {
              printf("Reviews:\n");
              for (j = 0; j < MAX_REVIEWS; j++) {
                if (library[i].reviews[j][0] != '\0') {
                  printf("%s\n", library[i].reviews[j]);
                }
              }
            }
            
            break;
          }
        }
        
        if (i == num_books) {
          printf("\nNo books found with title '%s'\n", search_title);
        }
        break;
        
      case 4: // Search for a book by author
        if (num_books == 0) {
          printf("\nThe library is empty. No books to search\n");
          break;
        }
        
        char search_author[MAX_AUTHOR];
        printf("\nEnter the author to search for: ");
        scanf(" %[^\n]", search_author);
        
        for (i = 0; i < num_books; i++) {
          if (strcmp(search_author, library[i].author) == 0) {
            printf("\nMATCH FOUND\n");
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Number of Pages: %d\n", library[i].num_pages);
            
            if (library[i].reviews[0][0] == '\0') {
              printf("No reviews yet\n");
            } else {
              printf("Reviews:\n");
              for (j = 0; j < MAX_REVIEWS; j++) {
                if (library[i].reviews[j][0] != '\0') {
                  printf("%s\n", library[i].reviews[j]);
                }
              }
            }
          }
        }
        
        if (i == num_books) {
          printf("\nNo books found by author '%s'\n", search_author);
        }
        break;
        
      case 5: // Exit the program
        printf("\nExiting the program...");
        break;
        
      default: // Invalid choice
        printf("\nInvalid choice. Please try again\n");
        break;
    }
  } while (choice != 5);
  
  return 0;
}