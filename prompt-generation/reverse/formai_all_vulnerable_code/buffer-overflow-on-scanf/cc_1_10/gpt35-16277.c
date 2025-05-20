//FormAI DATASET v1.0 Category: Ebook reader ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_SIZE 50
#define MAX_AUTHOR_SIZE 50

struct Ebook {
  int book_id;
  char book_title[MAX_TITLE_SIZE];
  char book_author[MAX_AUTHOR_SIZE];
  float book_price;
};

void display_menu();
int add_book(struct Ebook ebooks[], int book_count);
void display_books(struct Ebook ebooks[], int book_count);
void search_books(struct Ebook ebooks[], int book_count);

int main() {
  struct Ebook ebooks[MAX_BOOKS];
  int choice, book_count=0;

  do {
    display_menu();
    printf("\nEnter your choice (1-4): ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        book_count = add_book(ebooks, book_count);
        break;

      case 2:
        display_books(ebooks, book_count);
        break;

      case 3:
        search_books(ebooks, book_count);
        break;

      case 4:
        printf("\nExiting...");
        break;

      default:
        printf("\nInvalid choice! Please choose between 1 to 4.");
    }
  } while(choice != 4);

  return 0;
}

void display_menu() {
  printf("\n========= EBOOK READER MENU =========\n");
  printf("1. Add Ebook\n");
  printf("2. Display all Ebooks\n");
  printf("3. Search Ebooks\n");
  printf("4. Exit\n");
}

int add_book(struct Ebook ebooks[], int book_count) {
  if(book_count == MAX_BOOKS) {
    printf("\nCannot add new Ebook. Maximum count reached!");
    return book_count;
  }

  struct Ebook new_book;

  printf("\nEnter details of new Ebook:");
  printf("\nBook ID: ");
  scanf("%d", &new_book.book_id);
  printf("Book title: ");
  scanf("%s", new_book.book_title);
  printf("Book author: ");
  scanf("%s", new_book.book_author);
  printf("Book price: ");
  scanf("%f", &new_book.book_price);

  ebooks[book_count] = new_book;

  printf("\nEbook added successfully!");
  return book_count+1;
}

void display_books(struct Ebook ebooks[], int book_count) {
  if(book_count == 0) {
    printf("\nNo Ebooks added yet!");
    return;
  }

  printf("\nEbooks List:\n");
  printf("ID\tTitle\tAuthor\tPrice\n");
  printf("==================================\n");

  for(int i=0; i<book_count; i++) {
    printf("%d\t%s\t%s\t$%.2f\n", ebooks[i].book_id, ebooks[i].book_title, ebooks[i].book_author, ebooks[i].book_price);
  }
}

void search_books(struct Ebook ebooks[], int book_count) {
  if(book_count == 0) {
    printf("\nNo Ebooks added yet!");
    return;
  }

  int search_id, found_index=-1;

  printf("\nEnter Ebook ID to search: ");
  scanf("%d", &search_id);

  for(int i=0; i<book_count; i++) {
    if(ebooks[i].book_id == search_id) {
      found_index = i;
      break;
    }
  }

  if(found_index == -1) {
    printf("\nNo Ebook found with ID %d!", search_id);
  } else {
    printf("\nEbook found:");
    printf("\nID\tTitle\tAuthor\tPrice\n");
    printf("==================================\n");
    printf("%d\t%s\t%s\t$%.2f\n", ebooks[found_index].book_id, ebooks[found_index].book_title, ebooks[found_index].book_author, ebooks[found_index].book_price);
  }
}