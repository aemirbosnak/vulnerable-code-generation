//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defining structure for medicine details
struct medicine{
    char name[50];
    int quantity;
    float price;
    char expiry_date[20];
};

//defining function to add new medicine
void add_medicine(struct medicine *m, int *n){
    //getting input from user
    printf("Enter details of the new medicine:\n");
    printf("Name: ");
    scanf("%s", (m+*n)->name);
    printf("Quantity: ");
    scanf("%d", &(m+*n)->quantity);
    printf("Price: ");
    scanf("%f", &(m+*n)->price);
    printf("Expiry Date (dd/mm/yyyy): ");
    scanf("%s", (m+*n)->expiry_date);
    //incrementing the number of medicines in store
    (*n)++;
}

//function to search medicine by name
void search_medicine(struct medicine *m, int n){
    //getting input from user
    char search_name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", search_name);
    //searching for medicine by name
    int i;
    for(i=0;i<n;i++){
        if(strcmp((m+i)->name, search_name)==0){
            printf("\n---Medicine Details---\n");
            printf("Name: %s\n", (m+i)->name);
            printf("Quantity: %d\n", (m+i)->quantity);
            printf("Price: %.2f\n", (m+i)->price);
            printf("Expiry Date: %s\n", (m+i)->expiry_date);
            printf("----------------------\n");
            return;
        }
    }
    //if medicine not found
    printf("Medicine not found!\n");
}

//function to update medicine details
void update_medicine(struct medicine *m, int n){
    //getting input from user
    char update_name[50];
    printf("Enter medicine name to update: ");
    scanf("%s", update_name);
    //searching for medicine by name
    int i;
    for(i=0;i<n;i++){
        if(strcmp((m+i)->name, update_name)==0){
            printf("Enter new details:\n");
            printf("Name: ");
            scanf("%s", (m+i)->name);
            printf("Quantity: ");
            scanf("%d", &(m+i)->quantity);
            printf("Price: ");
            scanf("%f", &(m+i)->price);
            printf("Expiry Date (dd/mm/yyyy): ");
            scanf("%s", (m+i)->expiry_date);
            printf("\nMedicine details updated successfully!\n");
            return;
        }
    }
    //if medicine not found
    printf("Medicine not found!\n");
}

//function to display all medicines in store
void display_medicines(struct medicine *m, int n){
    printf("\n---Medicine List---\n");
    int i;
    for(i=0;i<n;i++){
        printf("Name: %s\n", (m+i)->name);
        printf("Quantity: %d\n", (m+i)->quantity);
        printf("Price: %.2f\n", (m+i)->price);
        printf("Expiry Date: %s\n", (m+i)->expiry_date);
        printf("--------------------\n");
    }
}

int main(){
    //declaring variables
    int n=0, choice;
    struct medicine *m;
    m = (struct medicine*) malloc(100*sizeof(struct medicine));
    //menu driven program
    while(1){
        printf("\n---MENU---\n");
        printf("1. Add new medicine\n");
        printf("2. Search medicine by name\n");
        printf("3. Update medicine details\n");
        printf("4. Display all medicines in store\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: add_medicine(m, &n);
                    break;
            case 2: search_medicine(m, n);
                    break;
            case 3: update_medicine(m, n);
                    break;
            case 4: display_medicines(m, n);
                    break;
            case 5: free(m);
                    exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}