//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: secure
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

struct Medical_Store {
    int med_id;
    char med_name[50];
    int quantity;
    float unit_price;
}med[MAX];

void add_med(int med_count){
    printf("Enter Medicine Details\n");
    printf("Medicine ID :");
    scanf("%d",&med[med_count].med_id);
    printf("Medicine Name :");
    scanf("%s",med[med_count].med_name);
    printf("Quantity :");
    scanf("%d",&med[med_count].quantity);
    printf("Unit Price :");
    scanf("%f",&med[med_count].unit_price);
}

void display_med(int med_count){
    printf("ID\tName\tQty\tPrice\n");
    for(int i=0;i<med_count;i++){
        printf("%d\t%s\t%d\t%.2f\n",med[i].med_id,med[i].med_name,med[i].quantity,med[i].unit_price);
    }
}

void search_med(int med_count){
    char name[50];
    int flag=0;
    printf("Enter Medicine Name :");
    scanf("%s",name);
    for(int i=0;i<med_count;i++){
        if(strcmp(name,med[i].med_name)==0){
            printf("ID\tName\tQty\tPrice\n");
            printf("%d\t%s\t%d\t%.2f\n",med[i].med_id,med[i].med_name,med[i].quantity,med[i].unit_price);
            flag=1;
        }
    }
    if(!flag){
        printf("Medicine not found!!\n");
    }
}

void update_med(int med_count){
    int id,flag=0;
    printf("Enter Medicine ID :");
    scanf("%d",&id);
    for(int i=0;i<med_count;i++){
        if(id==med[i].med_id){
            flag=1;
            printf("Enter New Quantity :");
            scanf("%d",&med[i].quantity);
            printf("Enter New Unit Price :");
            scanf("%f",&med[i].unit_price);
            printf("Details updated successfully!!\n");
        }
    }
    if(!flag){
        printf("Medicine not found!!\n");
    }
}

int main(){
    int choice,med_count=0;
    while(1){
        printf("\nMedical Store Management System\n");
        printf("1.Display Medicines\n2.Add Medicines\n3.Search Medicine\n4.Update Medicine Details\n5.Exit\n");
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                display_med(med_count);
                break;
            case 2:
                add_med(med_count);
                med_count++;
                break;
            case 3:
                search_med(med_count);
                break;
            case 4:
                update_med(med_count);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid Choice!!");
        }
    }
    return 0;
}