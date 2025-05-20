//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50
#define USERNAME_LENGTH 20
#define PASSWORD_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    float price;
    int quantity;
} Medicine;

typedef struct {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
} User;

Medicine medicines[MAX_MEDICINES];
int medicine_count = 0;

User users[10];
int user_count = 0;

// Function Declarations
void addMedicine();
void displayMedicines();
void userLogin();
int authenticateUser(char *username, char *password);
void userMenu();

int main() {
    // Predefined users for demonstration - username: admin, password: admin123
    strcpy(users[user_count].username, "admin");
    strcpy(users[user_count++].password, "admin123");

    // Start the program
    userLogin();
    return 0;
}

void userLogin() {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];

    printf("Welcome to the Medical Store Management System\n");
    
    printf("Enter Username: ");
    scanf("%s", username);
    
    printf("Enter Password: ");
    scanf("%s", password);
    
    if (authenticateUser(username, password)) {
        userMenu();
    } else {
        printf("Invalid username or password. Exiting...\n");
        exit(EXIT_FAILURE);
    }
}

int authenticateUser(char *username, char *password) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

void userMenu() {
    int choice;
    do {
        printf("\n1. Add Medicine\n2. Display Medicines\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                displayMedicines();
                break;
            case 3:
                printf("Exiting... Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
}

void addMedicine() {
    if (medicine_count >= MAX_MEDICINES) {
        printf("Inventory is full! Cannot add more medicines.\n");
        return;
    }
    Medicine m;
    printf("Enter Medicine Name: ");
    scanf("%s", m.name);
    
    printf("Enter Medicine Price: ");
    scanf("%f", &m.price);
    
    printf("Enter Medicine Quantity: ");
    scanf("%d", &m.quantity);
    
    medicines[medicine_count++] = m;
    printf("Medicine added successfully!\n");
}

void displayMedicines() {
    if (medicine_count == 0) {
        printf("No medicines available in the inventory.\n");
        return;
    }

    printf("Medicine Inventory:\n");
    printf("%-25s %-10s %-10s\n", "Name", "Price", "Quantity");
    for (int i = 0; i < medicine_count; i++) {
        printf("%-25s %-10.2f %-10d\n", medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
}