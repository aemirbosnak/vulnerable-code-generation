//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct medicine {
    char name[50];
    float price;
    int stock;
} medicine;

void add_medicine(medicine meds[], int *count) {
    if (*count < MAX_MEDICINES) {
        printf("Enter medicine name: ");
        scanf("%s", meds[*count].name);
        printf("Enter medicine price: ");
        scanf("%f", &meds[*count].price);
        printf("Enter medicine stock: ");
        scanf("%d", &meds[*count].stock);
        
        *count += 1;
        printf("Medicine added successfully!\n");
    } else {
        printf("Cannot add medicine: maximum limit reached.\n");
    }
}

void list_medicines(medicine meds[], int count) {
    if (count == 0) {
        printf("No medicines in stock.\n");
        return;
    }
    
    printf("%-20s %-10s %-10s\n", "Medicine Name", "Price", "Stock");
 
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10.2f %-10d\n", meds[i].name, meds[i].price, meds[i].stock);
    }
}

void search_medicine(medicine meds[], int count) {
    char search_term[50];
    printf("Enter medicine name to search: ");
    scanf("%s", search_term);
 
    for (int i = 0; i < count; i++) {
        if (strcmp(meds[i].name, search_term) == 0) {
            printf("%-20s %-10s %-10s\n", "Medicine Name", "Price", "Stock");
            printf("%-20s %-10.2f %-10d\n", meds[i].name, meds[i].price, meds[i].stock);
            return;
        }
    }
 
    printf("Medicine not found.\n");
}

void delete_medicine(medicine meds[], int *count) {
    char search_term[50];
    printf("Enter medicine name to delete: ");
    scanf("%s", search_term);
 
    for (int i = 0; i < *count; i++) {
        if (strcmp(meds[i].name, search_term) == 0) {
            for (int j = i; j < *count - 1; j++) {
                strcpy(meds[j].name, meds[j + 1].name);
                meds[j].price = meds[j + 1].price;
                meds[j].stock = meds[j + 1].stock;
            }
 
            *count -= 1;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
 
    printf("Medicine not found.\n");
}

int main() {
    int menu_choice, medicine_count = 0;
    medicine medicines[MAX_MEDICINES];
    
    while (1) {
        printf("\n***** Medical Store Management System *****\n");
        printf("1. Add medicine\n");
        printf("2. List all medicines\n");
        printf("3. Search medicine\n");
        printf("4. Delete medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &menu_choice);
        
        switch (menu_choice) {
            case 1:
                add_medicine(medicines, &medicine_count);
                break;
            case 2:
                list_medicines(medicines, medicine_count);
                break;
            case 3:
                search_medicine(medicines, medicine_count);
                break;
            case 4:
                delete_medicine(medicines, &medicine_count);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}