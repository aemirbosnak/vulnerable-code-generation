//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define FILE_NAME "data.txt"

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    int type; // 0 for expense, 1 for income
} Item;

Item items[MAX_ITEMS];
int current_index = 0;

void load_data() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file != NULL) {
        char line[100];
        while (fgets(line, sizeof(line), file)) {
            sscanf(line, "%s%f%d", items[current_index].name, &items[current_index].amount, &items[current_index].type);
            current_index++;
        }
        fclose(file);
    }
}

void save_data() {
    FILE *file = fopen(FILE_NAME, "w");
    for (int i = 0; i < current_index; i++) {
        fprintf(file, "%s %.2f %d\n", items[i].name, items[i].amount, items[i].type);
    }
    fclose(file);
}

void add_item(char *name, float amount, int type) {
    if (current_index < MAX_ITEMS) {
        strcpy(items[current_index].name, name);
        items[current_index].amount = amount;
        items[current_index].type = type;
        current_index++;
    } else {
        printf("Max number of items reached.\n");
    }
}

void view_balance() {
    float balance = 0;
    for (int i = 0; i < current_index; i++) {
        if (items[i].type == 1) {
            balance += items[i].amount;
        } else {
            balance -= items[i].amount;
        }
    }
    printf("Current balance: %.2f\n", balance);
}

int main() {
    load_data();

    char name[MAX_NAME_LENGTH];
    int choice, type;
    float amount;

    while (1) {
        printf("\n1. Add item\n2. View balance\n3. Save and exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("Enter type (0 for expense, 1 for income): ");
                scanf("%d", &type);
                add_item(name, amount, type);
                break;
            case 2:
                view_balance();
                break;
            case 3:
                save_data();
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}