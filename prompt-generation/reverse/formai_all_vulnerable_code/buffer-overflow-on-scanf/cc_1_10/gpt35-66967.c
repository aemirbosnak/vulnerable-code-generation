//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100 //maximum number of medicines 

struct Medicine{
    int id; //unique id for each medicine
    char name[50];
    int quantity;
    float price;
}medicines[MAX_SIZE];

int count = 0; //to keep track of number of medicines in stock

void addMedicine(){
    printf("Enter the details of the medicine to add:\n");

    printf("Enter the unique ID of the medicine: ");
    scanf("%d", &medicines[count].id);

    printf("Enter the name of the medicine: ");
    scanf("%s", medicines[count].name);

    printf("Enter the quantity of the medicine: ");
    scanf("%d", &medicines[count].quantity);

    printf("Enter the price of the medicine: ");
    scanf("%f", &medicines[count].price);

    printf("Medicine added successfully!\n");

    count++; //increment the count of medicines
}

void viewMedicines(){
    if(count == 0){
        printf("No medicines in stock!\n");
        return;
    }

    printf("ID\tName\tQuantity\tPrice\n");
    for(int i=0; i<count; i++){
        printf("%d\t%s\t%d\t\t%.2f\n", medicines[i].id, medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

void updateMedicine(){
    if(count == 0){
        printf("No medicines in stock!\n");
        return;
    }

    int id, index = -1;
    printf("Enter the ID of the medicine to update: ");
    scanf("%d", &id);

    for(int i=0; i<count; i++){
        if(medicines[i].id == id){
            index = i;
            break;
        }
    }

    if(index == -1){
        printf("Medicine with ID %d not found!\n", id);
        return;
    }

    printf("Enter the new details of the medicine:\n");

    printf("Enter the unique ID of the medicine: ");
    scanf("%d", &medicines[index].id);

    printf("Enter the name of the medicine: ");
    scanf("%s", medicines[index].name);

    printf("Enter the quantity of the medicine: ");
    scanf("%d", &medicines[index].quantity);

    printf("Enter the price of the medicine: ");
    scanf("%f", &medicines[index].price);

    printf("Medicine updated successfully!\n");
}

void deleteMedicine(){
    if(count == 0){
        printf("No medicines in stock!\n");
        return;
    }

    int id, index = -1;
    printf("Enter the ID of the medicine to delete: ");
    scanf("%d", &id);

    for(int i=0; i<count; i++){
        if(medicines[i].id == id){
            index = i;
            break;
        }
    }

    if(index == -1){
        printf("Medicine with ID %d not found!\n", id);
        return;
    }

    for(int i=index; i<count-1; i++){
        medicines[i] = medicines[i+1];
    }

    count--;

    printf("Medicine deleted successfully!\n");
}

int main(){
    int choice;

    while(1){
        printf("--------------\n");
        printf("1. Add Medicine\n");
        printf("2. View Medicines\n");
        printf("3. Update Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. Exit\n");
        printf("--------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addMedicine();
                break;
            case 2:
                viewMedicines();
                break;
            case 3:
                updateMedicine();
                break;
            case 4:
                deleteMedicine();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}