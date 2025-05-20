//FormAI DATASET v1.0 Category: Ebook reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define the structure to hold the Ebook data
struct Ebook {
    char title[100];
    char author[100];
    int pages;
    double price;
    char publisher[100];
};

// Define a function to read the Ebook data from a file
void readEbook(FILE* fp, struct Ebook* ebook) {
    fscanf(fp, "%s", ebook->title);
    fscanf(fp, "%s", ebook->author);
    fscanf(fp, "%d", &ebook->pages);
    fscanf(fp, "%lf", &ebook->price);
    fscanf(fp, "%s", ebook->publisher);
}

// Define a function to print the Ebook data to the console
void printEbook(struct Ebook* ebook) {
    printf("Title: %s\n", ebook->title);
    printf("Author: %s\n", ebook->author);
    printf("Pages: %d\n", ebook->pages);
    printf("Price: $%.2lf\n", ebook->price);
    printf("Publisher: %s\n", ebook->publisher);
}

int main() {
    FILE* fp;
    struct Ebook ebook;
    char fileName[100];

    printf("Enter the name of the Ebook file: ");
    scanf("%s", fileName);
    
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    
    // Read the Ebook data from the file
    readEbook(fp, &ebook);
    
    // Print the Ebook data to the console
    printEbook(&ebook);
    
    fclose(fp);

    return 0;
}