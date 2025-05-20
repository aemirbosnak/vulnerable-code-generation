//FormAI DATASET v1.0 Category: Unit converter ; Style: all-encompassing
#include<stdio.h>

/* Definition of all the conversion constants */

#define INCH2CM 2.54     
#define CM2INCH 0.3937  
#define G2OZ 0.03527     
#define OZ2G 28.35     
#define K2MILE 0.621    
#define MILE2K 1.609      

int main() {

    int choice;     /* To store the user's choice */
    float value;    /* To store the user's input */
    
    /* Displaying the options to the user */
    printf("Choose an option: \n");
    printf("1. Inches to Centimeters\n");
    printf("2. Centimeters to Inches\n");
    printf("3. Grams to Ounces\n");
    printf("4. Ounces to Grams\n");
    printf("5. Kilometers to Miles\n");
    printf("6. Miles to Kilometers\n");
    scanf("%d", &choice);

    /* Switch statement to perform the selected conversion based on user input */

    switch(choice){
        case 1:
            printf("Enter the length in inches: ");
            scanf("%f", &value);
            printf("%.2f inches is equal to %.2f centimeters\n", value, value * INCH2CM);
            break;
        case 2:
            printf("Enter the length in centimeters: ");
            scanf("%f", &value);
            printf("%.2f centimeters is equal to %.2f inches\n", value, value * CM2INCH);
            break;
        case 3:
            printf("Enter the weight in grams: ");
            scanf("%f", &value);
            printf("%.2f grams is equal to %.2f ounces\n", value, value * G2OZ);
            break;
        case 4:
            printf("Enter the weight in ounces: ");
            scanf("%f", &value);
            printf("%.2f ounces is equal to %.2f grams\n", value, value * OZ2G);
            break;
        case 5:
            printf("Enter the distance in kilometers: ");
            scanf("%f", &value);
            printf("%.2f kilometers is equal to %.2f miles\n", value, value * K2MILE);
            break;
        case 6:
            printf("Enter the distance in miles: ");
            scanf("%f", &value);
            printf("%.2f miles is equal to %.2f kilometers\n", value, value * MILE2K);
            break;
        default:
            printf("Invalid input\n");
            break;
    }

    return 0;
}