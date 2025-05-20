//FormAI DATASET v1.0 Category: Product Inventory System ; Style: statistical
#include<stdio.h>
#include<string.h>

struct product {
    int id;
    char name[30];
    int quantity;
    float price;
};

struct statistical_analysis {
    float mean_price;
    int max_quantity;
    int min_quantity;
};

void update_product(struct product* p, int new_quantity, float new_price) {
    p->quantity += new_quantity;
    p->price = new_price;
}

struct statistical_analysis analyze_inventory(struct product* arr, int size) {
    struct statistical_analysis stats;
    stats.mean_price = 0;
    stats.max_quantity = arr[0].quantity;
    stats.min_quantity = arr[0].quantity;
    for(int i=0; i<size; i++) {
        stats.mean_price += arr[i].price;
        if(arr[i].quantity > stats.max_quantity) {
            stats.max_quantity = arr[i].quantity;
        }
        if(arr[i].quantity < stats.min_quantity) {
            stats.min_quantity = arr[i].quantity;
        }
    }
    stats.mean_price /= size;
    return stats;
}

int main() {
    struct product inventory[100];
    int num_products = 0;
    char choice[10];
    do {
        printf("Enter product ID: ");
        scanf("%d", &inventory[num_products].id);
        printf("Enter product name: ");
        scanf("%s", inventory[num_products].name);
        printf("Enter product quantity: ");
        scanf("%d", &inventory[num_products].quantity);
        printf("Enter product price: ");
        scanf("%f", &inventory[num_products].price);
        num_products++;
        printf("Do you want to add another product? (y/n): ");
        scanf("%s", choice);
    } while(strcmp(choice, "y") == 0);

    printf("\nPRODUCT INVENTORY\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for(int i=0; i<num_products; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }

    struct statistical_analysis stats = analyze_inventory(inventory, num_products);
    printf("\nSTATISTICAL ANALYSIS\n");
    printf("Mean price: %.2f\n", stats.mean_price);
    printf("Max quantity: %d\n", stats.max_quantity);
    printf("Min quantity: %d\n", stats.min_quantity);

    int product_id;
    printf("\nEnter product ID to update: ");
    scanf("%d", &product_id);
    for(int i=0; i<num_products; i++) {
        if(inventory[i].id == product_id) {
            int new_quantity;
            printf("Enter new quantity for product: ");
            scanf("%d", &new_quantity);
            float new_price;
            printf("Enter new price for product: ");
            scanf("%f", &new_price);
            update_product(&inventory[i], new_quantity, new_price);
            printf("\nUPDATED PRODUCT INFORMATION\n");
            printf("ID\tName\tQuantity\tPrice\n");
            printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
    return 0;
}