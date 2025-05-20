//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct medicine inventory[1000];
int count = 0;

void add_medicine() {
    system("clear");
    printf("Enter Medicine ID: ");
    scanf("%d", &inventory[count].id);
    printf("Enter Medicine Name: ");
    scanf("%s", inventory[count].name);
    printf("Enter Quantity: ");
    scanf("%d", &inventory[count].quantity);
    printf("Enter Price: ");
    scanf("%f", &inventory[count].price);
    count++;
    printf("Medicine Details Successfully Added.\n");
}

void view_medicine() {
    system("clear");
    printf("ID\tMedicine Name\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void search_medicine() {
    system("clear");
    printf("Enter Medicine ID: ");
    int id;
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("Medicine Details:\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n", 
            inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Medicine not found.");
}

void update_medicine() {
    system("clear");
    int id;
    printf("Enter Medicine ID: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("Enter new Medicine Name: ");
            scanf("%s", inventory[i].name);
            printf("Enter new Quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new Price: ");
            scanf("%f", &inventory[i].price);
            printf("Medicine details updated successfully.\n");
            return;
        }
    }
    printf("Medicine not found.");

}

void delete_medicine() {
    system("clear");
    int id;
    printf("Enter Medicine ID to be deleted: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                inventory[j] = inventory[j+1];
            }
            count--;
            printf("Medicine successfully deleted.\n");
            return;
        }
    }
    printf("Medicine not found.");

}

int main() {
    int choice;
    while (1) {
        printf("1. Add Medicine\n2. View Medicine\n3. Search Medicine\n4. Update Medicine\n5. Delete Medicine\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: add_medicine();
                    break;
            case 2: view_medicine();
                    break;
            case 3: search_medicine();
                    break;
            case 4: update_medicine();
                    break;
            case 5: delete_medicine();
                    break;
            case 6: exit(0);
            default: printf("Invalid Choice.\n");        
        }
    }
    return 0;
}