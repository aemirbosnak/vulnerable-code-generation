//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine{
    char name[50];
    float price;
    int stock;
};

void addMedicine(struct Medicine* m_list, int* m_count){
    printf("\nEnter the medicine name: ");
    scanf("%s", m_list[*m_count].name);
    printf("Enter the medicine price: ");
    scanf("%f", &m_list[*m_count].price);
    printf("Enter the medicine stock: ");
    scanf("%d", &m_list[*m_count].stock);
    (*m_count)++;
    printf("Medicine added successfully!\n");
}

void displayMedicines(struct Medicine* m_list, int* m_count){
    printf("\nMedicines available in the store:\n");
    printf("---------------------------------\n");
    printf("|   Name\t\t|   Price\t|   Stock\t|\n");
    printf("---------------------------------\n");
    for(int i=0; i<*m_count; i++){
        printf("|   %s\t", m_list[i].name);
        printf("\t|   %.2f\t", m_list[i].price);
        printf("\t|   %d\t", m_list[i].stock);
        printf("\t|\n");
    }
    printf("---------------------------------\n");
}

void searchMedicine(struct Medicine* m_list, int* m_count){
    char m_name[50];
    printf("\nEnter the medicine name to search: ");
    scanf("%s", m_name);
    int found = 0;
    for(int i=0; i<*m_count; i++){
        if(strcmp(m_list[i].name, m_name) == 0){
            printf("\nThe medicine is available in the stock: %d\n", m_list[i].stock);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("\nThe medicine is not available in the stock.\n");
    }
}

void sellMedicine(struct Medicine* m_list, int* m_count){
    char m_name[50];
    int quantity;
    printf("\nEnter the medicine name to sell: ");
    scanf("%s", m_name);
    int found = 0;
    for(int i=0; i<*m_count; i++){
        if(strcmp(m_list[i].name, m_name) == 0){
            printf("Enter the quantity to sell: ");
            scanf("%d", &quantity);
            if(quantity > m_list[i].stock){
                printf("\nInsufficient stock!\n");
                break;
            }
            m_list[i].stock -= quantity;
            printf("\nMedicine sold successfully!\n");
            found = 1;
            break;
        }
    }
    if(!found){
        printf("\nThe medicine is not available in the stock.\n");
    }
}

void deleteMedicine(struct Medicine* m_list, int* m_count){
    char m_name[50];
    printf("\nEnter the medicine name to delete: ");
    scanf("%s", m_name);
    int found = 0;
    for(int i=0; i<*m_count; i++){
        if(strcmp(m_list[i].name, m_name) == 0){
            for(int j=i; j<*m_count-1; j++){
                m_list[j] = m_list[j+1];
            }
            (*m_count)--;
            printf("\nMedicine deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if(!found){
        printf("\nThe medicine is not available in the stock.\n");
    }
}

int main(){
    int choice, m_count = 0;
    struct Medicine m_list[100];

    do{
        printf("\nC Medical Store Management System\n");
        printf("----------------------------------\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Sell Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addMedicine(m_list, &m_count);
                break;
            case 2:
                displayMedicines(m_list, &m_count);
                break;
            case 3:
                searchMedicine(m_list, &m_count);
                break;
            case 4:
                sellMedicine(m_list, &m_count);
                break;
            case 5:
                deleteMedicine(m_list, &m_count);
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid Choice! Try Again.\n");
        }
    }while(1);

    return 0;
}