//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    float value;
    char unit[100];

    printf("Welcome to the Medieval Unit Converter!\n");
    printf("Which unit would you like to convert from?\n");
    printf("1. League\n2. Furlong\n3. Cubit\n4. Hand\n5. Ell\n6. Chain\n7. Rod\n8. Perch\n9. Fathom\n10. Cubit\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the value in Leagues: ");
            scanf("%f", &value);
            printf("The value in Furlongs is: %f\n", value * 3);
            break;
        case 2:
            printf("Enter the value in Furlongs: ");
            scanf("%f", &value);
            printf("The value in Leagues is: %f\n", value / 3);
            break;
        case 3:
            printf("Enter the value in Cubits: ");
            scanf("%f", &value);
            printf("The value in Furlongs is: %f\n", value * 6);
            break;
        case 4:
            printf("Enter the value in Hands: ");
            scanf("%f", &value);
            printf("The value in Furlongs is: %f\n", value * 4);
            break;
        case 5:
            printf("Enter the value in Ells: ");
            scanf("%f", &value);
            printf("The value in Furlongs is: %f\n", value * 1.5);
            break;
        case 6:
            printf("Enter the value in Chains: ");
            scanf("%f", &value);
            printf("The value in Furlongs is: %f\n", value * 22);
            break;
        case 7:
            printf("Enter the value in Rods: ");
            scanf("%f", &value);
            printf("The value in Furlongs is: %f\n", value * 16.5);
            break;
        case 8:
            printf("Enter the value in Perches: ");
            scanf("%f", &value);
            printf("The value in Furlongs is: %f\n", value * 16);
            break;
        case 9:
            printf("Enter the value in Fathoms: ");
            scanf("%f", &value);
            printf("The value in Furlongs is: %f\n", value * 6);
            break;
        case 10:
            printf("Enter the value in Cubits: ");
            scanf("%f", &value);
            printf("The value in Furlongs is: %f\n", value * 6);
            break;
        default:
            printf("Invalid input\n");
            exit(0);
    }

    return 0;
}