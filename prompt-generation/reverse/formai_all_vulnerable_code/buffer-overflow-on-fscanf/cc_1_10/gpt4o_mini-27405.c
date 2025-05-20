//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    int yearPublished;
    char genre[50];
    int pages;
} Book;

void extractMetadata(const char *filename, Book *book) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    
    fgets(book->title, sizeof(book->title), file);
    strtok(book->title, "\n"); // Remove newline

    fgets(book->author, sizeof(book->author), file);
    strtok(book->author, "\n"); // Remove newline

    fscanf(file, "%d", &book->yearPublished);
    fgetc(file); // Consume newline after year

    fgets(book->genre, sizeof(book->genre), file);
    strtok(book->genre, "\n"); // Remove newline

    fscanf(file, "%d", &book->pages);
    
    fclose(file);
}

void displayBookInfo(const Book *book) {
    printf("Book Metadata:\n");
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Year Published: %d\n", book->yearPublished);
    printf("Genre: %s\n", book->genre);
    printf("Pages: %d\n", book->pages);
}

void saveMetadataToFile(const Book *book, const char *outputFile) {
    FILE *file = fopen(outputFile, "w");
    if (!file) {
        perror("Failed to open output file");
        exit(EXIT_FAILURE);
    }
    
    fprintf(file, "Book Title: %s\n", book->title);
    fprintf(file, "Author: %s\n", book->author);
    fprintf(file, "Published Year: %d\n", book->yearPublished);
    fprintf(file, "Genre: %s\n", book->genre);
    fprintf(file, "Pages: %d\n", book->pages);
    
    fclose(file);
}

void countPagesByYear(const char *inputFile, int *yearCount, int *pagesPerYear, int *distinctYears) {
    FILE *file = fopen(inputFile, "r");
    if (!file) {
        perror("Failed to open input file for counting");
        exit(EXIT_FAILURE);
    }

    Book book;
    while (fgets(book.title, sizeof(book.title), file)) {
        strtok(book.title, "\n"); // Remove newline
        fgets(book.author, sizeof(book.author), file);
        strtok(book.author, "\n"); // Remove newline
        fscanf(file, "%d", &book.yearPublished);
        fgetc(file); // Consume newline
        fgets(book.genre, sizeof(book.genre), file);
        strtok(book.genre, "\n"); // Remove newline
        fscanf(file, "%d", &book.pages);
        
        yearCount[book.yearPublished - 1900] += 1; // Count for current year
        pagesPerYear[book.yearPublished - 1900] += book.pages; // Aggregate pages
        distinctYears[0] = (book.yearPublished > distinctYears[0]) ? book.yearPublished : distinctYears[0]; // Track distinct years
    }
    
    fclose(file);
}

void displayStatistics(int *yearCount, int *pagesPerYear, int distinctYears) {
    printf("Yearly Statistics:\n");
    for (int i = 1900; i <= distinctYears; i++) {
        if (yearCount[i - 1900] > 0) {
            printf("Year: %d, Books Count: %d, Total Pages: %d\n", i, yearCount[i - 1900], pagesPerYear[i - 1900]);
        }
    }
}

int main() {
    Book book;
    extractMetadata("book_metadata.txt", &book);
    displayBookInfo(&book);
    saveMetadataToFile(&book, "book_output.txt");
    
    int yearCount[123] = {0}; // From 1900 to 2022 (123 years)
    int pagesPerYear[123] = {0};
    int distinctYears[1] = {1900}; // Track maximum year
    
    countPagesByYear("book_metadata.txt", yearCount, pagesPerYear, distinctYears);
    displayStatistics(yearCount, pagesPerYear, distinctYears[0]);

    return 0;
}