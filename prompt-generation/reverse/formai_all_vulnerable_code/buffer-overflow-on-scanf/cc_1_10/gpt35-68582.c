//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: innovative
#include <stdio.h>
#include <string.h>

// Function to convert string month to its integer equivalent
int month_to_int(char month[]) {
    if (strcmp(month, "January") == 0) {
        return 1;
    } else if (strcmp(month, "February") == 0) {
        return 2;
    } else if (strcmp(month, "March") == 0) {
        return 3;
    } else if (strcmp(month, "April") == 0) {
        return 4;
    } else if (strcmp(month, "May") == 0) {
        return 5;
    } else if (strcmp(month, "June") == 0) {
        return 6;
    } else if (strcmp(month, "July") == 0) {
        return 7;
    } else if (strcmp(month, "August") == 0) {
        return 8;
    } else if (strcmp(month, "September") == 0) {
        return 9;
    } else if (strcmp(month, "October") == 0) {
        return 10;
    } else if (strcmp(month, "November") == 0) {
        return 11;
    } else if (strcmp(month, "December") == 0) {
        return 12;
    } else {
        return -1;
    }
}

// Function to convert integer month to its string equivalent
char* int_to_month(int month) {
    if (month == 1) {
        return "January";
    } else if (month == 2) {
        return "February";
    } else if (month == 3) {
        return "March";
    } else if (month == 4) {
        return "April";
    } else if (month == 5) {
        return "May";
    } else if (month == 6) {
        return "June";
    } else if (month == 7) {
        return "July";
    } else if (month == 8) {
        return "August";
    } else if (month == 9) {
        return "September";
    } else if (month == 10) {
        return "October";
    } else if (month == 11) {
        return "November";
    } else {
        return "December";
    }
}

// Function to convert date in string format to date in integer format
int date_converter(char date[]) {
    char* token;
    char delim[] = " ";
    char month_str[10];
    int month_int;
    int day;
    int year;
    
    // Tokenize the input string using delimiter as space and convert to integer format
    token = strtok(date, delim);
    strcpy(month_str, token);
    month_int = month_to_int(month_str);
    
    token = strtok(NULL, delim);
    day = atoi(token);
    
    token = strtok(NULL, delim);
    year = atoi(token);
    
    // Calculate the integer equivalent of the date
    return year*10000 + month_int*100 + day;
}

// Function to convert date in integer format to date in string format
char* date_converter_reverse(int date_int) {
    char date_str[11];
    char month_str[10];
    int month_int;
    int day;
    int year;
    
    // Extract the year, month and day from the integer format and convert to string format
    year = date_int/10000;
    month_int = (date_int/100)%100;
    sprintf(month_str, "%s", int_to_month(month_int));
    day = date_int%100;
    
    // Construct the string in date format "Month DD, YYYY"
    sprintf(date_str, "%s %02d, %04d", month_str, day, year);
    
    // Return the string in date format
    return date_str;
}

int main() {
    char date[20];
    int date_int;
    
    printf("Enter a date in string format (Month DD, YYYY): ");
    scanf("%19[^\n]", date);
    
    date_int = date_converter(date);
    
    printf("The integer equivalent of the date is: %d\n", date_int);
    
    printf("Enter a date in integer format (YYYYMMDD): ");
    scanf("%d", &date_int);
    
    printf("The string equivalent of the date is: %s", date_converter_reverse(date_int));
    
    return 0;
}