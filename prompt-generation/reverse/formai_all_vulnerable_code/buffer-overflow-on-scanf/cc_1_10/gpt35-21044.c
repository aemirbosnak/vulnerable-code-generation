//FormAI DATASET v1.0 Category: Database simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct book {
    char title[100];
    char author[50];
    int year;
    float price;
};

struct book inventory[MAX_BOOKS];
int num_books = 0;

void add_book() {
    if (num_books >= MAX_BOOKS) {
        printf("Inventory is full.\n");
        return;
    }

    struct book b;

    printf("Title: ");
    fgets(b.title, 100, stdin);
    b.title[strcspn(b.title, "\n")] = '\0';

    printf("Author: ");
    fgets(b.author, 50, stdin);
    b.author[strcspn(b.author, "\n")] = '\0';

    printf("Year: ");
    scanf("%d", &b.year);

    printf("Price: ");
    scanf("%f", &b.price);
    getchar();

    inventory[num_books++] = b;

    printf("Book added successfully.\n");
}

void search_books() {
    char search_term[100];

    printf("Enter search term: ");
    fgets(search_term, 100, stdin);
    search_term[strcspn(search_term, "\n")] = '\0';

    printf("Search results:\n");

    for (int i = 0; i < num_books; i++) {
        if (strstr(inventory[i].title, search_term) != NULL ||
            strstr(inventory[i].author, search_term) != NULL) {
            printf("Title: %s, Author: %s, Year: %d, Price: %.2f\n",
                   inventory[i].title, inventory[i].author,
                   inventory[i].year, inventory[i].price);
        }
    }
}

int main() {
    int option;

    while (1) {
        printf("Menu:\n");
        printf("1. Add book to inventory\n");
        printf("2. Search books\n");
        printf("3. Exit\n");

        printf("Enter option: ");
        scanf("%d", &option);
        getchar();

        switch (option) {
            case 1:
                add_book();
                break;
            case 2:
                search_books();
                break;
            case 3:
                printf("Goodbye.\n");
                exit(0);
            default:
                printf("Invalid option.\n");
                break;
        }
    }

    return 0;
}