//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: portable
#include <stdio.h>
#include <string.h>

typedef struct Ebook
{
    char title[50];
    char author[50];
    char genre[50];
    int pages;
    double price;
} Ebook;

Ebook ebooks[100];

int main()
{
    int i = 0;
    char command[20];

    printf("Welcome to the Ebook Reader!\n");

    // Create a loop to handle user commands
    while (1)
    {
        // Get the user command
        printf("Enter a command (add, list, search, quit): ");
        scanf("%s", command);

        // Check if the command is valid
        if (strcmp(command, "add") == 0)
        {
            // Get the book information
            printf("Enter the book title: ");
            scanf("%s", ebooks[i].title);

            printf("Enter the author's name: ");
            scanf("%s", ebooks[i].author);

            printf("Enter the genre: ");
            scanf("%s", ebooks[i].genre);

            printf("Enter the number of pages: ");
            scanf("%d", &ebooks[i].pages);

            printf("Enter the price: ");
            scanf("%lf", &ebooks[i].price);

            // Increment the index
            i++;
        }
        else if (strcmp(command, "list") == 0)
        {
            // List the books
            for (i = 0; i < i; i++)
            {
                printf("%s by %s (%.2lf)\n", ebooks[i].title, ebooks[i].author, ebooks[i].price);
            }
        }
        else if (strcmp(command, "search") == 0)
        {
            // Search for a book
            char search_term[50];

            printf("Enter the search term: ");
            scanf("%s", search_term);

            // Search for the book
            for (i = 0; i < i; i++)
            {
                if (strstr(ebooks[i].title, search_term) || strstr(ebooks[i].author, search_term))
                {
                    printf("%s by %s (%.2lf)\n", ebooks[i].title, ebooks[i].author, ebooks[i].price);
                }
            }
        }
        else if (strcmp(command, "quit") == 0)
        {
            // Quit the program
            break;
        }
        else
        {
            // Invalid command
            printf("Invalid command.\n");
        }
    }

    return 0;
}