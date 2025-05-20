//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50

//Function to print the main menu
void mainMenu() {
    printf("\n\n\t\t\tMEDICAL STORE MANAGEMENT SYSTEM\n");
    printf("\t\t\t---------------------------------\n\n");
    printf("\t\t1. Add medicine\n");
    printf("\t\t2. Sell medicine\n");
    printf("\t\t3. Stock inquiry\n");
    printf("\t\t4. Exit\n");
}

//Structure to hold medicine information
struct medicine {
    int id;
    char name[SIZE];
    float price;
    int quantity;
} med;

//Function to add medicine to store
void addMedicine() {
    FILE *fp;
    fp = fopen("medicines.txt","a");
    printf("\n\n\t\t\tADD NEW MEDICINE\n");
    printf("\t\t\t-----------------\n\n");
    printf("\t\tEnter the id of the medicine: ");
    scanf("%d", &med.id);
    printf("\t\tEnter the name of the medicine: ");
    scanf("%s", &med.name);
    printf("\t\tEnter the price of the medicine: ");
    scanf("%f", &med.price);
    printf("\t\tEnter the quantity of the medicine: ");
    scanf("%d", &med.quantity);
    fwrite(&med,sizeof(med),1,fp);
    fclose(fp);
    printf("\n\t\tMedicine added successfully!\n");
}

//Function to sell medicine from store
void sellMedicine() {
    FILE *fp1, *fp2;
    int id, quantity;
    float price;
    printf("\n\n\t\t\tSELL MEDICINE\n");
    printf("\t\t\t------------\n\n");
    printf("\t\tEnter the id of the medicine: ");
    scanf("%d", &id);
    printf("\t\tEnter the quantity to be sold: ");
    scanf("%d", &quantity);
    fp1 = fopen("medicines.txt","rb");
    fp2 = fopen("temp.txt","wb");
    while(fread(&med,sizeof(med),1,fp1)){
        if(med.id==id){
            if(med.quantity<quantity){
                printf("\n\t\tInsufficient stock!\n");
                fclose(fp1);
                fclose(fp2);
                remove("temp.txt");
                return;
            }
            else{
                price = med.price * quantity;
                printf("\n\t\tTotal price is %.2f\n", price);
                med.quantity = med.quantity - quantity;
            }
        }
        fwrite(&med,sizeof(med),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    remove("medicines.txt");
    rename("temp.txt","medicines.txt");
    if(price>0){
        printf("\n\t\tMedicine sold successfully!\n");
    }
}

//Function to display the stock of medicine
void stockInquiry() {
    FILE *fp;
    fp = fopen("medicines.txt","rb");
    printf("\n\n\t\t\tMEDICINE STOCK DETAILS\n");
    printf("\t\t\t----------------------\n\n");
    printf("\t\tID\t\t\tNAME\t\t\tPRICE\t\t\tQUANTITY\n");
    printf("\t\t----------------------------------------------------------------\n");
    while(fread(&med,sizeof(med),1,fp)){
        printf("\t\t%-20d%-20s%-20.2f%-20d\n", med.id, med.name, med.price, med.quantity);
    }
    fclose(fp);
}

//Main function
int main() {
    int choice;
    do {
        mainMenu();
        printf("\n\n\t\tEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                sellMedicine();
                break;
            case 3:
                stockInquiry();
                break;
            case 4:
                printf("\n\t\tProgram terminated successfully!\n\n");
                exit(0);
            default:
                printf("\n\t\tInvalid choice! Try again.\n");
        }
    } while(choice!=4);
    return 0;
}