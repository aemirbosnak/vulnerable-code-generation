//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Define the structure of a book
struct book{
    char title[50];
    char author[50];
    int publicationYear;
    float price;
};

//Function to compare two books based on their publication year
int compareBooks(const void* a, const void* b){
    const struct book* book1 = (const struct book*)a;
    const struct book* book2 = (const struct book*)b;

    if(book1->publicationYear > book2->publicationYear){
        return 1;
    }else if(book1->publicationYear < book2->publicationYear){
        return -1;
    }else{
        return 0;
    }
}

//Function to print the details of a book
void printBookDetails(const struct book* book){
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Publication Year: %d\n", book->publicationYear);
    printf("Price: $%.2f\n\n", book->price);
}

int main(){
    int numBooks;

    //Ask user for number of books
    printf("Enter the number of books: ");
    scanf("%d", &numBooks);

    //Create an array of books
    struct book* books = (struct book*)malloc(numBooks * sizeof(struct book));

    //Get details of each book from user
    for(int i=0; i<numBooks; i++){
        printf("Enter details for book %d:\n", i+1);
        printf("Title: ");
        scanf("%s", books[i].title);
        printf("Author: ");
        scanf("%s", books[i].author);
        printf("Publication Year: ");
        scanf("%d", &books[i].publicationYear);
        printf("Price: ");
        scanf("%f", &books[i].price);
    }

    //Sort the array of books based on publication year
    qsort(books, numBooks, sizeof(struct book), compareBooks);

    //Print the sorted list of books
    printf("Sorted list of books:\n");
    for(int i=0; i<numBooks; i++){
        printBookDetails(&books[i]);
    }

    free(books);

    return 0;
}