//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: optimized
#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} Item;

Item inventory[MAX_ITEMS];
int num_items = 0;

void add_item(char *name, int qty) {
    if (num_items >= MAX_ITEMS) {
        printf("Inventory is full!\n");
        return;
    }
    strcpy(inventory[num_items].name, name);
    inventory[num_items].quantity = qty;
    num_items++;
}

void update_quantity(char *name, int delta) {
    for (int i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].quantity += delta;
            break;
        }
    }
}

void remove_item(char *name) {
    for (int i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < num_items - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            num_items--;
            break;
        }
    }
}

int main() {
    char command[10], name[MAX_NAME_LEN];
    int qty, idx, choice;

    while (1) {
        printf("\n1. Add Item\n2. Update Quantity\n3. Remove Item\n4. Exit\n");
        scanf("%s", command);

        switch (command[0]) {
            case '1':
                scanf("%s %d", name, &qty);
                add_item(name, qty);
                break;
            case '2':
                scanf("%s %d", name, &qty);
                update_quantity(name, qty);
                break;
            case '3':
                scanf("%s", name);
                remove_item(name);
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid command!\n");
        }

        printf("\nCurrent Inventory:\n");
        for (int i = 0; i < num_items; i++) {
            printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
        }
    }

    return 0;
}