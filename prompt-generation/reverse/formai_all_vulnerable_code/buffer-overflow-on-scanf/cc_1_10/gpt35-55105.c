//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100 //Max array size

//function prototypes
void AddItem();
void DeleteItem();
void ModifyItem();
void ViewAllItems();
float CalculateBill(int [], int[], int);

//structure to hold cafe item details
struct Item {
    int item_id;
    char item_name[20];
    int item_price;
} item_list[MAX];
int item_count = 0;

int main() {
    int choice=0, bill[MAX], quantity[MAX], item_no=0, i;
    float total_amount;

    while(choice != 5) {
        printf("\n1. Add an Item\n2. Delete an Item\n3. Modify an Item\n4. View All Items\n5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                AddItem();
                break;

            case 2:
                DeleteItem();
                break;

            case 3:
                ModifyItem();
                break;

            case 4:
                ViewAllItems();
                break;

            case 5:
                printf("\nThank you for visiting our Cafe!");
                break;

            default:
                printf("\nInvalid choice! Please choose between 1-5.");
        }
        //Ask the user to continue (1) or exit (0)
        if(choice !=5 ){
            printf("\nWould you like to continue (1/0)? ");
            scanf("%d", &choice);
        }
    }
    //Ask the user to enter bill and quantity details for each item
    printf("\nEnter the bill and quantity details for each item: \n");
    for(i=0; i<item_count; i++) {
        printf("Item #%d - %s : Price : %d Rs : ", i+1, item_list[i].item_name, item_list[i].item_price);
        scanf("%d", &bill[i]);
        printf("Enter quantity : ");
        scanf("%d", &quantity[i]);
    }
    //calculate total bill amount
    total_amount = CalculateBill(bill, quantity, item_count);
    //print the total bill amount
    printf("\nTotal amount : %.2f Rs", total_amount);
    return 0;
}

//function to add an item into the cafe item list
void AddItem() {
    int i;

    printf("\nPlease enter the details of the new item : \n");
    printf("Enter item id : ");
    scanf("%d", &item_list[item_count].item_id);
    printf("Enter item name : ");
    scanf("%s", item_list[item_count].item_name);
    printf("Enter item price : ");
    scanf("%d", &item_list[item_count].item_price);
    item_count++;
    printf("\nItem added successfully!");
}

//function to delete an item from the cafe item list
void DeleteItem() {
    int i, item_id;

    printf("\nEnter the item id of the item to be deleted : ");
    scanf("%d", &item_id);
    for(i=0; i<item_count; i++) {
        if(item_list[i].item_id == item_id) {
            //shift all the elements after i to i-1 position
            for(int j=i; j<item_count-1; j++) {
                item_list[j] = item_list[j+1];
            }
            item_count--;
            printf("\nItem deleted successfully!");
            return;
        }
    }
    printf("\nItem not found!");
}

//function to modify an item in the cafe item list
void ModifyItem() {
    int i, item_id;

    printf("\nEnter the item id of the item to be modified : ");
    scanf("%d", &item_id);
    for(i=0; i<item_count; i++) {
        if(item_list[i].item_id == item_id) {
            printf("\nCurrent item details : ");
            printf("\nItem id: %d", item_list[i].item_id);
            printf("\nItem name: %s", item_list[i].item_name);
            printf("\nItem price: %d Rs", item_list[i].item_price);
            printf("\nEnter new item price : ");
            scanf("%d", &item_list[i].item_price);
            printf("\nItem modified successfully!");
            return;
        }
    }
    printf("\nItem not found!");
}

//function to view all items in the cafe item list
void ViewAllItems() {
    int i;

    printf("\nCafe Item List: \n");
    for(i=0; i<item_count; i++) {
        printf("\nItem #%d : ", i+1);
        printf("\nItem id : %d", item_list[i].item_id);
        printf("\nItem name: %s", item_list[i].item_name);
        printf("\nItem price: %d Rs", item_list[i].item_price);
    }
}

//function to calculate the total bill amount for all items
float CalculateBill(int bill[], int quantity[], int item_count) {
    float total_amount = 0.0;
    int i;

    for(i=0; i<item_count; i++) {
        total_amount += bill[i] * quantity[i];
    }
    return total_amount;
}