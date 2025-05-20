//FormAI DATASET v1.0 Category: Ebook reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_TITLE_LENGTH 50
#define MAX_FILENAME_LENGTH 100
#define MAX_BOOKMARKS 10

struct book {
    char title[MAX_TITLE_LENGTH];
    char filename[MAX_FILENAME_LENGTH];
    int bookmark[MAX_BOOKMARKS];
};

void display_menu() {
    printf("\n\n1. Open a book\n");
    printf("2. Add a bookmark\n");
    printf("3. Display bookmarks\n");
    printf("4. Quit\n\n");
}

int main() {

    struct book library[10];
    int num_books = 0;

    while(1) {

        display_menu();

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_books == 0) {
                    printf("Library is empty. Please add books.\n");
                    break;
                }
                printf("Enter book number: ");
                int book_num;
                scanf("%d", &book_num);
                if(book_num < 1 || book_num > num_books) {
                    printf("Invalid book number.\n");
                    break;
                }
                printf("Opening book '%s'...\n", library[book_num-1].title);
                FILE *fp = fopen(library[book_num-1].filename, "r");
                if(fp == NULL) {
                    printf("Error opening file.\n");
                    break;
                }
                int bookmark = library[book_num-1].bookmark[MAX_BOOKMARKS-1];
                if(bookmark != -1) {
                    int ch;
                    fseek(fp, bookmark, SEEK_SET);
                    printf("Resuming from bookmark...\n");
                    while((ch = getc(fp)) != EOF) {
                        putchar(ch);
                    }
                } else {
                    int ch;
                    printf("No bookmark found. Starting from the beginning...\n");
                    while((ch = getc(fp)) != EOF) {
                        putchar(ch);
                    }
                }
                fclose(fp);
                break;
            case 2:
                if(num_books == 0) {
                    printf("Library is empty. Please add books.\n");
                    break;
                }
                printf("Enter book number: ");
                scanf("%d", &book_num);
                if(book_num < 1 || book_num > num_books) {
                    printf("Invalid book number.\n");
                    break;
                }
                printf("Enter bookmark location (in bytes): ");
                scanf("%d", &bookmark);
                if(bookmark < 0) {
                    printf("Invalid bookmark location.\n");
                    break;
                }
                for(int i=0; i<MAX_BOOKMARKS; i++) {
                    if(library[book_num-1].bookmark[i] == -1) {
                        library[book_num-1].bookmark[i] = bookmark;
                        printf("Bookmark added.\n");
                        break;
                    } else if(i == MAX_BOOKMARKS-1) {
                        printf("Maximum number of bookmarks reached.\n");
                        break;
                    }
                }
                break;
            case 3:
                if(num_books == 0) {
                    printf("Library is empty. Please add books.\n");
                    break;
                }
                printf("Enter book number: ");
                scanf("%d", &book_num);
                if(book_num < 1 || book_num > num_books) {
                    printf("Invalid book number.\n");
                    break;
                }
                printf("Book '%s' bookmarks:\n", library[book_num-1].title);
                for(int i=0; i<MAX_BOOKMARKS; i++) {
                    if(library[book_num-1].bookmark[i] != -1) {
                        printf("%d. %d bytes\n", i+1, library[book_num-1].bookmark[i]);
                    } else {
                        break;
                    }
                }
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}