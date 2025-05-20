//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: grateful
int main() {
    int inventory[10];
    int choice;
    int item_count = 0;
    char item_name[20];

    // Initialize the inventory
    for (int i = 0; i < 10; i++) {
        inventory[i] = 0;
    }

    // Welcome message
    printf("Welcome to the C Product Inventory System!\n");

    // Main menu
    while (1) {
        printf("Please enter your choice:\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display inventory\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        // Add item
        if (choice == 1) {
            printf("Enter the name of the item: ");
            scanf("%s", item_name);
            printf("Enter the quantity of the item: ");
            scanf("%d", &item_count);
            inventory[item_count - 1] += item_count;
        }

        // Remove item
        else if (choice == 2) {
            printf("Enter the name of the item: ");
            scanf("%s", item_name);
            printf("Enter the quantity of the item: ");
            scanf("%d", &item_count);
            inventory[item_count - 1] -= item_count;
        }

        // Display inventory
        else if (choice == 3) {
            printf("Inventory:\n");
            for (int i = 0; i < 10; i++) {
                printf("%d: %d\n", i + 1, inventory[i]);
            }
        }

        // Quit
        else if (choice == 4) {
            printf("Thank you for using the C Product Inventory System!\n");
            break;
        }
    }

    return 0;
}