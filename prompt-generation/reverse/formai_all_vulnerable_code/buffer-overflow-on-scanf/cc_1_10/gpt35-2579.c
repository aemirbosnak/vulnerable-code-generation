//FormAI DATASET v1.0 Category: Ebook reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ebook {
    char title[100];
    char author[50];
    int pages;
    float price;
} ebook;

void display_menu() {
    printf("\nWelcome to Happy E-Reader!\n");
    printf("1. Display all books\n");
    printf("2. Search for a book\n");
    printf("3. Add a new book\n");
    printf("4. Remove a book\n");
    printf("5. Exit\n");
}

void display_books(ebook *books, int count) {
    printf("\nTitle\t\tAuthor\tPages\tPrice\n");
    printf("-------------------------------------------------\n");
    for(int i=0; i<count; i++) {
        printf("%s\t%s\t%d\t%.2f\n", books[i].title, books[i].author, books[i].pages, books[i].price);
    }
}

void search_book(ebook *books, int count) {
    char title[100], author[50];
    printf("Enter the title of the book: ");
    scanf("%s", title);
    printf("Enter the author of the book: ");
    scanf("%s", author);
    for(int i=0; i<count; i++) {
        if(strcmp(books[i].title, title) == 0 && strcmp(books[i].author, author) == 0) {
            printf("\nBook found!\n");
            printf("Title: %s\nAuthor: %s\nPages: %d\nPrice: %.2f\n", books[i].title, books[i].author, books[i].pages, books[i].price);
            return;
        }
    }
    printf("\nBook not found!\n");
}

int add_book(ebook *books, int count) {
    printf("Enter the title of the book: ");
    scanf("%s", books[count].title);
    printf("Enter the author of the book: ");
    scanf("%s", books[count].author);
    printf("Enter the number of pages: ");
    scanf("%d", &books[count].pages);
    printf("Enter the price: ");
    scanf("%f", &books[count].price);
    count++;
    return count;
}

int remove_book(ebook *books, int count, char title[100], char author[50]) {
    int index = -1;
    for(int i=0; i<count; i++) {
        if(strcmp(books[i].title, title) == 0 && strcmp(books[i].author, author) == 0) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("\nBook not found!\n");
    }
    else {
        for(int i=index; i<count-1; i++) {
            books[i] = books[i+1];
        }
        count--;
        printf("\nBook removed!\n");
    }
    return count;
}

int main() {
    ebook books[10];
    int count = 0, choice;
    while(1) {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: if(count == 0) {
                        printf("\nNo books found!\n");
                    }
                    else {
                        display_books(books, count);
                    }
                    break;
            case 2: search_book(books, count);
                    break;
            case 3: if(count == 10) {
                        printf("\nMaximum limit reached!\n");
                    }
                    else {
                        count = add_book(books, count);
                        printf("\nBook added!\n");
                    }
                    break;
            case 4: if(count == 0) {
                        printf("\nNo books found!\n");
                    }
                    else {
                        char title[100], author[50];
                        printf("Enter the title of the book: ");
                        scanf("%s", title);
                        printf("Enter the author of the book: ");
                        scanf("%s", author);
                        count = remove_book(books, count, title, author);
                    }
                    break;
            case 5: printf("\nThank you for using Happy E-Reader!\n");
                    exit(0);
            default: printf("\nInvalid choice!\n");
        }
    }
    return 0;
}