//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ebook {
    char title[256];
    char author[256];
    char genre[256];
    int pages;
    double price;
} Ebook;

Ebook ebooks[100];

void read_ebook(int index) {
    printf("Title: %s\n", ebooks[index].title);
    printf("Author: %s\n", ebooks[index].author);
    printf("Genre: %s\n", ebooks[index].genre);
    printf("Pages: %d\n", ebooks[index].pages);
    printf("Price: %.2lf\n", ebooks[index].price);
}

int main() {
    int index = 0;
    char command;

    printf("Enter 'add' to add a new ebook, 'read' to read an ebook, or 'exit' to exit: ");
    scanf("%c", &command);

    switch (command) {
        case 'a':
            printf("Enter the title of the ebook: ");
            scanf("%s", ebooks[index].title);
            printf("Enter the author of the ebook: ");
            scanf("%s", ebooks[index].author);
            printf("Enter the genre of the ebook: ");
            scanf("%s", ebooks[index].genre);
            printf("Enter the number of pages in the ebook: ");
            scanf("%d", &ebooks[index].pages);
            printf("Enter the price of the ebook: ");
            scanf("%lf", &ebooks[index].price);
            index++;
            break;
        case 'r':
            printf("Enter the index of the ebook you want to read: ");
            scanf("%d", &index);
            read_ebook(index);
            break;
        case 'e':
            exit(0);
            break;
        default:
            printf("Invalid command.\n");
            break;
    }

    return 0;
}