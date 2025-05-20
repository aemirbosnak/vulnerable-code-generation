//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: real-life
#include <stdio.h>
#include <string.h>

// Define struct for medicine
struct Medicine {
    char name[30];
    char company[30];
    float price;
    int stock;
};

// Define function to add medicine
void add_medicine(struct Medicine *meds, int size) {
    printf("Enter medicine name: ");
    scanf("%s", meds[size].name);
    printf("Enter medicine company: ");
    scanf("%s", meds[size].company);
    printf("Enter medicine price: ");
    scanf("%f", &meds[size].price);
    printf("Enter medicine stock: ");
    scanf("%d", &meds[size].stock);
    printf("Medicine successfully added!\n");
}

// Define function to remove medicine
void remove_medicine(struct Medicine *meds, int size) {
    int i, j;
    char name[30];
    printf("Enter medicine name: ");
    scanf("%s", name);
    for (i = 0; i < size; i++) {
        if (strcmp(meds[i].name, name) == 0) {
            for (j = i; j < size - 1; j++) {
                strcpy(meds[j].name, meds[j+1].name);
                strcpy(meds[j].company, meds[j+1].company);
                meds[j].price = meds[j+1].price;
                meds[j].stock = meds[j+1].stock;
            }
            break;
        }
    }
    if (i == size) {
        printf("Medicine not found!\n");
    } else {
        printf("Medicine successfully removed!\n");
    }
}

// Define function to update medicine
void update_medicine(struct Medicine *meds, int size) {
    int i;
    char name[30];
    printf("Enter medicine name: ");
    scanf("%s", name);
    for (i = 0; i < size; i++) {
        if (strcmp(meds[i].name, name) == 0) {
            printf("Enter new medicine name (or enter to skip): ");
            scanf("%s", meds[i].name);
            printf("Enter new medicine company (or enter to skip): ");
            scanf("%s", meds[i].company);
            printf("Enter new medicine price (or enter 0 to skip): ");
            scanf("%f", &meds[i].price);
            printf("Enter new medicine stock (or enter 0 to skip): ");
            scanf("%d", &meds[i].stock);
            printf("Medicine successfully updated!\n");
            break;
        }
    }
    if (i == size) {
        printf("Medicine not found!\n");
    }
}

// Define function to search medicine
void search_medicine(struct Medicine *meds, int size) {
    int i, found = 0;
    char name[30];
    printf("Enter medicine name: ");
    scanf("%s", name);
    for (i = 0; i < size; i++) {
        if (strcmp(meds[i].name, name) == 0) {
            printf("Name: %s\n", meds[i].name);
            printf("Company: %s\n", meds[i].company);
            printf("Price: %.2f\n", meds[i].price);
            printf("Stock: %d\n", meds[i].stock);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("Medicine not found!\n");
    }
}

// Define function to display all medicines
void display_medicines(struct Medicine *meds, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d. Name: %s, Company: %s, Price: %.2f, Stock: %d\n", i+1, meds[i].name, meds[i].company, meds[i].price, meds[i].stock);
    }
    if (size == 0) {
        printf("No medicines found!\n");
    }
}

// Define main function
int main() {
    struct Medicine meds[100];
    int choice, size = 0;
    while (1) {
        // Display menu
        printf("\nMEDICAL STORE MANAGEMENT SYSTEM\n");
        printf("1. Add medicine\n");
        printf("2. Remove medicine\n");
        printf("3. Update medicine\n");
        printf("4. Search medicine\n");
        printf("5. Display all medicines\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on user choice
        switch (choice) {
            case 1:
                add_medicine(meds, size);
                size++;
                break;
            case 2:
                remove_medicine(meds, size);
                size--;
                break;
            case 3:
                update_medicine(meds, size);
                break;
            case 4:
                search_medicine(meds, size);
                break;
            case 5:
                display_medicines(meds, size);
                break;
            case 6:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}