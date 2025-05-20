//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100
#define MAX_PATH_LEN 200

// Define a struct for an Ebook
typedef struct Ebook {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    char path[MAX_PATH_LEN];
    struct Ebook *next;
} Ebook;

// Function prototypes
Ebook* createEbook(const char* title, const char* author, const char* path);
void addEbook(Ebook** head, const char* title, const char* author, const char* path);
void displayEbooks(Ebook* head);
void readEbook(const char* path);
void freeEbooks(Ebook* head);

int main() {
    Ebook* ebookList = NULL;
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    char path[MAX_PATH_LEN];
    char choice;

    // Main menu
    do {
        printf("Ebook Reader Menu:\n");
        printf("1. Add Ebook\n");
        printf("2. Display Ebooks\n");
        printf("3. Read Ebook\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf(" %c", &choice);
        getchar(); // Consume the newline character

        switch (choice) {
            case '1':
                printf("Enter ebook title: ");
                fgets(title, MAX_TITLE_LEN, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline

                printf("Enter ebook author: ");
                fgets(author, MAX_AUTHOR_LEN, stdin);
                author[strcspn(author, "\n")] = 0; // Remove newline

                printf("Enter ebook file path: ");
                fgets(path, MAX_PATH_LEN, stdin);
                path[strcspn(path, "\n")] = 0; // Remove newline

                addEbook(&ebookList, title, author, path);
                break;
            case '2':
                displayEbooks(ebookList);
                break;
            case '3':
                printf("Enter the path of the ebook to read: ");
                fgets(path, MAX_PATH_LEN, stdin);
                path[strcspn(path, "\n")] = 0; // Remove newline
                readEbook(path);
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please choose again.\n");
        }
        printf("\n");
    } while (choice != '4');

    freeEbooks(ebookList);
    return 0;
}

// Create a new Ebook instance
Ebook* createEbook(const char* title, const char* author, const char* path) {
    Ebook* newEbook = (Ebook*)malloc(sizeof(Ebook));
    strncpy(newEbook->title, title, MAX_TITLE_LEN);
    strncpy(newEbook->author, author, MAX_AUTHOR_LEN);
    strncpy(newEbook->path, path, MAX_PATH_LEN);
    newEbook->next = NULL;
    return newEbook;
}

// Add an Ebook to the linked list
void addEbook(Ebook** head, const char* title, const char* author, const char* path) {
    Ebook* newEbook = createEbook(title, author, path);
    newEbook->next = *head;
    *head = newEbook;
    printf("Ebook added successfully!\n");
}

// Display all Ebooks
void displayEbooks(Ebook* head) {
    if (head == NULL) {
        printf("No ebooks available.\n");
        return;
    }

    printf("List of Ebooks:\n");
    int index = 1;
    while (head != NULL) {
        printf("%d. %s by %s\n", index++, head->title, head->author);
        head = head->next;
    }
}

// Read and display an Ebook content
void readEbook(const char* path) {
    FILE* file = fopen(path, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", path);
        return;
    }

    printf("Reading Ebook: %s\n", path);
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch); // Print each character to console
    }
    fclose(file);
    printf("\nEnd of Ebook.\n");
}

// Free memory allocated for Ebooks linked list
void freeEbooks(Ebook* head) {
    while (head != NULL) {
        Ebook* temp = head;
        head = head->next;
        free(temp);
    }
}