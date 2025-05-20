//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine{
    char name[30];
    char brand[20];
    int quantity;
    float price;
};

void add_medicine(struct medicine arr[], int *count);
void delete_medicine(struct medicine arr[], int *count);
void search_medicine(struct medicine arr[], int count);
void view_stock(struct medicine arr[], int count);

int main(){
    struct medicine arr[100];
    int choice, count = 0;

    do{
        printf("\n\t-------WELCOME TO THE MEDICAL STORE MANAGEMENT SYSTEM-------\n");
        printf("\nPlease choose an option:\n");
        printf("1. Add a medicine\n");
        printf("2. Delete a medicine\n");
        printf("3. Search for a medicine\n");
        printf("4. View stock\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_medicine(arr, &count);
                break;
            case 2:
                delete_medicine(arr, &count);
                break;
            case 3:
                search_medicine(arr, count);
                break;
            case 4:
                view_stock(arr, count);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }while(choice!=5);

    return 0;
}

void add_medicine(struct medicine arr[], int *count){
    printf("\nEnter the name of the medicine: ");
    getchar();
    fgets(arr[*count].name, 30, stdin);
    arr[*count].name[strcspn(arr[*count].name, "\n")] = '\0';

    printf("Enter the brand name of the medicine: ");
    scanf("%s", arr[*count].brand);

    printf("Enter the quantity of the medicine: ");
    scanf("%d", &arr[*count].quantity);

    printf("Enter the price of the medicine: ");
    scanf("%f", &arr[*count].price);

    printf("\nMedicine added successfully!\n");
    (*count)++;
}

void delete_medicine(struct medicine arr[], int *count){
    char name[30];
    printf("\nEnter the name of the medicine to be deleted: ");
    getchar();
    fgets(name, 30, stdin);
    name[strcspn(name, "\n")] = '\0';

    int found = 0;
    for(int i=0;i<*count;i++){
        if(strcmp(arr[i].name, name)==0){
            found = 1;
            for(int j=i;j<*count-1;j++){
                arr[j] = arr[j+1];
            }
            (*count)--;
            printf("\nMedicine deleted successfully!\n");
            break;
        }
    }
    if(found==0){
        printf("Medicine not found!\n");
    }
}

void search_medicine(struct medicine arr[], int count){
    char name[30];
    printf("\nEnter the name of the medicine to search: ");
    getchar();
    fgets(name, 30, stdin);
    name[strcspn(name, "\n")] = '\0';

    int found = 0;
    for(int i=0;i<count;i++){
        if(strcmp(arr[i].name, name)==0){
            found = 1;
            printf("\nName: %s\n", arr[i].name);
            printf("Brand: %s\n", arr[i].brand);
            printf("Quantity: %d\n", arr[i].quantity);
            printf("Price: %0.2f\n", arr[i].price);
            break;
        }
    }
    if(found==0){
        printf("Medicine not found!\n");
    }
}

void view_stock(struct medicine arr[], int count){
    if(count == 0){
        printf("\nStock is empty!\n");
    }
    else{
        printf("\nStock:\n");
        for(int i=0;i<count;i++){
            printf("%d. Name: %s, Brand: %s, Quantity: %d, Price: %0.2f\n", i+1, arr[i].name, arr[i].brand, arr[i].quantity, arr[i].price);
        }
    }
}