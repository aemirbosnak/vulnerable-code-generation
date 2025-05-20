//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: mind-bending
#include <stdio.h>
#include <string.h>

/* function prototypes */
char* convert_month(int);
void print_output(int, char*, int, int);

/* main function */
int main(void) {
    char date_input[11]; /* date input string */
    int month, day, year; /* date components */
    printf("Welcome to the Mind-Bending Natural Language Date Converter!\n");
    printf("Please enter a date in the format of Month DD, YYYY: ");
    fgets(date_input, 11, stdin); /* read date input string */
    sscanf(date_input, "%d %d, %d", &month, &day, &year); /* parse date input */
    char* month_str = convert_month(month); /* convert month integer to string */
    print_output(day, month_str, year, month); /* print output string */
    return 0;
}

/* function that converts a month integer to string */
char* convert_month(int month) {
    char* month_str;
    switch(month) {
        case 1:
            month_str = "January";
            break;
        case 2:
            month_str = "February";
            break;
        case 3:
            month_str = "March";
            break;
        case 4:
            month_str = "April";
            break;
        case 5:
            month_str = "May";
            break;
        case 6:
            month_str = "June";
            break;
        case 7:
            month_str = "July";
            break;
        case 8:
            month_str = "August";
            break;
        case 9:
            month_str = "September";
            break;
        case 10:
            month_str = "October";
            break;
        case 11:
            month_str = "November";
            break;
        case 12:
            month_str = "December";
            break;
        default:
            month_str = "Unknown";
            break;
    }
    return month_str;
}

/* function that prints the output string */
void print_output(int day, char* month, int year, int month_int) {
    char output_str[25]; /* output string buffer */
    if(month_int == day) {
        sprintf(output_str, "%d is the same as %s %d, %d. Your mind is bending!", day, month, day, year);
    } else if(year == month_int) {
        sprintf(output_str, "%s %d is the same as %d %d. Your mind is bending!", month, day, month_int, day);
    } else {
        sprintf(output_str, "%s %d, %d is the same as %d/%d/%d. Your mind is bending!", month, day, year, month_int, day, year);
    }
    printf("%s\n", output_str); /* print output string */
}