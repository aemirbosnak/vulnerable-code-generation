//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: scientific
// This is a Medical Store Management System program written in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Medicines

struct medicine {
    char medicine_name[50];
    char manufacturer[50];
    char expiry_date[15];
    int quantity;
    float price;
};

// Function to Add Medicine

void add_medicine() {
    FILE *fp;
    fp = fopen("medicines.txt","a+");

    char medicine_name[50];
    char manufacturer[50];
    char expiry_date[15];
    int quantity;
    float price;

    printf("Enter Medicine Name: ");
    scanf("%s", &medicine_name);
    printf("Enter Manufacturer: ");
    scanf("%s", &manufacturer);
    printf("Enter Expiry Date: ");
    scanf("%s", &expiry_date);
    printf("Enter Quantity: ");
    scanf("%d", &quantity);
    printf("Enter Price: ");
    scanf("%f", &price);

    fprintf(fp, "%s %s %s %d %f\n", medicine_name, manufacturer, expiry_date, quantity, price);

    printf("\nMedicine Added Successfully!\n\n");
    fclose(fp);
}

// Function to Search Medicine

void search_medicine() {
    char search_medicine[50];

    printf("Enter Medicine Name: ");
    scanf("%s", &search_medicine);

    FILE *fp;
    fp = fopen("medicines.txt","r");

    char medicine_name[50];
    char manufacturer[50];
    char expiry_date[15];
    int quantity;
    float price;
    int found = 0;

    while(fscanf(fp, "%s %s %s %d %f", medicine_name, manufacturer, expiry_date, &quantity, &price) != EOF) {
        if(strcmp(medicine_name, search_medicine) == 0) {
            printf("\nName\t\tManufacturer\t\tExpiry Date\t\tQuantity\t\tPrice\n");
            printf("%s\t\t%s\t\t\t%s\t\t%d\t\t\t%f\n\n", medicine_name, manufacturer, expiry_date, quantity, price);
            found = 1;
            break;
    
        }
    }
    if(found == 0) {
        printf("\nMedicine not found.\n\n");
    }
    fclose(fp);
}

// Function to List Medicine

void list_medicines() {
    printf("\nList of Medicines:\n");

    FILE *fp;
    fp = fopen("medicines.txt","r");

    char medicine_name[50];
    char manufacturer[50];
    char expiry_date[15];
    int quantity;
    float price;

    printf("\nName\t\tManufacturer\t\tExpiry Date\t\tQuantity\t\tPrice\n");

    while(fscanf(fp, "%s %s %s %d %f", medicine_name, manufacturer, expiry_date, &quantity, &price) != EOF) {
        printf("%s\t\t%s\t\t\t%s\t\t%d\t\t\t%f\n", medicine_name, manufacturer, expiry_date, quantity, price);
    }
    fclose(fp);
}

// Function to Update Medicine Quantity

void update_medicine_quantity() {
    char update_medicine[50];

    printf("\nEnter Medicine name to update quantity: ");
    scanf("%s", &update_medicine);

    FILE *fp;
    fp = fopen("medicines.txt","r");

    char medicine_name[50];
    char manufacturer[50];
    char expiry_date[15];
    int quantity;
    float price;
    int found = 0;

    while(fscanf(fp, "%s %s %s %d %f", medicine_name, manufacturer, expiry_date, &quantity, &price) != EOF) {
        if(strcmp(medicine_name, update_medicine) == 0) {
            found = 1;
            printf("\nEnter new quantity: ");
            scanf("%d", &quantity);

            FILE *ft;
            ft = fopen("temp.txt", "a+");

            fprintf(ft, "%s %s %s %d %f\n", medicine_name, manufacturer, expiry_date, quantity, price);

            printf("\nQuantity Updated Successfully!\n\n");
            fclose(ft);
        }
        else {
            FILE *ft;
            ft = fopen("temp.txt", "a+");

            fprintf(ft, "%s %s %s %d %f", medicine_name, manufacturer, expiry_date, quantity, price);

            fclose(ft);
        }
    }

    fclose(fp);
    remove("medicines.txt");
    rename("temp.txt", "medicines.txt");

    if(found == 0) {
        printf("\nMedicine not found.\n\n");
    }
}

int main() {
    int choice;

    do {
        printf("Medical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Search Medicine\n");
        printf("3. List Medicines\n");
        printf("4. Update Medicine Quantity\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                search_medicine();
                break;
            case 3:
                list_medicines();
                break;
            case 4:
                update_medicine_quantity();
                break;
            case 5:
                printf("Thank you for using Medical Store Management System!\n");
                exit(1);
        }
    } while(choice != 5);

    return 0;
}