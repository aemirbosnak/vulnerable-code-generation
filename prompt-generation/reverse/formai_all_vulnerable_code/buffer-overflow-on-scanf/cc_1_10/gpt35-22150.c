//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

struct medicine{
    char name[20];
    int quantity;
    float price;
};

void add_medicine(struct medicine *med, int size){
    for(int i=0; i<size; i++){
        printf("Enter name of the medicine %d: ", i+1);
        scanf("%s", (med+i)->name);
        printf("Enter quantity available: ");
        scanf("%d", &(med+i)->quantity);
        printf("Enter price: ");
        scanf("%f", &(med+i)->price);
    }
}

void search_medicine(struct medicine *med, int size){
    char temp[20];
    int found = 0;
    printf("\nEnter name of medicine to search: ");
    scanf("%s", temp);
    for(int i=0; i<size; i++){
        if(strcmp(temp, (med+i)->name)==0){
            found = 1;
            printf("Name: %s\n", (med+i)->name);
            printf("Quantity: %d\n", (med+i)->quantity);
            printf("Price: %.2f\n", (med+i)->price);
        }
    }
    if(!found){
        printf("Medicine not found!\n");
    }
}

void display_medicine(struct medicine *med, int size){
    printf("\nDetails of all medicines:\n");
    for(int i=0; i<size; i++){
        printf("Name: %s\n", (med+i)->name);
        printf("Quantity: %d\n", (med+i)->quantity);
        printf("Price: %.2f\n", (med+i)->price);
        printf("--------------------\n");
    }
}

void remove_medicine(struct medicine *med, int size){
    char temp[20];
    int found = 0;
    printf("\nEnter name of medicine to remove: ");
    scanf("%s", temp);
    for(int i=0; i<size; i++){
        if(strcmp(temp, (med+i)->name)==0){
            found = 1;
            printf("Removing %s from the list...\n", (med+i)->name);
            for(int j=i; j<size-1; j++){
                strcpy((med+j)->name, (med+j+1)->name);
                (med+j)->quantity = (med+j+1)->quantity;
                (med+j)->price = (med+j+1)->price;
            }
            break;
        }
    }
    if(!found){
        printf("Medicine not found!\n");
    }
}

int main(){
    int size;
    int choice = 0;
    printf("Enter number of medicines: ");
    scanf("%d", &size);
    struct medicine *med = (struct medicine*)malloc(size*sizeof(struct medicine));
    add_medicine(med, size);
    do{
        printf("\nMenu\n");
        printf("1- Search Medicine\n");
        printf("2- Display Medicines\n");
        printf("3- Remove Medicine\n");
        printf("4- Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                search_medicine(med, size);
                break;
            case 2:
                display_medicine(med, size);
                break;
            case 3:
                remove_medicine(med, size);
                size--;
                break;
            case 4:
                printf("Exiting program... \n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }while(choice!=4);
    free(med);
    return 0;
}