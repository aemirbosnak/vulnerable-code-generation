//FormAI DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void addBook();
void viewAllBooks();
void searchBook();
void deleteBook();
void updateBook();

int main()
{
    int choice;
    
    do {
        printf("\n======= Book Store =======\n");
        printf("1. Add Book\n");
        printf("2. View All Books\n");
        printf("3. Search for a Book\n");
        printf("4. Delete a Book\n");
        printf("5. Update Book Details\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addBook();  // call addBook function
                break;
            case 2:
                viewAllBooks();  // call viewAllBooks function
                break;
            case 3:
                searchBook();  // call searchBook function
                break;
            case 4:
                deleteBook();  // call deleteBook function
                break;
            case 5:
                updateBook();  // call updateBook function
                break;
            case 6:
                exit(0);  // exit the program
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
    } while (choice != 6);
    
    return 0;
}

// function to add book to file
void addBook()
{
    FILE *fp;
    char bookName[50], author[50];
    int ISBN;
    
    printf("\nEnter Book Name: ");
    scanf("%s", bookName);
    
    printf("Enter Author Name: ");
    scanf("%s", author);
    
    printf("Enter ISBN: ");
    scanf("%d", &ISBN);
    
    fp = fopen("books.txt", "a");  // open file in append mode
    
    if (fp == NULL) {
        printf("\nError: File could not be opened.\n");
        return;
    }
    
    fprintf(fp, "%s\t%s\t%d\n", bookName, author, ISBN);  // write data to file
    
    fclose(fp);  // close the file
    printf("\nBook added successfully!\n");
}

// function to view all books in file
void viewAllBooks()
{
    FILE *fp;
    char data[100];
    
    fp = fopen("books.txt", "r");  // open file in read mode
    
    if (fp == NULL) {
        printf("\nError: File could not be opened.\n");
        return;
    }
    
    printf("\n========= Book List =========\n");
    printf("Book Name\t\tAuthor\t\t\tISBN\n");
    printf("========= ========== ==========\n");
    
    while (fgets(data, 100, fp) != NULL) {  // read data line by line
        printf("%s", data);
    }
    
    fclose(fp);  // close the file
}

// function to search for a book in file
void searchBook()
{
    FILE *fp;
    char bookName[50], author[50], data[100];
    int ISBN, found = 0;
    
    printf("\nEnter Book Name to search: ");
    scanf("%s", bookName);
    
    printf("Enter Author Name to search: ");
    scanf("%s", author);
    
    printf("Enter ISBN to search: ");
    scanf("%d", &ISBN);
    
    fp = fopen("books.txt", "r");  // open file in read mode
    
    if (fp == NULL) {
        printf("\nError: File could not be opened.\n");
        return;
    }
    
    while (fgets(data, 100, fp) != NULL) {  // read data line by line
        sscanf(data, "%s %s %d", bookName, author, &ISBN);  // parse data
        
        if (strcmp(bookName, bookName) == 0 && strcmp(author, author) == 0 && ISBN == ISBN) {
            printf("\nThe Book is available in the book store.\n");
            printf("Book Name: %s\n", bookName);
            printf("Author Name: %s\n", author);
            printf("ISBN: %d\n", ISBN);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("\nThe Book is not available in the book store.\n");
    }
    
    fclose(fp);  // close the file
}

// function to delete a book from file
void deleteBook()
{
    FILE *fp1, *fp2;
    char bookName[50], author[50], data[100];
    int ISBN, found = 0;
    
    printf("\nEnter Book Name to delete: ");
    scanf("%s", bookName);
    
    printf("Enter Author Name to delete: ");
    scanf("%s", author);
    
    printf("Enter ISBN to delete: ");
    scanf("%d", &ISBN);
    
    fp1 = fopen("books.txt", "r");  // open file in read mode
    
    if (fp1 == NULL) {
        printf("\nError: File could not be opened.\n");
        return;
    }
    
    fp2 = fopen("temp.txt", "w");  // open temporary file in write mode
    
    while (fgets(data, 100, fp1) != NULL) {  // read data line by line
        sscanf(data, "%s %s %d", bookName, author, &ISBN);  // parse data
        
        if (strcmp(bookName, bookName) == 0 && strcmp(author, author) == 0 && ISBN == ISBN) {
            found = 1;
            continue;
        }
        
        fprintf(fp2, "%s", data);  // write data to temporary file
    }
    
    fclose(fp1);  // close the files
    fclose(fp2);
    
    remove("books.txt");     // remove the original file
    rename("temp.txt", "books.txt");    // rename the temporary file
    
    if (found) {
        printf("\nThe Book has been successfully deleted from the book store.\n");
    } else {
        printf("\nThe Book is not available in the book store.\n");
    }
}

// function to update book details in file
void updateBook()
{
    FILE *fp1, *fp2;
    char bookName[50], author[50], data[100];
    int ISBN, found = 0;
    
    printf("\nEnter Book Name to update: ");
    scanf("%s", bookName);
    
    printf("Enter Author Name to update: ");
    scanf("%s", author);
    
    printf("Enter ISBN to update: ");
    scanf("%d", &ISBN);
    
    fp1 = fopen("books.txt", "r");  // open file in read mode
    
    if (fp1 == NULL) {
        printf("\nError: File could not be opened.\n");
        return;
    }
    
    fp2 = fopen("temp.txt", "w");  // open temporary file in write mode
    
    while (fgets(data, 100, fp1) != NULL) {  // read data line by line
        sscanf(data, "%s %s %d", bookName, author, &ISBN);  // parse data
        
        if (strcmp(bookName, bookName) == 0 && strcmp(author, author) == 0 && ISBN == ISBN) {
            printf("\nEnter new details of Book\n");
            printf("New Name: ");
            scanf("%s", bookName);
            printf("New Author Name: ");
            scanf("%s", author);
            printf("New ISBN: ");
            scanf("%d", &ISBN);
            
            fprintf(fp2, "%s\t%s\t%d\n", bookName, author, ISBN);  // write the new data to temporary file
            found = 1;
            continue;
        }
        
        fprintf(fp2, "%s", data);  // write data to temporary file
    }
    
    fclose(fp1); // close the files
    fclose(fp2);
    
    remove("books.txt");     // remove the original file
    rename("temp.txt", "books.txt");    // rename the temporary file
    
    if (found) {
        printf("\nThe Book has been successfully updated in the book store.\n");
    } else {
        printf("\nThe Book is not available in the book store.\n");
    }
}