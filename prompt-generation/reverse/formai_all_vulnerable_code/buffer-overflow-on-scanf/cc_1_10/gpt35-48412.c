//FormAI DATASET v1.0 Category: Ebook reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of ebooks the library can hold
#define MAX_LIBRARY_SIZE 50

// Define the structure of an ebook
typedef struct {
    char title[50];
    char author[50];
    char language[20];
    float price;
    int year;
    char path[100];
} Ebook;

// Declare the library as a global variable
Ebook library[MAX_LIBRARY_SIZE];

// Declare the number of ebooks in the library as a global variable
int num_ebooks = 0;

// Function to add an ebook to the library
void add_ebook() {
    // Check if the library is full
    if (num_ebooks == MAX_LIBRARY_SIZE) {
        printf("The library is full!");
        return;
    }
    
    // Create a new ebook
    Ebook new_ebook;
    
    // Prompt the user for information about the ebook
    printf("Enter the title: ");
    scanf("%s", new_ebook.title);
    printf("Enter the author: ");
    scanf("%s", new_ebook.author);
    printf("Enter the language: ");
    scanf("%s", new_ebook.language);
    printf("Enter the price: ");
    scanf("%f", &new_ebook.price);
    printf("Enter the year of publication: ");
    scanf("%d", &new_ebook.year);
    printf("Enter the file path: ");
    scanf("%s", new_ebook.path);
    
    // Add the ebook to the library
    library[num_ebooks] = new_ebook;
    num_ebooks++;
    
    printf("Ebook added!\n\n");
}

// Function to display information about a specific ebook
void view_ebook() {
    // Prompt the user for the index of the ebook
    int index;
    printf("Enter the index of the ebook: ");
    scanf("%d", &index);
    
    // Check if the index is valid
    if (index < 0 || index >= num_ebooks) {
        printf("Invalid index!");
        return;
    }
    
    // Display information about the ebook
    printf("Title: %s\n", library[index].title);
    printf("Author: %s\n", library[index].author);
    printf("Language: %s\n", library[index].language);
    printf("Price: %.2f\n", library[index].price);
    printf("Year of publication: %d\n", library[index].year);
    printf("File path: %s\n\n", library[index].path);
}

// Function to display information about all ebooks in the library
void view_all_ebooks() {
    // Check if the library is empty
    if (num_ebooks == 0) {
        printf("The library is empty!");
        return;
    }
    
    // Display information about all ebooks in the library
    printf("Ebooks in the library:\n");
    for (int i = 0; i < num_ebooks; i++) {
        printf("%d. %s by %s (%d)\n", i, library[i].title, library[i].author, library[i].year);
    }
    printf("\n");
}

// Function to remove an ebook from the library
void remove_ebook() {
    // Prompt the user for the index of the ebook
    int index;
    printf("Enter the index of the ebook: ");
    scanf("%d", &index);
    
    // Check if the index is valid
    if (index < 0 || index >= num_ebooks) {
        printf("Invalid index!");
        return;
    }
    
    // Remove the ebook from the library
    for (int i = index; i < num_ebooks - 1; i++) {
        library[i] = library[i+1];
    }
    num_ebooks--;
    
    printf("Ebook removed!\n\n");
}

// Function to display the menu and get user input
void display_menu() {
    printf("Welcome to the Ebook Library!\n");
    printf("------------------------------\n\n");
    
    int choice = 0;
    do {
        printf("Menu:\n");
        printf("1. Add an ebook\n");
        printf("2. View an ebook\n");
        printf("3. View all ebooks\n");
        printf("4. Remove an ebook\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch (choice) {
            case 1:
                add_ebook();
                break;
            case 2:
                view_ebook();
                break;
            case 3:
                view_all_ebooks();
                break;
            case 4:
                remove_ebook();
                break;
            case 5:
                printf("Goodbye!");
                break;
            default:
                printf("Invalid choice! Please try again.\n\n");
                break;
        }
    } while (choice != 5);
}

int main() {
    display_menu();
    return 0;
}