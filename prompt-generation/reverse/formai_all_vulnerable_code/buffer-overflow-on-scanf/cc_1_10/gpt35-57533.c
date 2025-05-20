//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: complete
#include<stdio.h>

int main(){

    int day, month, year;

    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);

    if(day <= 0 || month <= 0 || year <= 0){
        printf("Invalid input!\n");
        return 0;
    }

    if(month > 12){
        printf("Invalid input!\n");
        return 0;
    }

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(year % 4 == 0){
        if(year % 100 == 0){
            if(year % 400 == 0){
                daysInMonth[1] = 29;
            }
        }else{
            daysInMonth[1] = 29;
        }
    }

    if(day > daysInMonth[month-1]){
        printf("Invalid input!\n");
        return 0;
    }

    int totalDays = 0;

    for(int i = 0; i < month-1; i++){
        totalDays += daysInMonth[i];
    }

    totalDays += day;

    printf("The day of year is: %d\n", totalDays);

    char monthName[][10] = {"January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};

    printf("The entered date is: %s %d, %d\n", monthName[month-1], day, year);

    return 0;
}