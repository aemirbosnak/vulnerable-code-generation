//FormAI DATASET v1.0 Category: Hotel Management System ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

// Function prototypes
void display_menu();
void check_in();
void check_out();
void display_records();

// Structure for room details
struct room{
    char room_number[10];
    char customer_name[50];
    int days;
    float cost;
}r[50];

int total_records = 0; // Variable to keep track of total records

// Function to display the menu
void display_menu(){
    printf("\n\n---Hotel Management System---\n");
    printf("\n1. Check-In");
    printf("\n2. Check-Out");
    printf("\n3. Display Records");
    printf("\n4. Exit");
}

// Function to check in a customer
void check_in(){
    printf("\n\n---Check-In---\n");
    printf("\nEnter Room Number: ");
    scanf("%s", r[total_records].room_number);
    printf("Enter Customer Name: ");
    scanf("%s", r[total_records].customer_name);
    printf("Enter Number of Days: ");
    scanf("%d", &r[total_records].days);
    printf("Enter Cost per Day: ");
    scanf("%f", &r[total_records].cost);
    total_records++; // Increment total records counter
}

// Function to check out a customer and generate bill
void check_out(){
    char room_number[10];
    int index = -1; // Variable to store index of room
    float bill_amount;
    printf("\n\n---Check-Out---\n");
    printf("\nEnter Room Number: ");
    scanf("%s", room_number);
    // search for room number in records
    for(int i=0; i<total_records; i++){
        if(strcmp(r[i].room_number, room_number)==0){
            index = i;
            break;
        }
    }
    if(index == -1){ // Room not found
        printf("\nRoom Not Found!\n");
    }
    else{ // Room found
        bill_amount = r[index].days * r[index].cost; // Calculate the bill amount
        // Display bill and customer details
        printf("\nRoom Number: %s", r[index].room_number);
        printf("\nCustomer Name: %s", r[index].customer_name);
        printf("\nNumber of Days: %d", r[index].days);
        printf("\nCost per Day: %.2f", r[index].cost);
        printf("\nTotal Bill Amount: %.2f\n", bill_amount);
        // Remove the record of the customer
        for(int i=index; i<total_records; i++){
            strcpy(r[i].room_number, r[i+1].room_number);
            strcpy(r[i].customer_name, r[i+1].customer_name);
            r[i].days = r[i+1].days;
            r[i].cost = r[i+1].cost;
        }
        total_records--; // Decrement total records counter
    }
}

// Function to display the records
void display_records(){
    printf("\n\n---Records---\n");
    if(total_records==0){
        printf("\nNo Records Found!\n");
    }
    else{
        printf("\nRoom Number\tCustomer Name\tDays\tCost per Day\n");
        for(int i=0; i<total_records; i++){
            printf("%s\t\t%s\t\t%d\t%.2f\n", r[i].room_number, r[i].customer_name, r[i].days, r[i].cost);
        }
    }
}

int main(){
    int choice;
    do{
        display_menu();
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: check_in(); break;
            case 2: check_out(); break;
            case 3: display_records(); break;
            case 4: printf("\nExiting..."); break;
            default: printf("\nInvalid Choice!");
        }
    }while(choice!=4);
    return 0;
}