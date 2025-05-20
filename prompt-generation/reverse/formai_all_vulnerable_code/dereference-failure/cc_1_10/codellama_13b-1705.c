//Code Llama-13B DATASET v1.0 Category: Ebook reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the ebook information
struct ebook {
    char title[50];
    char author[50];
    char genre[50];
    char pages[50];
    char chapter[50];
    char page[50];
    struct ebook *next;
};

// Function to read the ebook information
void read_ebook(struct ebook *ebook) {
    // Read the ebook title
    printf("Enter the ebook title: ");
    scanf("%s", ebook->title);

    // Read the ebook author
    printf("Enter the ebook author: ");
    scanf("%s", ebook->author);

    // Read the ebook genre
    printf("Enter the ebook genre: ");
    scanf("%s", ebook->genre);

    // Read the ebook pages
    printf("Enter the number of pages: ");
    scanf("%s", ebook->pages);

    // Read the ebook chapter
    printf("Enter the current chapter: ");
    scanf("%s", ebook->chapter);

    // Read the ebook page
    printf("Enter the current page: ");
    scanf("%s", ebook->page);

    // Create a new ebook structure and assign it to the next pointer
    ebook->next = (struct ebook *)malloc(sizeof(struct ebook));
    ebook = ebook->next;

    // Read the next ebook information
    read_ebook(ebook);
}

// Function to display the ebook information
void display_ebook(struct ebook *ebook) {
    // Display the ebook title
    printf("Ebook Title: %s\n", ebook->title);

    // Display the ebook author
    printf("Ebook Author: %s\n", ebook->author);

    // Display the ebook genre
    printf("Ebook Genre: %s\n", ebook->genre);

    // Display the ebook pages
    printf("Ebook Pages: %s\n", ebook->pages);

    // Display the ebook chapter
    printf("Ebook Chapter: %s\n", ebook->chapter);

    // Display the ebook page
    printf("Ebook Page: %s\n", ebook->page);

    // Display the next ebook information
    if (ebook->next != NULL) {
        display_ebook(ebook->next);
    }
}

int main() {
    // Create a new ebook structure
    struct ebook *ebook = (struct ebook *)malloc(sizeof(struct ebook));

    // Read the ebook information
    read_ebook(ebook);

    // Display the ebook information
    display_ebook(ebook);

    // Free the ebook structure
    free(ebook);

    return 0;
}