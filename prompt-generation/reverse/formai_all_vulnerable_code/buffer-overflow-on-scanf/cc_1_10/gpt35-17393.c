//FormAI DATASET v1.0 Category: Ebook reader ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure for storing the details of the ebook
struct ebook {
    char title[50];
    char author[50];
    char publisher[50];
    int year;
    char filename[50];
};

//Function to display the details of a particular ebook
void display_ebook(struct ebook *e) {
    printf("\nTitle: %s\nAuthor: %s\nPublisher: %s\nYear: %d\nFilename: %s\n", e->title, e->author, e->publisher, e->year, e->filename);
}

//Function to add a new ebook to the library
void add_ebook(struct ebook *e) {
    printf("Enter the Title: ");
    scanf("%s", e->title);
    printf("Enter the Author: ");
    scanf("%s", e->author);
    printf("Enter the Publisher: ");
    scanf("%s", e->publisher);
    printf("Enter the Year of Publication: ");
    scanf("%d", &e->year);
    printf("Enter the Filename: ");
    scanf("%s", e->filename);
}

//Function to search for an ebook by title
void search_ebook(struct ebook *library, int size) {
    char search_title[50];
    printf("Enter the Title to Search: ");
    scanf("%s", search_title);
    for(int i=0;i<size;i++) {
        if(strcmp(library[i].title, search_title) == 0) {
            display_ebook(&library[i]);
            return;
        }
    }
    printf("\nEbook Not Found!\n");
}

//Function to remove an ebook from the library
void remove_ebook(struct ebook *library, int *size) {
    char search_title[50];
    printf("Enter the Title to Remove: ");
    scanf("%s", search_title);
    int removed = 0;
    for(int i=0;i<*size;i++) {
        if(strcmp(library[i].title, search_title) == 0) {
            removed = 1;
            for(int j=i;j<*size-1;j++) {
                library[j] = library[j+1];
            }
            (*size)--;
            printf("\nEbook Removed Succesfully!\n");
            break;
        }
    }
    if(!removed) {
        printf("\nEbook Not Found!\n");
    }
}

//Main function
int main() {
    struct ebook library[20];
    int option, size=0;
    do {
        printf("\n******************** Ebook Reader ********************\n");
        printf("1. Add Ebook\n2. View Ebook by Title\n3. Remove Ebook\n4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch(option) {
            
            case 1:
                add_ebook(&library[size]);
                size++;
                break;
            
            case 2:
                search_ebook(library, size);
                break;
                
            case 3:
                remove_ebook(library, &size);
                break;
                
            case 4:
                printf("\nThank You for Using Ebook Reader!\n");
                break;
                
            default:
                printf("\nInvalid Option, please try again!\n");
                break;
        }
    }
    while(option != 4);
    
    return 0;
}