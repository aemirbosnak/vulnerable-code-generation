//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* structures */
struct medicine {
    char name[50];
    int quantity;
    float price;
};

struct customer {
    char name[50];
    int age;
};

struct sales {
    char date[11];
    char medicine_name[50];
    float price;
    int quantity;
    char customer_name[50];
};

/* function prototypes */
void menu();
int add_medicine();
void view_medicines();
int search_medicine(char[]);
void edit_medicine();
void delete_medicine();
void add_customer();
void view_customers();
int search_customer(char[]);
void edit_customer();
void delete_customer();
void add_sales();
void view_sales();

/* global variables */
struct medicine medicines[1000];
int medicine_count = 0;
struct customer customers[1000];
int customer_count = 0;
struct sales sales_record[1000];
int sales_count = 0;

/* main function */
int main() {
    printf("\nWelcome to Cyber Health Medical Store Management System!");
    menu();
    return 0;
}

/* function definitions */
void menu() {
    int choice;
    do {
        printf("\n\n1. Add medicine\n2. View medicines\n3. Search medicine\n4. Edit medicine\n5. Delete medicine\n");
        printf("6. Add customer\n7. View customers\n8. Search customer\n9. Edit customer\n10. Delete customer\n");
        printf("11. Add sales record\n12. View sales record\n13. Exit system\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                view_medicines();
                break;
            case 3: {
                char name[50];
                printf("Enter medicine name: ");
                scanf("%s", name);
                int index = search_medicine(name);
                if (index != -1) {
                    printf("\nMedicine is available");
                } else {
                    printf("\nMedicine not found");
                }
                break;
            }
            case 4:
                edit_medicine();
                break;
            case 5:
                delete_medicine();
                break;
            case 6:
                add_customer();
                break;
            case 7:
                view_customers();
                break;
            case 8: {
                char name[50];
                printf("Enter customer name: ");
                scanf("%s", name);
                int index = search_customer(name);
                if (index != -1) {
                    printf("\nCustomer is available");
                } else {
                    printf("\nCustomer not found");
                }
                break;
            }
            case 9:
                edit_customer();
                break;
            case 10:
                delete_customer();
                break;
            case 11:
                add_sales();
                break;
            case 12:
                view_sales();
                break;
            case 13:
                printf("\nThank you for using Cyber Health Medical Store Management System!");
                break;
            default:
                printf("\nInvalid choice");
                break;
        }
    } while (choice != 13);
}

int add_medicine() {
    char name[50];
    int quantity;
    float price;
    printf("\nEnter medicine name: ");
    scanf("%s", name);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    printf("Enter price: ");
    scanf("%f", &price);
    strcpy(medicines[medicine_count].name, name);
    medicines[medicine_count].quantity = quantity;
    medicines[medicine_count].price = price;
    medicine_count++;
    printf("\nMedicine added successfully");
}

void view_medicines() {
    for (int i = 0; i < medicine_count; i++) {
        printf("\nMedicine name: %s", medicines[i].name);
        printf("\nQuantity available: %d", medicines[i].quantity);
        printf("\nPrice per unit: %.2f", medicines[i].price);
        printf("\n");
    }
}

int search_medicine(char name[]) {
    for (int i = 0; i < medicine_count; i++) {
        if (strcmp(name, medicines[i].name) == 0) {
            printf("\nMedicine name: %s", medicines[i].name);
            printf("\nQuantity available: %d", medicines[i].quantity);
            printf("\nPrice per unit: %.2f", medicines[i].price);
            return i;
        }
    }
    return -1;
}

void edit_medicine() {
    char name[50];
    int quantity, index;
    float price;
    printf("\nEnter medicine name: ");
    scanf("%s", name);
    index = search_medicine(name);
    if (index == -1) {
        printf("\nMedicine not found");
    } else {
        printf("\nEnter new quantity: ");
        scanf("%d", &quantity);
        printf("Enter new price: ");
        scanf("%f", &price);
        medicines[index].quantity = quantity;
        medicines[index].price = price;
        printf("\nMedicine details updated successfully");
    }
}

