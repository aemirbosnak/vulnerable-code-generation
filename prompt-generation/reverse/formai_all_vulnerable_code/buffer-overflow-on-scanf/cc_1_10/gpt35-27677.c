//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_MEDICINES 100 //defining maximum medicines in inventory

//structure definition
struct medicalStore
{
    char name[50];
    int medicine_id;
    int stock_available;
    float price;
}medicines[MAX_MEDICINES];

//function to add medicine
void addMedicine(int medicine_count)
{
    printf("\nEnter the details for medicine number %d:", medicine_count + 1);
    printf("\nName: ");
    scanf("%s", medicines[medicine_count].name);
    printf("\nMedicine ID: ");
    scanf("%d", &medicines[medicine_count].medicine_id);
    printf("\nStock Available: ");
    scanf("%d", &medicines[medicine_count].stock_available);
    printf("\nPrice: ");
    scanf("%f", &medicines[medicine_count].price);
}

//function to display all medicines
void displayAllMedicines(int medicine_count)
{
    printf("\n\nDetails of Medicines in Inventory:\n");
    printf("      Name               ID    Stock Available    Price");
    for(int i = 0; i < medicine_count; i++)
    {
        printf("\n%-23s%-7d%-19d%-7.2f", medicines[i].name, medicines[i].medicine_id, medicines[i].stock_available, medicines[i].price);
    }
}

//function to search for medicine
void searchMedicine(int medicine_count)
{
    int id_search;
    printf("\nEnter medicine ID to search: ");
    scanf("%d", &id_search);
    for(int i = 0; i < medicine_count; i++)
    {
        if(medicines[i].medicine_id == id_search)
        {
            printf("\nDetails of Medicine:\n");
            printf("      Name               ID    Stock Available    Price\n");
            printf("%-23s%-7d%-19d%-7.2f\n", medicines[i].name, medicines[i].medicine_id, medicines[i].stock_available, medicines[i].price);
            return;
        }
    }
    printf("\nMedicine with ID %d not found in inventory.\n", id_search);
}

int main()
{
    int choice, medicine_count = 0;
    
    //menu driven program
    do
    {
        printf("\n********** WELCOME TO MEDICAL STORE MANAGEMENT SYSTEM **********\n");
        printf("\nPlease select an option from the menu:\n");
        printf("\n 1. Add New Medicine \n 2. Search for Medicine \n 3. Display Inventory \n 4. Exit\n");
        printf("\nOption: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1: //add new medicine to inventory
                    if(medicine_count < MAX_MEDICINES)
                    {
                        addMedicine(medicine_count);
                        medicine_count++;
                    }
                    else
                    {
                        printf("\nMaximum medicines limit reached.\n");
                    }
                    break;
                    
            case 2: //search for medicine in inventory
                    if(medicine_count > 0)
                    {
                        searchMedicine(medicine_count);
                    }
                    else
                    {
                        printf("\nNo medicines available in inventory.\n");
                    }
                    break;
                    
            case 3: //display all medicines in inventory
                    if(medicine_count > 0)
                    {
                        displayAllMedicines(medicine_count);
                    }
                    else
                    {
                        printf("\nNo medicines available in inventory.\n");
                    }
                    break;
                    
            case 4: //exit program
                    printf("\nThank you for using Medical Store Management System.\n");
                    exit(0);
                    break;
                    
            default: //invalid menu option
                     printf("\nInvalid option selected. Please select from the menu.\n");
                     break;
        }
    }while(choice != 4);

    return 0;
}