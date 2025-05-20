//FormAI DATASET v1.0 Category: Stock market tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stock {
    char name[20];
    float price;
    int volume;
} Stock;

int main() {

    Stock companies[5];
    char userChoice[10];
    int choice;
    int numCompanies = 0;

    while(1) {
        printf("What would you like to do?\n");
        printf("1. Add a new company\n");
        printf("2. View company details\n");
        printf("3. Quit program\n");
        fgets(userChoice, 10, stdin);
        choice = atoi(userChoice);

        switch(choice) {
            case 1:
                if(numCompanies >= 5) {
                    printf("Maximum number of companies reached\n");
                }
                else {
                    printf("Enter the name of the company:\n");
                    fgets(companies[numCompanies].name, 20, stdin);
                    printf("Enter the price of the stock:\n");
                    fgets(userChoice, 10, stdin);
                    companies[numCompanies].price = atof(userChoice);
                    printf("Enter the volume of the stock:\n");
                    fgets(userChoice, 10, stdin);
                    companies[numCompanies].volume = atoi(userChoice);
                    numCompanies++;
                    printf("Company added successfully\n");
                }
                break;
            case 2:
                if(numCompanies == 0) {
                    printf("No companies in tracker\n");
                }
                else {
                    printf("Enter the index of the company you would like to view:\n");
                    fgets(userChoice, 10, stdin);
                    int index = atoi(userChoice);
                    if(index >= numCompanies) {
                        printf("Invalid index entered\n");
                    } 
                    else {
                        printf("Company Name: %s", companies[index].name);
                        printf("Stock Price: $%.2f\n", companies[index].price);
                        printf("Stock Volume: %d\n", companies[index].volume);
                    }
                }
                break;
            case 3:
                printf("Exiting Program\n");
                exit(0);
            default:
                printf("Invalid Choice Entered\n");
        }
    }

    return 0;
}