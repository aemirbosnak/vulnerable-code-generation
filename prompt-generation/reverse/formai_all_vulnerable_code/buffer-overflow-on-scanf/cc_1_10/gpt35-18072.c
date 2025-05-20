//FormAI DATASET v1.0 Category: Database simulation ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//structure to hold book info
struct Book{
    char title[50];
    char author[50];
    int year;
};

//function to clear the input buffer
void clearBuffer(){
    char c;
    while((c=getchar()) != '\n' && c != EOF);
}

//function to add a book to the database
void addBook(struct Book** database, int* count){
    struct Book* temp = (struct Book*)malloc(sizeof(struct Book));
    printf("\nEnter the book title: ");
    fgets(temp->title, 50, stdin);
    printf("\nEnter the book author: ");
    fgets(temp->author, 50, stdin);
    printf("\nEnter the book year: ");
    scanf("%d", &temp->year);
    clearBuffer();
    (*count)++;
    if((*count) == 1){
        *database = (struct Book*)malloc(sizeof(struct Book));
    }
    else{
        *database = (struct Book*)realloc(*database, (*count)*sizeof(struct Book));
    }
    (*database)[*count-1] = *temp;
    free(temp);
    printf("\nBook added to the database\n");
}

//function to delete a book from the database
void deleteBook(struct Book** database, int* count){
    if(*count == 0){
        printf("\nNo books in the database\n");
        return;
    }
    char title[50], author[50];
    int year, flag=0;
    printf("\nEnter the book title: ");
    fgets(title, 50, stdin);
    printf("\nEnter the book author: ");
    fgets(author, 50, stdin);
    printf("\nEnter the book year: ");
    scanf("%d", &year);
    clearBuffer();
    for(int i=0; i<*count; i++){
        if(strcmp((*database)[i].title, title)==0 && strcmp((*database)[i].author, author)==0 && (*database)[i].year==year){
            for(int j=i; j<*count-1; j++){
                (*database)[j] = (*database)[j+1];
            }
            (*count)--;
            flag=1;
            printf("\nBook deleted from the database\n");
            break;
        }
    }
    if(flag==0){
        printf("\nNo such book found in the database\n");
    }
}

//function to display all the books in the database
void displayBooks(struct Book* database, int count){
    if(count == 0){
        printf("\nNo books in the database\n");
        return;
    }
    printf("\nTotal books in the database: %d\n", count);
    for(int i=0; i<count; i++){
        printf("\nBook %d\n", i+1);
        printf("Title: %s", database[i].title);
        printf("Author: %s", database[i].author);
        printf("Year: %d\n", database[i].year);
    }
}

int main(){
    struct Book* database = NULL;
    int count=0, choice;
    printf("Welcome to the Medieval Library Database\n");
    while(1){
        printf("\nChoose an option:\n");
        printf("1. Add a book\n");
        printf("2. Delete a book\n");
        printf("3. Display all books\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        clearBuffer();
        switch(choice){
            case 1: addBook(&database, &count);
                break;
            case 2: deleteBook(&database, &count);
                break;
            case 3: displayBooks(database, count);
                break;
            case 4: printf("\nGoodbye!\n");
                exit(0);
            default: printf("\nInvalid option, try again\n");
        }
    }
    return 0;
}