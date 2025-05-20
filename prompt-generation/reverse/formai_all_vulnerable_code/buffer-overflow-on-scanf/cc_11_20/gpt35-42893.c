//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine{
    char name[50];
    int id;
    char company[50];
    float price;
};

int main(){
    int size, choice, id, flag, update_choice, update_id;
    struct medicine med[100];
    printf("Enter the number of medicines you want to store: ");
    scanf("%d", &size);
    for(int i = 0; i < size; i++){
        printf("Enter the details of medicine %d:  \n", i+1);
        printf("Name: ");
        scanf("%s", med[i].name);
        printf("ID: ");
        scanf("%d", &med[i].id);
        printf("Company: ");
        scanf("%s", med[i].company);
        printf("Price: ");
        scanf("%f", &med[i].price);
    }
    do{
        flag = 0;
        printf("\nEnter:\n1 - To display all medicines\n2 - To search for a medicine\n3 - To update the price of a medicine\n4 - To exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nDetails of all medicines: \n");
                for(int i = 0; i < size; i++){
                    printf("Name: %s\t ID: %d\t Company: %s\t Price: %.2f\n", med[i].name, med[i].id, med[i].company, med[i].price);
                }
                break;
            case 2:
                printf("\nEnter the ID of the medicine you want to search: ");
                scanf("%d", &id);
                for(int i = 0; i < size; i++){
                    if(med[i].id == id){
                        printf("\nDetails of medicine %d:\n", id);
                        printf("Name: %s\t ID: %d\t Company: %s\t Price: %.2f\n", med[i].name, med[i].id, med[i].company, med[i].price);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    printf("There is no medicine with ID %d\n", id);
                }
                break;
            case 3:
                printf("\nEnter the ID of the medicine you want to update: ");
                scanf("%d", &update_id);
                for(int i = 0; i < size; i++){
                    if(med[i].id == update_id){
                        printf("\nEnter the new price for medicine %d: ", update_id);
                        scanf("%f", &med[i].price);
                        printf("\nPrice of medicine %d has been updated successfully.\n", update_id);
                        flag = 1;
                        break;
                      }
                }
                if(flag == 0){
                    printf("There is no medicine with ID %d\n", update_id);
                }
                break;
            case 4:
                printf("\nThank you for using the Medical Store Management System.\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Try Again.\n");
                break;
        }
    }while(choice != 4);
    return 0;
}