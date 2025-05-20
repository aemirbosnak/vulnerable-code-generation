//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine {
    char name[50];
    int quantity;
    float price;
};

int main() {
    int choice;
    int n = 0, i = 0;
    float total = 0;
    char search[50];
    
    struct Medicine* meds = (struct Medicine*) malloc(n * sizeof(struct Medicine));
    
    do {
        printf("\nWelcome to the Medical Store Management System!");
        printf("\n1. Add Medicine\n2. Display Medicines\n3. Search Medicines\n4. Delete Medicine\n5. Exit");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                n++;
                meds = (struct Medicine*) realloc(meds, n * sizeof(struct Medicine));
                printf("\nEnter name of medicine: ");
                scanf("%s", meds[n-1].name);
                printf("Enter quantity of medicine: ");
                scanf("%d", &meds[n-1].quantity);
                printf("Enter price of medicine: ");
                scanf("%f", &meds[n-1].price);
                break;
                
            case 2:
                printf("Medicines available in the store:\n");
                printf("Name\tQuantity\tPrice\n");
                for(i=0; i<n; i++) {
                    printf("%s\t%d\t\t%.2f\n", meds[i].name, meds[i].quantity, meds[i].price);
                }
                break;
                
            case 3:
                printf("\nEnter name of medicine you want to search: ");
                scanf("%s", search);
                for(i=0; i<n; i++) {
                    if(strcmp(meds[i].name, search) == 0) {
                        printf("Medicine found!\n");
                        printf("Name\tQuantity\tPrice\n");
                        printf("%s\t%d\t\t%.2f\n", meds[i].name, meds[i].quantity, meds[i].price);
                        break;
                    }
                }
                if(i == n) {
                    printf("Medicine not found!\n");
                }
                break;
                
            case 4:
                printf("\nEnter name of medicine you want to delete: ");
                scanf("%s", search);
                for(i=0; i<n; i++) {
                    if(strcmp(meds[i].name, search) == 0) {
                        printf("Medicine deleted!\n");
                        total -= meds[i].price * meds[i].quantity;
                        for(int j=i; j<n-1; j++) {
                            strcpy(meds[j].name, meds[j+1].name);
                            meds[j].quantity = meds[j+1].quantity;
                            meds[j].price = meds[j+1].price;
                        }
                        n--;
                        break;
                    }
                }
                if(i == n) {
                    printf("Medicine not found!\n");
                }
                break;
                
            case 5:
                printf("\nTotal value of medicines sold: %.2f\n", total);
                free(meds);
                exit(0);
                
            default:
                printf("\nInvalid choice!\n");
        }
        
        total = 0;
        for(i=0; i<n; i++) {
            total += meds[i].price * meds[i].quantity;
        }
        
    } while(choice != 5);
    
    return 0;
}