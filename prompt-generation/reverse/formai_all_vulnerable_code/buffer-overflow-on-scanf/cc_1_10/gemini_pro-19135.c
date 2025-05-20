//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store patient information
typedef struct Patient {
    char name[50];
    int age;
    char address[100];
    char phone[20];
    char email[50];
} Patient;

// Structure to store medicine information
typedef struct Medicine {
    char name[50];
    int quantity;
    float price;
    char expiry_date[20];
} Medicine;

// Structure to store sales information
typedef struct Sale {
    int invoice_number;
    char date[20];
    char patient_name[50];
    char medicine_name[50];
    int quantity;
    float total_amount;
} Sale;

// Function to add a new patient
void add_patient(Patient *patients, int *num_patients) {
    printf("Enter patient name: ");
    scanf(" %s", patients[*num_patients].name);

    printf("Enter patient age: ");
    scanf(" %d", &patients[*num_patients].age);

    printf("Enter patient address: ");
    scanf(" %s", patients[*num_patients].address);

    printf("Enter patient phone number: ");
    scanf(" %s", patients[*num_patients].phone);

    printf("Enter patient email address: ");
    scanf(" %s", patients[*num_patients].email);

    (*num_patients)++;
}

// Function to add a new medicine
void add_medicine(Medicine *medicines, int *num_medicines) {
    printf("Enter medicine name: ");
    scanf(" %s", medicines[*num_medicines].name);

    printf("Enter medicine quantity: ");
    scanf(" %d", &medicines[*num_medicines].quantity);

    printf("Enter medicine price: ");
    scanf(" %f", &medicines[*num_medicines].price);

    printf("Enter medicine expiry date: ");
    scanf(" %s", medicines[*num_medicines].expiry_date);

    (*num_medicines)++;
}

// Function to make a sale
void make_sale(Patient *patients, int num_patients, Medicine *medicines, int num_medicines, Sale *sales, int *num_sales) {
    char patient_name[50];
    char medicine_name[50];
    int quantity;

    printf("Enter patient name: ");
    scanf(" %s", patient_name);

    printf("Enter medicine name: ");
    scanf(" %s", medicine_name);

    printf("Enter quantity: ");
    scanf(" %d", &quantity);

    // Find the patient
    int patient_index = -1;
    for (int i = 0; i < num_patients; i++) {
        if (strcmp(patients[i].name, patient_name) == 0) {
            patient_index = i;
            break;
        }
    }

    // Find the medicine
    int medicine_index = -1;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, medicine_name) == 0) {
            medicine_index = i;
            break;
        }
    }

    // Check if the patient and medicine exist
    if (patient_index == -1) {
        printf("Patient not found!\n");
        return;
    }
    if (medicine_index == -1) {
        printf("Medicine not found!\n");
        return;
    }

    // Check if the medicine has enough quantity
    if (medicines[medicine_index].quantity < quantity) {
        printf("Not enough medicine in stock!\n");
        return;
    }

    // Calculate the total amount
    float total_amount = medicines[medicine_index].price * quantity;

    // Add the sale to the sales array
    sales[*num_sales].invoice_number = *num_sales + 1;
    strcpy(sales[*num_sales].date, "2023-03-08");
    strcpy(sales[*num_sales].patient_name, patient_name);
    strcpy(sales[*num_sales].medicine_name, medicine_name);
    sales[*num_sales].quantity = quantity;
    sales[*num_sales].total_amount = total_amount;

    (*num_sales)++;

    // Deduct the quantity from the medicine stock
    medicines[medicine_index].quantity -= quantity;

    printf("Sale made successfully!\n");
}

// Function to print the list of patients
void print_patients(Patient *patients, int num_patients) {
    printf("List of patients:\n");
    for (int i = 0; i < num_patients; i++) {
        printf("%d. %s\n", i + 1, patients[i].name);
    }
}

// Function to print the list of medicines
void print_medicines(Medicine *medicines, int num_medicines) {
    printf("List of medicines:\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("%d. %s\n", i + 1, medicines[i].name);
    }
}

// Function to print the list of sales
void print_sales(Sale *sales, int num_sales) {
    printf("List of sales:\n");
    for (int i = 0; i < num_sales; i++) {
        printf("%d. %s %s %d %f\n", sales[i].invoice_number, sales[i].patient_name, sales[i].medicine_name, sales[i].quantity, sales[i].total_amount);
    }
}

// Main function
int main() {
    // Create arrays to store patients, medicines, and sales
    Patient patients[100];
    Medicine medicines[100];
    Sale sales[100];

    // Initialize the number of patients, medicines, and sales to 0
    int num_patients = 0;
    int num_medicines = 0;
    int num_sales = 0;

    // Add some sample patients
    add_patient(patients, &num_patients);
    add_patient(patients, &num_patients);
    add_patient(patients, &num_patients);

    // Add some sample medicines
    add_medicine(medicines, &num_medicines);
    add_medicine(medicines, &num_medicines);
    add_medicine(medicines, &num_medicines);

    // Make some sample sales
    make_sale(patients, num_patients, medicines, num_medicines, sales, &num_sales);
    make_sale(patients, num_patients, medicines, num_medicines, sales, &num_sales);
    make_sale(patients, num_patients, medicines, num_medicines, sales, &num_sales);

    // Print the list of patients
    print_patients(patients, num_patients);

    // Print the list of medicines
    print_medicines(medicines, num_medicines);

    // Print the list of sales
    print_sales(sales, num_sales);

    return 0;
}