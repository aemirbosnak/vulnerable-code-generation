//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Medicine;

// function prototypes
void displayMenu();
void addMedicine();
void deleteMedicine();
void updateMedicine();
void searchMedicine();
void displayMedicine();
void saveToFile();
void loadFromFile();
int generateId();

Medicine medList[100];
int count = 0;

void displayMenu() {
    printf("1. Add Medicine\n");
    printf("2. Delete Medicine\n");
    printf("3. Update Medicine\n");
    printf("4. Search Medicine\n");
    printf("5. Display Medicines\n");
    printf("6. Save to File\n");
    printf("7. Load from File\n");
    printf("8. Quit\n");
}

void addMedicine() {
    printf("Enter medicine name: ");
    scanf("%49s", &medList[count].name);
    printf("Enter price: ");
    scanf("%f", &medList[count].price);
    printf("Enter quantity: ");
    scanf("%d", &medList[count].quantity);
    medList[count].id = generateId();
    printf("Medicine added successfully with ID %d\n", medList[count].id);
    count++;
}

void deleteMedicine() {
    int id;
    printf("Enter medicine ID to delete: ");
    scanf("%d", &id);
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (medList[i].id == id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < count - 1; i++) {
            medList[i] = medList[i + 1];
        }
        count--;
        printf("Medicine with ID %d deleted successfully\n", id);
    } else {
        printf("Medicine with ID %d not found\n", id);
    }
}

void updateMedicine() {
    int id;
    printf("Enter medicine ID to update: ");
    scanf("%d", &id);
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (medList[i].id == id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        printf("Enter new medicine name: ");
        scanf("%49s", &medList[index].name);
        printf("Enter new price: ");
        scanf("%f", &medList[index].price);
        printf("Enter new quantity: ");
        scanf("%d", &medList[index].quantity);
        printf("Medicine with ID %d updated successfully\n", id);
    } else {
        printf("Medicine with ID %d not found\n", id);
    }
}

void searchMedicine() {
    char keyword[50];
    printf("Enter search keyword: ");
    scanf("%49s", &keyword);
    printf("Search Results:\n");
    for (int i = 0; i < count; i++) {
        if (strstr(medList[i].name, keyword) != NULL) {
            printf("ID: %d\n", medList[i].id);
            printf("Name: %s\n", medList[i].name);
            printf("Price: %.2f\n", medList[i].price);
            printf("Quantity: %d\n", medList[i].quantity);
        }
    }
}

void displayMedicine() {
    printf("Medicine List:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", medList[i].id);
        printf("Name: %s\n", medList[i].name);
        printf("Price: %.2f\n", medList[i].price);
        printf("Quantity: %d\n", medList[i].quantity);
        printf("----------------------\n");
    }
}

void saveToFile() {
    FILE *fp;
    fp = fopen("medicines.txt", "w");
    if (fp != NULL) {
        for (int i = 0; i < count; i++) {
            fprintf(fp, "%d|%s|%.2f|%d\n", medList[i].id, medList[i].name, medList[i].price, medList[i].quantity);
        }
        fclose(fp);
        printf("Medicines saved to file successfully\n");
    } else {
        printf("Error: could not create file\n");
    }
}

void loadFromFile() {
    FILE *fp;
    fp = fopen("medicines.txt", "r");
    if (fp != NULL) {
        char buffer[100];
        count = 0;
        while (fgets(buffer, 100, fp) != NULL) {
            char *id, *name, *price, *quantity;
            id = strtok(buffer, "|");
            name = strtok(NULL, "|");
            price = strtok(NULL, "|");
            quantity = strtok(NULL, "\n");
            medList[count].id = atoi(id);
            strcpy(medList[count].name, name);
            medList[count].price = atof(price);
            medList[count].quantity = atoi(quantity);
            count++;
        }
        fclose(fp);
        printf("Medicines loaded from file successfully\n");
    } else {
        printf("Error: could not open file\n");
    }
}

int generateId() {
    if (count == 0) {
        return 1;
    } else {
        return medList[count - 1].id + 1;
    }
}

int main() {

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                deleteMedicine();
                break;
            case 3:
                updateMedicine();
                break;
            case 4:
                searchMedicine();
                break;
            case 5:
                displayMedicine();
                break;
            case 6:
                saveToFile();
                break;
            case 7:
                loadFromFile();
                break;
            case 8:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 8);

    return 0;
}