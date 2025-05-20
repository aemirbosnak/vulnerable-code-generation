//FormAI DATASET v1.0 Category: File handling ; Style: curious
#include<stdio.h>
#include<string.h>

struct Book {
    char title[50];
    char author[50];
    char publisher[50];
    int year;
};

int main() {
    struct Book books[5];
    char option[10];

    // Writing to the file
    FILE *fptr = fopen("booklist.txt", "w");
    if(fptr == NULL) {
        printf("Error opening file!");
        return 1;
    }
    printf("Enter details of 5 books: \n");
    fprintf(fptr, "Book List: \n");
    for(int i=0; i<5; i++) {
        printf("Book %d: \n", i+1);
        printf("Title: ");
        scanf("%s", books[i].title);
        printf("Author: ");
        scanf("%s", books[i].author);
        printf("Publisher: ");
        scanf("%s", books[i].publisher);
        printf("Year: ");
        scanf("%d", &books[i].year);
        fprintf(fptr, "Title: %s\nAuthor: %s\nPublisher: %s\nYear: %d\n\n", books[i].title, books[i].author, books[i].publisher, books[i].year);
    }
    fclose(fptr);

    // Reading from the file
    fptr = fopen("booklist.txt", "r");
    if(fptr == NULL) {
        printf("Error opening file!");
        return 1;
    }
    printf("\nBook List:\n\n");
    char line[200];
    while(fgets(line, sizeof(line), fptr)) {
        printf("%s", line);
    }
    fclose(fptr);

    // Appending to the file
    fptr = fopen("booklist.txt", "a");
    if(fptr == NULL) {
        printf("Error opening file!");
        return 1;
    }
    printf("\nWould you like to add another book? (yes/no): ");
    scanf("%s", option);
    if(strcmp(option, "yes") == 0) {
        struct Book newBook;
        printf("Enter details of the book: \n");
        printf("Title: ");
        scanf("%s", newBook.title);
        printf("Author: ");
        scanf("%s", newBook.author);
        printf("Publisher: ");
        scanf("%s", newBook.publisher);
        printf("Year: ");
        scanf("%d", &newBook.year);
        fprintf(fptr, "Title: %s\nAuthor: %s\nPublisher: %s\nYear: %d\n\n", newBook.title, newBook.author, newBook.publisher, newBook.year);
    }
    fclose(fptr);

    printf("\nThank you for using Book List!\n");
    return 0;
}