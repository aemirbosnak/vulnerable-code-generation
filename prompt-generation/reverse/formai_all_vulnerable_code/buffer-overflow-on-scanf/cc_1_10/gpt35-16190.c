//FormAI DATASET v1.0 Category: Unit converter ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define cm2ft(x) (x*0.032808)
#define ft2cm(x) (x*30.48)
#define lf2lg(x) (x/0.45359)
#define lg2lf(x) (x*0.45359)
#define km2mi(x) (x*0.62137)
#define mi2km(x) (x*1.60934)
#define l2gal(x) (x*0.264172)
#define gal2l(x) (x*3.78541)

void display_Menu(){
    printf("Enter the number to select the conversion:\n");
    printf("1. Centimeter to Feet\n");
    printf("2. Feet to Centimeter\n");
    printf("3. Pounds to Kilograms\n");
    printf("4. Kilograms to Pounds\n");
    printf("5. Kilometers to Miles\n");
    printf("6. Miles to Kilometers\n");
    printf("7. Liters to Gallons\n");
    printf("8. Gallons to Liters\n");
    printf("9. Exit\n");
}

int main(){
    int choice;
    float number, result;
    char ch;

    while(1){
        display_Menu();
        scanf("%d", &choice);
        if(choice==9)break;
        fflush(stdin);
        printf("Enter the number to convert: ");
        if(scanf("%f", &number)!=1){
            printf("Invalid input. Enter a number.\n");
            continue;
        }

        switch(choice){
            case 1:
                result=cm2ft(number);
                printf("%0.2f cm is equal to %0.2f ft.\n", number, result);
                break;
            case 2:
                result=ft2cm(number);
                printf("%0.2f ft is equal to %0.2f cm.\n", number, result);
                break;
            case 3:
                result=lg2lf(number);
                printf("%0.2f lb is equal to %0.2f kg.\n", number, result);
                break;
            case 4:
                result=lf2lg(number);
                printf("%0.2f kg is equal to %0.2f lb.\n", number, result);
                break;
            case 5:
                result=km2mi(number);
                printf("%0.2f km is equal to %0.2f mi.\n", number, result);
                break;
            case 6:
                result=mi2km(number);
                printf("%0.2f mi is equal to %0.2f km.\n", number, result);
                break;
            case 7:
                result=l2gal(number);
                printf("%0.2f L is equal to %0.2f gal.\n", number, result);
                break;
            case 8:
                result=gal2l(number);
                printf("%0.2f gal is equal to %0.2f L.\n", number, result);
                break;
            default:
                printf("Invalid selection. Try again.\n");
        }
        printf("Would you like to perform another conversion? (Y/N)\n");
        fflush(stdin);
        scanf("%c", &ch);
        if(tolower(ch)=='n')break;
    }
    printf("Goodbye!\n");
    return 0;
}