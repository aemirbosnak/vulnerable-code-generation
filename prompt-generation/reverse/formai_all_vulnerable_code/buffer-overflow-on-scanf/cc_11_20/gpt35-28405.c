//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct Medicine {
    char name[20];
    int quantity;
    float price;
};

struct Store {
    struct Medicine store_items[MAX];
    int item_count;
};

int main() {
    struct Store medical_store;
    medical_store.item_count = 0;
    char pwd[] = "password123";
    char in_pwd[20];
    printf("Enter Password to access the Medical Store Management System: ");
    scanf("%s", in_pwd);
    if(strcmp(pwd, in_pwd) != 0) {
        printf("Incorrect Password! Access Denied.\n");
        exit(EXIT_FAILURE);
    }
    int choice;
    do {
        printf("\n\nWelcome to the Paranoid Medical Store Management System!\n");
        printf("-----------------------------------------------------------\n");
        printf("1. Add a medicine to the store.\n");
        printf("2. Remove a medicine from the store.\n");
        printf("3. Update the quantity/price of a medicine in the store.\n");
        printf("4. Display all medicines in the store.\n");
        printf("5. Exit.\n");
        printf("-----------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                if(medical_store.item_count == MAX) {
                    printf("\nSorry! Maximum limit of store items reached.\n");
                    printf("Cannot add more medicines to the store.\n");
                    break;
                }
                printf("\nEnter details of medicine %d:\n", (medical_store.item_count+1));
                printf("Name: ");
                scanf("%s", medical_store.store_items[medical_store.item_count].name);
                printf("Quantity: ");
                scanf("%d", &medical_store.store_items[medical_store.item_count].quantity);
                printf("Price: ");
                scanf("%f", &medical_store.store_items[medical_store.item_count].price);
                printf("\nMedicine added to store successfully.\n");
                medical_store.item_count++;
                break;
            }
            case 2: {
                if(medical_store.item_count == 0) {
                    printf("\nSorry! The store is empty. Cannot remove medicines.\n");
                    break;
                }
                char medicine_name[20];
                printf("\nEnter name of medicine to remove: ");
                scanf("%s", medicine_name);
                int i, index = -1;
                for(i=0; i<medical_store.item_count; i++) {
                    if(strcmp(medicine_name, medical_store.store_items[i].name) == 0) {
                        index = i;
                        break;
                    }
                }
                if(index == -1) {
                    printf("\nSorry! Medicine not found in the store.\n");
                } else {
                    for(i=index; i<medical_store.item_count-1; i++) {
                        medical_store.store_items[i] = medical_store.store_items[i+1];
                    }
                    printf("\nMedicine removed from store successfully.\n");
                    medical_store.item_count--;
                }
                break;
            }
            case 3: {
                if(medical_store.item_count == 0) {
                    printf("\nSorry! The store is empty. Cannot update medicines.\n");
                    break;
                }
                char medicine_name[20];
                printf("\nEnter name of medicine to update: ");
                scanf("%s", medicine_name);
                int i, index = -1;
                for(i=0; i<medical_store.item_count; i++) {
                    if(strcmp(medicine_name, medical_store.store_items[i].name) == 0) {
                        index = i;
                        break;
                    }
                }
                if(index == -1) {
                    printf("\nSorry! Medicine not found in the store.\n");
                } else {
                    printf("\nEnter new quantity of medicine: ");
                    scanf("%d", &medical_store.store_items[index].quantity);
                    printf("Enter new price of medicine: ");
                    scanf("%f", &medical_store.store_items[index].price);
                    printf("\nMedicine updated successfully.\n");
                }
                break;
            }
            case 4: {
                printf("\nMedicines in the store:\n\n");
                printf("Name\tQuantity\tPrice\n");
                printf("-----------------------------------------------------------\n");
                int i;
                for(i=0; i<medical_store.item_count; i++) {
                    printf("%s\t%d\t\t%.2f\n", medical_store.store_items[i].name,
                            medical_store.store_items[i].quantity, medical_store.store_items[i].price);
                }
                break;
            }
            case 5: {
                printf("\n\nThank you for using the Paranoid Medical Store Management System!\n");
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);
            }
            default: {
                printf("\nInvalid choice! Please choose a valid option.\n");
                break;
            }
        }
    } while(choice != 5);
    return 0;
}