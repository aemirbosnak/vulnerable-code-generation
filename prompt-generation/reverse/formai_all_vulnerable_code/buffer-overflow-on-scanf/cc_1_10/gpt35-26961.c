//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine{
    int code;
    char name[50];
    float price;
    int stock;
};

void menu(){
    printf("============================================\n");
    printf("\t MEDICAL STORE MANAGEMENT SYSTEM\n");
    printf("============================================\n");
    printf(" [1] Add a new medicine\n");
    printf(" [2] Remove a medicine\n");
    printf(" [3] Update medicine information\n");
    printf(" [4] Display all medicines\n");
    printf(" [5] Generate sales report\n");
    printf(" [6] Generate inventory report\n");
    printf(" [7] Exit\n");
    printf("============================================\n");
}

void add_medicine(struct medicine *medicines, int *count){
    printf("Enter the medicine code: ");
    scanf("%d", &medicines[*count].code);
    printf("Enter the medicine name: ");
    scanf("%s", &medicines[*count].name);
    printf("Enter the medicine price: ");
    scanf("%f", &medicines[*count].price);
    printf("Enter the medicine stock: ");
    scanf("%d", &medicines[*count].stock);
    (*count)++;
}

void remove_medicine(struct medicine *medicines, int *count){
    int code, i, j;
    printf("Enter the medicine code: ");
    scanf("%d", &code);
    for(i=0; i<*count; i++){
        if(medicines[i].code == code){
            for(j=i; j<*count-1; j++){
                medicines[j] = medicines[j+1];
            }
            (*count)--;
            printf("Medicine removed successfully.\n");
            return;
        }
    }
    printf("Medicine not found.\n");
}

void update_medicine(struct medicine *medicines, int count){
    int code, i;
    printf("Enter the medicine code: ");
    scanf("%d", &code);
    for(i=0; i<count; i++){
        if(medicines[i].code == code){
            printf("Enter new price: ");
            scanf("%f", &medicines[i].price);
            printf("Enter new stock: ");
            scanf("%d", &medicines[i].stock);
            return;
        }
    }
    printf("Medicine not found.\n");
}

void display_medicines(struct medicine *medicines, int count){
    int i;
    printf("CODE\tNAME\t\tPRICE\tSTOCK\n");
    for(i=0; i<count; i++){
        printf("%d\t%s\t\t%.2f\t%d\n", medicines[i].code, medicines[i].name, medicines[i].price, medicines[i].stock);
    }
}

void generate_sales_report(struct medicine *medicines, int count){
    int i;
    float sales = 0;
    for(i=0; i<count; i++){
        sales += (medicines[i].price * medicines[i].stock);
    }
    printf("Total sales: %.2f\n", sales);
}

void generate_inventory_report(struct medicine *medicines, int count){
    int i, total_stock = 0;
    float total_value = 0;
    printf("CODE\tNAME\t\tPRICE\tSTOCK\tVALUE\n");
    for(i=0; i<count; i++){
        total_stock += medicines[i].stock;
        total_value += (medicines[i].price * medicines[i].stock);
        printf("%d\t%s\t\t%.2f\t%d\t%.2f\n", medicines[i].code, medicines[i].name, medicines[i].price, medicines[i].stock, (medicines[i].price * medicines[i].stock));
    }
    printf("Total stock: %d\n", total_stock);
    printf("Total value: %.2f\n", total_value);
}

int main(){
    struct medicine medicines[100];
    int count = 0, choice;
    while(1){
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: add_medicine(medicines, &count); break;
            case 2: remove_medicine(medicines, &count); break;
            case 3: update_medicine(medicines, count); break;
            case 4: display_medicines(medicines, count); break;
            case 5: generate_sales_report(medicines, count); break;
            case 6: generate_inventory_report(medicines, count); break;
            case 7: exit(0); break;
            default: printf("Invalid choice.\n"); break;
        }
    }
    return 0;
}