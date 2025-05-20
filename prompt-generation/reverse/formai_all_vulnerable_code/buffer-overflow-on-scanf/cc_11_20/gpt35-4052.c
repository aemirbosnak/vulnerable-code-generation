//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char name[30];
    int quantity;
    float price;
} Medicine;

int main() {
    int choice, num_medicines = 0, i;
    float total_price = 0;
    Medicine *medicines = NULL;
    char search_name[30];

    printf("Welcome to the C Medical Store Management System!\n");

    while(1) {
        printf("\nSelect an option:\n");
        printf("1. Add a new medicine\n");
        printf("2. Search for a medicine\n");
        printf("3. Display all medicines\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                Medicine m;
                printf("\nEnter medicine name: ");
                scanf("%s", m.name);
                printf("Enter quantity: ");
                scanf("%d", &m.quantity);
                printf("Enter price: ");
                scanf("%f", &m.price);

                medicines = realloc(medicines, (num_medicines + 1) * sizeof(Medicine));
                medicines[num_medicines++] = m;

                printf("\nMedicine added successfully!\n");
                break;
            }

            case 2: {
                printf("\nEnter medicine name to search: ");
                scanf("%s", search_name);

                for(i = 0; i < num_medicines; i++) {
                    if(strcmp(medicines[i].name, search_name) == 0) {
                        printf("\nMedicine %s found!\n", search_name);
                        printf("Quantity: %d\n", medicines[i].quantity);
                        printf("Price: %.2f\n", medicines[i].price);
                        break;
                    }
                }

                if(i == num_medicines) {
                    printf("\nMedicine %s not found.\n", search_name);
                }
                break;
            }

            case 3: {
                if(num_medicines == 0) {
                    printf("\nNo medicines found.\n");
                } else {
                    printf("\nMedicines:\n");

                    for(i = 0; i < num_medicines; i++) {
                        printf("%d. Name: %s, Quantity: %d, Price: %.2f\n", i+1, medicines[i].name, medicines[i].quantity, medicines[i].price);
                        total_price += medicines[i].price;
                    }

                    printf("\nTotal value of medicines: %.2f\n", total_price);
                }
                break;
            }

            case 4: {
                printf("\nThank you for using C Medical Store Management System!\n");
                exit(0);
            }

            default: printf("\nInvalid choice.\n");
        }
    }

    return 0;
}