//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: single-threaded
#include <stdio.h>
#include <string.h>

int main() {
    char str[50], month_name[20];
    int date, month, year;

    printf("Enter date in format (dd-mm-yyyy): ");
    scanf("%s", str);

    sscanf(str, "%d-%d-%d", &date, &month, &year);

    switch(month) {
        case 1:
            strcpy(month_name, "January");
            break;
        case 2:
            strcpy(month_name, "February");
            break;
        case 3:
            strcpy(month_name, "March");
            break;
        case 4:
            strcpy(month_name, "April");
            break;
        case 5:
            strcpy(month_name, "May");
            break;
        case 6:
            strcpy(month_name, "June");
            break;
        case 7:
            strcpy(month_name, "July");
            break;
        case 8:
            strcpy(month_name, "August");
            break;
        case 9:
            strcpy(month_name, "September");
            break;
        case 10:
            strcpy(month_name, "October");
            break;
        case 11:
            strcpy(month_name, "November");
            break;
        case 12:
            strcpy(month_name, "December");
            break;
        default:
            printf("Invalid month!");
            return 0;
    }

    printf("The date entered is: %s %d, %d\n", month_name, date, year);

    return 0;
}