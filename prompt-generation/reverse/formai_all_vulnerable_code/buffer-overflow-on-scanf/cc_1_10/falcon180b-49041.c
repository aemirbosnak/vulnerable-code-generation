//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct medicine{
    char name[50];
    int price;
    int quantity;
};

void addMedicine(struct medicine *m, int n){
    printf("Enter medicine name: ");
    scanf("%s", m[n].name);
    printf("Enter medicine price: ");
    scanf("%d", &m[n].price);
    printf("Enter medicine quantity: ");
    scanf("%d", &m[n].quantity);
}

void displayMedicine(struct medicine m[], int n){
    printf("\nName\tPrice\tQuantity\n");
    for(int i=0; i<n; i++){
        printf("%s\t%d\t%d\n", m[i].name, m[i].price, m[i].quantity);
    }
}

void searchMedicine(struct medicine m[], int n, char name[50]){
    printf("\nEnter medicine name to search: ");
    scanf("%s", name);
    int flag = 0;
    for(int i=0; i<n; i++){
        if(strcmp(m[i].name, name) == 0){
            printf("\nMedicine found!\n");
            printf("Name: %s\n", m[i].name);
            printf("Price: %d\n", m[i].price);
            printf("Quantity: %d\n", m[i].quantity);
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("\nMedicine not found!");
    }
}

void updateMedicine(struct medicine m[], int n){
    printf("\nEnter medicine name to update: ");
    scanf("%s", m[0].name);
    printf("Enter new medicine name: ");
    scanf("%s", m[0].name);
    printf("Enter new medicine price: ");
    scanf("%d", &m[0].price);
    printf("Enter new medicine quantity: ");
    scanf("%d", &m[0].quantity);
}

void deleteMedicine(struct medicine m[], int n){
    printf("\nEnter medicine name to delete: ");
    scanf("%s", m[0].name);
}

int main(){
    struct medicine m[MAX];
    int n = 0;

    while(1){
        printf("\nMEDICINE STORE MANAGEMENT SYSTEM\n");
        printf("1. Add medicine\n");
        printf("2. Display medicine\n");
        printf("3. Search medicine\n");
        printf("4. Update medicine\n");
        printf("5. Delete medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch(n){
            case 1:
                addMedicine(m, n);
                break;
            case 2:
                displayMedicine(m, n);
                break;
            case 3:
                searchMedicine(m, n, m[0].name);
                break;
            case 4:
                updateMedicine(m, n);
                break;
            case 5:
                deleteMedicine(m, n);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!");
        }
    }

    return 0;
}