//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine{
    int med_id;
    char med_name[20];
    float med_price;
    int med_quantity;
}med[100];

int count = 0;

void add_medicine(){
    printf("\nEnter Medicine ID: ");
    scanf("%d", &med[count].med_id);
    printf("Enter Medicine Name: ");
    scanf("%s", med[count].med_name);
    printf("Enter Medicine Price: ");
    scanf("%f", &med[count].med_price);
    printf("Enter Medicine Quantity: ");
    scanf("%d", &med[count].med_quantity);
    count++;
}

void display_medicine(){
    for(int i=0; i<count; i++){
        printf("Medicine ID: %d\n", med[i].med_id);
        printf("Medicine Name: %s\n", med[i].med_name);
        printf("Medicine Price: %0.2f\n", med[i].med_price);
        printf("Medicine Quantity: %d\n\n", med[i].med_quantity);
    }
}

void search_medicine(){
    int m_id, index=-1;
    printf("\nEnter Medicine ID to Search: ");
    scanf("%d", &m_id);
    for(int i=0; i<count; i++){
        if(med[i].med_id == m_id){
            index = i;
            break;
        }
    }
    if(index != -1){
        printf("Medicine ID: %d\n", med[index].med_id);
        printf("Medicine Name: %s\n", med[index].med_name);
        printf("Medicine Price: %0.2f\n", med[index].med_price);
        printf("Medicine Quantity: %d\n\n", med[index].med_quantity);
    } else {
        printf("Medicine not found in the database.\n");
    }
}

void update_medicine(){
    int m_id, index=-1;
    printf("\nEnter Medicine ID to Update: ");
    scanf("%d", &m_id);
    for(int i=0; i<count; i++){
        if(med[i].med_id == m_id){
            index = i;
            break;
        }
    }
    if(index != -1){
        printf("\nEnter Updated Medicine Name: ");
        scanf("%s", med[index].med_name);
        printf("Enter Updated Medicine Price: ");
        scanf("%f", &med[index].med_price);
        printf("Enter Updated Medicine Quantity: ");
        scanf("%d", &med[index].med_quantity);
        printf("\nMedicine Updated Successfully.\n");
    } else {
        printf("Medicine not found in the database.\n");
    }
}

void delete_medicine(){
    int m_id, index=-1;
    printf("\nEnter Medicine ID to Delete: ");
    scanf("%d", &m_id);
    for(int i=0; i<count; i++){
        if(med[i].med_id == m_id){
            index = i;
            break;
        }
    }
    if(index != -1){
        for(int i=index; i<count-1; i++){
            med[i].med_id = med[i+1].med_id;
            strcpy(med[i].med_name, med[i+1].med_name);
            med[i].med_price = med[i+1].med_price;
            med[i].med_quantity = med[i+1].med_quantity;
        }
        count--;
        printf("\nMedicine Deleted Successfully.\n");
    } else {
        printf("Medicine not found in the database.\n");
    }
}

int main(){
    int choice;
    printf("Welcome to Medical Store Management System!\n\n");
    while(1){
        printf("Select an Option:\n");
        printf("\t1. Add Medicine\n");
        printf("\t2. Display Medicine List\n");
        printf("\t3. Search Medicine\n");
        printf("\t4. Update Medicine Information\n");
        printf("\t5. Delete Medicine from System\n");
        printf("\t6. Exit\n\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_medicine();
                break;
            case 2:
                display_medicine();
                break;
            case 3:
                search_medicine();
                break;
            case 4:
                update_medicine();
                break;
            case 5:
                delete_medicine();
                break;
            case 6:
                printf("\nThank You for Using the System!\n");
                exit(0);
            default:
                printf("Invalid Choice! Please Select a Valid Option.\n");
        }
    }
    return 0;
}