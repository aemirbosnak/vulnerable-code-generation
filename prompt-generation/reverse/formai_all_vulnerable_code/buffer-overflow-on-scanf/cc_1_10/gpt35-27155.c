//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 1000

struct Medicine {
    char name[50];
    float price;
    int stock_count;
};

struct Medicine medicines[MAX_MEDICINES];
int medicine_count = 0;

void display_menu() {
    printf("1. Add medicine\n");
    printf("2. View medicine list\n");
    printf("3. Search medicine by name\n");
    printf("4. Sell medicine\n");
    printf("5. Exit\n");
}

void add_medicine() {
    if (medicine_count >= MAX_MEDICINES) {
        printf("Cannot add more medicines.\n");
        return;
    }
    
    struct Medicine new_medicine;
    printf("Name: ");
    fgets(new_medicine.name, 50, stdin);
    printf("Price: ");
    scanf("%f", &new_medicine.price);
    printf("Stock count: ");
    scanf("%d", &new_medicine.stock_count);
    getchar();
    
    medicines[medicine_count++] = new_medicine;
}

void print_medicine(struct Medicine medicine) {
    printf("%s \t%.2f \t%d\n", medicine.name, medicine.price, medicine.stock_count);
}

void view_medicine_list() {
    printf("Medicine List\n");
    printf("Name \tPrice \tStock Count\n");
    for (int i = 0; i < medicine_count; i++) {
        print_medicine(medicines[i]);
    }
}

void search_medicine() {
    printf("Enter medicine name to search: ");
    char search_name[50];
    fgets(search_name, 50, stdin);
    for (int i = 0; i < medicine_count; i++) {
        if (strcmp(medicines[i].name, search_name) == 0) {
            printf("Medicine found:\n");
            print_medicine(medicines[i]);
            return;
        }
    }
    printf("Medicine not found.\n");
}

int sell_medicine() {
    printf("Enter medicine name to sell: ");
    char sell_name[50];
    fgets(sell_name, 50, stdin);
    for (int i = 0; i < medicine_count; i++) {
        if (strcmp(medicines[i].name, sell_name) == 0) {
            printf("Enter quantity to sell: ");
            int sell_quantity;
            scanf("%d", &sell_quantity);
            if (sell_quantity > medicines[i].stock_count) {
                printf("Cannot sell more than stock.\n");
                return 0;
            }
            medicines[i].stock_count -= sell_quantity;
            printf("Total price: %.2f\n", medicines[i].price * sell_quantity);
            return 1;
        }
    }
    printf("Medicine not found.\n");
    return 0;
}

int main() {
    int choice;
    
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                view_medicine_list();
                break;
            case 3:
                search_medicine();
                break;
            case 4:
                sell_medicine();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while(choice != 5);
    
    return 0;
}