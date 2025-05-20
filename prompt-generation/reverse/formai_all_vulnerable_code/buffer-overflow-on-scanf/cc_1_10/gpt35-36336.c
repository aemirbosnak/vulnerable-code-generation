//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    int id;
    char name[50];
    int quantity;
    float price;
};

typedef struct medicine Medicine;

void displayMenu() {
    printf("********** Medical Store Management System **********\n");
    printf("1. Add Medicine\n");
    printf("2. Sell Medicine\n");
    printf("3. Update Medicine Information\n");
    printf("4. View All Medicines\n");
    printf("5. View Medicine Information\n");
    printf("6. Exit\n");
    printf("********************************************************\n");
}

int getMedicineIndexById(Medicine *medicines, int id, int n) {
    for(int i = 0; i < n; i++) {
        if(medicines[i].id == id) {
            return i;
        }
    }
    return -1;
}

void addMedicine(Medicine *medicines, int *n) {
    Medicine med;
    printf("Enter Medicine ID: ");
    scanf("%d", &med.id);
    printf("Enter Medicine Name: ");
    scanf("%s", med.name);
    printf("Enter Medicine Quantity: ");
    scanf("%d", &med.quantity);
    printf("Enter Medicine Price: ");
    scanf("%f", &med.price);
    medicines[*n] = med;
    (*n)++;
}

void sellMedicine(Medicine *medicines, int n, int id) {
    int index = getMedicineIndexById(medicines, id, n);
    if(index == -1) {
        printf("Medicine not found!\n");
        return;
    }
    printf("Enter Quantity to Sell: ");
    int quantity;
    scanf("%d", &quantity);
    if(quantity > medicines[index].quantity) {
        printf("Insufficient quantity!\n");
        return;
    }
    medicines[index].quantity -= quantity;
    printf("Total Price: %.2f\n", quantity * medicines[index].price);
}

void updateMedicine(Medicine *medicines, int n, int id) {
    int index = getMedicineIndexById(medicines, id, n);
    if(index == -1) {
        printf("Medicine not found!\n");
        return;
    }
    printf("Enter New Medicine Name (Press Enter to skip): ");
    char name[50];
    getchar(); // Consume newline character left by previous scanf
    fgets(name, 50, stdin);
    if(strlen(name) > 0 && name[strlen(name) - 1] == '\n') {
        name[strlen(name) - 1] = '\0';
    }
    if(strlen(name) > 0) {
        strcpy(medicines[index].name, name);
    }
    printf("Enter New Medicine Quantity (Press 0 to skip): ");
    int quantity;
    scanf("%d", &quantity);
    if(quantity > 0) {
        medicines[index].quantity = quantity;
    }
    printf("Enter New Medicine Price (Press 0.0 to skip): ");
    float price;
    scanf("%f", &price);
    if(price > 0.0) {
        medicines[index].price = price;
    }
}

void viewAllMedicines(Medicine *medicines, int n) {
    printf("ID\tName\tQuantity\tPrice\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", medicines[i].id, medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

void viewMedicineInfo(Medicine *medicines, int n, int id) {
    int index = getMedicineIndexById(medicines, id, n);
    if(index == -1) {
        printf("Medicine not found!\n");
        return;
    }
    printf("ID\tName\tQuantity\tPrice\n");
    printf("%d\t%s\t%d\t\t%.2f\n", medicines[index].id, medicines[index].name, medicines[index].quantity, medicines[index].price);
}

int main() {
    Medicine medicines[100];
    int n = 0;
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addMedicine(medicines, &n);
                break;
            case 2:
                {
                    int id;
                    printf("Enter Medicine ID to Sell: ");
                    scanf("%d", &id);
                    sellMedicine(medicines, n, id);
                    break;
                }
            case 3:
                {
                    int id;
                    printf("Enter Medicine ID to Update: ");
                    scanf("%d", &id);
                    updateMedicine(medicines, n, id);
                    break;
                }
            case 4:
                viewAllMedicines(medicines, n);
                break;
            case 5:
                {
                    int id;
                    printf("Enter Medicine ID to View Info: ");
                    scanf("%d", &id);
                    viewMedicineInfo(medicines, n, id);
                    break;
                }
            case 6:
                printf("Exiting!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 6);
    
    return 0;
}