//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct{
    char med_name[MAX];
    int med_qty;
    float price;
}Medicine;

Medicine med_list[MAX];
int med_count = 0;

void add_med(){
    if(med_count >= MAX){
        printf("Store capacity is full.\n");
        return;
    }
    printf("Enter medicine name: ");
    scanf("%s", med_list[med_count].med_name);
    printf("Enter medicine quantity: ");
    scanf("%d", &med_list[med_count].med_qty);
    printf("Enter medicine price: ");
    scanf("%f", &med_list[med_count].price);
    med_count++;
    printf("Medicine added successfully.\n");
}

void update_med(char* med_name){
    int i, flag = 0;
    for(i=0; i<med_count; i++){
        if(strcmp(med_list[i].med_name, med_name) == 0){
            printf("Enter updated quantity: ");
            scanf("%d", &med_list[i].med_qty);
            printf("Enter updated price: ");
            scanf("%f", &med_list[i].price);
            flag = 1;
            printf("Medicine updated successfully.\n");
            break;
        }
    }
    if(flag == 0){
        printf("Medicine not found.\n");
    }
}

void delete_med(char* med_name){
    int i, flag = 0;
    for(i=0; i<med_count; i++){
        if(strcmp(med_list[i].med_name, med_name) == 0){
            int j;
            for(j=i; j<med_count; j++){
                med_list[j] = med_list[j+1];
            }
            med_count--;
            flag = 1;
            printf("Medicine deleted successfully.\n");
            break;
        }
    }
    if(flag == 0){
        printf("Medicine not found.\n");
    }
}

void search_med(char* med_name){
    int i, flag = 0;
    printf("\nMedicine Name\t|Quantity\t|Price\n");
    printf("-----------------------------------------------------\n");
    for(i=0; i<med_count; i++){
        if(strcmp(med_list[i].med_name, med_name) == 0){
            printf("%s\t\t|%d\t\t|%.2f\n", med_list[i].med_name, med_list[i].med_qty, med_list[i].price);
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Medicine not found.\n");
    }
}

void display_med(){
    int i;
    printf("\nMedicine Name\t|Quantity\t|Price\n");
    printf("-----------------------------------------------------\n");
    for(i=0; i<med_count; i++){
        printf("%s\t\t|%d\t\t|%.2f\n", med_list[i].med_name, med_list[i].med_qty, med_list[i].price);
    }
}

void menu(){
    printf("\n----------------Medical Store Management System----------------\n\n");
    printf("1. Add medicine\n");
    printf("2. Update medicine\n");
    printf("3. Delete medicine\n");
    printf("4. Search medicine\n");
    printf("5. Display medicines\n");
    printf("6. Exit\n");
    printf("Enter an option: ");
}

int main(){
    int option;
    do{
        menu();
        scanf("%d", &option);
        switch(option){
            case 1:{
                add_med();
                break;
            }
            case 2:{
                char med_name[MAX];
                printf("Enter medicine name to update: ");
                scanf("%s", med_name);
                update_med(med_name);
                break;
            }
            case 3:{
                char med_name[MAX];
                printf("Enter medicine name to delete: ");
                scanf("%s", med_name);
                delete_med(med_name);
                break;
            }
            case 4:{
                char med_name[MAX];
                printf("Enter medicine name to search: ");
                scanf("%s", med_name);
                search_med(med_name);
                break;
            }
            case 5:{
                display_med();
                break;
            }
            case 6:{
                printf("Thank you for using Medical Store Management System.\n");
                break;
            }
            default:{
                printf("Invalid option.\n");
            }
        }
    }while(option != 6);
    return 0;
}