//FormAI DATASET v1.0 Category: Digital Auction System ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

struct Product{
    char name[20];
    int quantity;
    float price;
};

void printProduct(struct Product p){
    printf("Name:\t\t%s\nQuantity:\t%d\nPrice:\t\t%.2f\n\n", p.name, p.quantity, p.price);
}

int main(){
    printf("\t***Welcome to the Surrealist Auction!***\n\n");
    printf("Bidding starts at $500. Ready? Set. Go!\n\n");

    struct Product surreal = {"The Persistence of Memory by Salvador Dali", 1, 500};
    printProduct(surreal);

    float currentBid = 500;
    char bidder[20];

    printf("Who will bid next? ");
    scanf("%s", bidder);

    printf("How much would you like to bid, %s? $", bidder);
    scanf("%f", &currentBid);

    if(currentBid > surreal.price){
        surreal.price = currentBid;
        surreal.quantity++;
        printf("\nCongratulations, %s! You are now the highest bidder.\n", bidder);
        printf("The current bid is $%.2f.\n", surreal.price);
        printf("There are now %d %s(s) available for purchase.\n\n", surreal.quantity, surreal.name);
    } else {
        printf("\nSorry, %s, your bid of $%.2f is not high enough.\n", bidder, currentBid);
        printf("The current bid remains at $%.2f.\n", surreal.price);
    }

    printf("Time is running out! Bidding closes in 5 seconds...\n");

    for(int i=5; i>=0; i--){
        printf("%d...\n", i);
        sleep(1);
    }

    printf("\n\nSold! The winning bidder is %s.\n", bidder);
    printf("The final bid for %d %s(s) by %s is $%.2f.\n", surreal.quantity, surreal.name, bidder, surreal.price);

    return 0;
}