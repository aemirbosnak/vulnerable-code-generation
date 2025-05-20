//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct patient {
    char name[50];
    int age;
    char gender;
    char disease[50];
    char medication[50];
    int appointment_time;
};

struct inventory {
    char name[50];
    int quantity;
    float price;
};

struct sales {
    char name[50];
    int quantity;
    float total;
};

int main() {
    struct patient patients[100];
    struct inventory inventory[100];
    struct sales sales[100];

    int num_patients = 0;
    int num_inventory = 0;
    int num_sales = 0;

    printf("Welcome to the Medical Store Management System!\n");

    while (1) {
        printf("Enter command: ");
        char command[50];
        scanf("%s", command);

        if (strcmp(command, "add-patient") == 0) {
            printf("Enter patient name: ");
            scanf("%s", patients[num_patients].name);
            printf("Enter patient age: ");
            scanf("%d", &patients[num_patients].age);
            printf("Enter patient gender: ");
            scanf("%c", &patients[num_patients].gender);
            printf("Enter patient disease: ");
            scanf("%s", patients[num_patients].disease);
            printf("Enter patient medication: ");
            scanf("%s", patients[num_patients].medication);
            printf("Enter patient appointment time: ");
            scanf("%d", &patients[num_patients].appointment_time);
            num_patients++;
        } else if (strcmp(command, "add-inventory") == 0) {
            printf("Enter inventory name: ");
            scanf("%s", inventory[num_inventory].name);
            printf("Enter inventory quantity: ");
            scanf("%d", &inventory[num_inventory].quantity);
            printf("Enter inventory price: ");
            scanf("%f", &inventory[num_inventory].price);
            num_inventory++;
        } else if (strcmp(command, "add-sale") == 0) {
            printf("Enter sale name: ");
            scanf("%s", sales[num_sales].name);
            printf("Enter sale quantity: ");
            scanf("%d", &sales[num_sales].quantity);
            printf("Enter sale total: ");
            scanf("%f", &sales[num_sales].total);
            num_sales++;
        } else if (strcmp(command, "list-patients") == 0) {
            for (int i = 0; i < num_patients; i++) {
                printf("%s\n", patients[i].name);
            }
        } else if (strcmp(command, "list-inventory") == 0) {
            for (int i = 0; i < num_inventory; i++) {
                printf("%s\n", inventory[i].name);
            }
        } else if (strcmp(command, "list-sales") == 0) {
            for (int i = 0; i < num_sales; i++) {
                printf("%s\n", sales[i].name);
            }
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}