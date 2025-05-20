//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double input;
    char choice;
    int conversion = 0;

    do {
        printf("Enter a number to convert:\n");
        scanf("%lf", &input);

        printf("Enter the unit of measurement:\n");
        scanf(" %c", &choice);

        switch(choice) {
            case 'k':
                conversion = 1;
                break;
            case'm':
                conversion = 2;
                break;
            case 'g':
                conversion = 3;
                break;
            case 'l':
                conversion = 4;
                break;
            case 'u':
                conversion = 5;
                break;
            default:
                printf("Invalid unit of measurement.\n");
                exit(0);
        }

        switch(conversion) {
            case 1:
                printf("%.2lf kgs\n", input * 1);
                break;
            case 2:
                printf("%.2lf mgs\n", input * 1000000);
                break;
            case 3:
                printf("%.2lf gs\n", input * 1000000000);
                break;
            case 4:
                printf("%.2lf lgs\n", input * 1000000000000);
                break;
            case 5:
                printf("%.2lf ugs\n", input * 1000000000000000);
                break;
            default:
                printf("Invalid conversion.\n");
                exit(0);
        }

    } while(conversion!= 0);

    return 0;
}