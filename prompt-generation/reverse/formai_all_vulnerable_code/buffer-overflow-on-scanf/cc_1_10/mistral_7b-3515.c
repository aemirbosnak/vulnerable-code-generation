//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 50

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_TITLE_LEN];
} Book;

Book library[MAX_BOOKS];

int searchBook(const char* query, int booksCount, int titleOnly) {
    int resultIndex = -1;

    for (int i = 0; i < booksCount; ++i) {
        char title[MAX_TITLE_LEN];
        strcpy(title, library[i].title);

        if (titleOnly) {
            char* pos = strstr(title, query);

            if (pos) {
                resultIndex = i;
                break;
            }
        } else {
            char title[MAX_TITLE_LEN];
            strcpy(title, library[i].title);
            char author[MAX_TITLE_LEN];
            strcpy(author, library[i].author);

            int titleMatch = strspn(title, query) == strlen(query);
            int authorMatch = strspn(author, query) == strlen(query);

            if (titleMatch || authorMatch) {
                resultIndex = i;
                break;
            }
        }
    }

    return resultIndex;
}

int main() {
    int numBooks = 0;

    printf("Welcome, noble archivist, to the Castle Dracula Library!\n");
    printf("Enter the number of books in our vast collection:\n");
    scanf("%d", &numBooks);

    if (numBooks > MAX_BOOKS) {
        printf("Alas, our library is not that vast! Maximum number of books is %d.\n", MAX_BOOKS);
        return 1;
    }

    printf("Now, kindly enter the titles and authors of each book:\n");

    for (int i = 0; i < numBooks; ++i) {
        printf("Book %d:\n", i + 1);
        printf("Title: ");
        scanf("%s", library[i].title);
        printf("Author: ");
        scanf("%s", library[i].author);
    }

    char query[MAX_TITLE_LEN];
    int titleOnly = 0;

    printf("\nEnter the query to search for:\n");
    scanf("%s", query);
    printf("Do you want to search only in titles (y/n): ");
    scanf("%d", &titleOnly);

    int resultIndex = searchBook(query, numBooks, titleOnly);

    if (resultIndex == -1) {
        printf("No book was found with the given query.\n");
    } else {
        printf("A book was found! Its title is \"%s\" and its author is \"%s\".\n", library[resultIndex].title, library[resultIndex].author);
    }

    return 0;
}