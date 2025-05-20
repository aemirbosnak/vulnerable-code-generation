//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main(void) {

    char date[10];  // to store input date
    int day, month, year;  // to store separated day, month, year
    
    // prompt user for input date
    printf("Please enter a date in the format DD/MM/YYYY: ");
    scanf("%s", date);
    
    // separate individual values of day, month, and year
    sscanf(date, "%d/%d/%d", &day, &month, &year);
    
    // print converted date in natural language
    printf("The entered date is: ");
    switch(month) {
        case 1:
            printf("January");
            break;
        case 2:
            printf("February");
            break;
        case 3:
            printf("March");
            break;
        case 4:
            printf("April");
            break;
        case 5:
            printf("May");
            break;
        case 6:
            printf("June");
            break;
        case 7:
            printf("July");
            break;
        case 8:
            printf("August");
            break;
        case 9:
            printf("September");
            break;
        case 10:
            printf("October");
            break;
        case 11:
            printf("November");
            break;
        case 12:
            printf("December");
            break;
        default:
            printf("Invalid month");
            return 1;
    }
    printf(" %d", day);
    switch(day) {
        case 1:
        case 21:
        case 31:
            printf("st");
            break;
        case 2:
        case 22:
            printf("nd");
            break;
        case 3:
        case 23:
            printf("rd");
            break;
        default:
            printf("th");
            break;
    }
    printf(", %d\n", year);

    return 0;
}