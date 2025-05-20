//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    float num, res;
    int choice;

    printf("Enter the number to convert: ");
    scanf("%f", &num);

    printf("Enter the conversion choice:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Kilometer to Miles\n");
    printf("4. Miles to Kilometer\n");
    printf("5. Kilogram to Pound\n");
    printf("6. Pound to Kilogram\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            // Fahrenheit to Celsius
            res = (num - 32) * 5/9;
            printf("%f Fahrenheit is %f Celsius\n", num, res);
            break;
        case 2:
            // Celsius to Fahrenheit
            res = num * 9/5 + 32;
            printf("%f Celsius is %f Fahrenheit\n", num, res);
            break;
        case 3:
            // Kilometer to Miles
            res = num * 0.621371;
            printf("%f Kilometer is %f Miles\n", num, res);
            break;
        case 4:
            // Miles to Kilometer
            res = num / 0.621371;
            printf("%f Miles is %f Kilometer\n", num, res);
            break;
        case 5:
            // Kilogram to Pound
            res = num * 2.20462;
            printf("%f Kilogram is %f Pound\n", num, res);
            break;
        case 6:
            // Pound to Kilogram
            res = num / 2.20462;
            printf("%f Pound is %f Kilogram\n", num, res);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}