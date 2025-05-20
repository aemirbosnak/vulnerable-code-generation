//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: satisfied
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct medicine{
    int id;
    char name[20];
    int quantity;
    float price;
};

void addMedicine(struct medicine *med, int size);
void viewMedicine(struct medicine *med, int size);
void searchMedicine(struct medicine *med, int size);
void deleteMedicine(struct medicine *med, int *size);

int main(){
    int choice, size = 0;
    struct medicine *med = NULL;
    do{
        printf("\nMedical Store Management System\n");
        printf("1. Add new medicine\n");
        printf("2. View all medicine\n");
        printf("3. Search medicine\n");
        printf("4. Delete medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addMedicine(med, size);
                size++;
                break;
            case 2:
                viewMedicine(med, size);
                break;
            case 3:
                searchMedicine(med, size);
                break;
            case 4:
                deleteMedicine(med, &size);
                break;
            case 5:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice, please enter a valid choice.");
        }

    }while(choice != 5);

    return 0;
}

void addMedicine(struct medicine *med, int size){
    printf("Enter medicine id: ");
    scanf("%d", &med[size].id);
    printf("Enter medicine name: ");
    scanf("%s", med[size].name);
    printf("Enter medicine quantity: ");
    scanf("%d", &med[size].quantity);
    printf("Enter medicine price: ");
    scanf("%f", &med[size].price);
}

void viewMedicine(struct medicine *med, int size){
    printf("ID\tNAME\tQUANTITY\tPRICE\n");
    for(int i=0; i<size; i++){
        printf("%d\t%s\t%d\t\t%.2f\n", med[i].id, med[i].name, med[i].quantity, med[i].price);
    }
}

void searchMedicine(struct medicine *med, int size){
    int id, flag = 0;
    printf("Enter medicine id: ");
    scanf("%d", &id);
    for(int i=0; i<size; i++){
        if(med[i].id == id){
            printf("ID\tNAME\tQUANTITY\tPRICE\n");
            printf("%d\t%s\t%d\t\t%.2f\n", med[i].id, med[i].name, med[i].quantity, med[i].price);
            flag = 1;
        }
    }
    if(flag == 0){
        printf("Medicine not found.\n");
    }
}

void deleteMedicine(struct medicine *med, int *size){
    int id, flag = 0;
    printf("Enter medicine id to delete: ");
    scanf("%d", &id);
    for(int i=0; i<*size; i++){
        if(med[i].id == id){
            for(int j=i; j<*size-1; j++){
                med[j] = med[j+1];
            }
            (*size)--;
            printf("Medicine deleted successfully.\n");
            flag = 1;
        }
    }
    if(flag == 0){
        printf("Medicine not found.\n");
    }
}