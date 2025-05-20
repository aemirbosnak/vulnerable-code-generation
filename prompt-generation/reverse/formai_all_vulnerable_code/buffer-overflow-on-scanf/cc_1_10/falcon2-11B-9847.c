//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine {
    char name[50];
    char description[100];
    int price;
};

struct Medicine medicines[] = {
    {"Paracetamol", "Pain reliever", 10},
    {"Aspirin", "Pain reliever", 12},
    {"Ibuprofen", "Pain reliever", 8},
    {"Tylenol", "Pain reliever", 15},
    {"Benadryl", "Antihistamine", 20}
};

struct Medicine* findMedicine(char* name) {
    int i;
    for (i = 0; i < sizeof(medicines) / sizeof(struct Medicine); i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            return &medicines[i];
        }
    }
    return NULL;
}

struct Medicine* addMedicine(char* name, char* description, int price) {
    struct Medicine* med = malloc(sizeof(struct Medicine));
    if (med == NULL) {
        return NULL;
    }
    strcpy(med->name, name);
    strcpy(med->description, description);
    med->price = price;
    int i;
    for (i = 0; i < sizeof(medicines) / sizeof(struct Medicine); i++) {
        if (strcmp(med->name, medicines[i].name) == 0) {
            return NULL; // Medicine already exists
        }
    }
    medicines[sizeof(medicines) / sizeof(struct Medicine)] = *med;
    return med;
}

void printMedicines() {
    int i;
    printf("Medicine list:\n");
    for (i = 0; i < sizeof(medicines) / sizeof(struct Medicine); i++) {
        printf("%s - %s - %d\n", medicines[i].name, medicines[i].description, medicines[i].price);
    }
}

int main() {
    char name[50];
    char description[100];
    int price;
    struct Medicine* med;
    int choice = 0;
    while (choice!= 5) {
        printf("1. Add Medicine\n2. Find Medicine\n3. Print Medcines\n4. Quit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Medicine Name: ");
                scanf("%s", name);
                printf("Enter Medicine Description: ");
                scanf("%s", description);
                printf("Enter Medicine Price: ");
                scanf("%d", &price);
                med = addMedicine(name, description, price);
                if (med == NULL) {
                    printf("Medicine already exists.\n");
                }
                break;
            case 2:
                printf("Enter Medicine Name: ");
                scanf("%s", name);
                med = findMedicine(name);
                if (med == NULL) {
                    printf("Medicine not found.\n");
                } else {
                    printf("Medicine: %s\n", med->name);
                    printf("Description: %s\n", med->description);
                    printf("Price: %d\n", med->price);
                }
                break;
            case 3:
                printMedicines();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}