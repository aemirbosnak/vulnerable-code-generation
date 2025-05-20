//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

struct medicine{
    char name[20];
    int price;
    int quantity;
    int id;
};
typedef struct medicine medicine;

int total_cost = 0;

int add_medicine(medicine *medicines, int index){
    printf("Enter Medicine Details:\n\n");
    printf("Name: ");
    scanf("%s", medicines[index].name);
    printf("Price: ");
    scanf("%d", &medicines[index].price);
    printf("Quantity: ");
    scanf("%d", &medicines[index].quantity);
    printf("Id: ");
    scanf("%d", &medicines[index].id);
    printf("\n\nMedicine added successfully!\n\n");
    return ++index;
}

void remove_medicine(medicine *medicines, int index){
    int id;
    printf("Enter Medicine Id to remove: ");
    scanf("%d", &id);
    int found = 0;
    for(int i = 0; i<index; i++){
        if(medicines[i].id == id){
            found = 1;
            total_cost -= medicines[i].price * medicines[i].quantity;
            for(int j = i; j<index-1; j++){
                medicines[j] = medicines[j+1];
            }
            printf("\n\nMedicine removed successfully!\n\n");
            break;
        }
    }
    if(!found){
        printf("\n\nMedicine not found!\n\n");
    }
}

void display_stock(medicine *medicines, int index){
    printf("\n\n\t\tStock\n\n");
    printf("Name\t\tPrice\t\tQuantity\t\tId\n\n");
    for(int i = 0; i<index; i++){
        printf("%s\t\t%d\t\t%d\t\t\t%d\n", medicines[i].name, medicines[i].price, medicines[i].quantity, medicines[i].id);   
    }
}

void get_bill(medicine *medicines, int index){
    printf("Enter Medicine Ids:\n");
    int id, quantity;
    do{
        printf("Medicine Id (0 to stop): ");
        scanf("%d", &id);
        if(id == 0){
            break;
        }
        printf("Quantity: ");
        scanf("%d", &quantity);
        for(int i = 0; i<index; i++){
            if(medicines[i].id == id){
                if(medicines[i].quantity < quantity){
                    printf("\n\nStock not available!\n\n");
                    break;
                }
                printf("%s\t\t%d x %d\n", medicines[i].name, medicines[i].price, quantity); 
                total_cost += medicines[i].price * quantity;
                medicines[i].quantity -= quantity;
                break;
            }
            if(i == index-1){
                printf("\n\nMedicine not found!\n\n");
            }
        }
    }while(id != 0);
    printf("\nTotal Bill: %d\n\n", total_cost);
}

int main(){
    medicine medicines[100];
    int choice, index = 0;
    printf("\n\n\t\tC MEDICAL STORE MANAGEMENT SYSTEM\n\n");
    do{
        printf("1. Add Medicine\n");
        printf("2. Remove Medicine\n");
        printf("3. Display Stock\n");
        printf("4. Get Bill\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            index = add_medicine(medicines, index);
            break;
        case 2:
            remove_medicine(medicines, index);
            index--;
            break;
        case 3:
            display_stock(medicines, index);
            break;
        case 4:
            get_bill(medicines, index);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\n\nInvalid choice! Please try again.\n\n");
            break;
        }
    }while(1);
    return 0;
}