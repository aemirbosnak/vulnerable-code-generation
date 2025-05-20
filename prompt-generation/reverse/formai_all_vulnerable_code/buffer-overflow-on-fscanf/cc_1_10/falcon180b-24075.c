//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    char content[1000];
} ebook;

int main() {
    ebook book;
    int choice, res;
    char filename[100];

    printf("Welcome to the Ebook Reader!\n");
    printf("Enter 1 to create a new Ebook\n");
    printf("Enter 2 to read an existing Ebook\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the title of the Ebook: ");
            scanf("%s", book.title);
            printf("Enter the author of the Ebook: ");
            scanf("%s", book.author);
            printf("Enter the content of the Ebook:\n");
            fgets(book.content, 1000, stdin);
            strcat(book.content, "\n");
            printf("Ebook created successfully!\n");
            break;
        case 2:
            printf("Enter the filename of the Ebook: ");
            scanf("%s", filename);
            FILE *fp = fopen(filename, "r");
            if(fp == NULL) {
                printf("File not found!\n");
                exit(0);
            }
            res = fscanf(fp, "%s %s %[^\n]", book.title, book.author, book.content);
            if(res!= 3) {
                printf("Invalid Ebook format!\n");
                exit(0);
            }
            fclose(fp);
            printf("Ebook loaded successfully!\n");
            printf("Title: %s\n", book.title);
            printf("Author: %s\n", book.author);
            printf("Content:\n%s", book.content);
            break;
        default:
            printf("Invalid choice!\n");
            exit(0);
    }

    return 0;
}