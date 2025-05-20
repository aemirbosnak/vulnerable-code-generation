//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINE_COUNT 1000
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 50
#define MAX_MANUFACTURER_LENGTH 50
#define MAX_QUANTITY 10000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    char manufacturer[MAX_MANUFACTURER_LENGTH];
    int quantity;
    float price;
} medicine;

medicine medicines[MAX_MEDICINE_COUNT];
int medicine_count = 0;

void add_medicine() {
    printf("Enter medicine name: ");
    scanf("%s", medicines[medicine_count].name);
    printf("Enter medicine category: ");
    scanf("%s", medicines[medicine_count].category);
    printf("Enter medicine manufacturer: ");
    scanf("%s", medicines[medicine_count].manufacturer);
    printf("Enter medicine quantity: ");
    scanf("%d", &medicines[medicine_count].quantity);
    printf("Enter medicine price: ");
    scanf("%f", &medicines[medicine_count].price);
    medicine_count++;
}

void display_medicines() {
    printf("\nName\tCategory\tManufacturer\tQuantity\tPrice\n");
    for (int i = 0; i < medicine_count; i++) {
        printf("%s\t%s\t%s\t%d\t%f\n", medicines[i].name, medicines[i].category, medicines[i].manufacturer, medicines[i].quantity, medicines[i].price);
    }
}

void search_medicine() {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter medicine name to search: ");
    scanf("%s", search_name);
    for (int i = 0; i < medicine_count; i++) {
        if (strcmp(medicines[i].name, search_name) == 0) {
            printf("\nName\tCategory\tManufacturer\tQuantity\tPrice\n");
            printf("%s\t%s\t%s\t%d\t%f\n", medicines[i].name, medicines[i].category, medicines[i].manufacturer, medicines[i].quantity, medicines[i].price);
        }
    }
}

int main() {
    int choice;
    printf("Enter 1 to add medicine\nEnter 2 to display medicines\nEnter 3 to search medicine\nEnter 0 to exit\n");
    scanf("%d", &choice);
    while (choice!= 0) {
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
            default:
                printf("Invalid choice\n");
        }
        printf("\nEnter 1 to add medicine\nEnter 2 to display medicines\nEnter 3 to search medicine\nEnter 0 to exit\n");
        scanf("%d", &choice);
    }
    return 0;
}