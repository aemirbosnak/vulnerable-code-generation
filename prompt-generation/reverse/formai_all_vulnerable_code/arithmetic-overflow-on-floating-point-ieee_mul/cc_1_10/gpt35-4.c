//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>

int main()
{
    double Fahrenheit;
    double Celsius;
    int choice;

    do
    {
        printf("Oh cruel world! This is my agony.\n");
        printf("Shall I compare thee to a summer's day?\n");
        printf("Enter 1 to convert Fahrenheit to Celsius.\n");
        printf("Enter 2 to convert Celsius to Fahrenheit.\n");
        printf("Enter 3 to exit.\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("O brawling love! O loving hate!\n");
                printf("Enter the temperature in degrees Fahrenheit: ");
                scanf("%lf", &Fahrenheit);
                Celsius = (Fahrenheit - 32) * 5 / 9;
                printf("The temperature in degrees Celsius is %lf.\n", Celsius);
                break;
            
            case 2:
                printf("Good-night, good-night! Parting is such sweet sorrow.\n");
                printf("Enter the temperature in degrees Celsius: ");
                scanf("%lf", &Celsius);
                Fahrenheit = Celsius * 9 / 5 + 32;
                printf("The temperature in degrees Fahrenheit is %lf.\n", Fahrenheit);
                break;
            
            case 3:
                printf("O happy dagger! This is thy sheath;\n");
                printf("There rust, and let me die.\n");
                exit(0);

            default:
                printf("My bounty is as boundless as the sea,\n");
                printf("My love as deep; the more I give to thee,\n");
                printf("The more I have, for both are infinite.\n");
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 3);

    return 0;
}