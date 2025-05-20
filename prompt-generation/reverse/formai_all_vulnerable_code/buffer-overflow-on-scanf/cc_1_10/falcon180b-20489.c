//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ITEMS 100
#define MAX_NAME 50
#define MAX_AMOUNT 100
#define MAX_DATE 20

typedef struct{
    char name[MAX_NAME];
    char date[MAX_DATE];
    float amount;
}item;

void add_item(item *list, int n){
    printf("Enter item name: ");
    scanf("%s", list[n].name);
    printf("Enter item date: ");
    scanf("%s", list[n].date);
    printf("Enter item amount: ");
    scanf("%f", &list[n].amount);
}

void display_item(item list){
    printf("Item name: %s\n", list.name);
    printf("Item date: %s\n", list.date);
    printf("Item amount: %.2f\n", list.amount);
}

void sort_item(item *list, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(strcmp(list[i].date, list[j].date)>0){
                item temp=list[i];
                list[i]=list[j];
                list[j]=temp;
            }
        }
    }
}

int main(){
    item list[MAX_ITEMS];
    int n=0;

    while(n<MAX_ITEMS){
        printf("Enter 1 to add item\n");
        printf("Enter 2 to display items\n");
        printf("Enter 3 to exit\n");
        scanf("%d", &n);

        switch(n){
            case 1:
                printf("Enter number of items: ");
                scanf("%d", &n);
                for(int i=0; i<n; i++){
                    add_item(list, i);
                }
                break;

            case 2:
                sort_item(list, n);
                for(int i=0; i<n; i++){
                    display_item(list[i]);
                }
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}