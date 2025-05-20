//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    char ch;
    double num, result = 0;
    int choice;

    printf("\n\nUnit Converter\n\n");

    do{
        system("clear");
        printf("\n\nEnter the value to convert: ");
        scanf("%lf", &num);

        printf("\n\nEnter the unit of measurement you want to convert from: ");
        scanf(" %c", &ch);

        printf("\n\nEnter the unit of measurement you want to convert to: ");
        scanf(" %c", &ch);

        switch(ch){
            case 'K':
            case 'k':
                result = num + 273.15;
                printf("\n\n%lf %c is equal to %lf %c\n\n", num, ch, result, 'C');
                break;

            case 'C':
            case 'c':
                result = num - 273.15;
                printf("\n\n%lf %c is equal to %lf %c\n\n", num, ch, result, 'F');
                break;

            case 'F':
            case 'f':
                result = (num - 32) * (5.0/9.0);
                printf("\n\n%lf %c is equal to %lf %c\n\n", num, ch, result, 'C');
                break;

            case 'M':
            case'm':
                result = num * 0.001;
                printf("\n\n%lf %c is equal to %lf %c\n\n", num, ch, result, 'K');
                break;

            case 'G':
            case 'g':
                result = num * 0.000001;
                printf("\n\n%lf %c is equal to %lf %c\n\n", num, ch, result, 'M');
                break;

            case 'L':
            case 'l':
                result = num * 3.78541;
                printf("\n\n%lf %c is equal to %lf %c\n\n", num, ch, result, 'G');
                break;

            case 'O':
            case 'o':
                result = num * 0.264172;
                printf("\n\n%lf %c is equal to %lf %c\n\n", num, ch, result, 'L');
                break;

            default:
                printf("\n\nInvalid unit of measurement entered! ");
        }

        printf("\n\nDo you want to continue? (y/n): ");
        scanf(" %c", &ch);
        choice = ch;

    }while(choice == 'y' || choice == 'Y');

    return 0;
}