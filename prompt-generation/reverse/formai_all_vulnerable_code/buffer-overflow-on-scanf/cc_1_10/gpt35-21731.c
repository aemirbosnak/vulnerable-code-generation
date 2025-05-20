//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct inventory {
    char med_name[100];
    float price;
    int quantity;
};

struct inventory med_list[100];

int num_of_meds = 0;

void add_med() {
    printf("Enter name of the medicine: ");
    scanf("%s", med_list[num_of_meds].med_name);
    printf("Enter price of the medicine: ");
    scanf("%f", &med_list[num_of_meds].price);
    printf("Enter quantity of the medicine: ");
    scanf("%d", &med_list[num_of_meds].quantity);
    num_of_meds++;
    printf("Medicine added successfully!\n\n");
}

void display_meds() {
    if (num_of_meds == 0) {
        printf("No medicines in inventory!\n\n");
        return;
    }
    printf("List of medicines:\n");
    printf("----------------------------------------------------\n");
    printf("%-5s  %-20s  %-10s  %-10s\n", "S.No", "Medicine Name", "Price", "Quantity");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < num_of_meds; i++) {
        printf("%-5d  %-20s  %-10.2f  %-10d\n", i+1, med_list[i].med_name, med_list[i].price, med_list[i].quantity);
    }
    printf("----------------------------------------------------\n\n");
}

void search_med(char med_name[]) {
    int search_result = -1;
    for (int i = 0; i < num_of_meds; i++) {
        if (strcmp(med_list[i].med_name, med_name) == 0) {
            search_result = i;
            break;
        }
    }
    if (search_result == -1) {
        printf("Medicine not found in inventory!\n\n");
        return;
    }
    printf("Details of the medicine:\n");
    printf("----------------------------------------------------\n");
    printf("%-20s  %-10s  %-10s\n", "Medicine Name", "Price", "Quantity");
    printf("----------------------------------------------------\n");
    printf("%-20s  %-10.2f  %-10d\n", med_list[search_result].med_name, med_list[search_result].price, med_list[search_result].quantity);
    printf("----------------------------------------------------\n\n");
}

void buy_med(char med_name[], int count) {
    int buy_result = -1;
    for (int i = 0; i < num_of_meds; i++) {
        if (strcmp(med_list[i].med_name, med_name) == 0) {
            if (med_list[i].quantity >= count) {
                med_list[i].quantity -= count;
                buy_result = 1;
            }
            break;
        }
    }
    if (buy_result == -1) {
        printf("Medicine not found in inventory!\n\n");
        return;
    }
    printf("Medicine bought successfully!\n\n");
}

int main() {
    while (1) {
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Buy Medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_med();
                break;
            case 2:
                display_meds();
                break;
            case 3:
                printf("Enter name of the medicine: ");
                char search_med_name[100];
                scanf("%s", search_med_name);
                search_med(search_med_name);
                break;
            case 4:
                printf("Enter name of the medicine to buy: ");
                char buy_med_name[100];
                scanf("%s", buy_med_name);
                printf("Enter quantity to buy: ");
                int buy_count;
                scanf("%d", &buy_count);
                buy_med(buy_med_name, buy_count);
                break;
            case 5:
                printf("Thank you for using our system!\n");
                exit(0);
            default:
                printf("Invalid Choice!\n\n");
                break;
        }
    }
    return 0;
}