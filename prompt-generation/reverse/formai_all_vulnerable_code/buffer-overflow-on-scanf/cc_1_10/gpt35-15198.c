//FormAI DATASET v1.0 Category: Temperature Converter ; Style: surprised
#include<stdio.h>

//The program converts Celsius to Fahrenheit and vice versa.

int main(){

    int choice; //To store the choice of the user.
    float temp, res; //To store the temperature and the result.

    printf("***************************\n");
    printf("Welcome to Temperature Converter!\n");
    printf("***************************\n\n");

    printf("Choose an option:\n");
    printf("1. Convert Celsius to Fahrenheit.\n");
    printf("2. Convert Fahrenheit to Celsius.\n");
    printf("3. Exit the program.\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    while(choice != 3) //The loop will continue until the user chooses to exit.
    {
        switch(choice) {

            case 1: //Celsius to Fahrenheit
                printf("Enter the temperature in Celsius: ");
                scanf("%f", &temp);
                res = (temp*9/5) + 32;
                printf("%.2fC is equal to %.2fF.\n", temp, res);
                break;

            case 2: //Fahrenheit to Celsius
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%f", &temp);
                res = (temp-32) * 5/9;
                printf("%.2fF is equal to %.2fC.\n", temp, res);
                break;

            default: //If the user enters invalid choice
                printf("Invalid choice! Please try again.\n");
                break;
        }

        printf("\nChoose an option:\n");
        printf("1. Convert Celsius to Fahrenheit.\n");
        printf("2. Convert Fahrenheit to Celsius.\n");
        printf("3. Exit the program.\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

    } //End of while loop

    printf("\nThank you for using Temperature Converter!\n");

    return 0;
}