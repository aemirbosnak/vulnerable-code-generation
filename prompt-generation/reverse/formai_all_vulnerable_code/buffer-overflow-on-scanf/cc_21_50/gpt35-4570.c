//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for storing the details of medicines
struct Medicine {
    char name[50];
    char company[50];
    float price;
    int quantity;
}medicines[100];

int main() {
    int choice;
    int count = 0;

    while(1) {
        printf("===========================================\n");
        printf("            Medical Store Menu\n");
        printf("===========================================\n");
        printf("1. Add medicine\n");
        printf("2. Display medicine\n");
        printf("3. Search medicine\n");
        printf("4. Update medicine\n");
        printf("5. Delete medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Add a new medicine
                printf("Enter the name of the medicine: ");
                scanf("%s", medicines[count].name);
                printf("Enter the name of the company: ");
                scanf("%s", medicines[count].company);
                printf("Enter the price of the medicine: ");
                scanf("%f", &medicines[count].price);
                printf("Enter the quantity of the medicine: ");
                scanf("%d", &medicines[count].quantity);
                count++;
                printf("\nMedicine added successfully!\n\n");
                break;

            case 2:
                // Display all medicines
                if(count == 0) {
                    printf("\nNo medicines added yet!\n\n");
                } else {
                    printf("\nMedicine\tCompany\t\tPrice\tQuantity\n");
                    printf("--------------------------------------------------------\n");
                    for(int i=0; i<count; i++) {
                        printf("%s\t\t%s\t\t%.2f\t%d\n", medicines[i].name, medicines[i].company, medicines[i].price, medicines[i].quantity);
                    }
                    printf("--------------------------------------------------------\n\n");
                }
                break;

            case 3:
                // Search for a medicine by name
                if(count == 0) {
                    printf("\nNo medicines added yet!\n\n");
                } else {
                    char searchName[50];
                    printf("Enter the name of the medicine to search: ");
                    scanf("%s", searchName);
                    int found = 0;
                    for(int i=0; i<count; i++) {
                        if(strcmp(searchName, medicines[i].name) == 0) {
                            printf("\nMedicine\tCompany\t\tPrice\tQuantity\n");
                            printf("--------------------------------------------------------\n");
                            printf("%s\t\t%s\t\t%.2f\t%d\n", medicines[i].name, medicines[i].company, medicines[i].price, medicines[i].quantity);
                            printf("--------------------------------------------------------\n\n");
                            found = 1;
                        }
                    }
                    if(found == 0) {
                        printf("\nMedicine not found!\n\n");
                    }
                }
                break;

            case 4:
                // Update a medicine by name
                if(count == 0) {
                    printf("\nNo medicines added yet!\n\n");
                } else {
                    char updateName[50];
                    printf("Enter the name of the medicine to update: ");
                    scanf("%s", updateName);
                    int found = 0;
                    for(int i=0; i<count; i++) {
                        if(strcmp(updateName, medicines[i].name) == 0) {
                            printf("Enter the new name of the medicine: ");
                            scanf("%s", medicines[i].name);
                            printf("Enter the new name of the company: ");
                            scanf("%s", medicines[i].company);
                            printf("Enter the new price of the medicine: ");
                            scanf("%f", &medicines[i].price);
                            printf("Enter the new quantity of the medicine: ");
                            scanf("%d", &medicines[i].quantity);
                            printf("\nMedicine updated successfully!\n\n");
                            found = 1;
                        }
                    }
                    if(found == 0) {
                        printf("\nMedicine not found!\n\n");
                    }
                }
                break;

            case 5:
                // Delete a medicine by name
                if(count == 0) {
                    printf("\nNo medicines added yet!\n\n");
                } else {
                    char deleteName[50];
                    printf("Enter the name of the medicine to delete: ");
                    scanf("%s", deleteName);
                    int found = 0;
                    for(int i=0; i<count; i++) {
                        if(strcmp(deleteName, medicines[i].name) == 0) {
                            for(int j=i; j<count-1; j++) {
                                strcpy(medicines[j].name, medicines[j+1].name);
                                strcpy(medicines[j].company, medicines[j+1].company);
                                medicines[j].price = medicines[j+1].price;
                                medicines[j].quantity = medicines[j+1].quantity;
                            }
                            count--;
                            printf("\nMedicine deleted successfully!\n\n");
                            found = 1;
                            break;
                        }
                    }
                    if(found == 0) {
                        printf("\nMedicine not found!\n\n");
                    }
                }
                break;

            case 6:
                // Exit the program
                printf("\nThank you for using the Medical Store Management System!\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n\n");
        }
    }
    return 0;
}