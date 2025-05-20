//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct medicine {
    char name[50];
    int price;
    int quantity;
};

void main() {
    int choice,i;
    FILE *fp;
    struct medicine m[MAX];

    system("clear");

    printf("\n\n\t\tWELCOME TO MEDICAL STORE MANAGEMENT SYSTEM\n");
    printf("\n\t1.Add Medicine\n");
    printf("\t2.Update Medicine\n");
    printf("\t3.Delete Medicine\n");
    printf("\t4.Display Medicine\n");
    printf("\t5.Search Medicine\n");
    printf("\t6.Exit\n");

    while(1) {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("\nEnter name of medicine: ");
                scanf("%s",m[i].name);
                printf("Enter price of medicine: ");
                scanf("%d",&m[i].price);
                printf("Enter quantity of medicine: ");
                scanf("%d",&m[i].quantity);
                i++;
                break;

            case 2:
                printf("\nEnter the name of medicine to be updated: ");
                scanf("%s",m[i].name);
                printf("Enter new price of medicine: ");
                scanf("%d",&m[i].price);
                printf("Enter new quantity of medicine: ");
                scanf("%d",&m[i].quantity);
                break;

            case 3:
                printf("\nEnter the name of medicine to be deleted: ");
                scanf("%s",m[i].name);
                for(int j=i-1;j>=0;j--) {
                    strcpy(m[j].name,m[j+1].name);
                    m[j].price=m[j+1].price;
                    m[j].quantity=m[j+1].quantity;
                }
                i--;
                break;

            case 4:
                printf("\nName\tPrice\tQuantity\n");
                for(int j=0;j<=i-1;j++) {
                    printf("%s\t%d\t%d\n",m[j].name,m[j].price,m[j].quantity);
                }
                break;

            case 5:
                printf("\nEnter the name of medicine to be searched: ");
                scanf("%s",m[i].name);
                for(int j=0;j<=i-1;j++) {
                    if(strcmp(m[j].name,m[i].name)==0) {
                        printf("\nName: %s\nPrice: %d\nQuantity: %d",m[j].name,m[j].price,m[j].quantity);
                        break;
                    }
                }
                break;

            case 6:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    }
}