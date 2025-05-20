//FormAI DATASET v1.0 Category: Stock market tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the stock values
struct stock {
    char company_name[25];
    float current_price;
    float percent_change;
};

// Function to display menu
void display_menu() {
    printf("\nMenu\n");
    printf("1. Add a new stock\n");
    printf("2. Display all the stocks\n");
    printf("3. Find a stock by company name\n");
    printf("4. Exit\n");
}

int main() {
    int choice, i, found = 0;
    char search_name[25];
    struct stock s[50];

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                // Adding a new stock
                if(i < 50) {
                    printf("Enter company name: ");
                    scanf("%s", s[i].company_name);
                    printf("Enter current price: ");
                    scanf("%f", &s[i].current_price);
                    printf("Enter percent change: ");
                    scanf("%f", &s[i].percent_change);
                    i++;
                } else {
                    printf("You can add only 50 stocks!\n");
                }
                break;
            case 2:
                // Displaying all the stocks
                
                if(i == 0)
                    printf("No stocks added yet!\n");
                else {
                    printf("Company Name\tCurrent Price\t  Percent Change\n");
                    for(int j=0; j<i; j++) {
                        printf("%-16s %-17.2f %-5.2f\n", s[j].company_name, s[j].current_price, s[j].percent_change);
                    }
                }
                break;
            case 3:
                // Finding a stock by company name
                if(i == 0)
                    printf("No stocks added yet!\n");
                else {
                    printf("Enter company name to search: ");
                    scanf("%s", search_name);
                    for(int j=0; j<i; j++) {
                        if(strcmp(search_name, s[j].company_name) == 0) {
                            found = 1;
                            printf("Company Name\tCurrent Price\t  Percent Change\n");
                            printf("%-16s %-17.2f %-5.2f\n", s[j].company_name, s[j].current_price, s[j].percent_change);
                            break;
                        }
                    }
                    if(!found)
                        printf("Stock not found!\n");
                }
                break;
            case 4:
                // Exiting the program
                printf("Exiting the program\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(1);

    return 0;
}