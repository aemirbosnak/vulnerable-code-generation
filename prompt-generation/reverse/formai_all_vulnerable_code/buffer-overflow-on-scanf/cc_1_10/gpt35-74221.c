//FormAI DATASET v1.0 Category: Ebook reader ; Style: energetic
#include <stdio.h>

int main() {
    int num_of_pages = 100;
    int current_page = 1;
    char ebook_title[] = "The Art of Programming";
    char author[] = "John Doe";
    char ebook_format[] = "pdf";
    float ebook_size = 2.5;
    char ebook_language[] = "English";
    
    printf("Welcome to Ebook Reader!\n");
    printf("Title: %s\n", ebook_title);
    printf("Author: %s\n", author);
    printf("Format: %s\n", ebook_format);
    printf("Size: %.1f MB\n", ebook_size);
    printf("Language: %s\n", ebook_language);
    
    printf("\n");
    
    printf("Page %d/%d\n", current_page, num_of_pages);
    printf("Chapter One: Introduction\n\n");
    printf("Programming is an art form that can bring ideas to life. Learning how to code can be a rewarding and\n");
    printf("challenging experience, but with the right approach, it can become a fun and enjoyable experience.\n\n");
    
    // simulate user input
    char user_input;
    printf("Press 'n' for next page, or 'q' to quit: ");
    scanf("%c", &user_input);
    while (user_input != 'q') {
        if (user_input == 'n') {
            if (current_page < num_of_pages) {
                current_page++;
            } else {
                printf("You have reached the end of the book.\n");
            }
        }
        printf("\n");
        printf("Page %d/%d\n", current_page, num_of_pages);
        printf("Chapter One: Introduction\n\n");
        printf("Programming is an art form that can bring ideas to life. Learning how to code can be a rewarding and\n");
        printf("challenging experience, but with the right approach, it can become a fun and enjoyable experience.\n\n");
        printf("Press 'n' for next page, or 'q' to quit: ");
        scanf(" %c", &user_input);
    }
    
    printf("Thank you for using Ebook Reader!\n");
    
    return 0;
}