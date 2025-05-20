//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char manufacturer[50];
    char category[50];
    int quantity;
    float price;
} Medicine;

Medicine *medicines = NULL;
int num_medicines = 0;

void add_medicine() {
    Medicine *new_medicine = malloc(sizeof(Medicine));
    if (new_medicine == NULL) {
        printf("Error: Out of memory.\n");
        return;
    }

    printf("Enter the name of the medicine: ");
    scanf(" %s", new_medicine->name);

    printf("Enter the manufacturer of the medicine: ");
    scanf(" %s", new_medicine->manufacturer);

    printf("Enter the category of the medicine: ");
    scanf(" %s", new_medicine->category);

    printf("Enter the quantity of the medicine: ");
    scanf(" %d", &new_medicine->quantity);

    printf("Enter the price of the medicine: ");
    scanf(" %f", &new_medicine->price);

    medicines = realloc(medicines, (num_medicines + 1) * sizeof(Medicine));
    if (medicines == NULL) {
        printf("Error: Out of memory.\n");
        return;
    }

    medicines[num_medicines] = *new_medicine;
    num_medicines++;
}

void display_medicines() {
    if (num_medicines == 0) {
        printf("No medicines found.\n");
        return;
    }

    printf("%-5s %-20s %-20s %-20s %-10s %-10s\n", "ID", "Name", "Manufacturer", "Category", "Quantity", "Price");
    for (int i = 0; i < num_medicines; i++) {
        printf("%-5d %-20s %-20s %-20s %-10d %-10.2f\n", i + 1, medicines[i].name, medicines[i].manufacturer, medicines[i].category, medicines[i].quantity, medicines[i].price);
    }
}

void search_medicine() {
    char name[50];
    printf("Enter the name of the medicine to search for: ");
    scanf(" %s", name);

    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Medicine found:\n");
            printf("%-5s %-20s %-20s %-20s %-10s %-10s\n", "ID", "Name", "Manufacturer", "Category", "Quantity", "Price");
            printf("%-5d %-20s %-20s %-20s %-10d %-10.2f\n", i + 1, medicines[i].name, medicines[i].manufacturer, medicines[i].category, medicines[i].quantity, medicines[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found.\n");
    }
}

void update_medicine() {
    int id;
    printf("Enter the ID of the medicine to update: ");
    scanf(" %d", &id);

    if (id < 1 || id > num_medicines) {
        printf("Invalid ID.\n");
        return;
    }

    Medicine *medicine = &medicines[id - 1];

    printf("Enter the new name of the medicine: ");
    scanf(" %s", medicine->name);

    printf("Enter the new manufacturer of the medicine: ");
    scanf(" %s", medicine->manufacturer);

    printf("Enter the new category of the medicine: ");
    scanf(" %s", medicine->category);

    printf("Enter the new quantity of the medicine: ");
    scanf(" %d", &medicine->quantity);

    printf("Enter the new price of the medicine: ");
    scanf(" %f", &medicine->price);
}

void delete_medicine() {
    int id;
    printf("Enter the ID of the medicine to delete: ");
    scanf(" %d", &id);

    if (id < 1 || id > num_medicines) {
        printf("Invalid ID.\n");
        return;
    }

    for (int i = id - 1; i < num_medicines - 1; i++) {
        medicines[i] = medicines[i + 1];
    }

    num_medicines--;
    medicines = realloc(medicines, num_medicines * sizeof(Medicine));
}

void save_medicines() {
    FILE *fp = fopen("medicines.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    for (int i = 0; i < num_medicines; i++) {
        fprintf(fp, "%s\n", medicines[i].name);
        fprintf(fp, "%s\n", medicines[i].manufacturer);
        fprintf(fp, "%s\n", medicines[i].category);
        fprintf(fp, "%d\n", medicines[i].quantity);
        fprintf(fp, "%.2f\n", medicines[i].price);
    }

    fclose(fp);
}

void load_medicines() {
    FILE *fp = fopen("medicines.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        Medicine *new_medicine = malloc(sizeof(Medicine));
        if (new_medicine == NULL) {
            printf("Error: Out of memory.\n");
            return;
        }

        strcpy(new_medicine->name, line);
        fgets(line, sizeof(line), fp);
        strcpy(new_medicine->manufacturer, line);
        fgets(line, sizeof(line), fp);
        strcpy(new_medicine->category, line);
        fgets(line, sizeof(line), fp);
        new_medicine->quantity = atoi(line);
        fgets(line, sizeof(line), fp);
        new_medicine->price = atof(line);

        medicines = realloc(medicines, (num_medicines + 1) * sizeof(Medicine));
        if (medicines == NULL) {
            printf("Error: Out of memory.\n");
            return;
        }

        medicines[num_medicines] = *new_medicine;
        num_medicines++;
    }

    fclose(fp);
}

int main() {
    int choice;
    do {
        printf("\nMedical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Save Medicines\n");
        printf("7. Load Medicines\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                display_medicines();
                break;
            case 3:
                search_medicine();
                break;
            case 4:
                update_medicine();
                break;
            case 5:
                delete_medicine();
                break;
            case 6:
                save_medicines();
                break;
            case 7:
                load_medicines();
                break;
        }
    } while (choice != 8);

    return 0;
}