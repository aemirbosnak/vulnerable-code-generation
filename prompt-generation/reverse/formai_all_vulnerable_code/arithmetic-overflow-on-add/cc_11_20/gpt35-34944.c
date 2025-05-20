//FormAI DATASET v1.0 Category: Product Inventory System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct product {
    char name[20];
    int quantity;
    float price;
    char date_added[11];
    char date_updated[11];
};

int main() {

    int num_products = 0;
    int option = 0;

    // Dynamically allocate memory for the array of product structures
    struct product *inventory = (struct product*) malloc(sizeof(struct product));

    // Set the current date for date added and date updated
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char current_date[11];
    sprintf(current_date, "%d-%02d-%02d", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday);

    printf("Welcome to the Product Inventory System!\n");

    do {
        printf("\n-----------------------\n");
        printf("Please choose an option:\n");
        printf("1. Add a product\n");
        printf("2. View all products\n");
        printf("3. Update a product\n");
        printf("4. Delete a product\n");
        printf("5. Exit\n");
        printf("-----------------------\n");
        scanf("%d", &option);

        switch(option) {
            case 1: // Add a product
                printf("\n-----------\n");
                printf("Add a product:\n");
                printf("Name: ");
                scanf("%s", (inventory+num_products)->name);
                printf("Quantity: ");
                scanf("%d", &(inventory+num_products)->quantity);
                printf("Price: $");
                scanf("%f", &(inventory+num_products)->price);
                strcpy((inventory+num_products)->date_added, current_date);
                strcpy((inventory+num_products)->date_updated, current_date);
                num_products++;
                // Dynamically reallocate memory for the array of product structures
                inventory = (struct product*) realloc(inventory, sizeof(struct product) * (num_products+1));
                break;

            case 2: // View all products
                printf("\n------------------------------------------\n");
                printf("All Products:\n");
                printf("%-20s%-12s%-12s%s\n", "Name", "Quantity", "Price", "Date Added");
                for(int i=0; i<num_products; i++) {
                    printf("%-20s%-12d$%-11.2f%s\n", (inventory+i)->name, (inventory+i)->quantity, (inventory+i)->price, (inventory+i)->date_added);
                }
                printf("------------------------------------------\n");
                break;

            case 3: // Update a product
                printf("\n-----------\n");
                printf("Update a product:\n");
                printf("Name: ");
                char update_name[20];
                scanf("%s", update_name);
                for(int i=0; i<num_products; i++) {
                    if(strcmp((inventory+i)->name, update_name) == 0) {
                        printf("New Quantity: ");
                        scanf("%d", &(inventory+i)->quantity);
                        printf("New Price: $");
                        scanf("%f", &(inventory+i)->price);
                        strcpy((inventory+i)->date_updated, current_date);
                        printf("Product Updated!\n");
                        break;
                    }
                    else if(i == num_products-1) {
                        printf("Product not found.\n");
                    }
                }
                break;

            case 4: // Delete a product
                printf("\n-----------\n");
                printf("Delete a product:\n");
                printf("Name: ");
                char delete_name[20];
                scanf("%s", delete_name);
                for(int i=0; i<num_products; i++) {
                    if(strcmp((inventory+i)->name, delete_name) == 0) {
                        for(int j=i; j<num_products-1; j++) {
                            *(inventory+j) = *(inventory+j+1);
                        }
                        num_products--;
                        // Dynamically reallocate memory for the array of product structures
                        inventory = (struct product*) realloc(inventory, sizeof(struct product) * (num_products+1));
                        printf("Product Deleted!\n");
                        break;
                    }
                    else if(i == num_products-1) {
                        printf("Product not found.\n");
                    }
                }
                break;

            case 5: // Exit
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nPlease choose a valid option.\n");
        }

    } while(option != 5);

    free(inventory);

    return 0;
}