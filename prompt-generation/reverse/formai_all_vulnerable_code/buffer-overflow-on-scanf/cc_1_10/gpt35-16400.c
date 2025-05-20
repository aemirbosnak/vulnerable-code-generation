//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: grateful
#include<stdio.h>
#include<string.h>

//defining structure for menu items
struct Menu{
    char name[20];
    float price;
};

// declaring array of menu items
struct Menu menu[8] = {
    {"Latte", 3.5},
    {"Cappuccino", 3},
    {"Americano", 2.5},
    {"Espresso", 2},
    {"Mocha", 4},
    {"Chocolate Cake", 3.5},
    {"Cheese Cake", 4},
    {"Blueberry Muffin", 2.5}
};

//declaring function to print menu
void printMenu(){
    printf("\n---Menu---\n");
    for(int i=0;i<8;i++){
        printf("%d. %s - %.2f\n",(i+1),menu[i].name, menu[i].price);
    }
}

//declaring function to calculate total bill
float calculateTotal(int order[], int n){
    float total = 0;
    for(int i=0;i<n;i++){
        total += menu[order[i]-1].price;
    }
    return total;
}

int main(){
    int order[20]; // array to store customer's order
    int n=0;
    char input[10];
    while(1){
        printf("Enter item number to add to order or 'done' to finish order: ");
        scanf("%s",input);

        if(strcmp(input,"done")==0){
            break;
        }else{
            int item = atoi(input);
            if(item<1 || item>8){
                printf("Invalid item number!\n");
            }else{
                order[n++] = item;
            }
            
        }
    }

    printf("\n---Thanks for Choosing Our Cafe!---\n");
    printMenu(); //print menu
    printf("\nYour order:\n");
    for(int i=0;i<n;i++){
        printf("%d. %s - %.2f\n",(i+1),menu[order[i]-1].name,menu[order[i]-1].price);
    }

    float total = calculateTotal(order,n);
    printf("\nTotal: %.2f\n",total);

    printf("\n---Payment Successful--\n");
    return 0;
}