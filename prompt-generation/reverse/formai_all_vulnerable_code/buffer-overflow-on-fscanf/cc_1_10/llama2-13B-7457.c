//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

// Structure to store information about a book
typedef struct book {
    char title[50];
    char author[50];
    int publication_year;
    int pages;
} book;

// Function to read a book's information from a file
book read_book(FILE *file) {
    book b;
    fscanf(file, "%s%s%d%d", b.title, b.author, &b.publication_year, &b.pages);
    return b;
}

// Function to find the most frequently used words in a book
void find_frequent_words(book *books, int num_books) {
    int i, j, k, word_frequency[50];
    for (i = 0; i < 50; i++) {
        word_frequency[i] = 0;
    }
    for (i = 0; i < num_books; i++) {
        for (j = 0; j < strlen(books[i].title); j++) {
            for (k = 0; k < 50; k++) {
                if (books[i].title[j] == word_frequency[k]) {
                    word_frequency[k]++;
                    break;
                }
            }
        }
    }
    for (i = 0; i < 50; i++) {
        printf("%d. %s (%d times)\n", i + 1, word_frequency[i] ? word_frequency[i] : "None", word_frequency[i]);
    }
}

// Function to calculate the average number of words per page
void calculate_avg_words_per_page(book *books, int num_books) {
    int i, j, total_words = 0, total_pages = 0;
    for (i = 0; i < num_books; i++) {
        total_words += books[i].pages * strlen(books[i].title);
        total_pages++;
    }
    for (i = 0; i < num_books; i++) {
        printf("%.2f words per page\n", (double)books[i].pages * strlen(books[i].title) / total_pages);
    }
}

// Function to find the most frequently used authors in a collection of books
void find_frequent_authors(book *books, int num_books) {
    int i, j, k, author_frequency[50];
    for (i = 0; i < 50; i++) {
        author_frequency[i] = 0;
    }
    for (i = 0; i < num_books; i++) {
        for (j = 0; j < strlen(books[i].author); j++) {
            for (k = 0; k < 50; k++) {
                if (books[i].author[j] == author_frequency[k]) {
                    author_frequency[k]++;
                    break;
                }
            }
        }
    }
    for (i = 0; i < 50; i++) {
        printf("%d. %s (%d times)\n", i + 1, author_frequency[i] ? author_frequency[i] : "None", author_frequency[i]);
    }
}

int main() {
    int num_books = 5;
    book books[5];
    books[0] = read_book(fopen("book1.txt", "r"));
    books[1] = read_book(fopen("book2.txt", "r"));
    books[2] = read_book(fopen("book3.txt", "r"));
    books[3] = read_book(fopen("book4.txt", "r"));
    books[4] = read_book(fopen("book5.txt", "r"));

    find_frequent_words(books, num_books);
    calculate_avg_words_per_page(books, num_books);
    find_frequent_authors(books, num_books);

    return 0;
}