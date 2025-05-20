//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int medicine_id;
    char medicine_name[50];
    int expiry_date;
    int stock_count;
} Medicine;

void addMedicine(Medicine *medicines, int *medicine_count) {
    printf("Enter medicine id: ");
    scanf("%d", &medicines[*medicine_count].medicine_id);
    printf("Enter medicine name: ");
    scanf("%s", medicines[*medicine_count].medicine_name);
    printf("Enter expiry date (format: YYYYMMDD): ");
    scanf("%d", &medicines[*medicine_count].expiry_date);
    printf("Enter stock count: ");
    scanf("%d", &medicines[*medicine_count].stock_count);
    *medicine_count += 1;
}

void displayMedicines(Medicine *medicines, int medicine_count) {
    printf("Medicine ID\tMedicine Name\tExpiry Date\tStock Count\n");
    for (int i = 0; i < medicine_count; i++) {
        printf("%d\t\t%s\t\t%d\t\t%d\n", medicines[i].medicine_id, medicines[i].medicine_name, medicines[i].expiry_date, medicines[i].stock_count);
    }
}

void searchMedicine(Medicine *medicines, int medicine_count, int medicine_id) {
    int found = 0;
    for (int i = 0; i < medicine_count; i++) {
        if (medicines[i].medicine_id == medicine_id) {
            printf("Medicine ID\tMedicine Name\tExpiry Date\tStock Count\n");
            printf("%d\t\t%s\t\t%d\t\t%d\n", medicines[i].medicine_id, medicines[i].medicine_name, medicines[i].expiry_date, medicines[i].stock_count);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine with ID %d not found.\n", medicine_id);
    }
}

void updateStock(Medicine *medicines, int medicine_count, int medicine_id) {
    int found = 0;
    for (int i = 0; i < medicine_count; i++) {
        if (medicines[i].medicine_id == medicine_id) {
            printf("Enter new stock count: ");
            scanf("%d", &medicines[i].stock_count);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine with ID %d not found.\n", medicine_id);
    }
}

int main() {
    Medicine medicines[100];
    int medicine_count = 0;
    int choice = 0;
    int medicine_id = 0;
    while (1) {
        printf("\n1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Stock\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMedicine(medicines, &medicine_count);
                break;
            case 2:
                displayMedicines(medicines, medicine_count);
                break;
            case 3:
                printf("Enter medicine id to search: ");
                scanf("%d", &medicine_id);
                searchMedicine(medicines, medicine_count, medicine_id);
                break;
            case 4:
                printf("Enter medicine id to update stock: ");
                scanf("%d", &medicine_id);
                updateStock(medicines, medicine_count, medicine_id);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}