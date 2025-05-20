//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100 // maximum number of medicines in the store
struct medicines{
    int code;
    char name[50];
    int price;
    int quantity;
};

struct medicines med[SIZE];
int count = 0; // total number of medicines in store

// function to add new medicine to store
void add_medicine(){
    printf("\n *****ADDING NEW MEDICINE*****");
    printf("\nEnter Code of the medicine: ");
    scanf("%d",&med[count].code);
    printf("\nEnter Name of the medicine: ");
    scanf("%s",med[count].name);
    printf("\nEnter Price of the medicine: ");
    scanf("%d",&med[count].price);
    printf("\nEnter Quantity of the medicine: ");
    scanf("%d",&med[count].quantity);
    count++;
    printf("\nMedicine added successfully!");
}
// function to display all medicines
void display_all(){
    printf("\n*****ALL MEDICINES*****\n");
    printf("Code\tName\tPrice\tQuantity\n");
    for(int i=0;i<count;i++){
        printf("%d\t%s\t%d\t%d\n",med[i].code,med[i].name,med[i].price,med[i].quantity);
    }
}
// function to search medicine by code
void search_medicine(){
    int code,i;
    printf("\nEnter code of the medicine: ");
    scanf("%d",&code);
    for(i=0;i<count;i++){
        if(med[i].code == code){
            printf("\n Found Medicine \n");
            printf("Code\tName\tPrice\tQuantity\n");
            printf("%d\t%s\t%d\t%d\n",med[i].code,med[i].name,med[i].price,med[i].quantity);
            break;
        }
    }
    if(i>=count) printf("Medicine not found!");
}

int main(){
    while(1){
        printf("\n***** MEDICAL STORE MANAGEMENT SYSTEM *****");
        printf("\n1. Add New Medicine\n2. Display All Medicines\n3. Search for a Medicine\n4. Exit");
        printf("\nEnter Your Choice: ");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1: add_medicine();break;
            case 2: display_all();break;
            case 3: search_medicine();break;
            case 4: exit(0);
            default: printf("\nInvalid Choice, Please try again!");
        }
    }
    return 0;
}