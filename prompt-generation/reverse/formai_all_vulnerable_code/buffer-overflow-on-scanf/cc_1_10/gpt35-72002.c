//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define global variables */
int numOfMeds = 0;
int capacity = 100;
int numOfSales = 0;

/* Define Structures */
typedef struct {
    int id;
    char name[100];
    int quantity;
    float price;
    char expDate[11];
} Medicine;

typedef struct {
    int id;
    char name[100];
    char dateTime[20];
    Medicine* meds;
    int* quantity;
    float totalPrice;
    int numOfMeds;
} Sale;

/* Create an empty Medicine Store */
Medicine *store[100];

/* Function prototypes */
void addMedicine();
void removeMedicine();
void editMedicine();
void printMedicines();
void makeSale();

/* Main function */
int main() {
    int option;
    while (1) {
        printf("\n** MEDICAL STORE MANAGEMENT SYSTEM **\n");
        printf("1. Add Medicine\n");
        printf("2. Remove Medicine\n");
        printf("3. Edit Medicine\n");
        printf("4. Print List of Medicines\n");
        printf("5. Make a Sale\n");
        printf("6. Exit\n");
        printf("Select an option: ");

        scanf("%d", &option);
        switch (option) {
            case 1: addMedicine(); break;
            case 2: removeMedicine(); break;
            case 3: editMedicine(); break;
            case 4: printMedicines(); break;
            case 5: makeSale(); break;
            case 6: exit(0);
            default: printf("Invalid option. Try again\n");
        }
    }
    return 0;
}

/* Add Medicine Function */
void addMedicine() {
    if (numOfMeds >= capacity) {
        printf("Error: The maximum number of medicines have been added!\n");
        return;
    }

    Medicine* med = (Medicine*) malloc(sizeof(Medicine));
    med->id = numOfMeds + 1;

    printf("Enter Medicine Name: ");
    scanf("%s", med->name);

    printf("Enter Quantity: ");
    scanf("%d", &med->quantity);

    printf("Enter Price: ");
    scanf("%f", &med->price);

    printf("Enter Expiry Date (mm/dd/yyyy): ");
    scanf("%s", med->expDate);

    store[numOfMeds] = med;
    numOfMeds++;
    printf("Medicine added successfully!\n");
}

/* Remove Medicine Function */
void removeMedicine() {
    int id;
    printf("Enter Medicine ID: ");
    scanf("%d", &id);
    for (int i = 0; i < numOfMeds; i++) {
        if (store[i]->id == id) {
            free(store[i]);
            for (int j = i; j < numOfMeds - 1; j++) {
                store[j] = store[j+1];
            }
            numOfMeds--;
            printf("Medicine removed successfully!\n");
            return;
        }
    }
    printf("Medicine not found. Try again.\n");
}

/* Edit Medicine Function */
void editMedicine() {
    int id;
    printf("Enter Medicine ID: ");
    scanf("%d", &id);

    for (int i = 0; i < numOfMeds; i++) {
        if (store[i]->id == id) {
            Medicine* med = store[i];

            printf("Enter Medicine Name (%s): ", med->name);
            scanf("%s", med->name);

            printf("Enter Quantity (%d): ", med->quantity);
            scanf("%d", &med->quantity);

            printf("Enter Price (%.2f): ", med->price);
            scanf("%f", &med->price);

            printf("Enter Expiry Date (%s): ", med->expDate);
            scanf("%s", med->expDate);

            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found. Try again.\n");
}

/* Print Medicine Function */
void printMedicines() {
    if (numOfMeds == 0) {
        printf("No medicines in store.\n");
        return;
    }
    printf("ID\tMedicine Name\tQuantity\tPrice\tExpiry Date\n");
    for (int i = 0; i < numOfMeds; i++) {
        Medicine* med = store[i];
        printf("%d\t%s\t%d\t%.2f\t%s\n", med->id, med->name, med->quantity, med->price, med->expDate);
    }
}

/* Make Sale Function */
void makeSale() {
    if (numOfMeds == 0) {
        printf("No medicines in store. Cannot make a sale.\n");
        return;
    }

    Sale* sale = (Sale*) malloc(sizeof(Sale));
    sale->id = numOfSales + 1;
    sale->meds = (Medicine*) malloc(capacity * sizeof(Medicine));
    sale->quantity = (int*) malloc(capacity * sizeof(int));

    printf("Enter Name of Customer: ");
    scanf("%s", sale->name);

    printf("Enter Date and Time of Sale (mm/dd/yyyy hh:mm:ss): ");
    scanf("%s", sale->dateTime);

    while (1) {
        printMedicines();
        int id, qty;
        printf("\nEnter Medicine ID to add to cart (0 to stop): ");
        scanf("%d", &id);

        /* Break the loop and calculate total price if id is 0 */
        if (id == 0) {
            if (sale->numOfMeds == 0) {
                printf("Your cart is empty.\n");
                free(sale->meds);
                free(sale->quantity);
                free(sale);
                return;
            }
            break;
        }

        /* Get Medicine */
        Medicine* med = NULL;
        for (int i = 0; i < numOfMeds; i++) {
            if (store[i]->id == id) {
                med = store[i];
                break;
            }
        }

        /* Check if Medicine is found */
        if (med == NULL) {
            printf("Medicine not found. Try again.\n");
            continue;
        }

        /* Get Quantity */
        printf("Enter Quantity (Available: %d): ", med->quantity);
        scanf("%d", &qty);

        /* Check if Quantity is Available */
        if (qty > med->quantity || qty <= 0) {
            printf("Quantity requested is not available.\n");
            continue;
        }

        /* Add medicine to the sale */
        sale->meds[sale->numOfMeds] = *med;
        sale->quantity[sale->numOfMeds] = qty;
        sale->numOfMeds++;

        /* Update Quantity in store */
        med->quantity -= qty;

        /* Print success message */
        printf("%d x %s added to cart.\n", qty, med->name);
    }

    /* Get total price */
    for (int i = 0; i < sale->numOfMeds; i++) {
        sale->totalPrice += sale->meds[i].price * sale->quantity[i];
    }

    /* Add sale to sales list */
    numOfSales++;
    printf("Total Price: %.2f\n", sale->totalPrice);
    free(sale->meds);
    free(sale->quantity);
    free(sale);
    printf("Sale completed successfully!\n");
}