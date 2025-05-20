//FormAI DATASET v1.0 Category: Ebook reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ebook {
    char title[50];
    char author[50];
    char genre[50];
    double price;
    int rating;
};

void display_menu() {
    printf("1. Add Ebook\n");
    printf("2. Remove Ebook\n");
    printf("3. Search Ebook\n");
    printf("4. Display all Ebooks\n");
    printf("5. Exit\n");
}

void add_ebook(struct Ebook* ebooks, int* num_ebooks) {
    printf("Enter the title: ");
    scanf(" %[^\n]s", ebooks[*num_ebooks].title);
    printf("Enter the author: ");
    scanf(" %[^\n]s", ebooks[*num_ebooks].author);
    printf("Enter the genre: ");
    scanf(" %[^\n]s", ebooks[*num_ebooks].genre);
    printf("Enter the price: ");
    scanf(" %lf", &ebooks[*num_ebooks].price);
    printf("Enter the rating (out of 5): ");
    scanf(" %d", &ebooks[*num_ebooks].rating);
    (*num_ebooks)++;
}

void remove_ebook(struct Ebook* ebooks, int* num_ebooks) {
    char title[50];
    printf("Enter the title of the ebook to remove: ");
    scanf(" %[^\n]s", title);
    int i, j;
    for (i = 0; i < *num_ebooks; i++) {
        if (strcmp(ebooks[i].title, title) == 0) {
            for (j = i; j < *num_ebooks - 1; j++) {
                ebooks[j] = ebooks[j+1];
            }
            (*num_ebooks)--;
            printf("Ebook removed.\n");
            return;
        }
    }
    printf("Ebook not found.\n");
}

void search_ebook(struct Ebook* ebooks, int num_ebooks) {
    char title[50];
    printf("Enter the title of the ebook to search: ");
    scanf(" %[^\n]s", title);
    int i;
    for (i = 0; i < num_ebooks; i++) {
        if (strcmp(ebooks[i].title, title) == 0) {
            printf("Title: %s\n", ebooks[i].title);
            printf("Author: %s\n", ebooks[i].author);
            printf("Genre: %s\n", ebooks[i].genre);
            printf("Price: $%.2lf\n", ebooks[i].price);
            printf("Rating: %d/5\n", ebooks[i].rating);
            return;
        }
    }
    printf("Ebook not found.\n");
}

void display_all_ebooks(struct Ebook* ebooks, int num_ebooks) {
    int i;
    for (i = 0; i < num_ebooks; i++) {
        printf("Title: %s\n", ebooks[i].title);
        printf("Author: %s\n", ebooks[i].author);
        printf("Genre: %s\n", ebooks[i].genre);
        printf("Price: $%.2lf\n", ebooks[i].price);
        printf("Rating: %d/5\n", ebooks[i].rating);
        printf("\n");
    }
}

int main() {
    struct Ebook ebooks[100];
    int num_ebooks = 0;
    int choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf(" %d", &choice);
        switch (choice) {
            case 1:
                add_ebook(ebooks, &num_ebooks);
                break;
            case 2:
                remove_ebook(ebooks, &num_ebooks);
                break;
            case 3:
                search_ebook(ebooks, num_ebooks);
                break;
            case 4:
                display_all_ebooks(ebooks, num_ebooks);
                break;
            case 5:
                printf("Exiting Ebook reader...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
        printf("\n");
    } while (choice != 5);
    return 0;
}