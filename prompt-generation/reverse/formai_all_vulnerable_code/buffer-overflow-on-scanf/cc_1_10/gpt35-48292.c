//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine{
    char name[50];
    int id;
    float price;
    int quantity;
}store[100];

int num_medicines = 0;

void addMedicine(){
    printf("\nEnter the Medicine name: ");
    scanf("%s", store[num_medicines].name);

    printf("\nEnter the Medicine id: ");
    scanf("%d", &store[num_medicines].id);

    printf("\nEnter the Price of the Medicine: ");
    scanf("%f", &store[num_medicines].price);

    printf("\nEnter the Quantity of the medicine: ");
    scanf("%d", &store[num_medicines].quantity);

    num_medicines++;
}

void searchMedicine(){
    int id, i, found = 0;
    printf("\nEnter the Medicine id to search: ");
    scanf("%d", &id);

    for(i=0; i<num_medicines; i++){
        if(store[i].id == id){
            found = 1;
            printf("\nMedicine is Found!!!");
            printf("\nName of the Medicine: %s\nID of the Medicine: %d\nPrice of the medicine: %f\nQuantity of the medicine: %d", store[i].name, store[i].id, store[i].price, store[i].quantity);
        }
    }
    if(found == 0){
        printf("\nThis Medicine is not found!!!");
    }
}

void purchaseMedicine(){
    int id, i, found = 0, num_purchase;
    float total_cost;
    printf("\nEnter the Medicine id you want to buy: ");
    scanf("%d", &id);

    for(i=0; i<num_medicines; i++){
        if(store[i].id == id){
            found = 1;
            printf("\n%s is Available!!!", store[i].name);

            printf("\nEnter the Quantity of the medicine you want to buy: ");
            scanf("%d", &num_purchase);

            if(num_purchase > store[i].quantity){
                printf("\nSorry, not enough stock available with us.");
            }
            else{
                total_cost = num_purchase * store[i].price;
                printf("\n You have purchased %d %s medicine. Total cost is %f", num_purchase, store[i].name, total_cost);
                store[i].quantity -= num_purchase;
            }
        }
    }
    if(found == 0){
        printf("\nThis Medicine is not available with us!!!");
    }
}

void displayMedicines(){
    int i;
    printf("\nMedicines Stock in Store:\n");
    for(i=0; i<num_medicines; i++){
        printf("\nName of the Medicine: %s\nID of the Medicine: %d\nPrice of the medicine: %f\nQuantity of the medicine: %d\n", store[i].name, store[i].id, store[i].price, store[i].quantity);
    }
}

int main(){
    int choice;
    printf("\n*****Welcome to the Medical Store Management System*****\n");
    while(1){
        printf("\n Choose the Option:");
        printf("\n1) Add Medicine");
        printf("\n2) Search Medicine");
        printf("\n3) Purchase Medicine");
        printf("\n4) Display available Medicines in the Store");
        printf("\n5) Exit");
        printf("\n Your Choice:");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addMedicine();
                break;
            case 2:
                searchMedicine();
                break;
            case 3:
                purchaseMedicine();
                break;
            case 4:
                displayMedicines();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nInvalid Choice. Please Select the Valid Choice!!!!");
        }
    }
    return 0;
}