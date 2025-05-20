//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: mathematical
#include<stdio.h>

struct medicine{
    char name[50];
    int quantity;
    float price;
};

struct medicine stock[100];
int count=0;

void addMedicine(){
    printf("\nEnter medicine details:\n");
    printf("Name: ");
    scanf("%s", stock[count].name);
    printf("Quantity: ");
    scanf("%d", &stock[count].quantity);
    printf("Price: ");
    scanf("%f", &stock[count].price);
    printf("\nMedicine added successfully.\n");
    count++;
}

void displayMedicine(){
    if(count==0){
        printf("\nNo medicine in stock.\n");
    }else{
        printf("\nMedicine in stock:\n");
        for(int i=0; i<count; i++){
            printf("Name: %s\n", stock[i].name);
            printf("Quantity: %d\n", stock[i].quantity);
            printf("Price: %.2f\n\n", stock[i].price);
        }
    }
}

void searchMedicine(){
    char name[50];
    printf("\nEnter name of medicine to search: ");
    scanf("%s", name);
    int found=0;
    for(int i=0; i<count; i++){
        if(strcmp(name, stock[i].name)==0){
            printf("\nMedicine found.\n");
            printf("Name: %s\n", stock[i].name);
            printf("Quantity: %d\n", stock[i].quantity);
            printf("Price: %.2f\n", stock[i].price);
            found=1;
            break;
        }
    }
    if(found==0){
        printf("\nMedicine not found.\n");
    }
}

void updateMedicine(){
    char name[50];
    printf("\nEnter name of medicine to update: ");
    scanf("%s", name);
    int found=0;
    for(int i=0; i<count; i++){
        if(strcmp(name, stock[i].name)==0){
            printf("\nEnter updated details:\n");
            printf("Name: ");
            scanf("%s", stock[i].name);
            printf("Quantity: ");
            scanf("%d", &stock[i].quantity);
            printf("Price: ");
            scanf("%f", &stock[i].price);
            printf("\nMedicine updated successfully.\n");
            found=1;
            break;
        }
    }
    if(found==0){
        printf("\nMedicine not found.\n");
    }
}

void deleteMedicine(){
    char name[50];
    printf("\nEnter name of medicine to delete: ");
    scanf("%s", name);
    int found=0;
    for(int i=0; i<count; i++){
        if(strcmp(name, stock[i].name)==0){
            for(int j=i; j<count-1; j++){
                strcpy(stock[j].name, stock[j+1].name);
                stock[j].quantity=stock[j+1].quantity;
                stock[j].price=stock[j+1].price;
            }
            count--;
            printf("\nMedicine deleted successfully.\n");
            found=1;
            break;
        }
    }
    if(found==0){
        printf("\nMedicine not found.\n");
    }
}

int main(){
    int choice;
    printf("\nWelcome to the Medical Store Management System!\n");
    do{
        printf("\nSelect an option:\n");
        printf("1. Add a new medicine\n");
        printf("2. Display all medicine\n");
        printf("3. Search for a medicine\n");
        printf("4. Update a medicine\n");
        printf("5. Delete a medicine\n");
        printf("6. Exit\n");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                addMedicine();
                break;
            case 2:
                displayMedicine();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                updateMedicine();
                break;
            case 5:
                deleteMedicine();
                break;
            case 6:
                printf("\nThank you for using Medical Store Management System!\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    }while(choice!=6);
    
    return 0;
}