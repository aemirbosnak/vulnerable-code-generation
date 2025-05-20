//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine{
    char name[20];
    int stock;
    float price;
};

void addMedicine(struct medicine *med, int count){
    printf("Enter the name of medicine: ");
    scanf("%s", med[count].name);
    printf("Enter the stock of medicine: ");
    scanf("%d", &med[count].stock);
    printf("Enter the price of medicine: ");
    scanf("%f", &med[count].price);
    printf("Medicine Added Successfully!");
}

void removeMedicine(struct medicine *med, int count){
    char name[20];
    int i, flag = 0;
    printf("Enter the name of medicine to remove: ");
    scanf("%s", name);
    for(i = 0; i < count; i++){
        if(strcmp(med[i].name, name) == 0){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        for(int j = i; j < count-1; j++){
            med[j] = med[j+1];
        }
        printf("%s removed successfully!", name);
    }
    else{
        printf("Medicine not found!");
    }
}

void displayMedicine(struct medicine *med, int count){
    printf("Medicine | Stock | Price\n");
    for(int i = 0; i < count; i++){
        printf("%s | %d | %.2f\n", med[i].name, med[i].stock, med[i].price);
    }
}

int main(){
    int choice, count = 0, i;
    struct medicine *med = malloc(sizeof(struct medicine));
    while(1){
        printf("\n**** MEDICAL STORE MANAGEMENT SYSTEM ****\n");
        printf("1. Add Medicine\n");
        printf("2. Remove Medicine\n");
        printf("3. Display Medicine\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: // Add medicine
                count++;
                med = realloc(med, count * sizeof(struct medicine));
                addMedicine(med, count-1);
                break;
            case 2: // Remove medicine
                removeMedicine(med, count);
                count--;
                med = realloc(med, count * sizeof(struct medicine));
                break;
            case 3: // Display medicine
                displayMedicine(med, count);
                break;
            case 4: // Exit
                free(med);
                exit(0);
            default:
                printf("Invalid Choice!");
        }
    }
    return 0;
}