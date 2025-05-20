//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 255
#define MAX_AUTHOR_LENGTH 100
#define MAX_FILE_LENGTH 255

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
    float rating;  // Assume a rating out of 5
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Library;

void initialize_library(Library *library) {
    library->count = 0;
}

void load_books(Library *library, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file: %s\n", filename);
        return;
    }
    
    while (fscanf(file, "%[^,],%[^,],%d,%f\n", library->books[library->count].title,
                    library->books[library->count].author,
                    &library->books[library->count].pages,
                    &library->books[library->count].rating) != EOF && 
                    library->count < MAX_BOOKS) {
        library->count++;
    }

    fclose(file);
}

void list_books(const Library *library) {
    if (library->count == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("\nList of Books:\n");
    for (int i = 0; i < library->count; i++) {
        printf("%d: %s by %s (%d pages) - Rating: %.1f/5\n", 
                i + 1, 
                library->books[i].title, 
                library->books[i].author, 
                library->books[i].pages, 
                library->books[i].rating);
    }
}

float average_rating(const Library *library) {
    if (library->count == 0) return 0.0;
    float sum = 0.0;
    for (int i = 0; i < library->count; i++) {
        sum += library->books[i].rating;
    }
    return sum / library->count;
}

int count_books_over_threshold(const Library *library, float threshold) {
    int count = 0;
    for (int i = 0; i < library->count; i++) {
        if (library->books[i].rating > threshold) {
            count++;
        }
    }
    return count;
}

void save_books(const Library *library, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Could not open file for writing: %s\n", filename);
        return;
    }

    for (int i = 0; i < library->count; i++) {
        fprintf(file, "%s,%s,%d,%.1f\n", 
                library->books[i].title, 
                library->books[i].author, 
                library->books[i].pages,
                library->books[i].rating);
    }
    fclose(file);
}

void menu() {
    printf("\nE-Book Reader Menu:\n");
    printf("1. Load Books\n");
    printf("2. List Books\n");
    printf("3. Average Rating\n");
    printf("4. Count Books Over Rating Threshold\n");
    printf("5. Save Books\n");
    printf("6. Exit\n");
}

int main() {
    Library library;
    int choice;
    char filename[MAX_FILE_LENGTH];
    
    initialize_library(&library);

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter filename to load books from: ");
                scanf("%s", filename);
                load_books(&library, filename);
                break;
            case 2:
                list_books(&library);
                break;
            case 3:
                printf("Average Rating: %.1f\n", average_rating(&library));
                break;
            case 4: {
                float threshold;
                printf("Enter rating threshold: ");
                scanf("%f", &threshold);
                printf("Number of books with rating above %.1f: %d\n", threshold, count_books_over_threshold(&library, threshold));
                break;
            }
            case 5:
                printf("Enter filename to save books to: ");
                scanf("%s", filename);
                save_books(&library, filename);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);
    
    return 0;
}