//FormAI DATASET v1.0 Category: Phone Book ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure to hold phone book entries
struct PhoneBook {
    char name[50];
    char phone_number[15];
};

//Function prototypes
void addEntry(struct PhoneBook *book, int *size);
void displayBook(struct PhoneBook *book, int size);
void deleteEntry(struct PhoneBook *book, int *size, char *name);

int main() {
    int size = 0; //Number of entries in the phone book
    int choice = 0; //Menu choice
    char name[50]; //Name used for adding or deleting entries
    struct PhoneBook *book = NULL; //Array to hold entries (allocated dynamically)
    
    printf("Welcome to the C Phone Book!\n\n");
    
    while(choice != 4) {
        printf("Choose an option:\n");
        printf("1. Add an entry\n");
        printf("2. Display all entries\n");
        printf("3. Delete an entry\n");
        printf("4. Quit\n");
        printf(">> ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addEntry(book, &size);
                break;
            case 2:
                displayBook(book, size);
                break;
            case 3:
                printf("Enter name to delete: ");
                scanf("%s", name);
                deleteEntry(book, &size, name);
                break;
            case 4:
                printf("Thank you for using the C Phone Book!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    
    free(book); //Free allocated memory
    return 0;
}

//Function to add a new entry to the phone book
void addEntry(struct PhoneBook *book, int *size) {
    book = (struct PhoneBook *)realloc(book, (*size + 1) * sizeof(struct PhoneBook)); //Allocate memory for a new entry
    printf("Enter name: ");
    scanf("%s", book[*size].name);
    printf("Enter phone number (10 digits): ");
    scanf("%s", book[*size].phone_number);
    (*size)++; //Update number of entries in the phone book
    printf("Entry added.\n");
}

//Function to display all entries in the phone book
void displayBook(struct PhoneBook *book, int size) {
    printf("Phone Book Entries:\n");
    for(int i = 0; i < size; i++) {
        printf("%s: %s\n", book[i].name, book[i].phone_number);
    }
}

//Function to delete an entry from the phone book
void deleteEntry(struct PhoneBook *book, int *size, char *name) {
    int index = -1; //Index of the entry to delete
    for(int i = 0; i < *size; i++) {
        if(strcmp(book[i].name, name) == 0) { //Found the entry
            index = i;
            break;
        }
    }
    if(index == -1) { //Entry not found
        printf("Entry not found.\n");
    }
    else { //Entry found
        for(int i = index; i < *size - 1; i++) { //Shift entries over to fill gap
            strcpy(book[i].name, book[i+1].name);
            strcpy(book[i].phone_number, book[i+1].phone_number);
        }
        (*size)--; //Update number of entries in the phone book
        book = (struct PhoneBook *)realloc(book, *size * sizeof(struct PhoneBook)); //Free memory for deleted entry
        printf("Entry deleted.\n");
    }
}