//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine{
    char name[30];
    int quantity;
    float price;
    char expiry[11];
};
typedef struct medicine Medicine;

int main(){
    int option, index;
    int med_count = 0;
    Medicine* med_list = NULL;

    printf("***Welcome to Medical Store Management System***\n");

    while(1){
        printf("\nMenu:\n");
        printf("1. Add medicine\n");
        printf("2. Remove medicine\n");
        printf("3. Search medicine\n");
        printf("4. Display medicines\n");
        printf("5. Exit\n");

        printf("\nEnter option: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                med_count++;
                if(med_list == NULL){
                    med_list = (Medicine*)malloc(sizeof(Medicine));
                }else{
                    med_list = (Medicine*)realloc(med_list, med_count*sizeof(Medicine));
                }
                printf("\nEnter medicine details:\n");
                printf("Name: ");
                scanf("%s", med_list[med_count-1].name);
                printf("Quantity: ");
                scanf("%d", &med_list[med_count-1].quantity);
                printf("Price: ");
                scanf("%f", &med_list[med_count-1].price);
                printf("Expiry date (dd/mm/yyyy): ");
                scanf("%s", med_list[med_count-1].expiry);
                break;

            case 2:
                printf("\nEnter medicine index to remove: ");
                scanf("%d", &index);
                if(index >= med_count){
                    printf("Invalid index!\n");
                }else{
                    for(int i=index; i<med_count-1; i++){
                        med_list[i] = med_list[i+1];
                    }
                    med_count--;
                    if(med_list == NULL){
                        med_list = (Medicine*)malloc(sizeof(Medicine));
                    }else{
                        med_list = (Medicine*)realloc(med_list, med_count*sizeof(Medicine));
                    }
                    printf("Medicine removed!\n");
                }
                break;

            case 3:
                printf("\nEnter medicine name to search: ");
                char search[30];
                scanf("%s", search);
                int found_flag = 0;
                for(int i=0; i<med_count; i++){
                    if(strcmp(med_list[i].name, search) == 0){
                        printf("Name: %s\n", med_list[i].name);
                        printf("Quantity: %d\n", med_list[i].quantity);
                        printf("Price: %0.2f\n", med_list[i].price);
                        printf("Expiry date: %s\n", med_list[i].expiry);
                        found_flag = 1; 
                        break;
                    }
                }
                if(!found_flag){
                    printf("Medicine not found!\n");
                }
                break;

            case 4:
                printf("\nMedicine List:\n");
                for(int i=0; i<med_count; i++){
                    printf("Index: %d\n", i);
                    printf("Name: %s\n", med_list[i].name);
                    printf("Quantity: %d\n", med_list[i].quantity);
                    printf("Price: %0.2f\n", med_list[i].price);
                    printf("Expiry date: %s\n\n", med_list[i].expiry);
                }
                break;

            case 5:
                printf("Thank you for using Medical Store Management System!\n");
                free(med_list);
                exit(0);

            default:
                printf("Invalid option!\n");
                break;
        }
    }

    return 0;
}