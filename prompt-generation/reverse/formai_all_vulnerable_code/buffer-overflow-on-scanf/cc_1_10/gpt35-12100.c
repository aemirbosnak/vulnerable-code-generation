//FormAI DATASET v1.0 Category: Ebook reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_EBOOKS 10
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pageCount;
    float price;
} Ebook;

int numEbooks = 0;
Ebook ebooks[MAX_EBOOKS];

void addEbook() {
    if (numEbooks >= MAX_EBOOKS) {
        printf("Cannot add more ebooks, max limit reached.\n");
        return;
    }

    Ebook newEbook;
    printf("Enter ebook title: ");
    fgets(newEbook.title, MAX_TITLE_LENGTH, stdin);
    printf("Enter ebook author: ");
    fgets(newEbook.author, MAX_AUTHOR_LENGTH, stdin);
    printf("Enter ebook page count: ");
    scanf("%d", &newEbook.pageCount);
    printf("Enter ebook price: ");
    scanf("%f", &newEbook.price);

    ebooks[numEbooks] = newEbook;
    numEbooks++;
    
    getchar(); //consume the extra '\n' left by scanf
}

void displayEbook(Ebook ebook) {
    printf("\nTitle: %sAuthor: %sPage count: %dPrice: $%.2f\n",
           ebook.title, ebook.author, ebook.pageCount, ebook.price);
}

void displayAllEbooks() {
    printf("\n==== All Ebooks ====\n");
    for (int i = 0; i < numEbooks; i++) {
        printf("Ebook %d: ", i+1);
        displayEbook(ebooks[i]);
    }
    printf("=====================\n");
}

int main() {
    while (1) {
        printf("\n1. Add Ebook\n2. Display All Ebooks\n3. Exit\nSelect an option: ");
        int option;
        scanf("%d", &option);
        
        getchar(); //consume the extra '\n' left by scanf

        switch (option) {
            case 1:
                addEbook();
                break;
            case 2:
                displayAllEbooks();
                break;
            case 3:
                printf("Exiting Ebook Reader...\n");
                exit(0);
            default:
                printf("Invalid option. Please select again.\n");
        }
    }
    return 0;
}