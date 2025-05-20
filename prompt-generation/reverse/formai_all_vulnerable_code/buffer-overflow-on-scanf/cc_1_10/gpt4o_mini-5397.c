//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_BUFFER_LENGTH 256

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char *content;
    size_t size;
} Ebook;

void freeEbook(Ebook *ebook) {
    if (ebook->content) {
        free(ebook->content);
    }
}

int readEbook(const char *filename, Ebook *ebook) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return -1;
    }

    fgets(ebook->title, MAX_TITLE_LENGTH, file);
    ebook->title[strcspn(ebook->title, "\n")] = 0; // Remove newline

    fgets(ebook->author, MAX_AUTHOR_LENGTH, file);
    ebook->author[strcspn(ebook->author, "\n")] = 0; // Remove newline

    fseek(file, 0, SEEK_END);
    ebook->size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Skip title and author lines
    char buffer[MAX_BUFFER_LENGTH];
    fgets(buffer, MAX_BUFFER_LENGTH, file); // skip title
    fgets(buffer, MAX_BUFFER_LENGTH, file); // skip author

    ebook->content = (char *)malloc(ebook->size - (strlen(ebook->title) + strlen(ebook->author) + 2));
    if (!ebook->content) {
        fclose(file);
        perror("Failed to allocate memory for content");
        return -1;
    }

    // Copy content
    fread(ebook->content, 1, ebook->size - (strlen(ebook->title) + strlen(ebook->author) + 2), file);
    fclose(file);
    
    return 0;
}

void displayEbook(Ebook *ebook) {
    printf("Title: %s\n", ebook->title);
    printf("Author: %s\n", ebook->author);
    printf("\nContent:\n");
    printf("%s\n", ebook->content);
}

void searchKeyword(Ebook *ebook, const char *keyword) {
    char *ptr = strstr(ebook->content, keyword);
    if (ptr) {
        printf("Keyword '%s' found at position: %ld\n", keyword, ptr - ebook->content);
    } else {
        printf("Keyword '%s' not found.\n", keyword);
    }
}

void displayMenu() {
    printf("\nEbook Reader Menu:\n");
    printf("1. Display Ebook\n");
    printf("2. Search Keyword\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Ebook ebook;
    if (readEbook("ebook.txt", &ebook) != 0) {
        return EXIT_FAILURE;
    }

    int choice;
    char keyword[50];

    do {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Clear newline after scanf

        switch (choice) {
            case 1:
                displayEbook(&ebook);
                break;
            case 2:
                printf("Enter keyword to search: ");
                fgets(keyword, sizeof(keyword), stdin);
                keyword[strcspn(keyword, "\n")] = 0; // Remove newline
                searchKeyword(&ebook, keyword);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 3);

    freeEbook(&ebook);
    return EXIT_SUCCESS;
}