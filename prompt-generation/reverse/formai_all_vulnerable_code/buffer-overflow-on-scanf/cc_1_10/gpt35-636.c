//FormAI DATASET v1.0 Category: Ebook reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_EBOOKS 10
#define MAX_PAGES 500

struct Ebook {
    char title[50];
    char author[50];
    char publisher[50];
    int num_pages;
    char pages[MAX_PAGES][1000];
};

struct Ebook ebooks[MAX_EBOOKS];
int num_ebooks = 0;

void add_ebook() {
    struct Ebook ebook;
    printf("Enter the title of the ebook: ");
    scanf("%s", ebook.title);
    printf("Enter the author of the ebook: ");
    scanf("%s", ebook.author);
    printf("Enter the publisher of the ebook: ");
    scanf("%s", ebook.publisher);
    printf("Enter the number of pages of the ebook: ");
    scanf("%d", &ebook.num_pages);
    printf("Enter the contents of each page (max 1000 characters per page):\n");
    for (int i = 0; i < ebook.num_pages; i++) {
        printf("Page %d:\n", i+1);
        scanf("%s", ebook.pages[i]);
    }
    ebooks[num_ebooks++] = ebook;
}

void list_ebooks() {
    printf("List of all ebooks:\n");
    for (int i = 0; i < num_ebooks; i++) {
        printf("Title: %s\n", ebooks[i].title);
        printf("Author: %s\n", ebooks[i].author);
        printf("Publisher: %s\n", ebooks[i].publisher);
        printf("Number of pages: %d\n", ebooks[i].num_pages);
    }
}

void read_ebook() {
    char title[50];
    printf("Enter the title of the ebook to read: ");
    scanf("%s", title);
    for (int i = 0; i < num_ebooks; i++) {
        if (strcmp(ebooks[i].title, title) == 0) {
            printf("Reading ebook: %s\n", ebooks[i].title);
            for (int j = 0; j < ebooks[i].num_pages; j++) {
                printf("Page %d:\n", j+1);
                printf("%s\n", ebooks[i].pages[j]);
                printf("Press any key to continue to the next page...\n");
                getchar();
            }
            return;
        }
    }
    printf("Ebook with title '%s' was not found.\n", title);
}

int main() {
    while (1) {
        int choice;
        printf("\nEbook Reader Menu\n");
        printf("1. Add ebook\n");
        printf("2. List ebooks\n");
        printf("3. Read ebook\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_ebook();
                break;
            case 2:
                list_ebooks();
                break;
            case 3:
                read_ebook();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}