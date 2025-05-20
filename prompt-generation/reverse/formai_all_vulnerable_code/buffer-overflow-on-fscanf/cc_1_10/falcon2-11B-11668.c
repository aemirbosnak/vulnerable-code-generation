//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char book_title[100];
    char author[100];
    char chapter_title[100];
    char text[100];
    int chapter_number;
    int page_number;

    printf("Welcome to the Romantic Ebook Reader!\n");
    printf("Please enter the title of the book: ");
    scanf("%s", book_title);
    printf("Please enter the name of the author: ");
    scanf("%s", author);
    printf("Please enter the title of the first chapter: ");
    scanf("%s", chapter_title);

    FILE *file = fopen("romantic_ebook.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(file, "%d %s %d %s", &chapter_number, chapter_title, &page_number, text) == 4)
    {
        printf("%s\n\n", chapter_title);
        printf("%s\n\n", text);
        printf("Press 'n' to go to the next page, 'p' to go to the previous page, 'q' to quit.\n");
        printf("Enter your choice: ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'n')
        {
            page_number++;
        }
        else if (choice == 'p')
        {
            page_number--;
        }
        else if (choice == 'q')
        {
            break;
        }
    }

    fclose(file);
    return 0;
}