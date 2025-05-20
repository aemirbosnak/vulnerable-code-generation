//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[50];
    char brand[25];
    float price;
    int quantity;
} medicine;

void add_medicine(medicine* med, int size){
    int i;
    for(i = 0; i < size; i++){
        printf("Enter medicine name: ");
        scanf(" %[^\n]s", med[i].name);
        printf("Enter brand name: ");
        scanf(" %[^\n]s", med[i].brand);
        printf("Enter price: ");
        scanf("%f", &med[i].price);
        printf("Enter quantity: ");
        scanf("%d", &med[i].quantity);
    }
}

void display_inventory(medicine* med, int size){
    int i;
    printf("Medicine Name\tBrand\tPrice\tQuantity\n");
    for(i = 0; i < size; i++){
        printf("%s\t%s\t%.2f\t%d\n", med[i].name, med[i].brand, med[i].price, med[i].quantity);
    }
}

void search_medicine(medicine* med, int size){
    int i;
    char search_name[50];
    printf("Enter the medicine name you want to search: ");
    scanf(" %[^\n]s", search_name);
    for(i = 0; i < size; i++){
        if(strcmp(search_name, med[i].name) == 0){
            printf("Medicine Name\tBrand\tPrice\tQuantity\n");
            printf("%s\t%s\t%.2f\t%d\n", med[i].name, med[i].brand, med[i].price, med[i].quantity);
            return;
        }
    }
    printf("Medicine not found\n");
}

void update_medicine(medicine* med, int size){
    int i;
    char update_name[50];
    printf("Enter the medicine name you want to update: ");
    scanf(" %[^\n]s", update_name);
    for(i = 0; i < size; i++){
        if(strcmp(update_name, med[i].name) == 0){
            printf("Enter new medicine name: ");
            scanf(" %[^\n]s", med[i].name);
            printf("Enter new brand name: ");
            scanf(" %[^\n]s", med[i].brand);
            printf("Enter new price: ");
            scanf("%f", &med[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &med[i].quantity);
            printf("Medicine updated successfully\n");
            return;
        }
    }
    printf("Medicine not found\n");
}

void delete_medicine(medicine* med, int size){
    int i, del_index = -1;
    char del_name[50];
    printf("Enter the medicine name you want to delete: ");
    scanf(" %[^\n]s", del_name);
    for(i = 0; i < size; i++){
        if(strcmp(del_name, med[i].name) == 0){
            del_index = i;
            break;
        }
    }
    if(del_index == -1){
        printf("Medicine not found\n");
        return;
    }
    for(i = del_index; i < size - 1; i++){
        med[i] = med[i + 1];
    }
    printf("Medicine deleted successfully\n");
}

int main(){
    int choice, size = 0;
    medicine* med = (medicine*) malloc(sizeof(medicine));
    do{
        printf("\nMenu:\n1. Add Medicine\n2. Display Inventory\n3. Search Medicine\n4. Update Medicine\n5. Delete Medicine\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                size++;
                med = (medicine*) realloc(med, size * sizeof(medicine));
                add_medicine(med, size);
                break;
            case 2:
                if(size == 0){
                    printf("Inventory is empty\n");
                }
                else{
                    display_inventory(med, size);
                }
                break;
            case 3:
                if(size == 0){
                    printf("Inventory is empty\n");
                }
                else{
                    search_medicine(med, size);
                }
                break;
            case 4:
                if(size == 0){
                    printf("Inventory is empty\n");
                }
                else{
                    update_medicine(med, size);
                }
                break;
            case 5:
                if(size == 0){
                    printf("Inventory is empty\n");
                }
                else{
                    size--;
                    med = (medicine*) realloc(med, size * sizeof(medicine));
                    delete_medicine(med, size);
                }
                break;
            case 6:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 6);
    free(med);
    return 0;
}