void delete_medicine() {
    char name[50];
    int index;
    printf("\nEnter medicine name: ");
    scanf("%s", name);
    index = search_medicine(name);
    if (index == -1) {
        printf("\nMedicine not found");
    } else {
        for (int i = index; i < medicine_count-1; i++) {
            strcpy(medicines[i].name, medicines[i+1].name);
            medicines[i].quantity = medicines[i+1].quantity;
            medicines[i].price = medicines[i+1].price;
        }
        medicine_count--;
        printf("\nMedicine deleted successfully");
    }
}

void add_customer() {
    char name[50];
    int age;
    printf("\nEnter customer name: ");
    scanf("%s", name);
    printf("Enter customer age: ");
    scanf("%d", &age);
    strcpy(customers[customer_count].name, name);
    customers[customer_count].age = age;
    customer_count++;
    printf("\nCustomer added successfully");
}

void view_customers() {
    for (int i = 0; i < customer_count; i++) {
        printf("\nCustomer name: %s", customers[i].name);
        printf("\nCustomer age: %d", customers[i].age);
        printf("\n");
    }
}

int search_customer(char name[]) {
    for (int i = 0; i < customer_count; i++) {
        if (strcmp(name, customers[i].name) == 0) {
            printf("\nCustomer name: %s", customers[i].name);
            printf("\nCustomer age: %d", customers[i].age);
            return i;
        }
    }
    return -1;
}

void edit_customer() {
    char name[50];
    int age, index;
    printf("\nEnter customer name: ");
    scanf("%s", name);
    index = search_customer(name);
    if (index == -1) {
        printf("\nCustomer not found");
    } else {
        printf("\nEnter new age: ");
        scanf("%d", &age);
        customers[index].age = age;
        printf("\nCustomer details updated successfully");
    }
}

void delete_customer() {
    char name[50];
    int index;
    printf("\nEnter customer name: ");
    scanf("%s", name);
    index = search_customer(name);
    if (index == -1) {
        printf("\nCustomer not found");
    } else {
        for (int i = index; i < customer_count-1; i++) {
            strcpy(customers[i].name, customers[i+1].name);
            customers[i].age = customers[i+1].age;
        }
        customer_count--;
        printf("\nCustomer deleted successfully");
    }
}

void add_sales() {
    char date[11], medicine_name[50], customer_name[50];
    int quantity, index1, index2;
    float price;
    printf("\nEnter date (dd/mm/yyyy): ");
    scanf("%s", date);
    printf("Enter medicine name: ");
    scanf("%s", medicine_name);
    index1 = search_medicine(medicine_name);
    if (index1 == -1) {
        printf("\nMedicine not available");
        return;
    }
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    if (medicines[index1].quantity < quantity) {
        printf("\nQuantity not available");
        return;
    }
    printf("Enter customer name: ");
    scanf("%s", customer_name);
    index2 = search_customer(customer_name);
    if (index2 == -1) {
        printf("\nCustomer not found");
        return;
    }
    price = medicines[index1].price * quantity;
    strcpy(sales_record[sales_count].date, date);
    strcpy(sales_record[sales_count].medicine_name, medicine_name);
    sales_record[sales_count].quantity = quantity;
    sales_record[sales_count].price = price;
    strcpy(sales_record[sales_count].customer_name, customer_name);
    medicines[index1].quantity -= quantity;
    sales_count++;
    printf("\nSales record added successfully");
}

void view_sales() {
    for (int i = 0; i < sales_count; i++) {
        printf("\nDate: %s", sales_record[i].date);
        printf("\nMedicine name: %s", sales_record[i].medicine_name);
        printf("\nQuantity sold: %d", sales_record[i].quantity);
        printf("\nPrice: %.2f", sales_record[i].price);
        printf("\nCustomer name: %s", sales_record[i].customer_name);
        printf("\n");
    }
}