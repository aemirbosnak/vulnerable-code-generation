//FormAI DATASET v1.0 Category: Product Inventory System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

void printMenu();
void addProduct(Product *p);
void editProduct(Product *p);
void deleteProduct(Product *p);
void displayProduct(Product *p);

int main() {
    int choice;
    Product products[20];
    int count = 0;

    do {
        printMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(&products[count]);
                count++;
                printf("\nProduct added!\n");
                break;
            case 2:
                if(count > 0) {
                    editProduct(products);
                } else {
                    printf("No products to edit!\n");
                }
                break;
            case 3:
                if(count > 0) {
                    deleteProduct(products);
                    count--;
                } else {
                    printf("No products to delete!\n");
                }
                break;
            case 4:
                if(count > 0) {
                    displayProduct(products);
                } else {
                    printf("No products to display!\n");
                }
                break;
            case 5:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice, try again.\n");
        }

    } while(choice != 5);

    return 0;
}

void printMenu() {
    printf("\n***** C Product Inventory System *****\n");
    printf("1. Add a product\n");
    printf("2. Edit a product\n");
    printf("3. Delete a product\n");
    printf("4. Display all products\n");
    printf("5. Exit\n");
}

void addProduct(Product *p) {
    printf("\nEnter product ID: ");
    scanf("%d", &p->id);
    fflush(stdin);

    printf("Enter product name: ");
    gets(p->name);

    printf("Enter product price: ");
    scanf("%f", &p->price);

    printf("Enter product quantity: ");
    scanf("%d", &p->quantity);
}

void editProduct(Product *p) {
    int id, i;
    printf("\nEnter product ID to edit: ");
    scanf("%d", &id);

    for(i = 0; i < 20; i++) {
        if(p[i].id == id) {
            printf("Enter new name: ");
            gets(p[i].name);

            printf("Enter new price: ");
            scanf("%f", &p[i].price);

            printf("Enter new quantity: ");
            scanf("%d", &p[i].quantity);

            printf("\nProduct edited!\n");
            return;
        }
    }

    printf("\nProduct not found!\n");
}

void deleteProduct(Product *p) {
    int id, i, j;
    printf("\nEnter product ID to delete: ");
    scanf("%d", &id);

    for(i = 0; i < 20; i++) {
        if(p[i].id == id) {
            for(j = i; j < 19; j++) {
                p[j] = p[j+1];
            }
            printf("\nProduct deleted!\n");
            return;
        }
    }

    printf("\nProduct not found!\n");
}

void displayProduct(Product *p) {
    int i;
    printf("\nProduct ID\tProduct Name\tProduct Price\tProduct Quantity\n");
    for(i = 0; i < 20; i++) {
        if(p[i].id != 0) {
            printf("%d\t\t%s\t\t%.2f\t\t%d\n", p[i].id, p[i].name, p[i].price, p[i].quantity);
        }
    }
}