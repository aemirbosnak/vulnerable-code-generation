//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDS 100
#define MAX_LENGTH 50

struct medicine {
    int id;
    char name[MAX_LENGTH];
    float price;
    int stock;
};

int num_medicines = 0;
struct medicine medicines[MAX_MEDS];

void add_medicine() {
    struct medicine new_med;
    new_med.id = num_medicines + 1;

    printf("Enter medicine name: ");
    fgets(new_med.name, MAX_LENGTH, stdin);
    new_med.name[strcspn(new_med.name, "\n")] = 0;

    printf("Enter medicine price: ");
    scanf("%f", &new_med.price);

    printf("Enter medicine stock: ");
    scanf("%d", &new_med.stock);

    getchar();

    medicines[num_medicines] = new_med;
    num_medicines++;

    printf("Medicine added successfully.\n");
}

void print_stock() {
    printf("id \tname \tprice \tstock\n");

    for (int i = 0; i < num_medicines; i++) {
        printf("%d \t%s \t%.2f \t%d\n",
               medicines[i].id,
               medicines[i].name,
               medicines[i].price,
               medicines[i].stock);
    }
}

void search_medicine() {
    char search_name[MAX_LENGTH];

    printf("Enter name of medicine to search: ");
    fgets(search_name, MAX_LENGTH, stdin);
    search_name[strcspn(search_name, "\n")] = 0;

    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(search_name, medicines[i].name) == 0) {
            printf("id: %d\nname: %s\nprice: %.2f\nstock: %d\n",
                   medicines[i].id,
                   medicines[i].name,
                   medicines[i].price,
                   medicines[i].stock);
            return;
        }
    }

    printf("Medicine not found.\n");

}

void sell_medicine() {
    int sell_id, sell_amount;

    printf("Enter id of medicine to sell: ");
    scanf("%d", &sell_id);

    printf("Enter amount of medicine to sell: ");
    scanf("%d", &sell_amount);

    getchar();

    for (int i = 0; i < num_medicines; i++) {
        if (medicines[i].id == sell_id) {
            if (medicines[i].stock >= sell_amount) {
                medicines[i].stock -= sell_amount;
                printf("Sale successful. Total price: %.2f\n",
                       sell_amount * medicines[i].price);
                return;
            } else {
                printf("Not enough stock.\n");
                return;
            }
        }
    }

    printf("Medicine not found.\n");
}

int main() {
    int choice;

    do {
        printf("Menu\n");
        printf("1. Add medicine\n");
        printf("2. Print stock\n");
        printf("3. Search medicine\n");
        printf("4. Sell medicine\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                print_stock();
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

    } while (choice != 5);

    return 0;
}