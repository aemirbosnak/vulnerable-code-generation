//FormAI DATASET v1.0 Category: Ebook reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 20
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 50
#define MAX_CHAPTERS 50
#define MAX_PAGES_PER_CHAPTER 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int num_chapters;
    int num_pages[MAX_CHAPTERS];
    char chapters[MAX_CHAPTERS][MAX_PAGES_PER_CHAPTER];
} ebook;

int main() {
    ebook my_library[MAX_BOOKS];
    int num_books = 0;
    int i, j, k;
    int book_choice, chapter_choice, page_choice;

    while (1) {
        // Display main menu
        printf("==== Ebook Reader ====\n");
        printf("1. Add ebook to library\n");
        printf("2. View ebook library\n");
        printf("3. Open ebook\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add ebook to library
                if (num_books >= MAX_BOOKS) {
                    printf("Library is full!\n");
                    break;
                }
                printf("Enter title: ");
                scanf("%s", my_library[num_books].title);
                printf("Enter author: ");
                scanf("%s", my_library[num_books].author);
                printf("Enter number of chapters: ");
                scanf("%d", &my_library[num_books].num_chapters);
                for (i = 0; i < my_library[num_books].num_chapters; i++) {
                    printf("Enter number of pages in chapter %d: ", i+1);
                    scanf("%d", &my_library[num_books].num_pages[i]);
                    for (j = 0; j < my_library[num_books].num_pages[i]; j++) {
                        printf("Enter text on page %d: ", j+1);
                        scanf("%s", my_library[num_books].chapters[i][j]);
                    }
                }
                num_books++;
                break;

            case 2:
                // View ebook library
                printf("=== Ebook Library ===\n");
                for (i = 0; i < num_books; i++) {
                    printf("%d. %s by %s\n", i+1, my_library[i].title, my_library[i].author);
                }
                break;

            case 3:
                // Open ebook
                printf("Enter book number: ");
                scanf("%d", &book_choice);
                book_choice--;
                printf("=== %s by %s ===\n", my_library[book_choice].title, my_library[book_choice].author);
                for (i = 0; i < my_library[book_choice].num_chapters; i++) {
                    printf("Chapter %d:\n", i+1);
                    for (j = 0; j < my_library[book_choice].num_pages[i]; j++) {
                        printf("%s\n", my_library[book_choice].chapters[i][j]);
                    }
                    printf("\n");
                }
                printf("Press any key to return to main menu...");
                getchar();
                getchar();
                break;

            case 4:
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}