//FormAI DATASET v1.0 Category: Ebook reader ; Style: creative
#include<stdio.h>   //standard input/output library
#include<stdlib.h>  //standard library for dynamic memory allocation and random functions
#include<string.h>  //library for string operations

#define MAX_BOOKS 100 //maximum books that can be stored in the library
#define MAX_CHARACTERS 1000 //maximum characters in book description

//structure for book information
struct Book{
    int book_id;
    char book_name[50];
    char author_name[50];
    int year_of_publication;
    char description[MAX_CHARACTERS];
};

int main()
{
    struct Book library[MAX_BOOKS];  //array of book structures to store the books
    int n;                           //number of books in the library
    printf("Enter the number of books in the library: ");
    scanf("%d",&n);

    //reading the book details and storing in library
    for(int i=0;i<n;i++){
        printf("Enter the details of book %d:\n",i+1);
        printf("Book ID: ");
        scanf("%d",&library[i].book_id);
        printf("Book Name: ");
        scanf("%s",library[i].book_name);
        printf("Author Name: ");
        scanf("%s",library[i].author_name);
        printf("Year of Publication: ");
        scanf("%d",&library[i].year_of_publication);
        printf("Description: ");
        scanf(" %[^\n]",library[i].description);
    }

    int choice,id;
    do{
        //displaying the menu
        printf("\n\n~~~~~EBOOK READER~~~~~");
        printf("\n1. View Book Details");
        printf("\n2. Browse the Books");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the book ID: ");
                scanf("%d",&id);
                int flag=0;
                for(int i=0;i<n;i++){
                    if(id==library[i].book_id){
                        printf("Book Name: %s\nAuthor Name: %s\nYear of Publication: %d\nDescription: %s",library[i].book_name,library[i].author_name,library[i].year_of_publication,library[i].description);
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    printf("No book found with the given ID.");
                }
                break;
            case 2:
                printf("List of Books: \n");
                for(int i=0;i<n;i++){
                    printf("%d. %s, by %s\n",i+1,library[i].book_name,library[i].author_name);
                }
                printf("Enter the book number to read: ");
                int book_num;
                scanf("%d",&book_num);
                if(book_num>0 && book_num<=n){
                    printf("\n\n~~~~~%s~~~~~\n\n",library[book_num-1].book_name);
                    printf("%s",library[book_num-1].description);
                    printf("\n\n~~~~~END OF BOOK~~~~~\n\n");
                }
                else{
                    printf("Invalid book number. Please try again.");
                }
                break;
            case 3:
                printf("Exiting the program...");
                break;
            default:
                printf("Invalid choice. Please try again.");
        }
    }while(choice!=3);

    return 0;
}