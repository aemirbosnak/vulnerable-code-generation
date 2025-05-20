//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MAX_CUSTOMERS 10

void clearScreen(){
    printf("\033[H\033[J");
}

void printMemoryUsage(){
    struct sysinfo info;
    if (sysinfo(&info) != 0) {
        perror("sysinfo");
        return;
    }

    unsigned long totalRAM = info.totalram;
    unsigned long freeRAM = info.freeram;
    unsigned long usedRAM = totalRAM - freeRAM;

    printf("🔍 Memory Usage Monitor 🔍\n");
    printf("Total RAM: %lu bytes\n", totalRAM);
    printf("Free RAM: %lu bytes\n", freeRAM);
    printf("Used RAM: %lu bytes\n", usedRAM);
}

void listCustomers(char customers[MAX_CUSTOMERS][30], int count){
    printf("\n--- Customers List ---\n");
    for(int i = 0; i < count; i++){
        printf("%d. %s\n", i + 1, customers[i]);
    }
}

void addCustomer(char customers[MAX_CUSTOMERS][30], int *count){
    if (*count >= MAX_CUSTOMERS) {
        printf("🚫 Customer list is full!\n");
        return;
    }
    printf("Enter customer name: ");
    fgets(customers[*count], sizeof(customers[*count]), stdin);
    customers[*count][strcspn(customers[*count], "\n")] = 0; // Remove newline
    (*count)++;
    printf("✅ Customer added!\n");
}

void deleteCustomer(char customers[MAX_CUSTOMERS][30], int *count){
    if (*count == 0) {
        printf("🚫 No customers to delete!\n");
        return;
    }
    listCustomers(customers, *count);
    printf("Select customer number to delete: ");
    
    int numToDelete;
    scanf("%d", &numToDelete);
    getchar(); // Consume newline

    if (numToDelete < 1 || numToDelete > *count) {
        printf("🚫 Invalid customer number!\n");
        return;
    }

    for (int i = numToDelete - 1; i < *count - 1; i++) {
        strcpy(customers[i], customers[i + 1]);
    }
    (*count)--;
    printf("✅ Customer deleted!\n");
}

void showMenu(char customers[MAX_CUSTOMERS][30], int *count){
    while (1) {
        clearScreen();
        printMemoryUsage();

        printf("\n--- Menu ---\n");
        printf("1. Add Customer\n");
        printf("2. Delete Customer\n");
        printf("3. List Customers\n");
        printf("4. Exit\n");
        printf("Choose an option: ");

        int choice;
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                addCustomer(customers, count);
                break;
            case 2:
                deleteCustomer(customers, count);
                break;
            case 3:
                listCustomers(customers, *count);
                break;
            case 4:
                printf("🧳 Exiting the monitor. Have a great day!\n");
                return;
            default:
                printf("🚫 Invalid choice! Please try again.\n");
        }
        sleep(2); // Pause to allow user to read messages
    }
}

int main() {
    char customers[MAX_CUSTOMERS][30];
    int customerCount = 0;

    printf("🤖 Welcome to the Customer Memory Usage Monitor!\n");
    showMenu(customers, &customerCount);

    return 0;
}