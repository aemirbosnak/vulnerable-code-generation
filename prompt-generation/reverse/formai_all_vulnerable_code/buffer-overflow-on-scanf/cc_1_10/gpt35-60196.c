//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicalStore{
    char medname[60];
    int medid;
    int medprice;
};

void addProduct(struct medicalStore medicine[], int *n){
    printf("\nEnter the name of the medicine: ");
    scanf("%s", medicine[*n].medname);
    printf("\nEnter the Medicine ID: ");
    scanf("%d", &medicine[*n].medid);
    printf("\nEnter the Medicine Price: ");
    scanf("%d", &medicine[*n].medprice);
    (*n)++;
    printf("\n\nMedicine added successfully!\n\n");
}

void displayProducts(struct medicalStore medicine[], int n){
    printf("\n\nMedical Store Inventory\n\n");
    printf("Medicine Name\t\tMedicine ID\t\tMedicine Price\n");
    for(int i=0;i<n;i++){
        printf("%-20s\t\t%-10d\t\t%-10d\n", medicine[i].medname, medicine[i].medid, medicine[i].medprice);
    }
    printf("\n");
}

void searchProduct(struct medicalStore medicine[], int n){
    int id, flag=0;
    printf("\nEnter the medicine ID to search: ");
    scanf("%d", &id);
    for(int i=0;i<n;i++){
        if(medicine[i].medid == id){
            printf("\n\nMedicine Name: %s", medicine[i].medname);
            printf("\nMedicine ID: %d", medicine[i].medid);
            printf("\nMedicine Price: %d\n\n", medicine[i].medprice);
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("\n\nMedicine with ID %d not found!", id);
}

void deleteProduct(struct medicalStore medicine[], int *n){
    int id, flag=0;
    printf("\nEnter the Medicine ID to delete: ");
    scanf("%d", &id);
    for(int i=0;i<*n;i++){
        if(medicine[i].medid == id){
            for(int j=i;j<*n-1;j++){
                medicine[j]=medicine[j+1];
            }
            (*n)--;
            flag=1;
            printf("\n\nMedicine with ID %d deleted successfully!", id);
            break;
        }
    }
    if(flag==0)
        printf("\n\nMedicine with ID %d not found!", id);
}

void modifyProduct(struct medicalStore medicine[], int n){
    int id, flag=0;
    printf("\nEnter the Medicine ID to modify: ");
    scanf("%d", &id);
    for(int i=0;i<n;i++){
        if(medicine[i].medid == id){
            printf("\n\nEnter the modified medicine name: ");
            scanf("%s", medicine[i].medname);
            printf("\nEnter the modified medicine price: ");
            scanf("%d", &medicine[i].medprice);
            flag=1;
            printf("\n\nMedicine with ID %d modified successfully!", id);
            break;
        }
    }
    if(flag==0)
        printf("\n\nMedicine with ID %d not found!", id);
}

int main(){
    int n=0, choice;
    struct medicalStore medicine[100];
    printf("*******************************************\n");
    printf("*** Welcome to Medical Store Management ***\n");
    printf("*******************************************\n\n");
    while(1){
        printf("1. Add a Medicine\n");
        printf("2. Display the Medicines\n");
        printf("3. Search for a Medicine\n");
        printf("4. Delete a Medicine\n");
        printf("5. Modify a Medicine\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: addProduct(medicine, &n);
                    break;

            case 2: displayProducts(medicine, n);
                    break;

            case 3: searchProduct(medicine, n);
                    break;

            case 4: deleteProduct(medicine, &n);
                    break;

            case 5: modifyProduct(medicine, n);
                    break;

            case 6: exit(0);

            default: printf("\n\nInvalid choice! Try Again.\n\n");
        }
    }
    return 0;
}