//FormAI DATASET v1.0 Category: Ebook reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
  char title[50];
  char author[50];
  char publisher[50];
  int year_published;
  float price;
  int quantity;
};

struct Node {
  struct Book book;
  struct Node* next;
};

struct Node* head;

void add_book() {
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  
  printf("\nEnter the book title: ");
  fflush(stdin);
  gets(temp->book.title);
  
  printf("Enter the author name: ");
  fflush(stdin);
  gets(temp->book.author);
  
  printf("Enter the publisher name: ");
  fflush(stdin);
  gets(temp->book.publisher);
  
  printf("Enter the year published: ");
  fflush(stdin);
  scanf("%d", &temp->book.year_published);
  
  printf("Enter the price: ");
  fflush(stdin);
  scanf("%f", &temp->book.price);
  
  printf("Enter the quantity: ");
  fflush(stdin);
  scanf("%d", &temp->book.quantity);
  
  temp->next = head;
  head = temp;
}

void display_books() {
  struct Node* temp = head;

  printf("\nBooks Available in Store:\n\n");

   while (temp != NULL) {
    printf("Title: %s\n", temp->book.title);
    printf("Author: %s\n", temp->book.author);
    printf("Publisher: %s\n", temp->book.publisher);
    printf("Year Published: %d\n", temp->book.year_published);
    printf("Price: $%.2f\n", temp->book.price);
    printf("Quantity: %d\n\n", temp->book.quantity);

    temp = temp->next;
  }
}

void search_book() {
  char query[50];
  
  printf("\nEnter the book title to search: ");
  fflush(stdin);
  gets(query);
  
  struct Node* temp = head;
  int found = 0;

  while (temp != NULL) {
    if(strcmp(temp->book.title, query) == 0) {
      printf("\nBook Found:\n\n");

      printf("Title: %s\n", temp->book.title);
      printf("Author: %s\n", temp->book.author);
      printf("Publisher: %s\n", temp->book.publisher);
      printf("Year Published: %d\n", temp->book.year_published);
      printf("Price: $%.2f\n", temp->book.price);
      printf("Quantity: %d\n\n", temp->book.quantity);
      
      found = 1;
      break;
    }
    temp = temp->next;
  }

  if(found == 0) {
    printf("\nBook not found!\n\n");
  }
}

void remove_book() {
  char query[50];
  
  printf("\nEnter the book title to remove: ");
  fflush(stdin);
  gets(query);

  struct Node* temp = head;
  struct Node* prev;

  if(strcmp(temp->book.title, query) == 0) {
    head = temp->next;
    free(temp);
    return;
  }

  while (temp != NULL && strcmp(temp->book.title, query) != 0) {
    prev = temp;
    temp = temp->next;
  }

  if(temp == NULL) {
    printf("\nBook not found!\n\n");
    return;
  }

  prev->next = temp->next;
  free(temp);
}

int main() {
  head = NULL;

  printf("Welcome to the Ebook Store!\n\n");
  printf("1. Add book\n");
  printf("2. Display available books\n");
  printf("3. Search book\n");
  printf("4. Remove book\n");
  printf("5. Exit\n\n");

  while (1) {
    int choice;

    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_book();
        break;
      case 2:
        display_books();
        break;
      case 3:
        search_book();
        break;
      case 4:
        remove_book();
        break;
      case 5:
        printf("\nThank you for using Ebook Store!\n");
        exit(0);
      default:
        printf("\nInvalid choice! Please try again.\n");
    }
  }

  return 0;
}