//FormAI DATASET v1.0 Category: Ebook reader ; Style: creative
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct { 
    char title[50]; 
    char author[50]; 
    char pubDate[20]; 
    char filename[50]; 
} Book; 

int main() { 
    int i, numBooks, choice; 
    char searchTitle[50]; 
    FILE *fp; 
    Book *books; 

    // Read number of books. 
    fp = fopen("books.dat", "rb"); 
    if (fp == NULL) { 
        printf("Error opening file!"); 
        exit(1); 
    } 
    fread(&numBooks, sizeof(int), 1, fp); 
    books = (Book *) malloc(numBooks * sizeof(Book)); 
    fread(books, sizeof(Book), numBooks, fp); 
    fclose(fp); 

    // Display menu. 
    printf("Ebook Reader\n"); 
    printf("==================\n"); 
    printf("1. Search by Title\n"); 
    printf("2. Browse All Books\n"); 
    printf("3. Exit\n"); 
    printf("Choice: "); 
    scanf("%d", &choice); 

    while (choice != 3) { 
        switch (choice) { 
            case 1: // Search by title. 
                printf("Enter title: "); 
                scanf("%s", searchTitle); 
                for (i = 0; i < numBooks; i++) { 
                    if (strcmp(searchTitle, books[i].title) == 0) { 
                        printf("%s (%s, %s)\n", books[i].title, books[i].author, books[i].pubDate); 
                        printf("Opening %s...\n", books[i].filename); 
                        // Call external program to open ebook. 
                        system(books[i].filename); 
                        break; 
                    } 
                } 
                if (i == numBooks) { 
                    printf("Book not found.\n"); 
                } 
                break; 
            case 2: // Browse all books. 
                for (i = 0; i < numBooks; i++) { 
                    printf("%s (%s, %s)\n", books[i].title, books[i].author, books[i].pubDate); 
                } 
                printf("Enter index of book to open: "); 
                scanf("%d", &i); 
                if (i >= 0 && i < numBooks) { 
                    printf("Opening %s...\n", books[i].filename); 
                    // Call external program to open ebook. 
                    system(books[i].filename); 
                } else { 
                    printf("Invalid choice.\n"); 
                } 
                break; 
            default: // Invalid choice. 
                printf("Invalid choice.\n"); 
                break; 
        } 

        // Display menu again. 
        printf("==================\n"); 
        printf("Ebook Reader\n"); 
        printf("==================\n"); 
        printf("1. Search by Title\n"); 
        printf("2. Browse All Books\n"); 
        printf("3. Exit\n"); 
        printf("Choice: "); 
        scanf("%d", &choice); 
    } 

    free(books); 

    return 0; 
}