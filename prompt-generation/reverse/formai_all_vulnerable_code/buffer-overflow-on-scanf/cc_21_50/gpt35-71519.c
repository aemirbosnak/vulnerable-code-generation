//FormAI DATASET v1.0 Category: Ebook reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for the ebook
typedef struct {
    char title[50];
    char author[50];
    char publisher[50];
    float price;
} ebook;

int main() {
    int ebook_count = 0;
    ebook *library = NULL;
    
    printf("Welcome to the Ebook Reader!\n");
    
    int choice;
    
    do {
        printf("\nPlease select an option:\n");
        printf("1. Add an ebook\n");
        printf("2. View all ebooks\n");
        printf("3. Search ebooks by author\n");
        printf("4. Search ebooks by publisher\n");
        printf("5. Search ebooks by price\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 0:
                printf("\nThank you for using Ebook Reader. Goodbye!\n");
                
                // Free allocated memory
                free(library);
                break;
            case 1: {
                // Allocate memory for one more ebook
                ebook_count++;
                library = realloc(library, ebook_count * sizeof(ebook));
                
                // Get user input for ebook details
                printf("\nEbook #%d:\n", ebook_count);
                printf("Enter the title: ");
                scanf("%s", library[ebook_count-1].title);
                printf("Enter the author: ");
                scanf("%s", library[ebook_count-1].author);
                printf("Enter the publisher: ");
                scanf("%s", library[ebook_count-1].publisher);
                printf("Enter the price: ");
                scanf("%f", &library[ebook_count-1].price);
                
                printf("\nEbook #%d added successfully.\n", ebook_count);
                
                break;
            }
            case 2:
                if(ebook_count == 0) {
                    printf("\nError: No ebooks in library.\n");
                    break;
                }
                
                printf("\nAll ebooks in library:\n");
                
                for(int i=0; i<ebook_count; i++) {
                    printf("\nEbook #%d:\n", i+1);
                    printf("Title: %s\n", library[i].title);
                    printf("Author: %s\n", library[i].author);
                    printf("Publisher: %s\n", library[i].publisher);
                    printf("Price: $%.2f\n", library[i].price);
                }
                
                break;
            case 3: {
                if(ebook_count == 0) {
                    printf("\nError: No ebooks in library.\n");
                    break;
                }
                
                char author_search[50];
                printf("\nEnter author name: ");
                scanf("%s", author_search);
                
                printf("\nEbooks by author \"%s\":\n", author_search);
                
                int found = 0; // To check if any ebooks were found with the author name
                
                // Search for ebooks with the given author name
                for(int i=0; i<ebook_count; i++) {
                    if(strcmp(library[i].author, author_search) == 0) {
                        printf("\nEbook #%d:\n", i+1);
                        printf("Title: %s\n", library[i].title);
                        printf("Author: %s\n", library[i].author);
                        printf("Publisher: %s\n", library[i].publisher);
                        printf("Price: $%.2f\n", library[i].price);
                        
                        found = 1;
                    }
                }
                
                if(!found) {
                    printf("\nNo ebooks found with author name \"%s\".\n", author_search);
                }
                
                break;
            }
            case 4: {
                if(ebook_count == 0) {
                    printf("\nError: No ebooks in library.\n");
                    break;
                }
                
                char publisher_search[50];
                printf("\nEnter publisher name: ");
                scanf("%s", publisher_search);
                
                printf("\nEbooks by publisher \"%s\":\n", publisher_search);
                
                int found = 0; // To check if any ebooks were found with the publisher name
                
                // Search for ebooks with the given publisher name
                for(int i=0; i<ebook_count; i++) {
                    if(strcmp(library[i].publisher, publisher_search) == 0) {
                        printf("\nEbook #%d:\n", i+1);
                        printf("Title: %s\n", library[i].title);
                        printf("Author: %s\n", library[i].author);
                        printf("Publisher: %s\n", library[i].publisher);
                        printf("Price: $%.2f\n", library[i].price);
                        
                        found = 1;
                    }
                }
                
                if(!found) {
                    printf("\nNo ebooks found with publisher name \"%s\".\n", publisher_search);
                }
                
                break;
            }
            case 5: {
                if(ebook_count == 0) {
                    printf("\nError: No ebooks in library.\n");
                    break;
                }
                
                float price_search;
                printf("\nEnter maximum price: ");
                scanf("%f", &price_search);
                
                printf("\nEbooks under $%.2f:\n", price_search);
                
                int found = 0; // To check if any ebooks were found under the given price
                
                // Search for ebooks under the given price
                for(int i=0; i<ebook_count; i++) {
                    if(library[i].price <= price_search) {
                        printf("\nEbook #%d:\n", i+1);
                        printf("Title: %s\n", library[i].title);
                        printf("Author: %s\n", library[i].author);
                        printf("Publisher: %s\n", library[i].publisher);
                        printf("Price: $%.2f\n", library[i].price);
                        
                        found = 1;
                    }
                }
                
                if(!found) {
                    printf("\nNo ebooks found under $%.2f.\n", price_search);
                }
                
                break;
            }
            default:
                printf("\nError: Invalid choice.\n");
        }
    } while(choice != 0);
    
    return 0;
}