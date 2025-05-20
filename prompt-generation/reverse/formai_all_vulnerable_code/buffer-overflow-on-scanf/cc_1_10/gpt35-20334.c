//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOXES 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
} Box;

Box boxes[MAX_BOXES];
int numBoxes = 0;

void addBox(char name[], char description[], int quantity) {
    if(numBoxes >= MAX_BOXES) {
        printf("Sorry, warehouse is full.\n");
        return;
    }
    
    int id = numBoxes + 1;
    
    Box newBox = {
        .id = id,
        .quantity = quantity
    };
    
    strncpy(newBox.name, name, MAX_NAME_LENGTH);
    strncpy(newBox.description, description, MAX_DESCRIPTION_LENGTH);
    
    boxes[numBoxes] = newBox;
    numBoxes++;
    
    printf("Box with ID %d added to warehouse.\n", id);
}

void listBoxes() {
    printf("\nList of boxes in warehouse:\n\n");
    for(int i = 0; i < numBoxes; i++) {
        printf("ID: %d\n", boxes[i].id);
        printf("Name: %s\n", boxes[i].name);
        printf("Description: %s\n", boxes[i].description);
        printf("Quantity: %d\n", boxes[i].quantity);
        printf("-------------------------------------\n");
    }
}

void updateBox(int id, char name[], char description[], int quantity) {
    for(int i = 0; i < numBoxes; i++) {
        if(boxes[i].id == id) {
            strncpy(boxes[i].name, name, MAX_NAME_LENGTH);
            strncpy(boxes[i].description, description, MAX_DESCRIPTION_LENGTH);
            boxes[i].quantity = quantity;
            printf("Box with ID %d updated.\n", id);
            return;
        }
    }
    
    printf("Box with ID %d not found.\n", id);
}

void removeBox(int id) {
    for(int i = 0; i < numBoxes; i++) {
        if(boxes[i].id == id) {
            for(int j = i; j < numBoxes - 1; j++) {
                boxes[j] = boxes[j + 1];
            }
            numBoxes--;
            printf("Box with ID %d removed from warehouse.\n", id);
            return;
        }
    }
    
    printf("Box with ID %d not found.\n", id);
}

int main() {
    int choice, id, quantity;
    char name[MAX_NAME_LENGTH], description[MAX_DESCRIPTION_LENGTH];
    
    do {
        printf("1. Add box to warehouse\n");
        printf("2. List boxes in warehouse\n");
        printf("3. Update box in warehouse\n");
        printf("4. Remove box from warehouse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter box name: ");
                scanf("%s", name);
                printf("Enter box description: ");
                scanf("%s", description);
                printf("Enter box quantity: ");
                scanf("%d", &quantity);
                addBox(name, description, quantity);
                break;
            case 2:
                listBoxes();
                break;
            case 3:
                printf("Enter box ID: ");
                scanf("%d", &id);
                printf("Enter box name: ");
                scanf("%s", name);
                printf("Enter box description: ");
                scanf("%s", description);
                printf("Enter box quantity: ");
                scanf("%d", &quantity);
                updateBox(id, name, description, quantity);
                break;
            case 4:
                printf("Enter box ID: ");
                scanf("%d", &id);
                removeBox(id);
                break;
            case 5:
                printf("Goodbye.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
        
    } while(choice != 5);
    
    return 0;
}