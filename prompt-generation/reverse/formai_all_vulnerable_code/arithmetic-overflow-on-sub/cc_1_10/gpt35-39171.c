//FormAI DATASET v1.0 Category: Ebook reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define maximum and minimum values
#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_FILE_NAME 50

//create a structure to hold book information
struct Book {
  char title[MAX_TITLE_LENGTH];
  char author[MAX_AUTHOR_LENGTH];
  char fileName[MAX_FILE_NAME];
};

int main() {
  //initialize array of books
  struct Book books[MAX_BOOKS];
  int numBooks = 0;

  //ask user for input
  printf("Welcome to My Ebook Reader\n");
  printf("How many books do you want to add? Max: %d\n", MAX_BOOKS);
  scanf("%d", &numBooks);

  //validate user input
  if (numBooks > MAX_BOOKS) {
    printf("Error: exceeding maximum capacity of %d books\n", MAX_BOOKS);
    return 0;
  }

  //iterate through each book and gather information
  for (int i = 0; i < numBooks; i++) {
    printf("Book %d Title: ", i+1);
    scanf("%s", books[i].title);
    printf("Book %d Author: ", i+1);
    scanf("%s", books[i].author);
    printf("Book %d File Name: ", i+1);
    scanf("%s", books[i].fileName);
  }

  //display list of books
  printf("Book List\n");
  printf("----------\n");
  for (int i = 0; i < numBooks; i++) {
    printf("Title: %s\n", books[i].title);
    printf("Author: %s\n", books[i].author);
    printf("File Name: %s\n", books[i].fileName);
    printf("\n");
  }

  //ask user to choose a book
  int choice = 0;
  printf("Enter the number of the book you want to read: ");
  scanf("%d", &choice);

  //load selected book
  char file[MAX_FILE_NAME];
  strcpy(file, books[choice-1].fileName);
  FILE *fp;
  fp = fopen(file, "r");

  if (fp == NULL) {
    printf("Error: unable to open file %s", file);
    return 0;
  }

  //display ebook contents
  printf("\n%s\n", books[choice-1].title);
  printf("by %s\n\n", books[choice-1].author);
  char ch;
  while ((ch = fgetc(fp)) != EOF) {
    printf("%c", ch);
  }

  //close file and exit program
  printf("\n\nThank you for using My Ebook Reader!\n");
  fclose(fp);
  return 0;
}