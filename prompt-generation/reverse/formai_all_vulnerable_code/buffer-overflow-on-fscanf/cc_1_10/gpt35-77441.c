//FormAI DATASET v1.0 Category: Ebook reader ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Define constants */
#define MAX_BOOKS 10
#define MAX_TITLE_LENGTH 50
#define MAX_CHAPTERS 100

/* Define types */
typedef struct {
    char title[MAX_TITLE_LENGTH];
    int num_chapters;
    char chapters[MAX_CHAPTERS][MAX_TITLE_LENGTH];
} book_t;

/* Function prototypes */
void print_book(book_t *book);
void print_book_list(book_t *book_list[], int num_books);
void read_books(book_t *book_list[], int *num_books);
book_t *select_book(book_t *book_list[], int num_books);
void read_chapter(book_t *book, int chapter_num);

int main()
{
    book_t *book_list[MAX_BOOKS];
    int num_books = 0;
    int choice;

    /* Read in books */
    read_books(book_list, &num_books);

    /* Main loop */
    do {
        printf("\n\n");
        printf("1. List books\n");
        printf("2. Select book\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                /* Print out the book list */
                print_book_list(book_list, num_books);
                break;

            case 2:
                /* Select a book and read it */
                select_book(book_list, num_books);
                break;

            case 3:
                /* End program */
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}

/* Function definitions */

void print_book(book_t *book)
{
    int i;

    printf("Title: %s\n", book->title);
    printf("Number of chapters: %d\n", book->num_chapters);

    for (i = 0; i < book->num_chapters; i++)
    {
        printf("Chapter %d: %s\n", i+1, book->chapters[i]);
    }
}

void print_book_list(book_t *book_list[], int num_books)
{
    int i;

    for (i = 0; i < num_books; i++)
    {
        printf("%d. %s\n", i+1, book_list[i]->title);
    }
}

void read_books(book_t *book_list[], int *num_books)
{
    char title[MAX_TITLE_LENGTH];
    int num_chapters;
    char chapters[MAX_CHAPTERS][MAX_TITLE_LENGTH];
    int i, j;

    /* Read in books from a file */
    FILE *fp;
    fp = fopen("books.dat", "r");
    if (fp == NULL)
    {
        printf("Error: could not open file.\n");
    }
    else
    {
        while (fscanf(fp, "%s %d", title, &num_chapters) != EOF)
        {
            /* Allocate memory for the book */
            book_list[*num_books] = (book_t *) malloc(sizeof(book_t));

            /* Set the title */
            strcpy(book_list[*num_books]->title, title);

            /* Read in chapter titles */
            for (i = 0; i < num_chapters; i++)
            {
                fscanf(fp, "%s", chapters[i]);
            }

            /* Set the number of chapters and the chapter titles */
            book_list[*num_books]->num_chapters = num_chapters;
            for (j = 0; j < num_chapters; j++)
            {
                strcpy(book_list[*num_books]->chapters[j], chapters[j]);
            }

            /* Increment the number of books */
            (*num_books)++;
        }

        fclose(fp);
    }
}

book_t *select_book(book_t *book_list[], int num_books)
{
    int choice;

    /* Print out the book list */
    print_book_list(book_list, num_books);

    /* Get the user's choice */
    do {
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > num_books)
        {
            printf("Invalid choice.\n");
        }
    } while (choice < 1 || choice > num_books);

    /* Print out the selected book */
    printf("You selected:\n");
    print_book(book_list[choice-1]);

    /* Read in a chapter */
    int chapter_num;

    do {
        printf("Enter chapter to read: ");
        scanf("%d", &chapter_num);

        if (chapter_num < 1 || chapter_num > book_list[choice-1]->num_chapters)
        {
            printf("Invalid chapter.\n");
        }
    } while (chapter_num < 1 || chapter_num > book_list[choice-1]->num_chapters);

    read_chapter(book_list[choice-1], chapter_num);

    return book_list[choice-1];
}

void read_chapter(book_t *book, int chapter_num)
{
    printf("Chapter %d: %s\n\n", chapter_num, book->chapters[chapter_num-1]);
    printf("This is where the contents of the chapter would be displayed if this were a real Ebook reader.\n");
}