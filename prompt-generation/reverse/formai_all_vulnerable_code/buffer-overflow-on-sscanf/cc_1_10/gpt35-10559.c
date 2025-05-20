//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// function to convert natural language date to MM/DD/YYYY format
void convertDate(char date[]) {
    int day, year, month;
    char monthName[10];

    // reading the month name, day number and year from the input
    sscanf(date, "%s %d, %d", monthName, &day, &year);

    // converting the month name to month number
    if(strcmp(monthName, "January") == 0)
        month = 1;
    else if(strcmp(monthName, "February") == 0)
        month = 2;
    else if(strcmp(monthName, "March") == 0)
        month = 3;
    else if(strcmp(monthName, "April") == 0)
        month = 4;
    else if(strcmp(monthName, "May") == 0)
        month = 5;
    else if(strcmp(monthName, "June") == 0)
        month = 6;
    else if(strcmp(monthName, "July") == 0)
        month = 7;
    else if(strcmp(monthName, "August") == 0)
        month = 8;
    else if(strcmp(monthName, "September") == 0)
        month = 9;
    else if(strcmp(monthName, "October") == 0)
        month = 10;
    else if(strcmp(monthName, "November") == 0)
        month = 11;
    else if(strcmp(monthName, "December") == 0)
        month = 12;

    // printing the date in MM/DD/YYYY format
    printf("My love, on this romantic date of %d/%d/%d, let me profess my love for you.\n"
            "The month shall be filled with our love, like the %s sky with shining stars,\n"
            "And the days shall be counted in the warmth of our embrace, like %d roses in a bouquet.\n"
            "I vow to cherish every moment spent with you, because life is short and love is eternal.\n"
            "Together we will conquer all obstacles and make beautiful memories that we shall relish in our old age.\n"
            "Happy date my sweet love!\n", month, day, year, monthName, day);
}

int main() {
    char date[20];

    // reading the natural language date from user
    printf("Sweetheart, Please enter the date in natural language (Example format: January 1, 2022):\n");
    scanf("%[^\n]%*c", date);

    // calling the function to convert date and profess love
    convertDate(date);

    return 0;
}