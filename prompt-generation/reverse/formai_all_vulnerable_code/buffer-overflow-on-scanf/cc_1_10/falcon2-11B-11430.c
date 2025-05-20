//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[50];
    int quantity;
    double price;
};

struct product medicines[10];
int medicine_count = 0;

void add_medicine(struct product* medicine) {
    strcpy(medicines[medicine_count].name, medicine->name);
    medicines[medicine_count].quantity = medicine->quantity;
    medicines[medicine_count].price = medicine->price;
    medicine_count++;
}

int find_medicine(struct product* medicine) {
    int i;
    for (i = 0; i < medicine_count; i++) {
        if (strcmp(medicines[i].name, medicine->name) == 0) {
            return i;
        }
    }
    return -1;
}

void remove_medicine(struct product* medicine) {
    int index = find_medicine(medicine);
    if (index!= -1) {
        for (int i = index; i < medicine_count - 1; i++) {
            strcpy(medicines[i].name, medicines[i + 1].name);
            medicines[i].quantity = medicines[i + 1].quantity;
            medicines[i].price = medicines[i + 1].price;
        }
        medicine_count--;
    }
}

void update_medicine(struct product* medicine) {
    int index = find_medicine(medicine);
    if (index!= -1) {
        strcpy(medicines[index].name, medicine->name);
        medicines[index].quantity = medicine->quantity;
        medicines[index].price = medicine->price;
    }
}

void display_medicine() {
    int i;
    for (i = 0; i < medicine_count; i++) {
        printf("%s: %d @ %.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

int main() {
    struct product medicine;
    char choice;

    while (1) {
        printf("Medical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Remove Medicine\n");
        printf("3. Update Medicine\n");
        printf("4. Display Medicine\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter medicine name: ");
                scanf(" %s", medicine.name);
                printf("Enter medicine quantity: ");
                scanf(" %d", &medicine.quantity);
                printf("Enter medicine price: ");
                scanf(" %lf", &medicine.price);
                add_medicine(&medicine);
                break;

            case '2':
                printf("Enter medicine name: ");
                scanf(" %s", medicine.name);
                remove_medicine(&medicine);
                break;

            case '3':
                printf("Enter medicine name: ");
                scanf(" %s", medicine.name);
                update_medicine(&medicine);
                break;

            case '4':
                display_medicine();
                break;

            case '5':
                printf("Thank you for using the Medical Store Management System.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}