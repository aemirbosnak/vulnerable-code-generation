//FormAI DATASET v1.0 Category: Ebook reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_PER_LINE 200

typedef struct {
    char title[50];
    char author[30];
    int pageCount;
} Ebook;

void printBookDetails(Ebook book){
    printf("**** Book Details ****\n");
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Page Count: %d\n", book.pageCount);
}

int main(){
    char fileName[50];
    printf("Enter Ebook file name: ");
    scanf("%s", fileName);

    FILE *ebookFile;
    ebookFile = fopen(fileName, "r");
    if(ebookFile == NULL){
        printf("Cannot open file. Please try again!\n");
        return 1;
    }

    Ebook book;
    char line[MAX_CHAR_PER_LINE];
    int lineCounter = 0;
    while(fgets(line, MAX_CHAR_PER_LINE, ebookFile)){
        switch(lineCounter){
            case 0:
                strncpy(book.title, line, sizeof(book.title));
                break;
            case 1:
                strncpy(book.author, line, sizeof(book.author));
                break;
            case 2:
                book.pageCount = atoi(line);
                break;
            default:
                printf("Invalid format!\n");
                printBookDetails(book);
                return 1;
        }
        lineCounter++;
    }

    fclose(ebookFile);
    printBookDetails(book);
    return 0;
}