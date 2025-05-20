//FormAI DATASET v1.0 Category: Ebook reader ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char title[50];
    char author[50];
    char isbn[20];
    float price;
} Book;

void displayMenu();
void addBook(Book* bookList, int* numBooks);
void displayBooks(Book* bookList, int numBooks);
void searchBook(Book* bookList, int numBooks);

int main(){
    Book bookList[100];
    int numBooks = 0;

    while(1){
        displayMenu();

        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addBook(bookList, &numBooks);
                break;
            case 2:
                displayBooks(bookList, numBooks);
                break;
            case 3:
                searchBook(bookList, numBooks);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void displayMenu(){
    printf("\nEBOOK READER\n");
    printf("=======================================\n");
    printf("1. Add Book\n");
    printf("2. Display Books\n");
    printf("3. Search Book\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void addBook(Book* bookList, int* numBooks){
    Book newBook;

    printf("\nEnter details of book #%d\n", *numBooks+1);

    printf("Title: ");
    scanf(" %[^\n]", newBook.title);

    printf("Author: ");
    scanf(" %[^\n]", newBook.author);

    printf("ISBN: ");
    scanf(" %[^\n]", newBook.isbn);

    printf("Price: ");
    scanf("%f", &newBook.price);

    bookList[*numBooks] = newBook;
    *numBooks += 1;

    printf("\nBook added successfully!\n");
}

void displayBooks(Book* bookList, int numBooks){
    if(numBooks == 0){
        printf("\nNo books found.\n");
    }
    else{
        printf("\nList of books: \n");
        printf("---------------------------------------------------\n");
        printf("Title\t\tAuthor\t\tISBN\t\tPrice\n");
        printf("---------------------------------------------------\n");
        for(int i=0; i<numBooks; i++){
            printf("%s\t\t%s\t\t%s\t\t%.2f\n", bookList[i].title, bookList[i].author, bookList[i].isbn, bookList[i].price);
        }
        printf("---------------------------------------------------\n");
    }
}

void searchBook(Book* bookList, int numBooks){
    char keyword[50];
    int results = 0;

    printf("\nEnter search keyword: ");
    scanf(" %[^\n]", keyword);

    printf("\nSearch results:\n");
    printf("---------------------------------------------------\n");
    printf("Title\t\tAuthor\t\tISBN\t\tPrice\n");
    printf("---------------------------------------------------\n");

    for(int i=0; i<numBooks; i++){
        if(strstr(bookList[i].title, keyword) != NULL){ 
            printf("%s\t\t%s\t\t%s\t\t%.2f\n", bookList[i].title, bookList[i].author, bookList[i].isbn, bookList[i].price);
            results++;
        }
    }

    if(results == 0){
        printf("No results found for '%s'\n", keyword);
    }
    else{
        printf("Total results: %d\n", results);
    }

    printf("---------------------------------------------------\n");
}