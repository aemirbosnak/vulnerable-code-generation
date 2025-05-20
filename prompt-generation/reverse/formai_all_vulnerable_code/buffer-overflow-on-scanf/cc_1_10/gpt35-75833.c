//FormAI DATASET v1.0 Category: Unit converter ; Style: active
#include<stdio.h>

void inch_to_cm()
{
    float inch,cm;
    printf("Enter the value in Inches: ");
    scanf("%f",&inch);
    cm = inch * 2.54;
    printf("Value in Centimeters: %f cm\n",cm);
}

void cm_to_inch()
{
    float inch,cm;
    printf("Enter the value in Centimeters: ");
    scanf("%f",&cm);
    inch = cm / 2.54;
    printf("Value in Inches: %f inch\n",inch);
}

void kg_to_pound()
{
    float kg,pound;
    printf("Enter the value in Kilograms: ");
    scanf("%f",&kg);
    pound = kg * 2.20462;
    printf("Value in Pounds: %f pound\n",pound);
}

void pound_to_kg()
{
    float kg,pound;
    printf("Enter the value in Pounds: ");
    scanf("%f",&pound);
    kg = pound / 2.20462;
    printf("Value in Kilograms: %f kg\n",kg);
}

int main()
{
    int choice;
    printf("Welcome to Unit Converter!\n");
    
    do
    {
        printf("\nChoose an option:\n");
        printf("1. Inch to Centimeter\n");
        printf("2. Centimeter to Inch\n");
        printf("3. Kilogram to Pound\n");
        printf("4. Pound to Kilogram\n");
        printf("5. Exit\n");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                inch_to_cm();
                break;
            case 2:
                cm_to_inch();
                break;
            case 3:
                kg_to_pound();
                break;
            case 4:
                pound_to_kg();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid input!\n");
                break;
        }
    }while(choice != 5);

    return 0;
}