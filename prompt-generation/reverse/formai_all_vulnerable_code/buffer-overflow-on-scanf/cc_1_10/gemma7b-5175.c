//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("You have been transported to the digital realm of the ebook reader.\n");
    printf("Please select an option:\n");
    printf("1. Open a book.\n");
    printf("2. Create a new book.\n");
    printf("3. Exit.\n");

    int choice = 0;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the name of the book you want to open:");
            char book_name[20];
            scanf("%s", book_name);

            FILE *book_file = fopen(book_name, "r");
            if (book_file == NULL)
            {
                printf("Error opening book.\n");
            }
            else
            {
                printf("Book title: %s\n", book_name);
                printf("Author: Unknown\n");
                printf("Content:\n");

                char buffer[1024];
                while (fgets(buffer, 1024, book_file) != NULL)
                {
                    printf("%s", buffer);
                }

                fclose(book_file);
            }
            break;

        case 2:
            printf("Enter the name of the book you want to create:");
            char book_name2[20];
            scanf("%s", book_name2);

            FILE *book_file2 = fopen(book_name2, "w");
            if (book_file2 == NULL)
            {
                printf("Error creating book.\n");
            }
            else
            {
                printf("Book title: %s\n", book_name2);
                printf("Author: Unknown\n");
                printf("Content:\n");

                char buffer2[1024];
                scanf("%s", buffer2);

                fprintf(book_file2, "%s", buffer2);

                fclose(book_file2);
            }
            break;

        case 3:
            printf("Thank you for using the ebook reader.\n");
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}