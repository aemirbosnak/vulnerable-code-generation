//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENT 100
#define MAX_MEDICINE 100

typedef struct {
    char name[20];
    int age;
    int disease;
} Patient;

typedef struct {
    char name[20];
    char manufacturer[20];
    char expiry_date[20];
    char dosage[20];
} Medicine;

Patient patients[MAX_PATIENT];
int num_patients = 0;

Medicine medicines[MAX_MEDICINE];
int num_medicines = 0;

int main() {
    // Initialize the system
    for (int i = 0; i < MAX_PATIENT; i++) {
        patients[i].name[0] = '\0';
        patients[i].age = 0;
        patients[i].disease = 0;
    }

    for (int i = 0; i < MAX_MEDICINE; i++) {
        medicines[i].name[0] = '\0';
        medicines[i].manufacturer[0] = '\0';
        medicines[i].expiry_date[0] = '\0';
        medicines[i].dosage[0] = '\0';
    }

    // Add patients to the system
    for (int i = 0; i < 10; i++) {
        printf("Enter patient details: ");
        scanf("%s %d %d", patients[i].name, &patients[i].age, &patients[i].disease);
        num_patients++;
    }

    // Add medicines to the system
    for (int i = 0; i < 10; i++) {
        printf("Enter medicine details: ");
        scanf("%s %s %s %s", medicines[i].name, medicines[i].manufacturer, medicines[i].expiry_date, medicines[i].dosage);
        num_medicines++;
    }

    // Display the system information
    printf("Patients: ");
    for (int i = 0; i < num_patients; i++) {
        printf("%s (%d) (%d)\n", patients[i].name, patients[i].age, patients[i].disease);
    }

    printf("Medicines: ");
    for (int i = 0; i < num_medicines; i++) {
        printf("%s (%s) (%s) (%s)\n", medicines[i].name, medicines[i].manufacturer, medicines[i].expiry_date, medicines[i].dosage);
    }

    return 0;
}