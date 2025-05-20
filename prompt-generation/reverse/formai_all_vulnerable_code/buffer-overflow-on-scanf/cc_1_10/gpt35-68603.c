//FormAI DATASET v1.0 Category: Ebook reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char author[50];
    char publisher[50];
    int publicationYear;
    double price;
} Book;

typedef struct {
    char username[50];
    int numBooks;
    Book *ownedBooks;
} User;

int main() {
    User currentUser;
    printf("Please enter your username: ");
    scanf("%s", currentUser.username);
    
    currentUser.numBooks = 0;
    currentUser.ownedBooks = (Book *) malloc(sizeof(Book));
    
    printf("Welcome, %s! What would you like to do?\n", currentUser.username);
    printf("1. Add a book to your collection\n");
    printf("2. View your collection\n");
    printf("3. Quit\n");
    
    int choice;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\nEnter the book's title: ");
                scanf("%s", (currentUser.ownedBooks + currentUser.numBooks)->title);
                
                printf("Enter the book's author: ");
                scanf("%s", (currentUser.ownedBooks + currentUser.numBooks)->author);
                
                printf("Enter the book's publisher: ");
                scanf("%s", (currentUser.ownedBooks + currentUser.numBooks)->publisher);
                
                printf("Enter the book's publication year: ");
                scanf("%d", &(currentUser.ownedBooks + currentUser.numBooks)->publicationYear);
                
                printf("Enter the book's price: ");
                scanf("%lf", &(currentUser.ownedBooks + currentUser.numBooks)->price);
                
                currentUser.numBooks++;
                currentUser.ownedBooks = (Book *) realloc(currentUser.ownedBooks, (currentUser.numBooks + 1) * sizeof(Book));
                
                printf("\nBook added to your collection!\n\n");
                break;
                
            case 2:
                printf("\nBooks in your collection:\n");
                for (int i = 0; i < currentUser.numBooks; i++) {
                    printf("\nTitle: %s\n", (currentUser.ownedBooks + i)->title);
                    printf("Author: %s\n", (currentUser.ownedBooks + i)->author);
                    printf("Publisher: %s\n", (currentUser.ownedBooks + i)->publisher);
                    printf("Publication year: %d\n", (currentUser.ownedBooks + i)->publicationYear);
                    printf("Price: $%.2lf\n", (currentUser.ownedBooks + i)->price);
                }
                printf("\n");
                break;
                
            case 3:
                printf("\nThank you for using the Ebook reader program!\n");
                free(currentUser.ownedBooks);
                exit(0);
                
            default:
                printf("\nInvalid choice. Please try again.\n\n");
                break;
        }
    }
    return 0;
}