//FormAI DATASET v1.0 Category: Unit converter ; Style: irregular
#include <stdio.h>

int main() {

    char choice;
    
    printf("Welcome to the Ultimate Unit Converter program!\n");
    printf("This program can convert kilometers to miles and vice versa and also convert kilograms to pounds and vice versa.\n\n");
    
    do {
        printf("Please choose the type of conversion you would like to perform.\n");
        printf("1. Kilometers to miles.\n");
        printf("2. Miles to kilometers.\n");
        printf("3. Kilograms to pounds.\n");
        printf("4. Pounds to kilograms.\n\n");
        printf("Enter your choice (1-4): ");
        scanf("%c", &choice);
        
        if(choice == '1') {
            printf("\nYou have selected the conversion from kilometers to miles.\n");
            float kilometers;
            printf("Enter the number of kilometers: ");
            scanf("%f", &kilometers);
            float miles = kilometers * 0.621371;
            printf("%.2f kilometers is equal to %.2f miles.\n", kilometers, miles);
        }
        else if(choice == '2') {
            printf("\nYou have selected the conversion from miles to kilometers.\n");
            float miles;
            printf("Enter the number of miles: ");
            scanf("%f", &miles);
            float kilometers = miles * 1.60934;
            printf("%.2f miles is equal to %.2f kilometers.\n", miles, kilometers);
        }
        else if(choice == '3') {
            printf("\nYou have selected the conversion from kilograms to pounds.\n");
            float kilograms;
            printf("Enter the number of kilograms: ");
            scanf("%f", &kilograms);
            float pounds = kilograms * 2.20462;
            printf("%.2f kilograms is equal to %.2f pounds.\n", kilograms, pounds);
        }
        else if(choice == '4') {
            printf("\nYou have selected the conversion from pounds to kilograms.\n");
            float pounds;
            printf("Enter the number of pounds: ");
            scanf("%f", &pounds);
            float kilograms = pounds * 0.453592;
            printf("%.2f pounds is equal to %.2f kilograms.\n", pounds, kilograms);
        }
        else {
            printf("\nThe choice you have entered is invalid. Please try again.\n");
        }
        
        printf("\nDo you want to perform another conversion? (Y/N) ");
        scanf(" %c", &choice);
        
        if(choice != 'Y' && choice != 'N') {
            printf("\nThe choice you have entered is invalid. Please try again.\n");
            printf("Do you want to perform another conversion? (Y/N) ");
            scanf(" %c", &choice);
        }
        
    } while(choice == 'Y');
    
    printf("\nThank you for using the Ultimate Unit Converter program.\n\n");
    
    return 0;
}