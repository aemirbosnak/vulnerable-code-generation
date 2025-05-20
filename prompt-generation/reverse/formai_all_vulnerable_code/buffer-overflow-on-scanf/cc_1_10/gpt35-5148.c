//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining structure for medicines
struct medicine {
    char name[50];
    int quantity;
    float price;
};

// function to display menu
void menu() {
    printf("\nWelcome to C Medical Store Management System\n");
    printf("1. Add Medicine\n");
    printf("2. Update Medicine\n");
    printf("3. Delete Medicine\n");
    printf("4. View All Medicines\n");
    printf("5. Exit\n");
}

// function to add medicine
void add_medicine(struct medicine *medicines, int *count) {
    printf("\nAdding Medicine\n");
    printf("Enter Name: ");
    scanf("%s", medicines[*count].name);
    printf("Enter Quantity: ");
    scanf("%d", &medicines[*count].quantity);
    printf("Enter Price: ");
    scanf("%f", &medicines[*count].price);
    (*count)++;
    printf("Medicine Added Successfully!\n");
}

// function to get index of medicine given its name
int get_medicine_index(struct medicine *medicines, int count, char *name) {
    for (int i=0; i<count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// function to update medicine
void update_medicine(struct medicine *medicines, int count) {
    char name[50];
    printf("\nUpdating Medicine\n");
    printf("Enter Name: ");
    scanf("%s", name);
    int index = get_medicine_index(medicines, count, name);
    if (index == -1) {
        printf("Medicine not found!\n");
    } else {
        printf("Enter New Quantity: ");
        scanf("%d", &medicines[index].quantity);
        printf("Enter New Price: ");
        scanf("%f", &medicines[index].price);
        printf("Medicine Updated Successfully!\n");
    }
}

// function to delete medicine
void delete_medicine(struct medicine *medicines, int *count) {
    char name[50];
    printf("\nDeleting Medicine\n");
    printf("Enter Name: ");
    scanf("%s", name);
    int index = get_medicine_index(medicines, *count, name);
    if (index == -1) {
        printf("Medicine not found!\n");
    } else {
        for (int i=index; i<*count-1; i++) {
            strcpy(medicines[i].name, medicines[i+1].name);
            medicines[i].quantity = medicines[i+1].quantity;
            medicines[i].price = medicines[i+1].price;
        }
        (*count)--;
        printf("Medicine Deleted Successfully!\n");
    }
}

// function to view all medicines
void view_medicines(struct medicine *medicines, int count) {
    printf("\nAll Medicines\n");
    printf("Name\tQuantity\tPrice\n");
    for (int i=0; i<count; i++) {
        printf("%s\t%d\t\t%.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

// main function
int main() {
    struct medicine medicines[100];
    int count = 0; // number of medicines
    int choice;
    do {
        menu();
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // add medicine
                add_medicine(medicines, &count);
                break;
            case 2: // update medicine
                update_medicine(medicines, count);
                break;
            case 3: // delete medicine
                delete_medicine(medicines, &count);
                break;
            case 4: // view all medicines
                view_medicines(medicines, count);
                break;
            case 5: // exit
                printf("\nThank you for using C Medical Store Management System!\n");
                exit(0);
            default:
                printf("Invalid Choice! Try Again.\n");
        }

    } while (choice != 5);

    return 0;
}