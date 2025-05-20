//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 20
#define MAX_DESC_LEN 50
#define MAX_PRICE 100

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    int price;
} Medicine;

void print_menu() {
    printf("1. Add new medicine\n");
    printf("2. Remove medicine\n");
    printf("3. Update medicine details\n");
    printf("4. Print all medicines\n");
    printf("5. Quit\n");
}

void add_medicine(Medicine* medicines, int* num_medicines) {
    printf("Enter medicine name: ");
    scanf("%s", medicines[*num_medicines].name);
    printf("Enter medicine description: ");
    scanf("%s", medicines[*num_medicines].description);
    printf("Enter medicine price: ");
    scanf("%d", &medicines[*num_medicines].price);
    *num_medicines += 1;
}

void remove_medicine(Medicine* medicines, int* num_medicines) {
    int index;
    printf("Enter medicine index to remove: ");
    scanf("%d", &index);
    if (index >= 0 && index < *num_medicines) {
        for (int i = index; i < *num_medicines - 1; i++) {
            medicines[i] = medicines[i + 1];
        }
        *num_medicines -= 1;
    } else {
        printf("Invalid medicine index.\n");
    }
}

void update_medicine(Medicine* medicines, int* num_medicines) {
    int index;
    printf("Enter medicine index to update: ");
    scanf("%d", &index);
    if (index >= 0 && index < *num_medicines) {
        printf("Enter new medicine name: ");
        scanf("%s", medicines[index].name);
        printf("Enter new medicine description: ");
        scanf("%s", medicines[index].description);
        printf("Enter new medicine price: ");
        scanf("%d", &medicines[index].price);
    } else {
        printf("Invalid medicine index.\n");
    }
}

void print_medicines(Medicine* medicines, int num_medicines) {
    printf("Medicines:\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("%d. %s - %s (%d)\n", i + 1, medicines[i].name, medicines[i].description, medicines[i].price);
    }
}

int main() {
    Medicine medicines[MAX_PRICE];
    int num_medicines = 0;
    int choice;
    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_medicine(medicines, &num_medicines);
                break;
            case 2:
                remove_medicine(medicines, &num_medicines);
                break;
            case 3:
                update_medicine(medicines, &num_medicines);
                break;
            case 4:
                print_medicines(medicines, num_medicines);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}