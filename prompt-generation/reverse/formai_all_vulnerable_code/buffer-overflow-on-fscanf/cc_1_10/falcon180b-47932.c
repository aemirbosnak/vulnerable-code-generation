//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

typedef struct{
    char title[MAX_SIZE];
    char author[MAX_SIZE];
    int pages;
    char content[MAX_SIZE*100]; //Assuming maximum 100 pages with each page having maximum 1000 characters
}Book;

int main(){
    FILE *fp;
    char ch;
    Book book;

    //Opening the Ebook file
    fp=fopen("Ebook.txt","r");

    //Checking if the file is opened successfully
    if(fp==NULL){
        printf("Error in opening the file\n");
        exit(0);
    }

    //Reading the Ebook file
    fscanf(fp,"%s %s %d",book.title,book.author,&book.pages);
    fseek(fp,0,2); //Moving the file pointer to the end of the line
    rewind(fp);

    //Reading the content of the Ebook
    while((ch=fgetc(fp))!=EOF){
        if(ch=='\n'){ //Checking for new line character
            book.content[strlen(book.content)]='\0'; //Adding null character at the end of the string
            break;
        }
        else{
            strcat(book.content,&ch); //Appending the character to the content string
        }
    }

    //Closing the Ebook file
    fclose(fp);

    //Displaying the Ebook details
    printf("Title: %s\n",book.title);
    printf("Author: %s\n",book.author);
    printf("Pages: %d\n",book.pages);

    //Displaying the Ebook content
    printf("\n\n");
    printf("%s",book.content);

    return 0;
}