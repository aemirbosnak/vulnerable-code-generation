//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//define structure for medicine
struct medicine{
    char name[50];
    int quantity;
    float price;
};

//prototype for functions
void menu();
void add_medicine();
void sell_medicine();
void display_medicines();

//global variables
int choice, num_medicines;
struct medicine medicines[100];

int main(){
    num_medicines = 0;
    menu(); //call menu function
    return 0;
}

void menu(){
    printf("\nWelcome to Medical Store Management System\n");
    printf("1. Add Medicine\n");
    printf("2. Sell Medicine\n");
    printf("3. Display Medicines\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            add_medicine();
            break;
        case 2:
            sell_medicine();
            break;
        case 3:
            display_medicines();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice, enter again.");
            menu();
    }
}

void add_medicine(){
    char name[50];
    int quantity;
    float price;

    printf("\nEnter name of medicine: ");
    scanf("%s", name);
    printf("Enter quantity of medicine: ");
    scanf("%d", &quantity);
    printf("Enter price of medicine: ");
    scanf("%f", &price);

    strcpy(medicines[num_medicines].name, name);
    medicines[num_medicines].quantity = quantity;
    medicines[num_medicines].price = price;

    printf("\nMedicine added successfully.");
    num_medicines++;

    menu();
}

void sell_medicine(){
    char name[50];
    int quantity, index, found=0;
    float price, total_price;

    printf("\nEnter name of medicine: ");
    scanf("%s", name);
    printf("Enter quantity of medicine: ");
    scanf("%d", &quantity);

    for(int i=0; i<num_medicines; i++){
        if(strcmp(medicines[i].name, name)==0){
            found = 1;
            index = i;
            break;
        }
    }

    if(found){
        if(medicines[index].quantity>=quantity){
            price = medicines[index].price;
            total_price = price * quantity;

            medicines[index].quantity -= quantity;

            printf("\nMedicine sold successfully.\nTotal price: $%.2f", total_price);
        }else{
            printf("\nSorry, required quantity not available.");
        }
    }else{
        printf("\nMedicine not found.");
    }

    menu();
}

void display_medicines(){
    printf("\nMedicines available:\n");
    printf("Name\t\tQuantity\tPrice\n");

    for(int i=0; i<num_medicines; i++){
        printf("%s\t\t%d\t\t$%.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }

    menu();
}