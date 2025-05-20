//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// structure for each book
struct book{
    char title[50];
    char author[50];
    int pages;
    char genre[20];
};

// function to read data from file and store in an array of structures
void read_file(struct book* books, int size, FILE* fp){
    int i = 0;
    while(fscanf(fp, "%s %s %d %s\n", books[i].title, books[i].author, &books[i].pages, books[i].genre)!= EOF){
        i++;
    }
}

// function to display all books in the array
void display_books(struct book* books, int size){
    int i;
    for(i=0; i<size; i++){
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Pages: %d\n", books[i].pages);
        printf("Genre: %s\n\n", books[i].genre);
    }
}

// function to search for a book by title
int search_book(struct book* books, int size, char* title){
    int i;
    for(i=0; i<size; i++){
        if(strcmp(books[i].title, title) == 0){
            return i;
        }
    }
    return -1;
}

// main function
int main(){
    FILE* fp;
    char filename[20];
    int size, choice, result;
    struct book books[100];

    printf("Enter the name of the file containing book data: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("Error: File not found.\n");
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp)/sizeof(struct book);
    rewind(fp);

    read_file(books, size, fp);

    while(1){
        printf("\n1. Display all books\n2. Search for a book\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                display_books(books, size);
                break;

            case 2:
                printf("Enter the title of the book you want to search: ");
                scanf("%s", books[0].title);
                result = search_book(books, size, books[0].title);

                if(result == -1){
                    printf("Book not found.\n");
                }
                else{
                    printf("Book found at position %d.\n", result+1);
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}