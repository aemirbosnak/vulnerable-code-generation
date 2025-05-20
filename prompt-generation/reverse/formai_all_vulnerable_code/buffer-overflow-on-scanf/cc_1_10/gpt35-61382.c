//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Claude Shannon
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

struct Employee {
    char name[20];
    int employee_id;
    int contact_no;
};

struct Item {
    char name[50];
    int item_id;
    int available_quantity;
    float price;
};

int main()
{
    struct Employee employee[50];
    struct Item item[1000];

    //Display the main menu
    printf("******* MEDICAL STORE MANAGEMENT SYSTEM *******\n\n");
    printf("MAIN MENU\n");
    printf("1. Add Item\n");
    printf("2. Sell Item\n");
    printf("3. Search Item\n");
    printf("4. Generate Bill\n");
    printf("5. Exit\n");

    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            //Add item functionality
            break;
        case 2:
            //Sell item functionality
            break;
        case 3:
            //Item search functionality
            break;
        case 4:
            //Generate bill functionality
            break;
        case 5:
            //Exit the program
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
    return 0;
}