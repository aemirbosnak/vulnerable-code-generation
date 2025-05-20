//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

// Structure for a product
struct product{
    char name[50];
    int id;
    int price;
};

// Function to compare two products based on their price
int compare(const void *a, const void *b){
    struct product *p1 = (struct product *)a;
    struct product *p2 = (struct product *)b;

    if(p1->price > p2->price)
        return 1;
    else if(p1->price < p2->price)
        return -1;
    else
        return 0;
}

// Function to display the list of products
void display(struct product arr[], int n){
    printf("\nList of products:\n");
    for(int i=0; i<n; i++){
        printf("%d. %s - $%d\n", i+1, arr[i].name, arr[i].price);
    }
}

// Function to accept bid from user
int accept_bid(struct product arr[], int n){
    int id, bid;

    printf("\nEnter the ID of the product you want to bid on: ");
    scanf("%d", &id);

    for(int i=0; i<n; i++){
        if(arr[i].id == id){
            printf("\nEnter your bid for %s: ", arr[i].name);
            scanf("%d", &bid);

            if(bid > arr[i].price){
                arr[i].price = bid;
                return 1;
            }
            else{
                printf("\nYour bid is too low.\n");
                return 0;
            }
        }
    }

    printf("\nProduct not found.\n");
    return 0;
}

// Function to sort the list of products based on their price
void sort(struct product arr[], int n){
    qsort(arr, n, sizeof(struct product), compare);
}

// Main function
int main(){
    struct product arr[MAX];
    int n = 0;

    // Accepting products from user
    while(n < MAX){
        printf("\nEnter the details of the product:\n");
        printf("ID: ");
        scanf("%d", &arr[n].id);

        printf("Name: ");
        scanf("%s", arr[n].name);

        printf("Price: $");
        scanf("%d", &arr[n].price);

        n++;
    }

    // Displaying the list of products
    display(arr, n);

    // Accepting bids from user
    int choice;

    do{
        printf("\nEnter your choice:\n");
        printf("1. Place a bid\n2. Sort by price\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                accept_bid(arr, n);
                break;

            case 2:
                sort(arr, n);
                display(arr, n);
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid choice.\n");
        }
    }while(choice!= 3);

    return 0;
}