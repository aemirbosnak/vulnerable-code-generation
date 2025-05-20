//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAX_BOOK_SIZE 1024

typedef struct Book
{
    char title[MAX_BOOK_SIZE];
    char author[MAX_BOOK_SIZE];
    char content[MAX_BOOK_SIZE];
    int currentPage;
    int pages;
} Book;

Book books[10] = {
    {"The Lord of the Flies", "William Golding", "A classic novel about a group of boys stranded on a deserted island.", 1, 320},
    {"The Hobbit: An Unexpected Journey", "J.R.R. Tolkien", "A fantasy epic about a group of dwarves battling a dragon.", 1, 330},
    {"The Wizard of Oz", "L. Frank Baum", "A timeless children's story about a young girl who is transported to a magical land.", 1, 380}
};

int main()
{
    int bookIndex = 0;
    char input[MAX_BOOK_SIZE];

    printf("Welcome to the Great Library of the Round Table!");
    printf("\nPlease select a book by entering its title:");

    scanf("%s", input);

    for (bookIndex = 0; bookIndex < 10; bookIndex++)
    {
        if (strcmp(books[bookIndex].title, input) == 0)
        {
            break;
        }
    }

    if (bookIndex == 10)
    {
        printf("Error: Book not found.\n");
    }
    else
    {
        printf("Book title: %s\n", books[bookIndex].title);
        printf("Author: %s\n", books[bookIndex].author);
        printf("Content: %s\n", books[bookIndex].content);
        printf("Current page: %d\n", books[bookIndex].currentPage);
        printf("Number of pages: %d\n", books[bookIndex].pages);
    }

    return 0;
}