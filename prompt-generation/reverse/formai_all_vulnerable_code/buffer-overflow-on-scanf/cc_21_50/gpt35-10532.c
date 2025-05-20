//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: puzzling
#include <stdio.h>
#include <string.h>

int main() {
    
    printf("Welcome to the Date Converter Program!\n");
    printf("Input date format: dd-mm-yyyy or dd/mm/yyyy\n");
    char input_date[11];
    scanf("%s", &input_date); //Get user input

    //Convert date to numbers
    int day = 0, month = 0, year = 0, i;
    char delimiter[2];
    strcpy(delimiter, "-"); //Assume delimiter is "-"
    for(i = 0; i < strlen(input_date); i++) {
        if(input_date[i] == '/') {
            strcpy(delimiter, "/"); //If delimiter is "/", change it
            break;
        }
    }
    sscanf(input_date, "%d%s%d%s%d", &day, delimiter, &month, delimiter, &year);

    //Check for valid date
    int valid_date = 1;
    if(month < 1 || month > 12 || day < 1 || day > 31) {
        valid_date = 0;
    }
    else if(month == 2 && (year%4 == 0 && (year%100 != 0 || year%400 == 0))) { //Leap year
        if(day > 29) {
            valid_date = 0;
        }
    }
    else if(month == 2 && day > 28) {
        valid_date = 0;
    }
    else if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        valid_date = 0;
    }

    if(valid_date == 0) { //If date is not valid, print error and exit program
        printf("Error: Invalid date\n");
        return 0;
    }

    printf("Output date format: ");
    char output_format[10];
    scanf("%s", &output_format);

    if(strcmp(output_format, "dd-mmm-yyyy") == 0) { //Convert to dd-mmm-yyyy format
        char month_letters[12][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        printf("%02d-%s-%04d\n", day, month_letters[month-1], year);
    }
    else if(strcmp(output_format, "yyyymmdd") == 0) { //Convert to yyyymmdd format
        printf("%04d%02d%02d\n", year, month, day);
    }
    else if(strcmp(output_format, "mm-dd-yyyy") == 0) { //Convert to mm-dd-yyyy format
        printf("%02d-%02d-%04d\n", month, day, year);
    }
    else { //If output format is invalid, print error and exit program
        printf("Error: Invalid output format\n");
        return 0;
    }

    return 0;
}