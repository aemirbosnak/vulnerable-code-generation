//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: calm
#include <stdio.h>
#include <string.h>

int main() {
    int num_medicines, choice;
    float price;
    char medicine_name[50], search_medicine[50];

    printf("Welcome to the Medical Store Management System\n");
    printf("Enter the number of medicines in the store: ");
    scanf("%d", &num_medicines);

    char medicine_list[num_medicines][50];
    float medicine_price[num_medicines];

    // Taking input of the medicine names and prices 
    for(int i = 0; i < num_medicines; i++) {
        printf("\nEnter the name of medicine %d: ", i + 1);
        scanf("%s", medicine_name);
        strcpy(medicine_list[i], medicine_name);   // Copying the medicine name to the medicine list array

        printf("Enter the price of medicine %d: ", i + 1);
        scanf("%f", &price);
        medicine_price[i] = price;
    }

    // Displaying the medicine list
    printf("\nMedicine List\n");
    for(int i = 0; i < num_medicines; i++) {
        printf("%d. %s - $%.2f\n", i + 1, medicine_list[i], medicine_price[i]);
    }

    // Searching for a medicine 
    printf("\nEnter the name of the medicine you want to search: ");
    scanf("%s", search_medicine);

    int found = 0;  // Flag to check if the medicine was found or not

    for(int i = 0; i < num_medicines; i++) {
        if(strcmp(search_medicine, medicine_list[i]) == 0) {
            printf("Medicine %s found! Price - $%.2f\n", medicine_list[i], medicine_price[i]);
            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("Medicine not found!\n");
    }

    // Selling a medicine
    printf("\nEnter the number of the medicine you want to sell: ");
    scanf("%d", &choice);

    if(choice > num_medicines || choice < 1) {
        printf("Invalid input, please try again!\n");
    }
    else {
        printf("Medicine %s sold! Price - $%.2f\n", medicine_list[choice-1], medicine_price[choice-1]);
    }

    return 0;
}