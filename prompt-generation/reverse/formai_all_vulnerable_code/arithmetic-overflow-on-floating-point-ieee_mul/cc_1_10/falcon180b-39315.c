//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct {
    char name[50];
    char item[50];
    int quantity;
    float price;
    float amount;
}item;

int main() {
    FILE *fp;
    int n,i,j,choice;
    char ch;
    item bill[100];
    float total=0;
    printf("Enter number of items:\n");
    scanf("%d",&n);
    printf("Enter items:\n");
    for(i=0;i<n;i++) {
        bill[i].name[0]='\0';
        bill[i].item[0]='\0';
        printf("Enter name of item %d:\n",i+1);
        scanf("%s",bill[i].name);
        printf("Enter item name %d:\n",i+1);
        scanf("%s",bill[i].item);
        printf("Enter quantity of item %d:\n",i+1);
        scanf("%d",&bill[i].quantity);
        printf("Enter price of item %d:\n",i+1);
        scanf("%f",&bill[i].price);
        total+=(bill[i].quantity*bill[i].price);
        bill[i].amount=bill[i].quantity*bill[i].price;
    }
    printf("Total amount: %.2f\n",total);
    printf("Bill:\n");
    for(i=0;i<n;i++) {
        printf("%s - %s - %d - %.2f - %.2f\n",bill[i].name,bill[i].item,bill[i].quantity,bill[i].price,bill[i].amount);
    }
    printf("Press 1 to save bill in a text file.\n");
    scanf("%d",&choice);
    if(choice==1) {
        fp=fopen("bill.txt","w");
        if(fp==NULL) {
            printf("Error in opening file.\n");
            exit(0);
        }
        fprintf(fp,"Total amount: %.2f\n",total);
        fprintf(fp,"Bill:\n");
        for(i=0;i<n;i++) {
            fprintf(fp,"%s - %s - %d - %.2f - %.2f\n",bill[i].name,bill[i].item,bill[i].quantity,bill[i].price,bill[i].amount);
        }
        fprintf(fp,"\nThank you for visiting our cafe.\n");
        fclose(fp);
        printf("Bill saved in bill.txt.\n");
    }
    return 0;
}