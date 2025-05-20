//FormAI DATASET v1.0 Category: Ebook reader ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
} Book;

int book_count = 0;
Book library[MAX_BOOKS];

void add_book() {
    Book b;
    printf("Enter the book title: ");
    fgets(b.title, MAX_TITLE_LENGTH, stdin);
    printf("Enter the author's name: ");
    fgets(b.author, MAX_AUTHOR_LENGTH, stdin);
    printf("Enter the number of pages: ");
    scanf("%d", &b.pages);
    getchar(); //consume the newline character left behind by scanf
    library[book_count++] = b;
}

void view_library() {
    printf("Library Contents\n");
    printf("----------------\n");
    for(int i=0;i<book_count;i++) {
        printf("%d. %s by %s - %d pages\n", i+1, library[i].title, library[i].author, library[i].pages);
    }
}

void export_to_file() {
    char filename[100];
    printf("Enter the filename to export to: ");
    fgets(filename, 100, stdin);
    FILE *fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Error creating file\n");
        return;
    }
    for(int i=0;i<book_count;i++) {
        fprintf(fp, "%s,%s,%d\n", library[i].title, library[i].author, library[i].pages);
    }
    printf("Exported library to file successfully\n");
    fclose(fp);
}

void import_from_file() {
    char filename[100];
    printf("Enter the filename to import from: ");
    fgets(filename, 100, stdin);
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    char line[200];
    while(fgets(line, sizeof(line), fp)) {
        char *t = strtok(line, ",");
        char *a = strtok(NULL, ",");
        int p = atoi(strtok(NULL, ","));
        Book b;
        strcpy(b.title, t);
        strcpy(b.author, a);
        b.pages = p;
        library[book_count++] = b;
    }
    printf("Imported library from file successfully\n");
    fclose(fp);
}

void main_menu() {
    printf("C Ebook Reader\n");
    printf("---------------\n");
    printf("1. Add Book\n");
    printf("2. View Library\n");
    printf("3. Export Library to File\n");
    printf("4. Import Library from File\n");
    printf("5. Quit\n");
    printf("\nEnter your choice: ");
}

int main() {
    int choice = 0;
    while(choice!=5) {
        main_menu();
        scanf("%d", &choice); 
        getchar(); //consume the newline character left behind by scanf
        switch(choice) {
            case 1: add_book(); break;
            case 2: view_library(); break;
            case 3: export_to_file(); break;
            case 4: import_from_file(); break;
            case 5: printf("Quitting...\n"); break;
            default: printf("Invalid choice\n"); break;
        }
    }
    return 0;
}