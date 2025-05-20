//FormAI DATASET v1.0 Category: Unit converter ; Style: calm
#include<stdio.h>

int main(){
    int option; // Variable to store the user's option
    float value, result; // Variables to store the user's input and conversion result

    printf("\nWelcome to the Unit Converter!\n");
    printf("---------------------------------------\n");

    //Loop until user chooses to exit
    while(1){
        printf("\nPlease choose an option:\n");
        printf("1. Convert length from meters into feet\n");
        printf("2. Convert temperature from Celsius into Fahrenheit\n");
        printf("3. Convert weight from kilograms into pounds\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &option); //Read user input

        switch(option){
            case 1:
                printf("\nEnter the length in meters: ");
                scanf("%f", &value);
                result = value * 3.281; //Convert meters into feet
                printf("%.2f meters is equal to %.2f feet.\n", value, result);
                break;

            case 2:
                printf("\nEnter the temperature in Celsius: ");
                scanf("%f", &value);
                result = (value * 9/5) + 32; //Convert Celsius into Fahrenheit
                printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", value, result);
                break;

            case 3:
                printf("\nEnter the weight in kilograms: ");
                scanf("%f", &value);
                result = value * 2.205; //Convert kilograms into pounds
                printf("%.2f kilograms is equal to %.2f pounds.\n", value, result);
                break;

            case 4:
                printf("\nThank you for using the Unit Converter! Goodbye!\n");
                return 0;

            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}