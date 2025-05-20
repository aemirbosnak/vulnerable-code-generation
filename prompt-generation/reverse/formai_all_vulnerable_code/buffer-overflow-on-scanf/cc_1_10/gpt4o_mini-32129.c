//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100
#define MAX_CONTENT_LEN 1000
#define MAX_EBOOKS 50

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    char content[MAX_CONTENT_LEN];
} Ebook;

void displayMenu() {
    printf("\nEbook Reader Menu:\n");
    printf("1. Add Ebook\n");
    printf("2. View Ebook\n");
    printf("3. Delete Ebook\n");
    printf("4. List Ebooks\n");
    printf("5. Exit\n");
    printf("Choose an option (1-5): ");
}

void addEbook(Ebook *ebooks, int *ebookCount) {
    if (*ebookCount >= MAX_EBOOKS) {
        printf("Ebook library is full! Cannot add more ebooks.\n");
        return;
    }

    Ebook newEbook;

    printf("Enter title: ");
    getchar(); // Clear newline character from buffer.
    fgets(newEbook.title, MAX_TITLE_LEN, stdin);
    newEbook.title[strcspn(newEbook.title, "\n")] = 0; // Remove newline.

    printf("Enter author: ");
    fgets(newEbook.author, MAX_AUTHOR_LEN, stdin);
    newEbook.author[strcspn(newEbook.author, "\n")] = 0; // Remove newline.

    printf("Enter content: ");
    fgets(newEbook.content, MAX_CONTENT_LEN, stdin);
    newEbook.content[strcspn(newEbook.content, "\n")] = 0; // Remove newline.

    ebooks[*ebookCount] = newEbook;
    (*ebookCount)++;
    printf("Ebook added successfully!\n");
}

void viewEbook(Ebook *ebooks, int ebookCount) {
    if (ebookCount == 0) {
        printf("No ebooks available to view.\n");
        return;
    }

    int index;
    printf("Enter the index of the ebook to view (0-%d): ", ebookCount - 1);
    scanf("%d", &index);

    if (index < 0 || index >= ebookCount) {
        printf("Invalid index!\n");
        return;
    }

    printf("\nTitle: %s\n", ebooks[index].title);
    printf("Author: %s\n", ebooks[index].author);
    printf("Content: %s\n", ebooks[index].content);
}

void deleteEbook(Ebook *ebooks, int *ebookCount) {
    if (*ebookCount == 0) {
        printf("No ebooks available to delete.\n");
        return;
    }

    int index;
    printf("Enter the index of the ebook to delete (0-%d): ", *ebookCount - 1);
    scanf("%d", &index);

    if (index < 0 || index >= *ebookCount) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index; i < *ebookCount - 1; i++) {
        ebooks[i] = ebooks[i + 1];
    }
    
    (*ebookCount)--;
    printf("Ebook deleted successfully!\n");
}

void listEbooks(Ebook *ebooks, int ebookCount) {
    if (ebookCount == 0) {
        printf("No ebooks available.\n");
        return;
    }

    printf("\nEbook List:\n");
    for (int i = 0; i < ebookCount; i++) {
        printf("%d. %s by %s\n", i, ebooks[i].title, ebooks[i].author);
    }
}

int main() {
    Ebook ebooks[MAX_EBOOKS];
    int ebookCount = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEbook(ebooks, &ebookCount);
                break;
            case 2:
                viewEbook(ebooks, ebookCount);
                break;
            case 3:
                deleteEbook(ebooks, &ebookCount);
                break;
            case 4:
                listEbooks(ebooks, ebookCount);
                break;
            case 5:
                printf("Exiting the Ebook Reader. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select between 1 to 5.\n");
        }
    } while (choice != 5);

    return 0;
}