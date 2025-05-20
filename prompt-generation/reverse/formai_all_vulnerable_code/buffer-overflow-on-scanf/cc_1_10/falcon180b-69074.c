//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void convert(double num, char from, char to) {
    switch(from) {
        case'm':
            switch(to) {
                case 'km':
                    printf("%.2f meters is %.2f kilometers.\n", num, num/1000);
                    break;
                case 'cm':
                    printf("%.2f meters is %.2f centimeters.\n", num, num*100);
                    break;
                case'mm':
                    printf("%.2f meters is %.2f millimeters.\n", num, num*1000);
                    break;
                default:
                    printf("Invalid conversion.\n");
            }
            break;
        case 'km':
            switch(to) {
                case'm':
                    printf("%.2f kilometers is %.2f meters.\n", num, num*1000);
                    break;
                case 'cm':
                    printf("%.2f kilometers is %.2f centimeters.\n", num, num*100000);
                    break;
                case'mm':
                    printf("%.2f kilometers is %.2f millimeters.\n", num, num*1000000);
                    break;
                default:
                    printf("Invalid conversion.\n");
            }
            break;
        case 'cm':
            switch(to) {
                case'm':
                    printf("%.2f centimeters is %.2f meters.\n", num, num/100);
                    break;
                case 'km':
                    printf("%.2f centimeters is %.2f kilometers.\n", num, num/100000);
                    break;
                case'mm':
                    printf("%.2f centimeters is %.2f millimeters.\n", num, num*10);
                    break;
                default:
                    printf("Invalid conversion.\n");
            }
            break;
        case'mm':
            switch(to) {
                case'm':
                    printf("%.2f millimeters is %.2f meters.\n", num, num/1000);
                    break;
                case 'cm':
                    printf("%.2f millimeters is %.2f centimeters.\n", num, num/10);
                    break;
                case 'km':
                    printf("%.2f millimeters is %.2f kilometers.\n", num, num/1000000);
                    break;
                default:
                    printf("Invalid conversion.\n");
            }
            break;
        default:
            printf("Invalid unit.\n");
    }
}

int main() {
    char from, to;
    double num;
    printf("Enter the number to convert: ");
    scanf("%lf", &num);
    printf("Enter the unit to convert from: ");
    scanf(" %c", &from);
    printf("Enter the unit to convert to: ");
    scanf(" %c", &to);
    convert(num, from, to);
    return 0;
}