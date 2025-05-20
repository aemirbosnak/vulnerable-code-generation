//FormAI DATASET v1.0 Category: Database Indexing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for the indexing system
typedef struct {
    int index;
    char *name;
} Index;

int main() {
    int option = 1;
    
    // Array of indices
    Index indexArray[50];
    int currentIndex = 0;
    
    while (option != 0) {
        printf("Welcome to the Database Indexing System!\n");
        printf("Please select an option:\n");
        printf("1. Add an index\n");
        printf("2. View all indices\n");
        printf("3. Search for an index\n");
        printf("0. Exit\n");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                // Adding an index
                printf("Please enter the index number:\n");
                int newNumber;
                scanf("%d", &newNumber);
                
                printf("Please enter the name for the index:\n");
                char newName[50];
                scanf("%s", newName);
                
                // Creating a new index struct and adding it to the array
                Index newIndex;
                newIndex.index = newNumber;
                newIndex.name = (char*) malloc(sizeof(char) * 50);
                strcpy(newIndex.name, newName);
                
                indexArray[currentIndex] = newIndex;
                currentIndex++;
                
                printf("Index added successfully!\n");
                break;
            case 2:
                // Viewing all indices
                printf("Index\tName\n");
                for (int i = 0; i < currentIndex; i++) {
                    printf("%d\t%s\n", indexArray[i].index, indexArray[i].name);
                }
                break;
            case 3:
                // Searching for an index
                printf("Please enter the index number you wish to search for:\n");
                int searchNumber;
                scanf("%d", &searchNumber);

                // Using linear search to find the matching index
                for (int i = 0; i < currentIndex; i++) {
                    if (indexArray[i].index == searchNumber) {
                        printf("Index found: %d\t%s\n", indexArray[i].index, indexArray[i].name);
                        break;
                    }
                }
                break;
            case 0:
                // Exit
                printf("Exiting program...\n");
                break;
            default:
                // Invalid option
                printf("Invalid option, please try again.\n");
                break;
        }
    }
    
    return 0;
}