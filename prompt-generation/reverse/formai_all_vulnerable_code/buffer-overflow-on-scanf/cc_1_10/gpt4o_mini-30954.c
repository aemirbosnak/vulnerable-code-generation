//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAPTERS 5
#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 1024

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Chapter;

typedef struct {
    char book_title[MAX_TITLE_LENGTH];
    Chapter chapters[MAX_CHAPTERS];
    int chapter_count;
} Ebook;

// Function to display the book title
void display_book_title(char *title) {
    printf("\n--- Welcome to '%s' ---\n", title);
}

// Function to display chapter content
void display_chapter(Chapter chapter) {
    printf("\n" "Chapter: %s\n", chapter.title);
    printf("%s\n", chapter.content);
}

// Function to display all chapters
void display_all_chapters(Ebook ebook) {
    for (int i = 0; i < ebook.chapter_count; i++) {
        printf("%d. %s\n", i + 1, ebook.chapters[i].title);
    }
}

// Function to search for a keyword in the book
void search_keyword(Ebook ebook, char *keyword) {
    printf("\nSearching for '%s' in the book...\n", keyword);
    int found = 0;
    for (int i = 0; i < ebook.chapter_count; i++) {
        if (strstr(ebook.chapters[i].content, keyword) != NULL) {
            printf("Found in Chapter %d: %s\n", i + 1, ebook.chapters[i].title);
            found = 1;
        }
    }
    if (!found) {
        printf("No occurrences found for '%s'.\n", keyword);
    }
}

// Function to read a selected chapter
void read_chapter(Ebook ebook) {
    int chapter_num;
    printf("Enter chapter number to read (1-%d): ", ebook.chapter_count);
    scanf("%d", &chapter_num);
    if (chapter_num < 1 || chapter_num > ebook.chapter_count) {
        printf("Invalid chapter number.\n");
    } else {
        display_chapter(ebook.chapters[chapter_num - 1]);
    }
}

// Function for main program logic
void ebook_reader(Ebook ebook) {
    int choice;
    do {
        display_book_title(ebook.book_title);
        printf("\n--- Menu ---\n");
        printf("1. List Chapters\n");
        printf("2. Read Chapter\n");
        printf("3. Search Keyword\n");
        printf("4. Quit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                display_all_chapters(ebook);
                break;
            case 2:
                read_chapter(ebook);
                break;
            case 3: {
                char keyword[MAX_TITLE_LENGTH];
                printf("Enter keyword to search: ");
                scanf("%s", keyword);
                search_keyword(ebook, keyword);
                break;
            }
            case 4:
                printf("Exiting the ebook reader. Happy reading!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

// Main function
int main() {
    Ebook myEbook = {
        .book_title = "Journey to the Unknown",
        .chapter_count = 3,
        .chapters = {
            {"Chapter 1: The Start", "In the beginning, there was a journey that ..."},
            {"Chapter 2: The Challenge", "As the days passed, the challenge became ..."},
            {"Chapter 3: The Resolution", "Finally, the resolution brought peace and ..."}
        }
    };

    ebook_reader(myEbook);

    return 0;
}