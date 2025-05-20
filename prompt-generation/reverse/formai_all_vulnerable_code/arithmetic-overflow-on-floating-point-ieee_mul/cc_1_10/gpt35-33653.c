//FormAI DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>

int main(){
    printf("Welcome to the Convert-O-Tron 9000!\n");
    printf("🚀👨‍🚀👩‍🚀🛰️❤️\n");
    printf("This revolutionary unit converter can convert almost anything you can think of!\n");
    printf("🌡️💧📐📏🧭\n");

    int option;
    float value;

    //Menu
    printf("\nPlease select your conversion option:\n");
    printf("1: Celsius to Fahrenheit\n");
    printf("2: Feet to Meters\n");
    printf("3: Kilograms to Pounds\n");
    printf("4: Liters to Gallons\n");
    printf("5: Quit\n");

    //Loop until the user selects the quit option
    while(1){
        printf("\nEnter option: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                //Celsius to Fahrenheit Conversion
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &value);
                printf("%.2f Celsius is equal to %.2f Fahrenheit.\n\n", value, (value * 9/5) + 32);
                break;
            case 2:
                //Feet to Meters Conversion
                printf("\nEnter length in feet: ");
                scanf("%f", &value);
                printf("%.2f feet is equal to %.2f meters.\n\n", value, value * 0.3048);
                break;
            case 3:
                //Kilograms to Pounds Conversion
                printf("\nEnter weight in kilograms: ");
                scanf("%f", &value);
                printf("%.2f kilograms is equal to %.2f pounds.\n\n", value, value * 2.20462);
                break;
            case 4:
                //Liters to Gallons Conversion
                printf("\nEnter volume in liters: ");
                scanf("%f", &value);
                printf("%.2f liters is equal to %.2f gallons.\n\n", value, value * 0.264172);
                break;
            case 5:
                //Quit
                printf("\nThank you for using the Convert-O-Tron 9000! Goodbye!👋👋👋\n");
                return 0;
            default:
                //Invalid Option
                printf("\nInvalid Option. Please try again.\n");
                break;
        }
    }

    return 0;
}