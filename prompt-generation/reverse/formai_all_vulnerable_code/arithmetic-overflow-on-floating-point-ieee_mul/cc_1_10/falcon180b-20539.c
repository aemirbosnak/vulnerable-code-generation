//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: random
//Include necessary header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Define maximum length of string
#define MAX 100

//Structure for bill
struct Bill{
    char name[MAX];
    int quantity;
    float price;
    float total;
};

//Function to calculate total
float calculateTotal(struct Bill bill){
    return bill.quantity*bill.price;
}

//Function to print bill
void printBill(struct Bill bill){
    printf("Name: %s\n",bill.name);
    printf("Quantity: %d\n",bill.quantity);
    printf("Price: $%.2f\n",bill.price);
    printf("Total: $%.2f\n\n",bill.total);
}

//Main function
int main(){
    //Initialize variables
    char name[MAX];
    int quantity;
    float price;
    struct Bill bill;

    //Loop to enter multiple bills
    while(1){
        //Clear input buffer
        fflush(stdin);

        //Get name
        printf("Enter name: ");
        scanf("%s",name);

        //Convert name to uppercase
        for(int i=0;i<strlen(name);i++){
            name[i] = toupper(name[i]);
        }

        //Get quantity
        printf("Enter quantity: ");
        scanf("%d",&quantity);

        //Get price
        printf("Enter price: ");
        scanf("%f",&price);

        //Calculate total
        bill.quantity = quantity;
        bill.price = price;
        bill.total = calculateTotal(bill);

        //Print bill
        printf("Bill for %s:\n",name);
        printBill(bill);

        //Ask user if they want to enter another bill
        char choice;
        printf("Do you want to enter another bill? (y/n): ");
        scanf(" %c",&choice);

        //Check if user wants to enter another bill
        if(choice == 'n' || choice == 'N'){
            //Exit loop
            break;
        }
    }

    //Return 0 to indicate successful termination
    return 0;
}