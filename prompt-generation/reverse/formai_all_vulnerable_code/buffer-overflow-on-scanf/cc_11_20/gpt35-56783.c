//FormAI DATASET v1.0 Category: Ebook reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 1000
#define MAX_PAGES 1000

typedef struct {
    char title[50];
    char author[30];
    int pages[MAX_PAGES];
    int num_pages;
} Book;

Book library[MAX_BOOKS];
int num_books = 0;

int main() {
    char title[50], author[30], page_num_str[10];
    int page_num, choice, i, j;

    printf("Welcome to the Decentralized C Ebook Reader!\n");

    while (1) {
        printf("\n1. Add Book\n");
        printf("2. View Book\n");
        printf("3. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Book Title: ");
                scanf("%s", title);

                for (i = 0; i < num_books; i++) {
                    if (strcmp(library[i].title, title) == 0) {
                        printf("Book already exists in library.\n");
                        break;
                    }
                }

                if (i == num_books) {
                    strcpy(library[num_books].title, title);
                    printf("Enter Author Name: ");
                    scanf("%s", author);
                    strcpy(library[num_books].author, author);
                    
                    j = 0;
                    library[num_books].num_pages = 0;
                    printf("Enter Page Numbers (0 to stop): ");
                    
                    do {
                        scanf("%d", &page_num);
                        if (page_num != 0) {
                            library[num_books].pages[j] = page_num;
                            library[num_books].num_pages++;
                            j++;
                        }
                    } while (page_num != 0);
                    num_books++;
                }

                break;
            case 2:
                printf("Enter Book Title: ");
                scanf("%s", title);

                for (i = 0; i < num_books; i++) {
                    if (strcmp(library[i].title, title) == 0) {
                        printf("Book Title: %s\n", library[i].title);
                        printf("Author: %s\n", library[i].author);

                        printf("Pages: ");
                        for (j = 0; j < library[i].num_pages; j++) {
                            sprintf(page_num_str, "%d, ", library[i].pages[j]);
                            printf("%s", page_num_str);
                        }
                        printf("\n");

                        break;
                    }
                }

                if (i == num_books) {
                    printf("Book not found.\n");
                }

                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}