//FormAI DATASET v1.0 Category: Ebook reader ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

struct ebook {
    char title[50];
    char author[50];
    char publisher[50];
    int pages;
    float price;
};

int main() 
{
    int n, i;
    printf("Enter the number of ebooks: ");
    scanf("%d", &n);

    struct ebook *ebook_list = (struct ebook*)malloc(n * sizeof(struct ebook)); 
    if (ebook_list == NULL) {
        printf("Error: Unable to allocate memory on the heap\n");
        return 1;
    }
    
    for (i = 0; i < n; i++) {
        printf("\nEnter details of ebook #%d:\n", i + 1);
        printf("Title: ");
        scanf("%s", ebook_list[i].title);
        printf("Author: ");
        scanf("%s", ebook_list[i].author);
        printf("Publisher: ");
        scanf("%s", ebook_list[i].publisher);
        printf("Number of pages: ");
        scanf("%d", &ebook_list[i].pages);
        printf("Price: ");
        scanf("%f", &ebook_list[i].price);
    }

    printf("\nYour Ebook Library Entries:\n");
    printf("--------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("Ebook #%d\n", i+1);
        printf("Title: %s\n", ebook_list[i].title);
        printf("Author: %s\n", ebook_list[i].author);
        printf("Publisher: %s\n", ebook_list[i].publisher);
        printf("Number of pages: %d\n", ebook_list[i].pages);
        printf("Price: $%.2f\n", ebook_list[i].price);
    }

    free(ebook_list);
    return 0;
}