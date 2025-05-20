//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Structure for Medical Stores*/
struct medicine{
    char name[20];
    int id;
    int quantity;
    float price;
};

/*Function Declaration*/
void addMedicine(struct medicine *, int);
void deleteMedicine(struct medicine *, int);
void searchMedicine(struct medicine *, int);
void updateMedicine(struct medicine *, int);

int main(){

    struct medicine *store;
    int n, choice;

    printf("Enter the number of medicines to be stored: ");
    scanf("%d", &n);

    /*Dynamic allocation of memory*/
    store = (struct medicine *)calloc(n, sizeof(struct medicine));

    /*Add and manipulate medicines*/
    do{
        printf("1. Add a new medicine\n");
        printf("2. Delete a medicine\n");
        printf("3. Search for a medicine\n");
        printf("4. Update medicine information\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                addMedicine(store, n);
                break;

            case 2:
                deleteMedicine(store, n);
                break;

            case 3:
                searchMedicine(store, n);
                break;

            case 4:
                updateMedicine(store, n);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please enter again.\n");
        }

    }while(choice!=5);

    /*Freeing the allocated memory*/
    free(store);

    return 0;
}

/*Function to add medicine*/
void addMedicine(struct medicine *store, int n){

    int i;
    for(i=0; i<n; i++){

        if(store[i].id==0){

            printf("Enter the name of medicine: ");
            scanf("%s", &store[i].name);
            printf("Enter the id of medicine: ");
            scanf("%d", &store[i].id);
            printf("Enter the quantity of medicine: ");
            scanf("%d", &store[i].quantity);
            printf("Enter the price of medicine: ");
            scanf("%f", &store[i].price);

            printf("Medicine added successfully!\n");
            return;
        }
    }

    printf("Cannot add medicine! Store is full.\n");
}

/*Function to delete medicine*/
void deleteMedicine(struct medicine *store, int n){

    int id, i, flag=0;
    printf("Enter the id of medicine to be deleted: ");
    scanf("%d", &id);

    for(i=0; i<n; i++){

        if(store[i].id==id){

            strcpy(store[i].name, "");
            store[i].id=0;
            store[i].quantity=0;
            store[i].price=0.0;

            printf("Medicine deleted successfully!\n");
            return;
        }
    }

    printf("Cannot delete medicine! Medicine not found in store.\n");
}

/*Function to search medicine*/
void searchMedicine(struct medicine *store, int n){

    int id, i, flag=0;
    printf("Enter the id of medicine to be searched: ");
    scanf("%d", &id);

    for(i=0; i<n; i++){

        if(store[i].id==id){

            printf("\nName: %s", store[i].name);
            printf("\nID: %d", store[i].id);
            printf("\nQuantity Available: %d", store[i].quantity);
            printf("\nPrice: %.2f\n", store[i].price);

            flag=1;
            break;
        }
    }

    if(flag==0)
        printf("Medicine not found in store.\n");
}

/*Function to update medicine*/
void updateMedicine(struct medicine *store, int n){

    int id, i, flag=0, c;
    printf("Enter the id of medicine to be updated: ");
    scanf("%d", &id);

    for(i=0; i<n; i++){

        if(store[i].id==id){

            printf("1. Update Name\n");
            printf("2. Update Quantity\n");
            printf("3. Update Price\n");
            printf("Enter your choice: ");
            scanf("%d", &c);

            switch(c){

                case 1:
                    printf("Enter the new name: ");
                    scanf("%s", &store[i].name);
                    break;

                case 2:
                    printf("Enter the new quantity: ");
                    scanf("%d", &store[i].quantity);
                    break;

                case 3:
                    printf("Enter the new price: ");
                    scanf("%f", &store[i].price);
                    break;

                default:
                    printf("Invalid choice! Please enter again.\n");
            }

            printf("Medicine updated successfully!\n");
            flag=1;
            break;
        }
    }

    if(flag==0)
        printf("Cannot update medicine! Medicine not found in store.\n");
}