//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures for the program
typedef struct {
    char name[50];
    char address[100];
    char contact[10];
    float price;
} Medicine;

typedef struct {
    Medicine *medicines;
    int num_medicines;
    float total_price;
} MedicineStore;

// Function prototypes
void addMedicine(MedicineStore *store, Medicine medicine);
void printMedicineStore(MedicineStore *store);

int main() {
    MedicineStore store = {NULL, 0, 0};

    // Add some medicines to the store
    addMedicine(&store, (Medicine) {"Paracetamol", "100 mg", "500 mg", 10.00});
    addMedicine(&store, (Medicine) {"Ibuprofen", "200 mg", "1000 mg", 20.00});
    addMedicine(&store, (Medicine) {"Panadol", "500 mg", "2000 mg", 30.00});

    // Print the medicine store
    printMedicineStore(&store);

    return 0;
}

// Function definitions
void addMedicine(MedicineStore *store, Medicine medicine) {
    store->medicines = realloc(store->medicines, (store->num_medicines + 1) * sizeof(Medicine));
    store->medicines[store->num_medicines] = medicine;
    store->num_medicines++;
    store->total_price += medicine.price;
}

void printMedicineStore(MedicineStore *store) {
    printf("Medicine Store\n");
    printf("--------------\n");
    printf("Total medicines: %d\n", store->num_medicines);
    printf("Total price: %.2f\n", store->total_price);
    for (int i = 0; i < store->num_medicines; i++) {
        printf("%s\n", store->medicines[i].name);
        printf("%s\n", store->medicines[i].address);
        printf("%s\n", store->medicines[i].contact);
        printf("%.2f\n", store->medicines[i].price);
        printf("\n");
    }
}