//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Structures for Medical Store Management System
struct medicine{
    char name[50];
    int price;
    int quantity;
};
struct customer{
    char name[50];
    int age;
    char gender[10];
    char address[100];
    int contact;
};
struct purchase{
    struct medicine med;
    struct customer cust;
    int date;
    int time;
};
//Functions for Medical Store Management System
void addMedicine(){
    FILE *fp;
    fp=fopen("medicine.txt","ab");
    struct medicine med;
    printf("Enter medicine name: ");
    scanf("%s",med.name);
    printf("Enter medicine price: ");
    scanf("%d",&med.price);
    printf("Enter medicine quantity: ");
    scanf("%d",&med.quantity);
    fwrite(&med,sizeof(med),1,fp);
    fclose(fp);
}
void displayMedicine(){
    FILE *fp;
    fp=fopen("medicine.txt","rb");
    struct medicine med;
    while(fread(&med,sizeof(med),1,fp)==1){
        printf("\nName: %s\nPrice: %d\nQuantity: %d\n",med.name,med.price,med.quantity);
    }
    fclose(fp);
}
void purchaseMedicine(){
    FILE *fp;
    fp=fopen("purchase.txt","ab");
    struct purchase pur;
    printf("Enter customer name: ");
    scanf("%s",pur.cust.name);
    printf("Enter customer age: ");
    scanf("%d",&pur.cust.age);
    printf("Enter customer gender: ");
    scanf("%s",pur.cust.gender);
    printf("Enter customer address: ");
    scanf("%s",pur.cust.address);
    printf("Enter customer contact: ");
    scanf("%d",&pur.cust.contact);
    printf("Enter medicine name: ");
    scanf("%s",pur.med.name);
    pur.med.price=0;
    pur.med.quantity=0;
    fwrite(&pur,sizeof(pur),1,fp);
    fclose(fp);
}
void displayPurchase(){
    FILE *fp;
    fp=fopen("purchase.txt","rb");
    struct purchase pur;
    while(fread(&pur,sizeof(pur),1,fp)==1){
        printf("\nCustomer Name: %s\nAge: %d\nGender: %s\nAddress: %s\nContact: %d\n",pur.cust.name,pur.cust.age,pur.cust.gender,pur.cust.address,pur.cust.contact);
        printf("Medicine Name: %s\nPrice: %d\nQuantity: %d\n",pur.med.name,pur.med.price,pur.med.quantity);
        printf("\nDate: %d-%d-%d\nTime: %d:%d:%d\n",pur.date/10000,pur.date%10000/100,pur.date%100,pur.time/10000,pur.time%10000/100,pur.time%100);
    }
    fclose(fp);
}
int main(){
    int choice;
    while(1){
        printf("\n1.Add Medicine\n2.Display Medicine\n3.Purchase Medicine\n4.Display Purchase\n5.Exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                addMedicine();
                break;
            case 2:
                displayMedicine();
                break;
            case 3:
                purchaseMedicine();
                break;
            case 4:
                displayPurchase();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!");
        }
    }
    return 0;
}