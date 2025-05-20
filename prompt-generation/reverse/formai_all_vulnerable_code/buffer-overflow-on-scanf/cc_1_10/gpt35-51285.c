//FormAI DATASET v1.0 Category: Unit converter ; Style: secure
#include <stdio.h>

void displayMenu(){
    printf("\n1. Convert meters to feet");
    printf("\n2. Convert Fahrenheit to Celsius");
    printf("\n3. Convert kilometers to miles");
    printf("\n4. Exit");
}

double mToFeet(double meters){
    return meters * 3.281;
}

double fToCelsius(double fahrenheit){
    return (fahrenheit - 32) * 5 / 9;
}

double kmToMiles(double kilometers){
    return kilometers * 0.621;
}

int main(){
    int choice;
    double inputValue, result;
    while(1){
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter meters: ");
                scanf("%lf", &inputValue);
                result = mToFeet(inputValue);
                printf("%.2lf meters is equal to %.2lf feet\n", inputValue, result);
                break;
            case 2:
                printf("Enter Fahrenheit: ");
                scanf("%lf", &inputValue);
                result = fToCelsius(inputValue);
                printf("%.2lf Fahrenheit is equal to %.2lf Celsius\n", inputValue, result);
                break;
            case 3:
                printf("Enter kilometers: ");
                scanf("%lf", &inputValue);
                result = kmToMiles(inputValue);
                printf("%.2lf kilometers is equal to %.2lf miles\n", inputValue, result);
                break;
            case 4:
                printf("\nGoodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }
    return 0;
}