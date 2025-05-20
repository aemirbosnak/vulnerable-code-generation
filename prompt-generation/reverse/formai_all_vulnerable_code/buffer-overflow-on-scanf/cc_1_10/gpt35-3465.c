//FormAI DATASET v1.0 Category: File handling ; Style: peaceful
#include <stdio.h>

struct Book {
    char title[50];
    char author[50];
    float price;
};

// function prototype
void addBookToFile(FILE *file, struct Book *book);

int main() {
    FILE *file;
    file = fopen("books.txt", "w"); // create and open file for writing
    if(file == NULL) {
        printf("Error: Cannot create file.\n");
        return 1;
    }
    
    int numBooks;
    printf("How many books do you want to add to the file?: ");
    scanf("%d", &numBooks);
    
    // create array of books
    struct Book books[numBooks];
    
    // get user input for each book
    for(int i = 0; i < numBooks; i++) {
        printf("Enter the title of book %d: ", i+1);
        scanf("%s", books[i].title);
        printf("Enter the author of book %d: ", i+1);
        scanf("%s", books[i].author);
        printf("Enter the price of book %d: ", i+1);
        scanf("%f", &books[i].price);
        
        addBookToFile(file, &books[i]); // add book to file
    }
    
    fclose(file); // close file
    
    printf("Books have been added to the file.\n");
    
    return 0;
}

// function to add book to file
void addBookToFile(FILE *file, struct Book *book) {
    fprintf(file, "Title: %s\n", book->title);
    fprintf(file, "Author: %s\n", book->author);
    fprintf(file, "Price: %.2f\n\n", book->price);
}