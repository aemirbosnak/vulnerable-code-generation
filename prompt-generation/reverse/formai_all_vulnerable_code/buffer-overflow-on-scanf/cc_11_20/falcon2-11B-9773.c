//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>

typedef struct{
    char name[20];
    float price;
    int quantity;
} Product;

typedef struct{
    char name[20];
    char address[50];
    char phone[15];
    char email[50];
    char password[20];
} User;

typedef struct{
    char name[20];
    int id;
    User user;
    Product product;
    int stock;
} Order;

int main(){
    int i,j,k;
    char ch;
    srand(time(0));
    User users[10];
    Product products[10];
    Order orders[10];
    char option = 'y';
    int choice;
    while(option == 'y' || option == 'Y'){
        printf("1. Add Product\n2. View Products\n3. Add User\n4. View Users\n5. Add Order\n6. View Orders\n7. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                for(i=0; i<10; i++){
                    products[i].name[0] = '\0';
                    products[i].price = 0;
                    products[i].quantity = 0;
                }
                printf("Enter product name: ");
                scanf("%s", products[i].name);
                printf("Enter product price: ");
                scanf("%f", &products[i].price);
                printf("Enter product quantity: ");
                scanf("%d", &products[i].quantity);
                break;
            case 2:
                for(i=0; i<10; i++){
                    printf("%s\t\t%.2f\t\t%d\n", products[i].name, products[i].price, products[i].quantity);
                }
                break;
            case 3:
                for(i=0; i<10; i++){
                    printf("Enter user name: ");
                    scanf("%s", users[i].name);
                    printf("Enter user address: ");
                    scanf("%s", users[i].address);
                    printf("Enter user phone number: ");
                    scanf("%s", users[i].phone);
                    printf("Enter user email: ");
                    scanf("%s", users[i].email);
                    printf("Enter user password: ");
                    scanf("%s", users[i].password);
                }
                break;
            case 4:
                for(i=0; i<10; i++){
                    printf("User name: %s\nAddress: %s\nPhone number: %s\nEmail: %s\nPassword: %s\n", users[i].name, users[i].address, users[i].phone, users[i].email, users[i].password);
                }
                break;
            case 5:
                for(i=0; i<10; i++){
                    orders[i].name[0] = '\0';
                    orders[i].id = 0;
                    orders[i].user.name[0] = '\0';
                    orders[i].user.address[0] = '\0';
                    orders[i].user.phone[0] = '\0';
                    orders[i].user.email[0] = '\0';
                    orders[i].user.password[0] = '\0';
                    orders[i].product.name[0] = '\0';
                    orders[i].product.price = 0;
                    orders[i].product.quantity = 0;
                }
                printf("Enter order name: ");
                scanf("%s", orders[i].name);
                printf("Enter order id: ");
                scanf("%d", &orders[i].id);
                printf("Enter user name: ");
                scanf("%s", orders[i].user.name);
                printf("Enter user address: ");
                scanf("%s", orders[i].user.address);
                printf("Enter user phone number: ");
                scanf("%s", orders[i].user.phone);
                printf("Enter user email: ");
                scanf("%s", orders[i].user.email);
                printf("Enter user password: ");
                scanf("%s", orders[i].user.password);
                printf("Enter product name: ");
                scanf("%s", orders[i].product.name);
                printf("Enter product price: ");
                scanf("%f", &orders[i].product.price);
                printf("Enter product quantity: ");
                scanf("%d", &orders[i].product.quantity);
                break;
            case 6:
                for(i=0; i<10; i++){
                    printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%d\t\t%.2f\t\t%d\n", orders[i].name, orders[i].user.name, orders[i].user.address, orders[i].user.phone, orders[i].user.email, orders[i].user.password, orders[i].product.name, orders[i].product.price, orders[i].product.quantity);
                }
                break;
            case 7:
                option = 'n';
                break;
            default:
                printf("Invalid input, please try again\n");
        }
        printf("Do you want to continue (y/n): ");
        scanf("%c", &ch);
    }
    return 0;
}