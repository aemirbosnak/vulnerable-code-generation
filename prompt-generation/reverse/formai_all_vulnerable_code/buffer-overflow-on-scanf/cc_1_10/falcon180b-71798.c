//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    float num, result;
    int choice;

    printf("Enter your choice:\n1. Length\n2. Weight\n3. Temperature\n4. Volume\n5. Exit\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter the length in meters: ");
            scanf("%f", &num);
            result = num * 3.28084;
            printf("The length in feet is: %.2f\n", result);
            break;

        case 2:
            printf("Enter the weight in kilograms: ");
            scanf("%f", &num);
            result = num * 2.20462;
            printf("The weight in pounds is: %.2f\n", result);
            break;

        case 3:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &num);
            result = (num * 9/5) + 32;
            printf("The temperature in Fahrenheit is: %.2f\n", result);
            break;

        case 4:
            printf("Enter the volume in liters: ");
            scanf("%f", &num);
            result = num * 0.264172;
            printf("The volume in gallons is: %.2f\n", result);
            break;

        case 5:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}

/* Sample Output:
Enter your choice:
1
Enter the length in meters: 5
The length in feet is: 16.40

Enter your choice:
2
Enter the weight in kilograms: 10
The weight in pounds is: 22.05

Enter your choice:
3
Enter the temperature in Celsius: 25
The temperature in Fahrenheit is: 77.00

Enter your choice:
4
Enter the volume in liters: 2
The volume in gallons is: 0.53

Enter your choice:
5
Exiting program...
*/