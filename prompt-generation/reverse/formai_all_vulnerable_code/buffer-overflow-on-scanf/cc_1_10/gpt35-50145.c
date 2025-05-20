//FormAI DATASET v1.0 Category: Temperature Converter ; Style: random
#include<stdio.h>

int main(){

    int choice;

    float temp_f, temp_c;

    printf("\n\nWelcome to Our Temperature Converter Program!\n");


    printf("\nPlease Choose the Conversion Type:\n\n");


    printf("\t1. Fahrenheit to Celsius Conversion\n");

    printf("\t2. Celsius to Fahrenheit Conversion\n");

    printf("\t3. Exit Program\n");


    printf("\nPlease Enter Your Choice: ");

    scanf("%d", &choice);


    switch(choice){

        case 1: //Fahrenheit to Celsius Conversion

            printf("\nPlease Enter the Temperature in Fahrenheit: ");

            scanf("%f", &temp_f);

            temp_c = (temp_f - 32) * 5/9;

            printf("\n%f Fahrenheit is Equal to %f Celsius\n", temp_f, temp_c);

            break;

        case 2: //Celsius to Fahrenheit Conversion

            printf("\nPlease Enter the Temperature in Celsius: ");

            scanf("%f", &temp_c);

            temp_f = (temp_c * 9/5) + 32;

            printf("\n%f Celsius is Equal to %f Fahrenheit\n", temp_c, temp_f);

            break;

        case 3: //Exit Program

            printf("\nExiting Program...\n");

            break;

        default: //Invalid Choice Selected

            printf("\nInvalid Choice Selected, Please Try Again\n");

            break;

    }

    printf("\n\nThank You for Using Our Temperature Converter Program!\n");

    return 0;

}