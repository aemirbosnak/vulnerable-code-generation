//FormAI DATASET v1.0 Category: Product Inventory System ; Style: safe
#include<stdio.h>
#include<string.h>

// structure to store product details
struct product {
    char name[20];
    int id, stockCount;
    float price;
} p[50];

// function to add products
void addProduct(int index) {
    printf("\nEnter product id: ");
    scanf("%d", &p[index].id);
    printf("Enter product name: ");
    scanf("%s", p[index].name);
    printf("Enter product price: ");
    scanf("%f", &p[index].price);
    printf("Enter stock count: ");
    scanf("%d", &p[index].stockCount);
}

// function to display product details
void display(int index) {
    printf("\nID: %d\nName: %s\nPrice: %.2f\nStock Count: %d\n", p[index].id, p[index].name, p[index].price, p[index].stockCount);
}

// function to search for a product by name
void search(char pname[]) {
    int flag = 0;
    for(int i=0; i<50; i++) {
        if(strcmp(pname, p[i].name)==0) {
            display(i);
            flag = 1;
            break;
        }
    }
    if(flag==0) {
        printf("\nProduct not found!\n");
    }
}

// function to edit product details
void edit(int pid) {
    int flag = 0;
    for(int i=0; i<50; i++) {
        if(pid==p[i].id) {
            printf("\nEnter new product name: ");
            scanf("%s", p[i].name);
            printf("Enter new product price: ");
            scanf("%f", &p[i].price);
            printf("Enter new stock count: ");
            scanf("%d", &p[i].stockCount);
            flag = 1;
            printf("\nProduct details updated successfully!\n");
            break;
        }
    }
    if(flag==0) {
        printf("\nProduct not found!\n");
    }
}

// function to delete a product
void deleteProduct(int pid) {
    int flag = 0;
    for(int i=0; i<50; i++) {
        if(pid==p[i].id) {
            p[i].id = p[i+1].id;
            strcpy(p[i].name, p[i+1].name);
            p[i].price = p[i+1].price;
            p[i].stockCount = p[i+1].stockCount;
            flag = 1;
            printf("\nProduct deleted successfully!\n");
            break;
        }
    }
    if(flag==0) {
        printf("\nProduct not found!\n");
    }
}

// main function
int main() {
    int ch, pid, index=0;
    char pname[20];
    while(1) {
        printf("\n***** PRODUCT INVENTORY SYSTEM *****\n\n");
        printf("1. Add product\n");
        printf("2. Display product\n");
        printf("3. Search product\n");
        printf("4. Edit product details\n");
        printf("5. Delete product\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: // add product
                if(index==50) {
                    printf("\nInventory is full! Cannot add more products.\n");
                }
                else {
                    addProduct(index);
                    index++;
                    printf("\nProduct added successfully!\n");
                }
                break;
            case 2: // display product
                if(index==0) {
                    printf("\nInventory is empty! Add products.\n");
                }
                else {
                    for(int i=0; i<index; i++) {
                        display(i);
                    }
                }
                break;
            case 3: // search product
                printf("\nEnter product name: ");
                scanf("%s", pname);
                search(pname);
                break;
            case 4: // edit product details
                printf("\nEnter product id: ");
                scanf("%d", &pid);
                edit(pid);
                break;
            case 5: // delete product
                printf("\nEnter product id: ");
                scanf("%d", &pid);
                deleteProduct(pid);
                index--;
                break;
            case 6: // exit
                printf("\nExiting program!");
                exit(0);
            default: // invalid choice
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}