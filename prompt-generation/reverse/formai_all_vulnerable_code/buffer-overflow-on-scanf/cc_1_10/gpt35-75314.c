//FormAI DATASET v1.0 Category: Ebook reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EBOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 50
#define MAX_PAGES 5000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int num_pages;
    char* content;
} Ebook;

Ebook ebook_collection[MAX_EBOOKS];
int num_ebooks = 0;

int add_ebook() {
    if (num_ebooks < MAX_EBOOKS) {
        Ebook e;
        printf("Title: ");
        scanf("%s", e.title);
        printf("Author: ");
        scanf("%s", e.author);
        printf("Number of pages: ");
        scanf("%d", &e.num_pages);
        if (e.num_pages > MAX_PAGES) {
            printf("Sorry, the maximum number of pages allowed is %d\n", MAX_PAGES);
            return 0;
        }
        e.content = (char*) malloc((e.num_pages + 1) * sizeof(char));
        printf("Content: ");
        scanf("%s", e.content);
        ebook_collection[num_ebooks++] = e;
        return 1;
    }
    else {
        printf("Sorry, the maximum number of ebooks allowed is %d\n", MAX_EBOOKS);
        return 0;
    }
}

void list_ebooks() {
    if (num_ebooks > 0) {
        printf("List of ebooks:\n");
        printf("%-20s\t%-20s\t%-10s\n", "Title", "Author", "# Pages");
        for (int i = 0; i < num_ebooks; i++) {
            printf("%-20s\t%-20s\t%-10d\n", ebook_collection[i].title, ebook_collection[i].author, ebook_collection[i].num_pages);
        }
    }
    else {
        printf("No ebooks in collection.\n");
    }
}

int main() {
    printf("Welcome to My EBook Reader\n");
    int choice = 0;
    do {
        printf("\nMenu:\n");
        printf("1. Add Ebook\n");
        printf("2. List Ebooks\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: add_ebook(); break;
            case 2: list_ebooks(); break;
            case 3: printf("Exiting...\n"); break;
            default: printf("Invalid choice, try again.\n");
        }
    } while (choice != 3);
    return 0;
}