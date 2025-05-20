//FormAI DATASET v1.0 Category: Unit converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    float in, out;
    
    printf("Welcome to the Unit Converter!\n\n");
    
    while (1) {
        printf("Please select the conversion you wish to perform\n");
        printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n3. Kilometers to Miles\n");
        printf("4. Miles to Kilometers\n5. Meters to Feet\n6. Feet to Meters\n7. Exit\n");
        
        scanf("%d", &choice);
        
        if (choice == 7) {
            printf("\nThank you for using the Unit Converter!\n");
            break;
        }
        
        printf("Please enter the value you wish to convert: ");
        scanf("%f", &in);
        
        switch (choice) {
            case 1:
                out = (in * 9/5) + 32;
                printf("%.2f Celsius = %.2f Fahrenheit\n", in, out);
                break;
            case 2:
                out = (in - 32) * 5/9;
                printf("%.2f Fahrenheit = %.2f Celsius\n", in, out);
                break;
            case 3:
                out = in * 0.621371;
                printf("%.2f Kilometers = %.2f Miles\n", in, out);
                break;
            case 4:
                out = in * 1.60934;
                printf("%.2f Miles = %.2f Kilometers\n", in, out);
                break;
            case 5:
                out = in * 3.28084;
                printf("%.2f Meters = %.2f Feet\n", in, out);
                break;
            case 6:
                out = in * 0.3048;
                printf("%.2f Feet = %.2f Meters\n", in, out);
                break;
            default:
                printf("Invalid input, please try again.\n");
                break;
        }
    }
    
    return 0;
}