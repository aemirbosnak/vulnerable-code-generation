//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20 //defining maximum size for storing medicines

//defining structure for medicine
struct medicine{
    char name[20];
    int qty;
    float price;
};

struct medicine store[MAX]; //defining struct type array for storing medicines
int count = 0; //Variable for counting the quantity of medicines in the store

//Function for adding medicine to the store
void addMedicine(){
    printf("\nAdd Medicine:\n");
    printf("--------------------------\n");
    printf("Enter Name of Medicine: ");
    scanf("%s",store[count].name);
    printf("Enter Quantity of Medicine: ");
    scanf("%d",&store[count].qty);
    printf("Enter Price of Medicine: ");
    scanf("%f",&store[count].price);
    printf("\nMedicine Added Successfully!\n");
    count++;
}

//Function for displaying all the medicines in the store
void displayMedicines(){
    if(count == 0){
        printf("\nNo Medicines in Store!\n");
        return;
    }
    printf("\nAll Medicines:\n");
    printf("--------------------\n");
    printf("Name\tQuantity\tPrice\n");
    printf("--------------------\n");
    for(int i=0;i<count;i++){
        printf("%s\t%d\t%.2f\n",store[i].name,store[i].qty,store[i].price);
    }
}

//Function for searching for a medicine in the store
void searchMedicine(){
    char search[20];
    int found = 0;
    printf("\nEnter the name of medicine you want to search: ");
    scanf("%s",search);
    for(int i=0;i<count;i++){
        if(strcmp(store[i].name,search) == 0){
            printf("\nMedicine Found!!\n");
            printf("Name\tQuantity\tPrice\n");
            printf("-----------------------------\n");
            printf("%s\t%d\t%.2f\n",store[i].name,store[i].qty,store[i].price);
            found=1; //set found to true
            break;
        }
    }
    if(!found) printf("\nMedicine Not Found!\n");
}

//Function for updating quantity of a medicine in the store
void updateMedicine(){
    char update[20];
    int found = 0, newQty;
    printf("\nEnter the name of medicine you want to update: ");
    scanf("%s",update);
    for(int i=0;i<count;i++){
        if(strcmp(store[i].name,update) == 0){
            printf("\nMedicine Found!!\n");
            printf("Name\tQuantity\tPrice\n");
            printf("-----------------------------\n");
            printf("%s\t%d\t%.2f\n",store[i].name,store[i].qty,store[i].price);
            printf("\nEnter New Quantity: ");
            scanf("%d",&newQty);
            store[i].qty = newQty; //updating quantity
            printf("\nQuantity of %s has been updated successfully to %d\n",store[i].name,newQty);
            found=1; //set found to true
            break;
        }
    }
    if(!found) printf("\nMedicine Not Found!\n");
}

int main(){
    int choice;
    printf("-----------------------------\n");
    printf("Medical Store Management System\n");
    printf("-----------------------------\n");
    do{
        printf("\n1. Add Medicine\n");
        printf("2. Display All Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine Quantity\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: addMedicine(); break;
            case 2: displayMedicines(); break;
            case 3: searchMedicine(); break;
            case 4: updateMedicine(); break;
            case 5: exit(0);
            default: printf("\nInvalid Choice! Try Again.\n");
        }
    } while(1);
    return 0;
}