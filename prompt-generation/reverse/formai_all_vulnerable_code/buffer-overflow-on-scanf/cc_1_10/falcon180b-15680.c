//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

typedef struct {
    char name[50];
    char type[50];
    int quantity;
    double price;
    double total_cost;
} medicine;

int search(medicine arr[], char name[], int n) {
    int i;
    for(i=0;i<n;i++) {
        if(strcmp(arr[i].name,name)==0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int choice,i,j,n,m;
    char ch;
    medicine arr[100];
    printf("Enter the number of medicines: ");
    scanf("%d",&n);
    printf("Enter the details of each medicine:\n");
    for(i=0;i<n;i++) {
        printf("Enter medicine name: ");
        scanf("%s",arr[i].name);
        printf("Enter medicine type: ");
        scanf("%s",arr[i].type);
        printf("Enter quantity: ");
        scanf("%d",&arr[i].quantity);
        printf("Enter price: ");
        scanf("%lf",&arr[i].price);
        arr[i].total_cost=arr[i].price*arr[i].quantity;
    }
    while(1) {
        printf("\n1.Display all medicines\n2.Search a medicine\n3.Exit\n");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("\nName\tType\tQuantity\tPrice\tTotal Cost\n");
                for(i=0;i<n;i++) {
                    printf("%s\t%s\t%d\t%.2lf\t%.2lf\n",arr[i].name,arr[i].type,arr[i].quantity,arr[i].price,arr[i].total_cost);
                }
                break;
            case 2:
                printf("\nEnter medicine name to search: ");
                scanf("%s",ch);
                m=search(arr,ch,n);
                if(m==-1) {
                    printf("\nMedicine not found!");
                }
                else {
                    printf("\nName\tType\tQuantity\tPrice\tTotal Cost\n");
                    printf("%s\t%s\t%d\t%.2lf\t%.2lf\n",arr[m].name,arr[m].type,arr[m].quantity,arr[m].price,arr[m].total_cost);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }
    return 0;
}