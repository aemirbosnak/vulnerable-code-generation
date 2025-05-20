//FormAI DATASET v1.0 Category: Ebook reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EBOOKS 1000
#define MAX_TITLE_SIZE 100
#define MAX_AUTHOR_SIZE 50
#define MAX_PAGES 10000
#define MAX_FILE_SIZE 1000

typedef struct Ebook{
    char title[MAX_TITLE_SIZE];
    char author[MAX_AUTHOR_SIZE];
    int pages;
    char* contents;
}Ebook;

Ebook ebooks[MAX_EBOOKS];

int numEbooks = 0;

int addEbook(char* title, char* author, int pages, char* contents){
    if(numEbooks >= MAX_EBOOKS){
        return 0;
    }
    strcpy(ebooks[numEbooks].title, title);
    strcpy(ebooks[numEbooks].author, author);
    ebooks[numEbooks].pages = pages;
    ebooks[numEbooks].contents = (char*)malloc(strlen(contents) * sizeof(char));
    strcpy(ebooks[numEbooks].contents, contents);
    numEbooks++;
    return 1;
}

void readEbook(int ebookIndex){
    printf("Title: %s\n", ebooks[ebookIndex].title);
    printf("Author: %s\n", ebooks[ebookIndex].author);
    printf("Pages: %d\n\n", ebooks[ebookIndex].pages);
    printf("%s\n", ebooks[ebookIndex].contents);
}

int main(){

    char title[MAX_TITLE_SIZE];
    char author[MAX_AUTHOR_SIZE];
    int pages;
    char filename[MAX_FILE_SIZE];

    printf("Welcome to the Ebook Reader!\n\n");

    while(1){
        printf("What would you like to do?\n");
        printf("1. Read an Ebook\n");
        printf("2. Add an Ebook\n");
        printf("3. Quit\n");

        int choice;
        scanf("%d", &choice);

        if(choice == 1){
            // Read an Ebook
            printf("Which Ebook would you like to read? Enter the index: ");
            int index;
            scanf("%d", &index);
            readEbook(index);
        }
        else if(choice == 2){
            // Add an Ebook
            printf("Enter the title of the Ebook: ");
            scanf("%s", title);

            printf("Enter the author of the Ebook: ");
            scanf("%s", author);

            printf("Enter the number of pages in the Ebook: ");
            scanf("%d", &pages);

            printf("Enter the name of the file containing the contents of the Ebook: ");
            scanf("%s", filename);

            FILE* file = fopen(filename, "r");
            if(file == NULL){
                printf("Couldn't open file '%s'\n", filename);
                continue;
            }

            char contents[MAX_PAGES];
            int size = 0;
            while(!feof(file) && size < MAX_PAGES){
                int c = fgetc(file);
                if(c == EOF) break;
                contents[size++] = c;
            }
            contents[size] = '\0';
            fclose(file);

            if(addEbook(title, author, pages, contents)){
                printf("Ebook added successfully!\n");
            }
            else{
                printf("Could not add Ebook.\n");
            }
        }
        else if(choice == 3){
            // Quit
            printf("Thank you for using the Ebook Reader!\n");
            break;
        }
        else{
            printf("Invalid choice. Please try again.\n");
        }
    }

    for(int i=0; i<numEbooks; i++){
        free(ebooks[i].contents);
    }

    return 0;
}