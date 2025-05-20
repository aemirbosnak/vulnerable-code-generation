//FormAI DATASET v1.0 Category: Ebook reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EBOOKS 10

typedef struct ebook {
   char title[50];
   char author[50];
   int year;
   float price;
} Ebook;

Ebook ebooks[MAX_EBOOKS];
int num_ebooks = 0;

void display_menu() {
    printf("Welcome to the E-Book Reader! Please select an option:\n");
    printf("1. Add an e-book\n");
    printf("2. View e-books\n");
    printf("3. Quit\n");
}

void add_ebook() {
    if (num_ebooks >= MAX_EBOOKS) {
        printf("Error: Maximum number of e-books reached.\n");
        return;
    }
    Ebook e;
    printf("Enter e-book title: ");
    scanf("%[^\n]%*c", e.title);
    printf("Enter author name: ");
    scanf("%[^\n]%*c", e.author);
    printf("Enter publication year: ");
    scanf("%d", &e.year);
    printf("Enter price: ");
    scanf("%f", &e.price);
    ebooks[num_ebooks++] = e;
    printf("E-book added successfully!\n");
}

void view_ebooks() {
    if (num_ebooks == 0) {
        printf("No e-books to display.\n");
        return;
    }
    printf("Title\tAuthor\tYear\tPrice\n");
    for (int i = 0; i < num_ebooks; i++) {
        Ebook e = ebooks[i];
        printf("%s\t%s\t%d\t%.2f\n", e.title, e.author, e.year, e.price);
    }
}

int main() {
    int choice;
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_ebook();
                break;
            case 2:
                view_ebooks();
                break;
            case 3:
                printf("Exiting E-Book Reader. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}