//FormAI DATASET v1.0 Category: Data mining ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUMMARY_LEN 1000
#define MAX_BOOKS 10000
#define MAX_TITLE_LEN 100

typedef struct {
    char title[MAX_TITLE_LEN];
    char summary[MAX_SUMMARY_LEN];
} Book;

int main() {
    // Open book summaries file
    FILE *fp;
    fp = fopen("book_summaries.txt", "r");
    if (fp == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    // Allocate memory for array of books
    Book *book_list = malloc(sizeof(Book) * MAX_BOOKS);
    if (book_list == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }

    // Read in book summaries and titles
    int count = 0;
    char temp[MAX_SUMMARY_LEN];
    char title[MAX_TITLE_LEN];
    while (fgets(temp, sizeof(temp), fp) != NULL && count < MAX_BOOKS) {
        // Extract title
        sscanf(temp, "%[^,],", title); // Read until comma and ignore comma

        // Extract summary
        int summary_start = strlen(title) + 1; // + 1 to skip comma
        strcpy(book_list[count].summary, &temp[summary_start]);
        book_list[count].summary[strlen(book_list[count].summary) - 1] = '\0'; // Remove newline character

        // Store title separately
        strcpy(book_list[count].title, title);

        count++;
    }
    fclose(fp);

    // Data mining examples
    // Example 1: Count number of books with the word "survival" in summary
    int survival_count = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(book_list[i].summary, "survival") != NULL) {
            survival_count++;
        }
    }
    printf("Number of books about survival: %d\n", survival_count);

    // Example 2: Find longest book title
    int longest_title_len = 0;
    char longest_title[MAX_TITLE_LEN];
    for (int i = 0; i < count; i++) {
        if (strlen(book_list[i].title) > longest_title_len) {
            longest_title_len = strlen(book_list[i].title);
            strcpy(longest_title, book_list[i].title);
        }
    }
    printf("Longest book title: %s\n", longest_title);

    // Free memory and exit program
    free(book_list);
    return 0;
}