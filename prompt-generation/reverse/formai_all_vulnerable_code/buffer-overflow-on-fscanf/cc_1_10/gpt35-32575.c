//FormAI DATASET v1.0 Category: Ebook reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char title[50];
    char author[50];
    float price;
    int pages;
} book;

//Function to display the details of a book
void displayBook(book b) {
    printf("\nTitle: %s", b.title);
    printf("\nAuthor: %s", b.author);
    printf("\nPrice: $%.2f", b.price);
    printf("\nPages: %d", b.pages);
}

int main() {
    int choice, i, numBooks;
    char fileName[50];
    book *myBooks;

    printf("Welcome to My Books Ebook Reader!\n");

    printf("Enter the name of the file containing your book collection: ");
    scanf("%s", fileName);

    //Read the number of books from the file and allocate memory for the array
    FILE *fp = fopen(fileName, "r");
    fscanf(fp, "%d", &numBooks);
    myBooks = malloc(numBooks * sizeof(book));

    //Read the book details from the file and store in the array
    for(i=0; i<numBooks; i++) {
        fscanf(fp, "%s", myBooks[i].title);
        fscanf(fp, "%s", myBooks[i].author);
        fscanf(fp, "%f", &myBooks[i].price);
        fscanf(fp, "%d", &myBooks[i].pages);
    }
    fclose(fp);

    //Display the menu and read the user's choice
    do {
        printf("\n\nMENU\n");
        printf("1. Display all books\n");
        printf("2. Search for a book\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n\nDISPLAYING ALL BOOKS\n");
                for(i=0; i<numBooks; i++) {
                    displayBook(myBooks[i]);
                }
                break;

            case 2:
                printf("\n\nSEARCH FOR A BOOK\n");
                char searchTitle[50];
                printf("Enter the title of the book you want to search for: ");
                scanf("%s", searchTitle);
                for(i=0; i<numBooks; i++) {
                    if(strcmp(searchTitle, myBooks[i].title)==0) {
                        displayBook(myBooks[i]);
                        break;
                    }
                }
                if(i==numBooks) {
                    printf("The book \"%s\" was not found in your collection.", searchTitle);
                }
                break;

            case 3:
                printf("\n\nTHANK YOU FOR USING MY BOOKS EBOOK READER!");
                break;

            default:
                printf("\n\nINVALID CHOICE! PLEASE ENTER A VALID OPTION FROM THE MENU.");
        }

    } while(choice != 3);

    free(myBooks);
    return 0;
}