//FormAI DATASET v1.0 Category: Digital Auction System ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PROD 100 // Maximum number of products allowed to be auctioned
#define MAX_BID 20 // Maximum number of bids allowed for a product

struct Product{
    int id;
    char name[50];
    float initial_price;
    float highest_bid;
    char highest_bidder[50];
    int bids_placed;
}product[MAX_PROD];

int num_products=0;

void add_product(){
    if(num_products==MAX_PROD){
        printf("No more products can be added!\n");
        return;
    }
    printf("Enter Product Name: ");
    scanf("%s", product[num_products].name);
    printf("Enter Initial Price: ");
    scanf("%f", &product[num_products].initial_price);
    product[num_products].highest_bid=product[num_products].initial_price;
    product[num_products].id=num_products+1;
    product[num_products].bids_placed=0;
    strcpy(product[num_products].highest_bidder, "No bids placed yet!");
    num_products++;
    printf("Product added successfully!\n");
}

void view_products(){
    if(num_products==0){
        printf("No products available for auction!\n");
        return;
    }
    printf("Products Available for Auction\n");
    printf("ID\tProduct\t\tInitial Price\tHighest Bid\tBidder\t\tBids Placed\n");
    for(int i=0;i<num_products;i++){
        printf("%d\t%s\t\t%.2f\t\t%.2f\t\t%s\t\t%d\n", product[i].id, product[i].name, product[i].initial_price, product[i].highest_bid, product[i].highest_bidder, product[i].bids_placed);
    }
}

void place_bid(){
    if(num_products==0){
        printf("No products available for auction!\n");
        return;
    }
    int id;
    printf("Enter the product ID to place the bid: ");
    scanf("%d", &id);
    if(id<=0 || id>num_products){
        printf("Product ID not found!\n");
        return;
    }
    id--;
    float amount;
    printf("Enter the bid amount: ");
    scanf("%f", &amount);
    if(amount<=product[id].highest_bid){
        printf("Bid amount too low!\n");
        return;
    }
    strncpy(product[id].highest_bidder, "Another Bidder", 14);
    product[id].highest_bid=amount;
    product[id].bids_placed++;
    printf("Bid placed successfully!\n");
}

int main(){
    int choice;
    while(1){
        printf("\nDigital Auction System\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Place Bid\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_product();
                break;
            case 2:
                view_products();
                break;
            case 3:
                place_bid();
                break;
            case 4:
                printf("Thank you for using Digital Auction System!\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}