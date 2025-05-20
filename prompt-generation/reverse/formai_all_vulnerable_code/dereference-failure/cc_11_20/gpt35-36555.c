//FormAI DATASET v1.0 Category: Unit converter ; Style: energetic
#include <stdio.h>

int main() {
    printf("Welcome to the Unit Converter!\n");
    printf("We're excited to help you convert any unit you need.\n");

    int option;
    printf("Please select the type of unit you would like to convert:\n");
    printf("1. Length\n2. Temperature\n3. Weight\n4. Time\n");
    printf("Enter your option: ");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("You have selected Length. Please select the units you'd like to convert from and to:\n");
            printf("1. Feet to Meters\n2. Meters to Feet\n3. Inches to Centimeters\n4. Centimeters to Inches\n");
            int sub_option;
            printf("Enter your sub-option: ");
            scanf("%d", &sub_option);

            float input_value;
            printf("Enter the value you'd like to convert: ");
            scanf("%f", &input_value);

            if (sub_option == 1) {
                printf("%.2f feet is equal to %.2f meters.\n", input_value, input_value/3.281);
            }
            else if (sub_option == 2) {
                printf("%.2f meters is equal to %.2f feet.\n", input_value, input_value*3.281);
            }
            else if (sub_option == 3) {
                printf("%.2f inches is equal to %.2f centimeters.\n", input_value, input_value*2.54);
            }
            else if (sub_option == 4) {
                printf("%.2f centimeters is equal to %.2f inches.\n", input_value, input_value/2.54);
            }
            else {
                printf("Invalid sub-option selected.\n");
            }
            break;
        case 2:
            printf("You have selected Temperature. Please select the units you'd like to convert from and to:\n");
            printf("1. Fahrenheit to Celsius\n2. Celsius to Fahrenheit\n");
            printf("Enter your sub-option: ");
            scanf("%d", &sub_option);

            printf("Enter the value you'd like to convert: ");
            scanf("%f", &input_value);

            if (sub_option == 1) {
                printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", input_value, (input_value - 32) * 5/9);
            }
            else if (sub_option == 2) {
                printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", input_value, (input_value * 9/5) + 32);
            }
            else {
                printf("Invalid sub-option selected.\n");
            }
            break;
        case 3:
            printf("You have selected Weight. Please select the units you'd like to convert from and to:\n");
            printf("1. Pounds to Kilograms\n2. Kilograms to Pounds\n");
            printf("Enter your sub-option: ");
            scanf("%d", &sub_option);

            printf("Enter the value you'd like to convert: ");
            scanf("%f", &input_value);

            if (sub_option == 1) {
                printf("%.2f pounds is equal to %.2f kilograms.\n", input_value, input_value/2.205);
            }
            else if (sub_option == 2) {
                printf("%.2f kilograms is equal to %.2f pounds.\n", input_value, input_value*2.205);
            }
            else {
                printf("Invalid sub-option selected.\n");
            }
            break;
        case 4:
            printf("You have selected Time. Please select the units you'd like to convert from and to:\n");
            printf("1. Seconds to Minutes\n2. Minutes to Seconds\n");
            printf("Enter your sub-option: ");
            scanf("%d", &sub_option);

            printf("Enter the value you'd like to convert: ");
            scanf("%f", &input_value);

            if (sub_option == 1) {
                printf("%.2f seconds is equal to %.2f minutes.\n", input_value, input_value/60);
            }
            else if (sub_option == 2) {
                printf("%.2f minutes is equal to %.2f seconds.\n", input_value, input_value*60);
            }
            else {
                printf("Invalid sub-option selected.\n");
            }
            break;
        default:
            printf("Invalid option selected.\n");
            break;
    }

    printf("Thanks for using our Unit Converter. Have a great day!\n");

    return 0;
}