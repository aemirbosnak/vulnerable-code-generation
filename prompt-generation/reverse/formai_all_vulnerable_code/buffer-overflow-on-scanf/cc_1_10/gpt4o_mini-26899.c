//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_BOOKS 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;
} Book;

void addBook(Book *library, int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }
    printf("Enter book title: ");
    getchar();  // Clear newline left by previous input
    fgets(library[*count].title, MAX_TITLE_LENGTH, stdin);
    library[*count].title[strcspn(library[*count].title, "\n")] = 0; // Remove newline

    printf("Enter author name: ");
    fgets(library[*count].author, MAX_AUTHOR_LENGTH, stdin);
    library[*count].author[strcspn(library[*count].author, "\n")] = 0; // Remove newline

    printf("Enter year of publication: ");
    scanf("%d", &library[*count].year);

    (*count)++;
}

void printBooks(Book *library, int count) {
    printf("\nList of Books:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s by %s (%d)\n", i + 1, library[i].title, library[i].author, library[i].year);
    }
}

int compareTitle(const void *a, const void *b) {
    return strcmp(((Book *)a)->title, ((Book *)b)->title);
}

int compareAuthor(const void *a, const void *b) {
    return strcmp(((Book *)a)->author, ((Book *)b)->author);
}

int compareYear(const void *a, const void *b) {
    return ((Book *)a)->year - ((Book *)b)->year;
}

void sortBooks(Book *library, int count, int option) {
    switch(option) {
        case 1:
            qsort(library, count, sizeof(Book), compareTitle);
            printf("Books sorted by title.\n");
            break;
        case 2:
            qsort(library, count, sizeof(Book), compareAuthor);
            printf("Books sorted by author.\n");
            break;
        case 3:
            qsort(library, count, sizeof(Book), compareYear);
            printf("Books sorted by year.\n");
            break;
        default:
            printf("Invalid option!\n");
            break;
    }
}

void menu() {
    printf("\nLibrary Menu:\n");
    printf("1. Add Book\n");
    printf("2. Print Book List\n");
    printf("3. Sort Books\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Book *library = malloc(MAX_BOOKS * sizeof(Book));
    int count = 0;
    
    if (library == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int choice;
    while (1) {
        menu();
        scanf("%d", &choice);
        
        if (choice == 1) {
            addBook(library, &count);
        } else if (choice == 2) {
            printBooks(library, count);
        } else if (choice == 3) {
            printf("Sort by:\n");
            printf("1. Title\n");
            printf("2. Author\n");
            printf("3. Year\n");
            int sortOption;
            scanf("%d", &sortOption);
            sortBooks(library, count, sortOption);
        } else if (choice == 4) {
            printf("Exiting the Library System.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    free(library);
    return 0;
}