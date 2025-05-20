//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: dynamic
#include <stdio.h>
#include <string.h>

void display_ebook_menu()
{
    printf("\n");
    printf("--------------------------------------------------------\n");
    printf("           E-Book Reader Menu                           \n");
    printf("--------------------------------------------------------\n");
    printf("1. List Books\n");
    printf("2. Search Books\n");
    printf("3. Add Book\n");
    printf("4. Delete Book\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main()
{
    int choice;
    char book_name[20];
    char author_name[20];
    int pages;
    int book_id;

    while (1)
    {
        display_ebook_menu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // List Books function
                break;
            case 2:
                // Search Books function
                break;
            case 3:
                // Add Book function
                break;
            case 4:
                // Delete Book function
                break;
            case 5:
                // Exit function
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}