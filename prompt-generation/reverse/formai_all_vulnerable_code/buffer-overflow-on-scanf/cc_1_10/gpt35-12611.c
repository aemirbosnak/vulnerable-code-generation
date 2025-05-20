//FormAI DATASET v1.0 Category: Ebook reader ; Style: happy
#include<stdio.h> 
#include<string.h> 

int main() { 

    char bookTitle[50]; 
    char author[50]; 
    char genre[50]; 
    int pageNum = 0; 

    printf("Enter the title of the book: "); 
    scanf("%s", bookTitle); 

    printf("Enter the author of the book: "); 
    scanf("%s", author); 

    printf("Enter the genre of the book: "); 
    scanf("%s", genre); 

    printf("Enter the number of pages in the book: "); 
    scanf("%d", &pageNum); 

    printf("\n"); 

    printf("******************************\n"); 
    printf("      %s\n", bookTitle); 
    printf("      by %s\n", author); 
    printf("      Genre: %s\n", genre); 
    printf("      Pages: %d\n", pageNum); 
    printf("******************************\n\n"); 

    printf("What page are you currently on? "); 
    int currentPageNum; 
    scanf("%d", &currentPageNum); 

    if (currentPageNum < 0 || currentPageNum > pageNum) { 
        printf("Invalid page number."); 
        return 1; 
    } 

    printf("\n"); 

    printf("******************************\n"); 
    printf("      %s\n", bookTitle); 
    printf("******************************\n\n"); 

    printf("Here's what's on page %d:\n\n", currentPageNum); 

    char pageContent[500]; 
    printf("<< "); 
    fgets(pageContent, 500, stdin); 
    printf("%s >>\n\n", pageContent); 

    printf("Press enter when you're done reading."); 
    getchar(); 

    printf("\n"); 

    printf("Thanks for reading! That's all for now."); 

    return 0; 
}