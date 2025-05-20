//FormAI DATASET v1.0 Category: Ebook reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 100
#define MAX_AUTHOR 50
#define MAX_FILENAME 50

// Define a structure to store books 
struct Book {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    char filename[MAX_FILENAME];
};

// Function to display the main menu
void displayMenu() {
    printf("\n------------------------\n");
    printf("1. Add Book\n");
    printf("2. View Books\n");
    printf("3. Read Book\n");
    printf("4. Exit\n");
    printf("------------------------\n");
    printf("Enter your choice: ");
}

// Function to add a book
void addBook() {
    FILE *fptr;
    char filename[MAX_FILENAME];
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];

    printf("\nEnter the title of the book: ");
    fgets(title, MAX_TITLE, stdin);
    printf("Enter the author of the book: ");
    fgets(author, MAX_AUTHOR, stdin);

    // Remove the newline character at the end of the strings
    title[strcspn(title, "\n")] = 0;
    author[strcspn(author, "\n")] = 0;

    // Generate the filename for the book
    sprintf(filename, "%s_%s.txt", title, author);

    // Open the file in write mode
    fptr = fopen(filename, "w");

    // Check if the file opened successfully
    if (fptr == NULL) {
        printf("\nError opening file!\n");
        return;
    }

    // Write some example content to the file
    fprintf(fptr, "This is an example book!\n\n");
    fprintf(fptr, "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n");
    fprintf(fptr, "Phasellus ac sodales erat, vel aliquam odio.\n");

    // Close the file
    fclose(fptr);

    printf("\nBook added successfully!\n");
}

// Function to view all books
void viewBooks() {
    FILE *fptr;
    char filename[MAX_FILENAME];
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int i = 1;

    printf("\nList of books:\n");

    // Iterate through all the files in the current directory
    system("ls *.txt > temp.txt");
    fptr = fopen("temp.txt", "r");

    // Check if the file opened successfully
    if (fptr == NULL) {
        printf("\nError opening file!\n");
        return;
    }

    while (fgets(filename, MAX_FILENAME, fptr)) {
        // Remove the newline character at the end of the string
        filename[strcspn(filename, "\n")] = 0;

        // Extract the title and author from the filename
        sscanf(filename, "%[^_]_%[^.].txt", title, author);

        // Print the book information
        printf("%d. %s by %s\n", i++, title, author);
    }

    // Close the files and delete the temporary file
    fclose(fptr);
    system("rm temp.txt");
}

// Function to read a book
void readBook() {
    FILE *fptr;
    char filename[MAX_FILENAME];
    char line[100];

    // Prompt the user to enter the filename of the book
    printf("\nEnter the filename of the book : ");
    fgets(filename, MAX_FILENAME, stdin);

    // Remove the newline character at the end of the string
    filename[strcspn(filename, "\n")] = 0;

    // Open the file in read mode
    fptr = fopen(filename, "r");

    // Check if the file opened successfully
    if (fptr == NULL) {
        printf("\nError opening file!\n");
        return;
    }

    // Read and display the contents of the book
    printf("\n%s\n", filename);
    while (fgets(line, 100, fptr)) {
        printf("%s", line);
    }

    // Close the file
    fclose(fptr);
}

int main() {
    int choice;

    printf("Welcome to my unique C Ebook reader!\n");

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                readBook();
                break;
            case 4:
                printf("\nGoodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}