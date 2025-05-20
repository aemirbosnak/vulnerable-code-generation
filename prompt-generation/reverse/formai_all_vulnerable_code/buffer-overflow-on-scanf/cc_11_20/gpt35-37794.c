//FormAI DATASET v1.0 Category: Unit converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    float value;
    printf("Welcome to the all-encompassing C Unit Converter!\n");

    while(1)
    {
        printf("\nChoose the type of conversion you wish to perform:\n");
        printf("1. Length\n");
        printf("2. Temperature\n");
        printf("3. Weight/Mass\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        if(choice==1)
        {
            printf("\nChoose the unit you wish to convert from:\n");
            printf("1. Centimeters (cm)\n");
            printf("2. Meters (m)\n");
            printf("3. Kilometers (km)\n");
            printf("\nEnter the value to be converted: ");
            scanf("%f",&value);
            if(choice==1)
            {
                printf("\n%.2f cm is %.2f m\n",value,value/100);
                printf("%.2f cm is %.2f km\n",value,value/100000);
            }
            else if(choice==2)
            {
                printf("\n%.2f m is %.2f cm\n",value,value*100);
                printf("%.2f m is %.2f km\n",value,value/1000);
            }
            else if(choice==3)
            {
                printf("\n%.2f km is %.2f cm\n",value,value*100000);
                printf("%.2f km is %.2f m\n",value,value*1000);
            }
        }
        else if(choice==2)
        {
            printf("\nChoose the unit you wish to convert from:\n");
            printf("1. Celsius (°C)\n");
            printf("2. Fahrenheit (°F)\n");
            printf("3. Kelvin (K)\n");
            printf("\nEnter the value to be converted: ");
            scanf("%f",&value);
            if(choice==1)
            {
                printf("\n%.2f °C is %.2f °F\n",value,(value*1.8)+32);
                printf("%.2f °C is %.2f K\n",value,value+273.15);
            }
            else if(choice==2)
            {
                printf("\n%.2f °F is %.2f °C\n",value,(value-32)/1.8);
                printf("%.2f °F is %.2f K\n",value,(value+459.67)/1.8);
            }
            else if(choice==3)
            {
                printf("\n%.2f K is %.2f °C\n",value,value-273.15);
                printf("%.2f K is %.2f °F\n",value,(value*1.8)-459.67);
            }
        }
        else if(choice==3)
        {
            printf("\nChoose the unit you wish to convert from:\n");
            printf("1. Grams (g)\n");
            printf("2. Kilograms (kg)\n");
            printf("3. Pounds (lbs)\n");
            printf("\nEnter the value to be converted: ");
            scanf("%f",&value);
            if(choice==1)
            {
                printf("\n%.2f g is %.2f kg\n",value,value/1000);
                printf("%.2f g is %.2f lbs\n",value,value*0.00220462);
            }
            else if(choice==2)
            {
                printf("\n%.2f kg is %.2f g\n",value,value*1000);
                printf("%.2f kg is %.2f lbs\n",value,value*2.20462);
            }
            else if(choice==3)
            {
                printf("\n%.2f lbs is %.2f g\n",value,value/0.00220462);
                printf("%.2f lbs is %.2f kg\n",value,value/2.20462);
            }
        }
        else if(choice==4) exit(0);
        else printf("\nInvalid Choice!");
    }
    return 0;
}