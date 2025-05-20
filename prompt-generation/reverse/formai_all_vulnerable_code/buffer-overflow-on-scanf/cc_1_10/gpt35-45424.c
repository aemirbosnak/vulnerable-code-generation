//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

struct Medicine{
    char name[50];
    int id;
    int quantity;
    float price;
};

void addMedicine(struct Medicine stock[], int index){
    printf("\n Enter Medicine ID: ");
    scanf("%d",&stock[index].id);
    printf("\n Enter Medicine Name: ");
    scanf("%s",stock[index].name);
    printf("\n Enter Medicine Quantity: ");
    scanf("%d",&stock[index].quantity);
    printf("\n Enter Medicine Price: ");
    scanf("%f",&stock[index].price);
    printf("\n Medicine record created successfully");
}

void removeMedicine(struct Medicine stock[], int index){
    if(stock[index].quantity == 0){
        printf("\n Medicine already out of stock \n\n");
    }
    else{
        stock[index].quantity--;
        printf("\n Medicine stock updated successfully");
    }
}

void searchMedicine(struct Medicine stock[], int index){
    printf("\n Medicine ID: %d \n Medicine name: %s \n Medicine quantity: %d \n Medicine price: $%.2f \n\n",stock[index].id, stock[index].name, stock[index].quantity, stock[index].price);
}

int main(){
    int n, option, id, found;
    printf(" Welcome to Medical Store Management System \n\n");
    printf(" Enter number of Medicines in your stock: ");
    scanf("%d",&n);
    struct Medicine stock[n];
    
    for(int i=0; i<n; i++){
        printf("\n Enter details of medicine %d \n", i+1);
        addMedicine(stock, i);
    }
    
    do {
        printf(" Choose an Option: \n\n");
        printf(" [1] - Add Medicine \n [2] - Remove Medicine \n [3] - Search Medicine \n [4] - Exit\n\n");
        scanf("%d",&option);
        
        switch(option){
            case 1:
                addMedicine(stock, n);
                n++;
                break;
            case 2:
                printf("\n Enter Medicine ID to be removed: ");
                scanf("%d",&id);
                found=0;
                
                for(int i=0; i<n; i++){
                    if(stock[i].id == id){
                        found=1;
                        removeMedicine(stock, i);
                    }
                }
                
                if(found==0){
                    printf("\n Medicine not found \n\n");
                }
                break;
            case 3:
                printf("\n Enter Medicine ID to be searched: ");
                scanf("%d",&id);
                found=0;
                
                for(int i=0; i<n; i++){
                    if(stock[i].id == id){
                        found=1;
                        searchMedicine(stock, i);
                    }
                }
                
                if(found==0){
                    printf("\n Medicine not found \n\n");
                }
                break;
            case 4:
                printf("\n Thank you for using Medical Store Management System!");
                exit(0);
            default:
                printf("\n Invalid Option \n\n");
                break;
        }
    }while(option!=4);
    return 0;
}