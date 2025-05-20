//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

struct item{
    char name[20];
    int quantity;
    float price;
};

void displayList(struct item* list, int size){
    printf("\nName\t Quantity\t Price");
    for(int i=0; i<size; i++){
        printf("\n%s\t %d\t\t %.2f", list[i].name, list[i].quantity, list[i].price);
    }
    printf("\n");
}

void addItem(struct item* list, int size){
    printf("\nEnter item name: ");
    scanf("%s", list[size].name);
    printf("Enter item quantity: ");
    scanf("%d", &list[size].quantity);
    printf("Enter item price: ");
    scanf("%f", &list[size].price);
}

void removeItem(struct item* list, int size, char* name){
    int index = -1;
    for(int i=0; i<size; i++){
        if(strcmp(list[i].name, name) == 0){
            index = i;
            break;
        }
    }
    if(index == -1)
        printf("\nItem not found.");
    else{
        for(int i=index; i<size-1; i++)
            list[i] = list[i+1];
        printf("\nItem removed successfully!");
    }
}

int main(){
    int input = 0, size = 0;
    struct item* list = NULL;
    do{
        printf("\nChoose an option:\n1. Display List\n2. Add Item\n3. Remove Item\n4. Exit\nEnter your choice: ");
        scanf("%d", &input);
        switch(input){
            case 1:
                if(size == 0)
                    printf("\nList is empty.");
                else
                    displayList(list, size);
                break;
            case 2:
                size += 1;
                list = (struct item*) realloc(list, sizeof(struct item) * size);
                addItem(list, size-1);
                printf("\nItem added successfully!");
                break;
            case 3:
                if(size == 0)
                    printf("\nList is empty.");
                else{
                    char name[20];
                    printf("\nEnter item name to remove: ");
                    scanf("%s", name);
                    removeItem(list, size, name);
                    size -= 1;
                    list = (struct item*) realloc(list, sizeof(struct item) * size);
                }
                break;
            case 4:
                printf("\nExiting Warehouse Management System.");
                break;
            default:
                printf("\nInvalid input. Please enter a valid choice.");
        }
    }while(input != 4);
    free(list);
    return 0;
}