//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medical_store{
    char med_name[20];
    int med_id;
    float price;
    int quantity;
}med[100];

int num_of_med;

void add_med(){
    printf("Enter the details of medicine: \n");
    printf("Enter the medicine name: ");
    scanf("%s", med[num_of_med].med_name);
    printf("Enter the medicine ID: ");
    scanf("%d", &med[num_of_med].med_id);
    printf("Enter the medicine price: ");
    scanf("%f", &med[num_of_med].price);
    printf("Enter the quantity: ");
    scanf("%d", &med[num_of_med].quantity);
    num_of_med++;
    printf("\nMedicine added successfully!\n\n");
}

int search_med(int id){
    for(int i=0; i<num_of_med; i++){
        if(med[i].med_id == id){
            return i;
        }
    }
    return -1;
}

void delete_med(){
    int id, idx;
    printf("Enter the ID of medicine to delete: ");
    scanf("%d", &id);
    idx = search_med(id);
    if(idx == -1){
        printf("\nMedicine with entered ID not found!\n\n");
    }else{
        for(int i=idx; i<num_of_med-1; i++){
            med[i] = med[i+1];
        }
        num_of_med--;
        printf("\nMedicine deleted successfully!\n\n");
    }
}

void update_med(){
    int id, idx, choice;
    printf("Enter the ID of medicine to update: ");
    scanf("%d", &id);
    idx = search_med(id);
    if(idx == -1){
        printf("\nMedicine with entered ID not found!\n\n");
    }else{
        printf("\nWhat do you want to update?\n");
        printf("1. Medicine name\n");
        printf("2. Medicine price\n");
        printf("3. Medicine quantity\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the new medicine name: ");
                scanf("%s", med[idx].med_name);
                break;
            case 2:
                printf("Enter the new medicine price: ");
                scanf("%f", &med[idx].price);
                break;
            case 3:
                printf("Enter the new quantity: ");
                scanf("%d", &med[idx].quantity);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
        printf("\nMedicine details updated successfully!\n\n");
    }
}

void display_med(){
    printf("\nList of medicines: \n\n");
    printf("Name\t\tID\t\tPrice\t\tQuantity\n");
    for(int i=0; i<num_of_med; i++){
        printf("%s\t\t%d\t\t%.2f\t\t%d\n", med[i].med_name, med[i].med_id, med[i].price, med[i].quantity);
    }
    printf("\n");
}

int main(){
    int choice = 0;
    while(choice != 5){
        printf("\n\nWelcome to Medical Store Management System!\n");
        printf("1. Add medicine\n");
        printf("2. Delete medicine\n");
        printf("3. Update medicine details\n");
        printf("4. Display medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_med();
                break;
            case 2:
                delete_med();
                break;
            case 3:
                update_med();
                break;
            case 4:
                display_med();
                break;
            case 5:
                printf("\n\nThank you for using Medical Store Management System!\n");
                break;
            default:
                printf("\nInvalid choice! Try again\n\n");
                break;
        }
    }
    return 0;
}