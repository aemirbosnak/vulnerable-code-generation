//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

struct medicine{
    char name[MAX];
    int quantity;
    float price;
};

struct medicine store[MAX];
int count=0;

void addMedicine(){
    struct medicine m;
    printf("\nEnter the name of the medicine: ");
    scanf("%s", m.name);
    printf("Enter the quantity: ");
    scanf("%d", &m.quantity);
    printf("Enter the price: ");
    scanf("%f", &m.price);

    store[count] = m;
    count++;

    printf("\nMedicine Added Successfully!\n");
}

void displayMedicines(){
    printf("\nList of Medicines:\n");
    printf("Name\tQuantity\tPrice\n");
    for(int i=0; i<count; i++){
        printf("%s\t%d\t\t%.2f\n", store[i].name, store[i].quantity, store[i].price);
    }
}

void searchMedicine(){
    char search_name[MAX];
    printf("\nEnter the name of the medicine: ");
    scanf("%s", search_name);
    int found = 0;

    for(int i=0; i<count; i++){
        if(strcmp(search_name,store[i].name) == 0){
            found = 1;
            printf("\n%s\t%d\t\t%.2f\n", store[i].name, store[i].quantity, store[i].price);
            break;
        }
    }
    if(!found){
        printf("\nOops! Medicine not found!\n");
    }
}

void deleteMedicine(){
    char delete_name[MAX];
    printf("\nEnter the name of the medicine: ");
    scanf("%s", delete_name);
    int found = 0;

    for(int i=0; i<count; i++){
        if(strcmp(delete_name,store[i].name) == 0){
            found = 1;
            for(int j=i; j<count-1; j++){
                store[j] = store[j+1];
            }
            count--;
            printf("\nMedicine Deleted Successfully!\n");
            break;
        }
    }
    if(!found){
        printf("\nOops! Medicine not found!\n");
    }
}

void options(){
    printf("\n------------------------------\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Search for a Medicine\n");
    printf("4. Delete a Medicine\n");
    printf("5. Exit\n");
    printf("------------------------------\n");
    printf("\nEnter your choice: ");
}

int main(){
    int choice;
    while(1){
        options();
        scanf("%d", &choice);
        switch(choice){
            case 1: addMedicine(); break;
            case 2: displayMedicines(); break;
            case 3: searchMedicine(); break;
            case 4: deleteMedicine(); break;
            case 5: exit(0);
            default: printf("\nPlease enter a valid choice!\n"); 
        }
    }
    return 0;
}