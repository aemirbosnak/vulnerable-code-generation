//FormAI DATASET v1.0 Category: Ebook reader ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

struct eBook {
    char title[50];
    char author[50];
    int pages;
    float price;
};

int main() {
    int n, choice, i;
    printf("Enter number of eBooks: ");
    scanf("%d", &n);
    struct eBook *books = (struct eBook*) malloc(n * sizeof(struct eBook));
    printf("\n----- Enter eBook details -----\n");
    for (i = 0; i < n; i++) {
        printf("\nBook %d:\n", i+1);
        printf("Title: ");
        scanf("%s", books[i].title);
        printf("Author: ");
        scanf("%s", books[i].author);
        printf("Pages: ");
        scanf("%d", &books[i].pages);
        printf("Price: ");
        scanf("%f", &books[i].price);
    }
    printf("\n----- eBook List -----\n");
    for (i = 0; i < n; i++) {
        printf("\nBook %d\n", i+1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Pages: %d\n", books[i].pages);
        printf("Price: $%.2f\n", books[i].price);
    }
    printf("\n----- Welcome to eBook Reader! -----\n");
    while (1) {
        printf("\nEnter book number to read (Enter 0 to exit): ");
        scanf("%d", &choice);
        if (choice == 0) {
            printf("\nThank you for using eBook Reader!\n");
            break;
        }
        else if (choice < 1 || choice > n) {
            printf("\nInvalid choice! Please enter a valid book number.\n");
        }
        else {
            printf("\n----- %s by %s -----\n", books[choice-1].title, books[choice-1].author);
            printf("Pages: %d\n", books[choice-1].pages);
            printf("Price: $%.2f\n", books[choice-1].price);
            // Read book functionality can be added here
        }
    }
    free(books);
    return 0;
}