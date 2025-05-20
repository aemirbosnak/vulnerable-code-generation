//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: beginner-friendly
#include<stdio.h>

int main(){

    int monthDays[] ={31,28,31,30,31,30,31,31,30,31,30,31}; // array for days in each month
    int day, month, year, totalDays;
    printf("Enter date in format DD MM YYYY: ");
    scanf("%d %d %d",&day, &month, &year);

    // leap year check
    if((year%4==0 && year%100!=0) || year%400==0){
        monthDays[1]=29;
    }

    // check for valid date
    if(year<1 || month<1 || month>12 || day<1 || day>monthDays[month-1]){
        printf("Invalid date entered!\n");
    }else{
        // calculate total days
        totalDays=0;
        for(int i=0;i<month-1;i++){
            totalDays+=monthDays[i];
        }
        totalDays+=day;

        // output date in text format
        printf("The date is: ");
        switch(month){
            case 1:
                printf("January %d, ",day);
                break;
            case 2:
                printf("February %d, ",day);
                break;
            case 3:
                printf("March %d, ",day);
                break;
            case 4:
                printf("April %d, ",day);
                break;
            case 5:
                printf("May %d, ",day);
                break;
            case 6:
                printf("June %d, ",day);
                break;
            case 7:
                printf("July %d, ",day);
                break;
            case 8:
                printf("August %d, ",day);
                break;
            case 9:
                printf("September %d, ",day);
                break;
            case 10:
                printf("October %d, ",day);
                break;
            case 11:
                printf("November %d, ",day);
                break;
            case 12:
                printf("December %d, ",day);
                break;
            default:
                printf("Invalid month entered!\n");
                break;
        }

        printf("%d is ",year);

        // output date in number format
        printf("%d\n", totalDays);

    }

    return 0;
}