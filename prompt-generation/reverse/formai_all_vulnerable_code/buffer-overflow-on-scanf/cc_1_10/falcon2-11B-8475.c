//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: complex
#include <stdio.h>
#include <string.h>

typedef struct Patient {
    char name[50];
    int age;
    char address[100];
    char phone[20];
} Patient;

typedef struct Medicine {
    char name[50];
    float price;
} Medicine;

typedef struct MedicalStore {
    int id;
    Patient patient;
    Medicine medicine;
} MedicalStore;

int main() {
    MedicalStore store[10];
    
    for(int i=0; i<10; i++) {
        store[i].id = i;
        printf("Enter patient name: ");
        scanf("%s", store[i].patient.name);
        printf("Enter patient age: ");
        scanf("%d", &store[i].patient.age);
        printf("Enter patient address: ");
        scanf("%s", store[i].patient.address);
        printf("Enter patient phone: ");
        scanf("%s", store[i].patient.phone);
        printf("Enter medicine name: ");
        scanf("%s", store[i].medicine.name);
        printf("Enter medicine price: ");
        scanf("%f", &store[i].medicine.price);
    }
    
    for(int i=0; i<10; i++) {
        printf("Patient ID: %d\n", store[i].id);
        printf("Patient Name: %s\n", store[i].patient.name);
        printf("Patient Age: %d\n", store[i].patient.age);
        printf("Patient Address: %s\n", store[i].patient.address);
        printf("Patient Phone: %s\n", store[i].patient.phone);
        printf("Medicine Name: %s\n", store[i].medicine.name);
        printf("Medicine Price: %f\n", store[i].medicine.price);
    }
    
    return 0;
}