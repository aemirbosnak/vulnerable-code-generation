//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: relaxed
#include<stdio.h>
struct medicine{
    char name[100];
    int quantity;
    float price;
};
void addMedicine(struct medicine[100],int);
void removeMedicine(struct medicine[100],int);
void displayMedicine(struct medicine[100],int);
void searchMedicine(struct medicine[100],int);
void displayMenu();
int count=0;
int main(){
    struct medicine stock[100];
    int choice;
    while(1){
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                addMedicine(stock,count);
                count++;
                break;
            case 2:
                removeMedicine(stock,count);
                count--;
                break;
            case 3:
                displayMedicine(stock,count);
                break;
            case 4:
                searchMedicine(stock,count);
                break;
            case 5:
                printf("\nExiting program...\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}
void displayMenu(){
    printf("\nWelcome to our Medical Store Management System!\n");
    printf("1. Add Medicine\n");
    printf("2. Remove Medicine\n");
    printf("3. Display All Medicines\n");
    printf("4. Search for a Medicine\n");
    printf("5. Exit\n");
}
void addMedicine(struct medicine stock[100],int count){
    printf("\nAdding Medicine...\n");
    printf("Enter Medicine Name: ");
    scanf("%s",stock[count].name);
    printf("Enter Medicine Quantity: ");
    scanf("%d",&stock[count].quantity);
    printf("Enter Medicine Price: ");
    scanf("%f",&stock[count].price);
    printf("\nMedicine Successfuly Added!\n");
}
void removeMedicine(struct medicine stock[100],int count){
    char name[100];
    int i,j,found=0;
    printf("\nRemoving Medicine...\n");
    printf("Enter Medicine Name: ");
    scanf("%s",name);
    for(i=0;i<count;i++){
        if(strcmp(name,stock[i].name)==0){
            found=1;
            for(j=i;j<count-1;j++){
                stock[j]=stock[j+1];
            }
            printf("\nMedicine Successfuly Removed!\n");
            break;
        }
    }
    if(found==0){
        printf("\nMedicine not found!\n");
    }
}
void displayMedicine(struct medicine stock[100],int count){
    int i;
    printf("\nDisplaying Medicine...\n");
    printf("\n%-20s %-10s %-10s\n","Medicine Name","Quantity","Price");
    for(i=0;i<count;i++){
        printf("%-20s %-10d %-10.2f\n",stock[i].name,stock[i].quantity,stock[i].price);
    }
}
void searchMedicine(struct medicine stock[100],int count){
    char name[100];
    int i,found=0;
    printf("\nSearching for Medicine...\n");
    printf("Enter Medicine Name: ");
    scanf("%s",name);
    for(i=0;i<count;i++){
        if(strcmp(name,stock[i].name)==0){
            found=1;
            printf("\n%-20s %-10s %-10s\n","Medicine Name","Quantity","Price");
            printf("%-20s %-10d %-10.2f\n",stock[i].name,stock[i].quantity,stock[i].price);
            break;
        }
    }
    if(found==0){
        printf("\nMedicine not found!\n");
    }
}