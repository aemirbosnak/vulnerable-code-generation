//FormAI DATASET v1.0 Category: Ebook reader ; Style: excited
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

//Function that prints the Ebook reader interface
void printInterface(){
   printf("\t\t---------------\n");
   printf("\t\t| EBOOK READER |\n");
   printf("\t\t---------------\n");
   printf("\t     ____________________________\n");
   printf("\t    /                            \\\n");
   printf("\t   /                              \\\n");
   printf("\t  /                                \\\n");
   printf("\t /__________________________________\\\n");
   printf("\t|                                    |\n");
   printf("\t|           Ebook Reader            |\n");
   printf("\t|____________________________________|\n");
   printf("\t|                                    |\n");
   printf("\t|          1. Open an Ebook          |\n");
   printf("\t|          2. Close Ebook            |\n");
   printf("\t|          3. Bookmark Page          |\n");
   printf("\t|          4. View Bookmarks         |\n");
   printf("\t|          5. Exit                   | \n");
   printf("\t|____________________________________|\n");
}

//Function that opens an Ebook and prints out its content
void openEbook(char book[]){
    FILE *ebook;
    char line[100];

    ebook = fopen(book, "r");
    
    if(ebook == NULL){
        printf("\nERROR! Could not open file %s\n", book);
        exit(1);
    }
    
    printf("\nWelcome to %s\n", book);
    printf("------------------------\n");
   
    while(fgets(line, sizeof(line), ebook)){
        printf("%s", line);
    }
    
    fclose(ebook);;
}

//Struct that stores the bookmark information
struct Bookmark{
    char book[100];
    int page;
};

//Function that bookmarks a specific page in a specific book
void bookmarkPage(struct Bookmark *b, char book[], int page){
    strcpy(b->book, book);
    b->page = page;
    printf("\nBookmark added at page %d in %s\n", b->page, b->book);
}

//Function that displays all the saved bookmarks
void viewBookmarks(struct Bookmark *b, int count){
    if(count == 0){
        printf("\nNo bookmarks saved.\n");
        return;
    }
    printf("\nBOOKMARKS:\n");
    printf("-----------------------\n");
    for(int i = 0; i < count; i++){
        printf("Book: %s\tPage: %d\n", b[i].book, b[i].page);
    }
    printf("-----------------------\n");
}

int main(){
    int choice, page, bookmarkCount = 0;
    char book[100];
    struct Bookmark bookmarks[10];

    //Main loop of the program
    do {
        printInterface();
        printf("\nSelect an option: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter the name of the book: ");
                scanf("%s", book);
                openEbook(book);
                break;
            case 2:
                printf("\nEbook closed.\n");
                break;
            case 3:
                printf("\nEnter the name of the book to bookmark: ");
                scanf("%s", book);
                printf("Enter the page number to bookmark: ");
                scanf("%d", &page);
                bookmarkPage(&bookmarks[bookmarkCount++], book, page);
                break;
            case 4:
                viewBookmarks(bookmarks, bookmarkCount);
                break;
            case 5:
                printf("\nThank you for using Ebook Reader.\n");
                break;
            default:
                printf("\nInvalid input. Please try again.\n");
        }

    } while(choice != 5);

    return 0;
}