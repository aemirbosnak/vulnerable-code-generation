//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// defining structures
struct Item {
    char name[20];
    float price;
    int quantity;
};

struct Bill {
    int bill_no;
    char date[15];
    struct Item items[10];
    int total_items;
    float total_bill;
};

// main function
int main() {
    int num_bills;
    
    // getting input for number of bills to be generated
    printf("Enter number of bills to be generated: ");
    scanf("%d", &num_bills);
    printf("\n");
    
    // creating a dynamic array of bills based on user input
    struct Bill *bills = (struct Bill*) malloc(num_bills * sizeof(struct Bill));
    
    // generating bills
    for(int i=0; i<num_bills; i++) {
        // initializing bill details
        printf("Enter details for Bill %d:\n", (i+1));
        printf("Bill number: ");
        scanf("%d", &(bills[i].bill_no));
        printf("Date (dd-mm-yyyy): ");
        scanf("%s", &(bills[i].date));
        printf("Number of items purchased: ");
        scanf("%d", &(bills[i].total_items));
        
        // generating items list for the bill
        printf("\nEnter details for each item purchased:\n");
        for(int j=0; j<bills[i].total_items; j++) {
            printf("Item %d name: ", (j+1));
            scanf("%s", &(bills[i].items[j].name));
            printf("Item %d price: ", (j+1));
            scanf("%f", &(bills[i].items[j].price));
            printf("Item %d quantity: ", (j+1));
            scanf("%d", &(bills[i].items[j].quantity));
            printf("\n");
        }
        
        // calculating total bill for the bill
        bills[i].total_bill = 0;
        for(int j=0; j<bills[i].total_items; j++) {
            bills[i].total_bill += (bills[i].items[j].price * bills[i].items[j].quantity);
        }
    }
    
    // displaying the bills
    printf("\n\n");
    printf("*************************************\n");
    printf("*********** C CAFE BILL *************\n");
    printf("*************************************\n\n");
    for(int i=0; i<num_bills; i++) {
        printf("Bill number: %d\t\t\tDate: %s\n", bills[i].bill_no, bills[i].date);
        printf("-------------------------------------\n");
        printf("Item Name\t\t\tPrice\tQuantity\n");
        printf("-------------------------------------\n");
        for(int j=0; j<bills[i].total_items; j++) {
            printf("%-20s\t\t%f\t%d\n", bills[i].items[j].name, bills[i].items[j].price, bills[i].items[j].quantity);
        }
        printf("-------------------------------------\n");
        printf("Total Bill: %f\n\n", bills[i].total_bill);
    }
    
    // freeing memory used by the dynamic array
    free(bills);
    
    return 0;
}