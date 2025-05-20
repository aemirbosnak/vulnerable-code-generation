//FormAI DATASET v1.0 Category: Database querying ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book{
    char title[50];
    char author[30];
    char publisher[30];
    int year;
    float price;
};

int main(){
    struct book b[5]= {
        {"The Alchemist","Paulo Coelho","HarperCollins",1988,8.99},
        {"The Da Vinci Code","Dan Brown","Doubleday",2003,15.99},
        {"Think and Grow Rich","Napoleon Hill","Rupa Publications",1937,6.99},
        {"Harry Potter and the Philosopher's Stone","J.K. Rowling","Bloomsbury",1997,10.99},
        {"The Lord of the Rings","J.R.R. Tolkien","George Allen & Unwin",1954,19.99}
    };
    char query[50];
    int choice;
    float min_price, max_price;
    printf(" ***** Welcome to the Book Database *****\n");
    printf("1. Display all books\n2. Search books by title\n3. Search books by author\n4. Search books by publisher\n5. Search books by year\n6. Search books within a price range\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("\nDisplaying all books:\n");
            for(int i=0;i<5;i++){
                printf("Title: %s\nAuthor: %s\nPublisher: %s\nYear: %d\nPrice: $%.2f\n\n",b[i].title,b[i].author,b[i].publisher,b[i].year,b[i].price);
            }
            break;
        case 2:
            printf("\nEnter the title you want to search: ");
            scanf("%s",query);
            printf("\n Search results are:\n");
            for(int i=0;i<5;i++){
                if(strcmp(b[i].title, query) == 0){
                    printf("Title: %s\nAuthor: %s\nPublisher: %s\nYear: %d\nPrice: $%.2f\n\n",b[i].title,b[i].author,b[i].publisher,b[i].year,b[i].price);
                }
            }
            break;
        case 3:
            printf("\nEnter the author you want to search: ");
            scanf("%s",query);
            printf("\n Search results are:\n");
            for(int i=0;i<5;i++){
                if(strcmp(b[i].author, query) == 0){
                    printf("Title: %s\nAuthor: %s\nPublisher: %s\nYear: %d\nPrice: $%.2f\n\n",b[i].title,b[i].author,b[i].publisher,b[i].year,b[i].price);
                }
            }
            break;
        case 4:
            printf("\nEnter the publisher you want to search: ");
            scanf("%s",query);
            printf("\n Search results are:\n");
            for(int i=0;i<5;i++){
                if(strcmp(b[i].publisher, query) == 0){
                    printf("Title: %s\nAuthor: %s\nPublisher: %s\nYear: %d\nPrice: $%.2f\n\n",b[i].title,b[i].author,b[i].publisher,b[i].year,b[i].price);
                }
            }
            break;
        case 5:
            printf("\nEnter the year you want to search: ");
            scanf("%s",query);
            printf("\n Search results are:\n");
            for(int i=0;i<5;i++){
                if(b[i].year == atoi(query)){
                    printf("Title: %s\nAuthor: %s\nPublisher: %s\nYear: %d\nPrice: $%.2f\n\n",b[i].title,b[i].author,b[i].publisher,b[i].year,b[i].price);
                }
            }
            break;
        case 6:
            printf("\nEnter minimum price: ");
            scanf("%f",&min_price);
            printf("\nEnter maximum price: ");
            scanf("%f",&max_price);
            printf("\n Search results are:\n");
            for(int i=0;i<5;i++){
                if(b[i].price >= min_price && b[i].price <= max_price){
                    printf("Title: %s\nAuthor: %s\nPublisher: %s\nYear: %d\nPrice: $%.2f\n\n",b[i].title,b[i].author,b[i].publisher,b[i].year,b[i].price);
                }
            }
            break;
        default:
            printf("\nInvalid Input.");
            break;
    }
    return 0;
}