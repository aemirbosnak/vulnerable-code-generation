//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: shape shifting
#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float price;
} Medicine;

void menu() {
    printf("Welcome to the Medical Store Management System!\n");
    printf("1. Add medicine\n");
    printf("2. View all medicines\n");
    printf("3. Search medicine\n");
    printf("4. Update medicine\n");
    printf("5. Delete medicine\n");
    printf("6. Exit\n");
}

void addMedicine(Medicine *medicines, int *count) {
    printf("Enter medicine details:\n");
    printf("ID: ");
    scanf("%d", &medicines[*count].id);
    printf("Name: ");
    scanf("%s", medicines[*count].name);
    printf("Price: ");
    scanf("%f", &medicines[*count].price);
    (*count)++;
}

void viewMedicines(Medicine *medicines, int count) {
    printf("All medicines:\n");
    for (int i = 0; i < count; ++i) {
        printf("ID: %d\n", medicines[i].id);
        printf("Name: %s\n", medicines[i].name);
        printf("Price: %.2f\n", medicines[i].price);
    }
}

void searchMedicine(Medicine *medicines, int count) {
    int id, found = 0;
    printf("Enter medicine ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; ++i) {
        if (medicines[i].id == id) {
            printf("Medicine found:\n");
            printf("Name: %s\n", medicines[i].name);
            printf("Price: %.2f\n", medicines[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

void updateMedicine(Medicine *medicines, int count) {
    int id, found = 0;
    printf("Enter medicine ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < count; ++i) {
        if (medicines[i].id == id) {
            printf("Enter updated details:\n");
            printf("Name: ");
            scanf("%s", medicines[i].name);
            printf("Price: ");
            scanf("%f", &medicines[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

void deleteMedicine(Medicine *medicines, int *count) {
    int id, found = 0;
    printf("Enter medicine ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < *count; ++i) {
        if (medicines[i].id == id) {
            for (int j = i; j < *count - 1; ++j) {
                medicines[j] = medicines[j+1];
            }
            (*count)--;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    } else {
        printf("Medicine deleted!\n");
    }
}

int main() {
    Medicine medicines[100];
    int choice, count = 0;
    do {
        menu();
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMedicine(medicines, &count);
                break;
            case 2:
                viewMedicines(medicines, count);
                break;
            case 3:
                searchMedicine(medicines, count);
                break;
            case 4:
                updateMedicine(medicines, count);
                break;
            case 5:
                deleteMedicine(medicines, &count);
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 6);
    return 0;
}