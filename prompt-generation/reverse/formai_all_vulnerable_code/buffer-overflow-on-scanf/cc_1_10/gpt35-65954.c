//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining the structure of the Medicine Information
typedef struct Medicine {
    char name[50];
    int batch_number;
    float price;
    int quantity;
    char expiry_date[15];
    char manufacturer[50];
} Medicine;

//Function to add Medicine to the Inventory
void addMedicine(Medicine *m, int n) {
    printf("Enter Medicine Information\n");
    for(int i=0;i<n;i++) {
        getchar(); //Clearing the input buffer
        printf("Enter Medicine Name: ");
        gets(m[i].name);
        printf("Enter Batch Number: ");
        scanf("%d", &m[i].batch_number);
        printf("Enter Medicine Price: ");
        scanf("%f", &m[i].price);
        printf("Enter Medicine Quantity: ");
        scanf("%d", &m[i].quantity);
        getchar(); //Clearing the input buffer
        printf("Enter Expiry Date(dd/mm/yyyy): ");
        gets(m[i].expiry_date);
        printf("Enter Manufacturer Name: ");
        gets(m[i].manufacturer);
    }
}

//Function to display all the Medicines in the Inventory
void displayMedicine(Medicine *m, int n) {
    printf("Medicine Information\n");
    for(int i=0;i<n;i++) {
        printf("Medicine Name: %s\n", m[i].name);
        printf("Batch Number: %d\n", m[i].batch_number);
        printf("Price: %.2f\n", m[i].price);
        printf("Quantity: %d\n", m[i].quantity);
        printf("Expiry Date: %s\n", m[i].expiry_date);
        printf("Manufacturer Name: %s\n\n", m[i].manufacturer);
    }
}

//Function to search a Medicine by Name, Batch Number or Manufacturer Name
void searchMedicine(Medicine *m, int n) {
    char keyword[50];
    int count = 0; //Counter Variable to keep track of number of Medicines found
    printf("Enter Medicine Name, Batch Number or Manufacturer Name to Search: ");
    getchar(); //Clearing the input buffer
    gets(keyword);
    for(int i=0;i<n;i++) {
        if(strstr(m[i].name, keyword) || strstr(m[i].manufacturer, keyword) || m[i].batch_number == atoi(keyword)) {
            printf("Medicine Name: %s\n", m[i].name);
            printf("Batch Number: %d\n", m[i].batch_number);
            printf("Price: %.2f\n", m[i].price);
            printf("Quantity: %d\n", m[i].quantity);
            printf("Expiry Date: %s\n", m[i].expiry_date);
            printf("Manufacturer Name: %s\n\n", m[i].manufacturer);
            count++;
        }
    }
    if(count == 0)
        printf("Medicine Not Found\n\n");
}

//Function to update the Quantity of a Medicine
void updateQuantity(Medicine *m, int n) {
    int batch_number, update_quantity, flag = 0;
    printf("Enter Batch Number of the Medicine: ");
    scanf("%d", &batch_number);
    for(int i=0;i<n;i++) {
        if(m[i].batch_number == batch_number) {
            printf("Enter Quantity to Update: ");
            scanf("%d", &update_quantity);
            m[i].quantity += update_quantity;
            printf("Updated Quantity: %d\n", m[i].quantity);
            flag = 1;
        }
    }
    if(flag == 0)
        printf("Medicine Not Found\n\n");
}

int main() {
    int choice, n;
    Medicine *m;
    printf("Enter Number of Medicines: ");
    scanf("%d", &n);
    m = (Medicine*) malloc(n * sizeof(Medicine)); //Dynamic Allocation of memory for Medicine Information
    while(1) {
        printf("\nMedical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Display All Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Quantity of a Medicine\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addMedicine(m, n);
                break;
            case 2:
                displayMedicine(m, n);
                break;
            case 3:
                searchMedicine(m, n);
                break;
            case 4:
                updateQuantity(m, n);
                break;
            case 5:
                printf("Thank You for using Medical Store Management System\n\n");
                exit(0);
            default:
                printf("Invalid Choice\n\n");
        }
    }
    return 0;
}