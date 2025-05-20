//FormAI DATASET v1.0 Category: Ebook reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef struct ebook{
    char title[50];
    char author[50];
    int pages;
} Ebook;

Ebook* read_book(char* filename);
void display_book(Ebook* book);
void free_book(Ebook* book);

int main(){
    Ebook* book1 = read_book("book1.txt");
    Ebook* book2 = read_book("book2.txt");
    Ebook* current_book = book1;

    int menu_choice = 0;
    while(menu_choice != 4){
        printf("Currently reading: %s\n", current_book->title);
        printf("1. Read next book\n");
        printf("2. Display current book information\n");
        printf("3. Free current book from memory\n");
        printf("4. Exit program\n");
        printf("Enter menu choice: ");
        scanf("%d", &menu_choice);

        switch(menu_choice){
            case 1:
                if(current_book == book1){
                    current_book = book2;
                }else{
                    current_book = book1;
                }
                break;
            case 2:
                display_book(current_book);
                break;
            case 3:
                free_book(current_book);
                if(current_book == book1){
                    current_book = book2;
                }else{
                    current_book = book1;
                }
                break;
            case 4: 
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

Ebook* read_book(char* filename){
    Ebook* book = (Ebook*)malloc(sizeof(Ebook));

    // Code to read in book data from file
    FILE* fp = fopen(filename, "r");
    fscanf(fp, "%s", book->title);
    fscanf(fp, "%s", book->author);
    fscanf(fp, "%d", &book->pages);
    fclose(fp);

    return book;
}

void display_book(Ebook* book){
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %d\n", book->pages);
}

void free_book(Ebook* book){
    free(book);
}