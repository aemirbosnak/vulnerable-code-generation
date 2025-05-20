//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: rigorous
#include<stdio.h>

void displayResult(int day, int mon, int year){
    printf("The equivalent date in natural language is:\n");
    switch(mon){
        case 1:
            printf("%dst January, %d.\n",day,year);
            break;
        case 2:
            printf("%dnd February, %d.\n",day,year);
            break;
        case 3:
            printf("%drd March, %d.\n",day,year);
            break;
        case 4:
            printf("%dth April, %d.\n",day,year);
            break;
        case 5:
            printf("%dth May, %d.\n",day,year);
            break;
        case 6:
            printf("%dth June, %d.\n",day,year);
            break;
        case 7:
            printf("%dth July, %d.\n",day,year);
            break;
        case 8:
            printf("%dth August, %d.\n",day,year);
            break;
        case 9:
            printf("%dth September, %d.\n",day,year);
            break;
        case 10:
            printf("%dth October, %d.\n",day,year);
            break;
        case 11:
            printf("%dth November, %d.\n",day,year);
            break;
        case 12:
            printf("%dth December, %d.\n",day,year);
            break;
        default:
            printf("Invalid month.\n");
            break;
    }
}

int main(){
    int day, mon, year, format;
    printf("Enter the date in the format DD/MM/YYYY: ");
    scanf("%d/%d/%d",&day,&mon,&year);
    printf("Choose the desired date format:\n");
    printf("1. DD/MM/YYYY\n2. Natural Language\n");
    scanf("%d",&format);
    switch(format){
        case 1:
            printf("The entered date is: %d/%d/%d.\n",day,mon,year);
            break;
        case 2:
            displayResult(day,mon,year);
            break;
        default:
            printf("Invalid format choice.\n");
            break;
    }
    return 0;
}