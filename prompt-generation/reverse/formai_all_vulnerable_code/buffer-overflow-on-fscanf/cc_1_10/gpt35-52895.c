//FormAI DATASET v1.0 Category: Ebook reader ; Style: scientific
// Header file for C Ebook Reader Example Program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Book {
    char title[100];
    char author[50];
    char publisher[50];
    char ISBN[14];
    int year;
    int pageCount;
} books[100];

int main() {
    int numBooks, i, pageNumber;
    char searchTitle[100];
    FILE *fp;
    
    // Reading in book data from file
    fp = fopen("books.txt", "r");
    if (fp == NULL) {
        printf("Error loading file\n");
        exit(1);
    }
    
    fscanf(fp, "%d", &numBooks);
    for (i = 0; i < numBooks; i++) {
        fscanf(fp, "%[^\n]\n", books[i].title);
        fscanf(fp, "%[^\n]\n", books[i].author);
        fscanf(fp, "%[^\n]\n", books[i].publisher);
        fscanf(fp, "%[^\n]\n", books[i].ISBN);
        fscanf(fp, "%d", &books[i].year);
        fscanf(fp, "%d", &books[i].pageCount);
    }
    fclose(fp);
    
    // User searches for a book by title
    printf("Enter the title of the book you want to read: ");
    scanf("%[^\n]%*c", searchTitle);
    
    // Finding the book in the array of books
    struct Book book;
    int found = 0;
    for (i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, searchTitle) == 0) {
            book = books[i];
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Book not found\n");
        exit(1);
    }
    
    // Displaying book information
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Publisher: %s\n", book.publisher);
    printf("ISBN: %s\n", book.ISBN);
    printf("Year: %d\n", book.year);
    printf("Page Count: %d\n", book.pageCount);
    
    // Reading book by page number
    printf("Enter the page number to read: ");
    scanf("%d", &pageNumber);
    
    fp = fopen("book.txt", "r");
    if (fp == NULL) {
        printf("Error loading file\n");
        exit(1);
    }
    
    char line[100];
    int currentPage = 0;
    while (fgets(line, sizeof(line), fp)) {
        if (currentPage == pageNumber) {
            printf("%s", line);
            break;
        }
        if (line[0] == '\f') {
            currentPage++;
        }
    }
    fclose(fp);
    
    return 0;
}