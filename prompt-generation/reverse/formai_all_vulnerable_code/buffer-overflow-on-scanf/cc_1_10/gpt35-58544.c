//FormAI DATASET v1.0 Category: Ebook reader ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Defining the Custom Data Type 
typedef struct {
    char title[100];
    char author[100];
    char publisher[100];
    int year;
    long int ISBN;
    float price;
} Book;

// Function to Read a Book from the File 
void read_book(Book * b, FILE * fp) {
    fscanf(fp, "%[^,],%[^,],%[^,],%d,%ld,%f", b->title, b->author, b->publisher, &b->year, &b->ISBN, &b->price);
}

// Function to Print a Book 
void print_book(Book b) {
    printf("Title: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Publisher: %s\n", b.publisher);
    printf("Year: %d\n", b.year);
    printf("ISBN: %ld\n", b.ISBN);
    printf("Price: %f\n", b.price);
}

// Function to Display the Menu 
int display_menu() {
    int choice;
    printf("\n------------------------\n");
    printf("1. Display Book(s)\n");
    printf("2. Add Book\n");
    printf("3. Remove Book\n");
    printf("4. Update Book\n");
    printf("5. Exit\n");
    printf("------------------------\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to Display All Books 
void display_all_books(Book * books, int num_books) {
    printf("\nAll Books:\n");
    for (int i = 0; i < num_books; i++) {
        printf("Book %d:\n", i + 1);
        print_book(books[i]);
    }
}

// Function to Add a Book 
Book add_book() {
    Book b;
    printf("\nEnter Details:\n");
    printf("Title: ");
    scanf(" %[^\n]s", b.title);
    printf("Author: ");
    scanf(" %[^\n]s", b.author);
    printf("Publisher: ");
    scanf(" %[^\n]s", b.publisher);
    printf("Year: ");
    scanf(" %d", &b.year);
    printf("ISBN: ");
    scanf(" %ld", &b.ISBN);
    printf("Price: ");
    scanf(" %f", &b.price);
    return b;
}

// Function to Remove a Book 
void remove_book(Book * books, int * num_books) {
    long int ISBN;
    printf("\nEnter ISBN of the Book to Remove: ");
    scanf("%ld", &ISBN);
    
    int index = -1;
    for (int i = 0; i < *num_books; i++) {
        if (books[i].ISBN == ISBN) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("\nBook with ISBN %ld not found.\n", ISBN);
        return;
    }
    
    for (int i = index; i < *num_books - 1; i++) {
        books[i] = books[i + 1];
    }
    
    (*num_books)--;
    printf("\nBook with ISBN %ld removed successfully.\n", ISBN);
}

// Function to Update a Book 
void update_book(Book * books, int num_books) {
    long int ISBN;
    printf("\nEnter ISBN of the Book to Update: ");
    scanf("%ld", &ISBN);
    
    int index = -1;
    for (int i = 0; i < num_books; i++) {
        if (books[i].ISBN == ISBN) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("\nBook with ISBN %ld not found.\n", ISBN);
        return;
    }
    
    printf("\nUpdate Details:\n");
    printf("Title (old: %s): ", books[index].title);
    scanf(" %[^\n]s", books[index].title);
    printf("Author (old: %s): ", books[index].author);
    scanf(" %[^\n]s", books[index].author);
    printf("Publisher (old: %s): ", books[index].publisher);
    scanf(" %[^\n]s", books[index].publisher);
    printf("Year (old: %d): ", books[index].year);
    scanf(" %d", &books[index].year);
    printf("Price (old: %f): ", books[index].price);
    scanf(" %f", &books[index].price);
    
    printf("\nBook with ISBN %ld updated successfully.\n", ISBN);
}

int main() {
    FILE * fp = fopen("books.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    
    int num_books = 0;
    Book books[50];
    
    while (!feof(fp)) {
        read_book(&books[num_books], fp);
        num_books++;
    }
    
    fclose(fp);
    
    while (1) {
        int choice = display_menu();
        
        switch (choice) {
            case 1:
                display_all_books(books, num_books);
                break;
            case 2:
                if (num_books == 50) {
                    printf("\nCannot add more books. Maximum limit reached.\n");
                    break;
                }
                Book b = add_book();
                books[num_books] = b;
                num_books++;
                printf("\nBook added successfully.\n");
                break;
            case 3:
                if (num_books == 0) {
                    printf("\nNo books are available to remove.\n");
                    break;
                }
                remove_book(books, &num_books);
                break;
            case 4:
                if (num_books == 0) {
                    printf("\nNo books are available to update.\n");
                    break;
                }
                update_book(books, num_books);
                break;
            case 5:
                fp = fopen("books.txt", "w");
                if (fp == NULL) {
                    printf("Error: Could not open file.\n");
                    exit(1);
                }
                
                for (int i = 0; i < num_books; i++) {
                    fprintf(fp, "%s,%s,%s,%d,%ld,%f\n", books[i].title, books[i].author, books[i].publisher, books[i].year, books[i].ISBN, books[i].price);
                }
                
                fclose(fp);
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}