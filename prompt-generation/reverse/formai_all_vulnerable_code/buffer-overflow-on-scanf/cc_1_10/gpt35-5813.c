//FormAI DATASET v1.0 Category: Ebook reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int page;  // current page number
    int total_pages; // total pages in book
    float font_size; // font size
} ebook;

void display_page(ebook book) {
    printf("Page number: %d\n", book.page);
    printf("Total pages: %d\n", book.total_pages);
    printf("Font size: %.1f\n\n", book.font_size);
}

int main() {
    ebook my_book;
    my_book.page = 1;
    my_book.total_pages = 100;
    my_book.font_size = 12.5;
  
    printf("Welcome to my Ebook reader!\n\n");
    printf("Press 'n' for Next page\n");
    printf("Press 'p' for Previous page\n");
    printf("Press 'f' for Increase font size\n");
    printf("Press 's' for Decrease font size\n");
    printf("Press 'q' to Quit\n\n");
  
    int quit = 0;
    char input;
  
    while (!quit) {
        display_page(my_book);
    
        scanf(" %c", &input);
    
        switch (input) {
            case 'n':
                if (my_book.page < my_book.total_pages) {
                    my_book.page++;
                } else {
                    printf("You have reached the end of the book!\n");
                }
                break;
          
            case 'p':
                if (my_book.page > 1) {
                    my_book.page--;
                } else {
                    printf("You are on the first page of the book!\n");
                }
                break;
          
            case 'f':
                my_book.font_size += 0.5;
                break;
                
            case 's':
                if (my_book.font_size > 1) {
                    my_book.font_size -= 0.5;
                } else {
                    printf("Cannot decrease font size any further!\n");
                }
                break;
          
            case 'q':
                printf("Thanks for using my Ebook reader! Goodbye :)\n");
                quit = 1;
                break;
                
            default:
                printf("Invalid input. Try again!\n");
                break;
        }
  
        system("clear"); // clear screen for better visualization
    }

    return 0;
}