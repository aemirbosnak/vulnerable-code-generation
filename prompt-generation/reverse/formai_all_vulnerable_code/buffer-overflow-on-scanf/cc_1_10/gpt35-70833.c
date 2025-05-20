//FormAI DATASET v1.0 Category: Hotel Management System ; Style: random
#include <stdio.h>

// Function to add customer
void addCustomer(int room[], char name[][20], int type[], int days[], int count) {
    printf("Enter customer name: ");
    scanf("%s", name[count]);
    printf("Enter room number: ");
    scanf("%d", &room[count]);
    printf("Enter room type (1-Standard, 2-Deluxe, 3-Suite): ");
    scanf("%d", &type[count]);
    printf("Enter number of days of stay: ");
    scanf("%d", &days[count]);
    printf("Customer added successfully!\n");
    printf("-------------------------------------------------\n");
}

// Function to display customer details
void displayCustomers(int room[], char name[][20], int type[], int days[], int count) {
    printf("Room No.\tCustomer Name\tRoom Type\tDays\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t\t%s\t\t", room[i], name[i]);
        if (type[i] == 1) {
            printf("Standard\t");
        } else if (type[i] == 2) {
            printf("Deluxe\t\t");
        } else {
            printf("Suite\t\t");
        }
        printf("%d\n", days[i]);
    }
    printf("-------------------------------------------------\n");
}

// Function to calculate bill
void calculateBill(int room[], char name[][20], int type[], int days[], int count) {
    int bill = 0;
    for (int i = 0; i < count; i++) {
        if (type[i] == 1) {
            bill += 1000 * days[i];
        } else if (type[i] == 2) {
            bill += 2000 * days[i];
        } else {
            bill += 3000 * days[i];
        }
    }
    printf("Total bill: Rs. %d\n", bill);
    printf("-------------------------------------------------\n");
}

int main() {
    int choice, count = 0;
    int room[100], type[100], days[100];
    char name[100][20];

    printf("Welcome to C Hotel Management System!\n");
    printf("-------------------------------------------------\n");

    do {
        printf("1. Add customer\n");
        printf("2. Display customers\n");
        printf("3. Calculate bill\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addCustomer(room, name, type, days, count);
                count++;
                break;
            case 2:
                displayCustomers(room, name, type, days, count);
                break;
            case 3:
                calculateBill(room, name, type, days, count);
                break;
            case 4:
                printf("Thank you for using C Hotel Management System!\n");
                printf("-------------------------------------------------\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                printf("-------------------------------------------------\n");
                break;
        }
    } while (choice != 4);

    return 0;
}