//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 1000
#define MED_NAME_LEN 30

struct medicine {
    char name[MED_NAME_LEN];
    int stock;
    float price;
};

typedef struct medicine medicine_t;

int num_medicines = 0;

medicine_t medicines[MAX_MEDICINES];

void add_medicine(char name[], int stock, float price) {
    if (num_medicines == MAX_MEDICINES) {
        printf("Error: Maximum number of medicines reached!\n");
        return;
    }
    
    medicine_t new_medicine;
    strcpy(new_medicine.name, name);
    new_medicine.stock = stock;
    new_medicine.price = price;
    
    medicines[num_medicines] = new_medicine;
    num_medicines++;
    
    printf("Medicine Added Successfully!\n");
}

void update_medicine(char name[], int new_stock, float new_price) {
    int index = -1;
    
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Error: Medicine Not Found!\n");
        return;
    }
    
    medicines[index].stock = new_stock;
    medicines[index].price = new_price;
    
    printf("Medicine Updated Successfully!\n");
}

void sell_medicine(char name[], int quantity) {
    int index = -1;
    
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Error: Medicine Not Found!\n");
        return;
    }
    
    if (medicines[index].stock < quantity) {
        printf("Error: Not Enough Stock!\n");
        return;
    }
    
    medicines[index].stock -= quantity;
    
    float total_price = medicines[index].price * quantity;
    
    printf("Medicine Sold Successfully! Total Price: %.2f\n", total_price);
}

void print_medicines() {
    printf("Medicine List:\n");
    
    for (int i = 0; i < num_medicines; i++) {
        printf("%d. %s - Stock: %d - Price: %.2f\n", i+1, medicines[i].name, medicines[i].stock, medicines[i].price);
    }
}

void print_menu() {
    printf("Medical Store Management System\n");
    printf("1. Add Medicine\n");
    printf("2. Update Medicine\n");
    printf("3. Sell Medicine\n");
    printf("4. View Medicine List\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    char name[MED_NAME_LEN];
    int stock;
    float price;
    
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter Medicine Name: ");
                scanf("%s", name);
                printf("Enter Stock: ");
                scanf("%d", &stock);
                printf("Enter Price: ");
                scanf("%f", &price);
                add_medicine(name, stock, price);
                break;
                
            case 2:
                printf("Enter Medicine Name to Update: ");
                scanf("%s", name);
                printf("Enter New Stock: ");
                scanf("%d", &stock);
                printf("Enter New Price: ");
                scanf("%f", &price);
                update_medicine(name, stock, price);
                break;
                
            case 3:
                printf("Enter Medicine Name to Sell: ");
                scanf("%s", name);
                printf("Enter Quantity: ");
                scanf("%d", &stock);
                sell_medicine(name, stock);
                break;
                
            case 4:
                print_medicines();
                break;
                
            case 5:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid Choice!\n");
        }
        
    } while (choice != 5);
    
    return 0;
}