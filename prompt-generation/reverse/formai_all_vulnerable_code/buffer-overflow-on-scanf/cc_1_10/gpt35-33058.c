//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine {
    int med_id;
    char med_name[50];
    int quantity;
    float price;
    int expiry_date[3];
};

void addMedicine(struct medicine* med_list, int size) {
    int id;
    char name[50];
    int qty;
    float price;
    int exp_date[3];
    printf("Enter medicine ID: ");
    scanf("%d", &id);
    for (int i=0; i<size; i++) {
        if (med_list[i].med_id == id) {
            printf("Medicine with ID %d already exists!\n", id);
            return;
        }
    }
    printf("Enter medicine name: ");
    scanf("%s", name);
    printf("Enter quantity: ");
    scanf("%d", &qty);
    printf("Enter price: ");
    scanf("%f", &price);
    printf("Enter expiry date [dd/mm/yyyy]: ");
    scanf("%d/%d/%d", &exp_date[0], &exp_date[1], &exp_date[2]);
    struct medicine med;
    med.med_id = id;
    strcpy(med.med_name, name);
    med.quantity = qty;
    med.price = price;
    memcpy(med.expiry_date, exp_date, sizeof(exp_date));
    med_list[size] = med;
    printf("Medicine added successfully!\n");
}

void removeMedicine(struct medicine* med_list, int size) {
    int id;
    printf("Enter medicine ID to remove: ");
    scanf("%d", &id);
    int i=0;
    for (i=0; i<size; i++) {
        if (med_list[i].med_id == id) {
            break;
        }
    }
    if (i == size) {
        printf("Medicine with ID %d not found!\n", id);
        return;
    }
    for (int j=i; j<size-1; j++) {
        med_list[j] = med_list[j+1];
    }
    printf("Medicine with ID %d removed successfully!\n", id);
}

void displayMedicine(struct medicine* med_list, int size) {
    printf("Medicine ID\tMedicine Name\tQuantity\tPrice\tExpiry Date\n");
    for (int i=0; i<size; i++) {
        printf("%d\t\t%s\t\t%d\t\t%.2f\t%d/%d/%d\n", med_list[i].med_id,
               med_list[i].med_name, med_list[i].quantity, med_list[i].price,
               med_list[i].expiry_date[0], med_list[i].expiry_date[1],
               med_list[i].expiry_date[2]);
    }
}

void searchMedicine(struct medicine* med_list, int size) {
    int id;
    printf("Enter medicine ID to search: ");
    scanf("%d", &id);
    for (int i=0; i<size; i++) {
        if (med_list[i].med_id == id) {
            printf("Medicine details: \n");
            printf("Medicine ID\tMedicine Name\tQuantity\tPrice\tExpiry Date\n");
            printf("%d\t\t%s\t\t%d\t\t%.2f\t%d/%d/%d\n", med_list[i].med_id,
                   med_list[i].med_name, med_list[i].quantity, med_list[i].price,
                   med_list[i].expiry_date[0], med_list[i].expiry_date[1],
                   med_list[i].expiry_date[2]);
            return;
        }
    }
    printf("Medicine with ID %d not found!\n", id);
}

void updateMedicine(struct medicine* med_list, int size) {
    int id;
    printf("Enter medicine ID to update: ");
    scanf("%d", &id);
    int i=0;
    for (i=0; i<size; i++) {
        if (med_list[i].med_id == id) {
            break;
        }
    }
    if (i == size) {
        printf("Medicine with ID %d not found!\n", id);
        return;
    }
    char name[50];
    int qty;
    float price;
    int exp_date[3];
    printf("Enter new medicine name (leave blank to keep old name): ");
    scanf("%s", name);
    if (strcmp(name, "") != 0) {
        strcpy(med_list[i].med_name, name);
    }
    printf("Enter new quantity: ");
    scanf("%d", &qty);
    med_list[i].quantity = qty;
    printf("Enter new price: ");
    scanf("%f", &price);
    med_list[i].price = price;
    printf("Enter new expiry date [dd/mm/yyyy]: ");
    scanf("%d/%d/%d", &exp_date[0], &exp_date[1], &exp_date[2]);
    memcpy(med_list[i].expiry_date, exp_date, sizeof(exp_date));
    printf("Medicine with ID %d updated successfully!\n", id);
}

int main() {
    struct medicine med_list[100];
    int size = 0;
    int choice = 0;
    while (1) {
        printf("\n");
        printf("1. Add Medicine\n");
        printf("2. Remove Medicine\n");
        printf("3. Display Medicines\n");
        printf("4. Search Medicine\n");
        printf("5. Update Medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice) {
            case 1:
                addMedicine(med_list, size);
                size++;
                break;
            case 2:
                removeMedicine(med_list, size);
                size--;
                break;
            case 3:
                displayMedicine(med_list, size);
                break;
            case 4:
                searchMedicine(med_list, size);
                break;
            case 5:
                updateMedicine(med_list, size);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}