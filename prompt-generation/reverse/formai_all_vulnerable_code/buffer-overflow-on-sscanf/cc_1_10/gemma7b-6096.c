//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_menu(void);
void read_book(void);
void search_book(void);
void update_book(void);
void delete_book(void);

int main()
{
    int choice;

    display_menu();
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            read_book();
            break;
        case 2:
            search_book();
            break;
        case 3:
            update_book();
            break;
        case 4:
            delete_book();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

void display_menu(void)
{
    printf("\nWelcome to the Book Management System!\n");
    printf("Please select an option:\n");
    printf("1. Read a book\n");
    printf("2. Search for a book\n");
    printf("3. Update a book\n");
    printf("4. Delete a book\n");
    printf("Enter your choice: ");
}

void read_book(void)
{
    printf("Enter the book title: ");
    char title[256];
    scanf("%s", title);

    printf("Enter the author's name: ");
    char author[256];
    scanf("%s", author);

    printf("Enter the book genre: ");
    char genre[256];
    scanf("%s", genre);

    FILE *fp = fopen("books.txt", "a");
    fprintf(fp, "%s, %s, %s\n", title, author, genre);
    fclose(fp);

    printf("Book added successfully!\n");
}

void search_book(void)
{
    char title[256];
    printf("Enter the book title: ");
    scanf("%s", title);

    FILE *fp = fopen("books.txt", "r");
    char book_info[1024];
    while (fgets(book_info, 1024, fp) != NULL)
    {
        char book_title[256];
        char book_author[256];
        char book_genre[256];

        sscanf(book_info, "%s, %s, %s", book_title, book_author, book_genre);

        if (strcmp(book_title, title) == 0)
        {
            printf("Book title: %s\n", book_title);
            printf("Author: %s\n", book_author);
            printf("Genre: %s\n", book_genre);
            break;
        }
    }

    if (feof(fp))
    {
        printf("Book not found.\n");
    }
    fclose(fp);
}

void update_book(void)
{
    char title[256];
    printf("Enter the book title: ");
    scanf("%s", title);

    FILE *fp = fopen("books.txt", "r");
    char book_info[1024];
    while (fgets(book_info, 1024, fp) != NULL)
    {
        char book_title[256];
        char book_author[256];
        char book_genre[256];

        sscanf(book_info, "%s, %s, %s", book_title, book_author, book_genre);

        if (strcmp(book_title, title) == 0)
        {
            printf("Enter the new book title: ");
            scanf("%s", book_title);

            printf("Enter the new author's name: ");
            scanf("%s", book_author);

            printf("Enter the new book genre: ");
            scanf("%s", book_genre);

            FILE *fpw = fopen("books.txt", "w");
            fprintf(fpw, "%s, %s, %s\n", book_title, book_author, book_genre);
            fclose(fpw);

            printf("Book updated successfully!\n");
            break;
        }
    }

    if (feof(fp))
    {
        printf("Book not found.\n");
    }
    fclose(fp);
}

void delete_book(void)
{
    char title[256];
    printf("Enter the book title: ");
    scanf("%s", title);

    FILE *fp = fopen("books.txt", "r");
    char book_info[1024];
    while (fgets(book_info, 1024, fp) != NULL)
    {
        char book_title[256];
        char book_author[256];
        char book_genre[256];

        sscanf(book_info, "%s, %s, %s", book_title, book_author, book_genre);

        if (strcmp(book_title, title) == 0)
        {
            FILE *fpw = fopen("books.txt", "w");
            char book_data[1024];
            rewind(fp);
            while (fgets(book_data, 1024, fp) != NULL)
            {
                if (strcmp(book_title, book_data) != 0)
                {
                    fprintf(fpw, "%s\n", book_data);
                }
            }
            fclose(fpw);

            printf("Book deleted successfully!\n");
            break;
        }
    }

    if (feof(fp))
    {
        printf("Book not found.\n");
    }
    fclose(fp);
}