//FormAI DATASET v1.0 Category: Ebook reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 10
#define MAX_CHAPTERS 20
#define MAX_PAGES 50

typedef struct page {
    int number;
    char text[100];
} Page;

typedef struct chapter {
    int number;
    Page pages[MAX_PAGES];
} Chapter;

typedef struct book {
    char title[50];
    Chapter chapters[MAX_CHAPTERS];
} Book;

int main() {
    int numBooks = 0;
    Book books[MAX_BOOKS];

    // Add some sample books
    Book myBook = {"C Programming", {
            {1, { {1, "Introduction"}, {2, "Variables"} }},
            {2, { {1, "Functions"}, {2, "Pointers"} }},
            {3, { {1, "Arrays"}, {2, "Structures"} }}
        }
    };
    books[numBooks] = myBook;
    numBooks++;

    Book anotherBook = {"Data Structures", {
            {1, { {1, "Introduction"}, {2, "Arrays"} }},
            {2, { {1, "Stacks"}, {2, "Queues"} }},
            {3, { {1, "Trees"}, {2, "Graphs"} }}
        }
    };
    books[numBooks] = anotherBook;
    numBooks++;

    // Display all books
    printf("Available Books:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%d. %s\n", i+1, books[i].title);
    }

    // Select a book
    int selectedBookIndex;
    printf("Enter the number of the book you want to read: ");
    scanf("%d", &selectedBookIndex);
    selectedBookIndex--;

    // Display all chapters in the selected book
    Book selectedBook = books[selectedBookIndex];
    printf("\nChapters in %s:\n", selectedBook.title);
    for (int i = 0; i < MAX_CHAPTERS; i++) {
        if (selectedBook.chapters[i].number > 0) {
            printf("%d. Chapter %d\n", i+1, selectedBook.chapters[i].number);
        }
    }

    // Select a chapter
    int selectedChapterIndex;
    printf("Enter the number of the chapter you want to read: ");
    scanf("%d", &selectedChapterIndex);
    selectedChapterIndex--;

    // Display all pages in the selected chapter
    Chapter selectedChapter = selectedBook.chapters[selectedChapterIndex];
    printf("\n%s, Chapter %d:\n", selectedBook.title, selectedChapter.number);
    for (int i = 0; i < MAX_PAGES; i++) {
        if (selectedChapter.pages[i].number > 0) {
            printf("Page %d:\n%s\n", selectedChapter.pages[i].number, selectedChapter.pages[i].text);
        }
    }

    return 0;
}