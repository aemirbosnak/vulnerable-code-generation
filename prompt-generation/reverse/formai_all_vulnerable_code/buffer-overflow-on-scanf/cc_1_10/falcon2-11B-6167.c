//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

struct medicine {
    char name[50];
    float price;
};

void add_medicine(struct medicine *medicine) {
    printf("Enter medicine name: ");
    scanf("%s", medicine->name);

    printf("Enter medicine price: ");
    scanf("%f", &medicine->price);
}

void display_medicine_list(struct medicine *medicine_list, int size) {
    for (int i = 0; i < size; i++) {
        printf("Name: %s, Price: %.2f\n", medicine_list[i].name, medicine_list[i].price);
    }
}

int main() {
    struct medicine medicine_list[10];

    int size = 0;

    while (1) {
        printf("\nMedical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicine List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine(&medicine_list[size]);
                size++;
                break;
            case 2:
                display_medicine_list(medicine_list, size);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}