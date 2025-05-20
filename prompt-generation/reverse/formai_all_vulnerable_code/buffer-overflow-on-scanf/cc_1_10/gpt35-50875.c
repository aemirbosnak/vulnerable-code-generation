//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Linus Torvalds
#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_QUANTITY 999

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int numProducts = 0;

void addProduct(char* name, char* description, int quantity, float price){
    if(numProducts < MAX_PRODUCTS){
        strcpy(inventory[numProducts].name, name);
        strcpy(inventory[numProducts].description, description);
        inventory[numProducts].quantity = quantity;
        inventory[numProducts].price = price;
        numProducts++;
        printf("Product added successfully!\n");
    }
    else{
        printf("Inventory full! Cannot add more products.\n");
    }
}

void displayInventory(){
    printf("%-10s %-30s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    for(int i=0; i<numProducts; i++){
        printf("%-10d %-30s %-10d $%-10.2f\n", i+1, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateQuantity(int id, int quantity){
    if(id <= numProducts && id >= 1){
        inventory[id-1].quantity += quantity;
        if(inventory[id-1].quantity > MAX_QUANTITY){
            inventory[id-1].quantity = MAX_QUANTITY;
        }
        printf("Quantity updated successfully!\n");
    }
    else{
        printf("Invalid product ID.\n");
    }
}

void removeProduct(int id){
    if(id <= numProducts && id >= 1){
        for(int i=id-1; i<numProducts-1; i++){
            inventory[i] = inventory[i+1];
        }
        numProducts--;
        printf("Product removed successfully!\n");
    }
    else{
        printf("Invalid product ID.\n");
    }
}

int main(){
    char input;
    do{
        printf("------------------\n");
        printf("Product Inventory\n");
        printf("------------------\n");
        printf("1. Add product\n");
        printf("2. Display inventory\n");
        printf("3. Update quantity\n");
        printf("4. Remove product\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf(" %c", &input);
        switch(input){
            case '1':{
                char name[MAX_NAME_LENGTH];
                char description[MAX_DESCRIPTION_LENGTH];
                int quantity;
                float price;
                printf("Enter product name: ");
                scanf(" %[^\n]s", name);
                printf("Enter product description: ");
                scanf(" %[^\n]s", description);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                printf("Enter product price: ");
                scanf("%f", &price);
                addProduct(name, description, quantity, price);
                break;
            }
            case '2':{
                displayInventory();
                break;
            }
            case '3':{
                int id, quantity;
                printf("Enter product ID: ");
                scanf("%d", &id);
                printf("Enter quantity to update (+/-): ");
                scanf("%d", &quantity);
                updateQuantity(id, quantity);
                break;
            }
            case '4':{
                int id;
                printf("Enter product ID to remove: ");
                scanf("%d", &id);
                removeProduct(id);
                break;
            }
            case '5':{
                printf("Exiting program...\n");
                break;
            }
            default:{
                printf("Invalid input. Please try again.\n");
            }
        }
    }while(input != '5');
    return 0;
}