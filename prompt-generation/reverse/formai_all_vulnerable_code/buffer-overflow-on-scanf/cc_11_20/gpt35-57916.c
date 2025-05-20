//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: medieval
#include <stdio.h>
#include <string.h>

int main(void)
{
    char date[20], month[10], year[10];
    int d, m, y;

    printf("Milady/Mylord, prithee entereth the date in mm-dd-yyyy format: ");
    scanf("%s", date);

    // extracting day
    char *ptr = strtok(date, "-");
    d = atoi(ptr);

    // extracting month
    ptr = strtok(NULL, "-");
    strcpy(month, ptr);

    // extracting year
    ptr = strtok(NULL, "-");
    strcpy(year, ptr);
    y = atoi(year);

    // converting month to numeric value
    if(strcmp(month, "January") == 0)
        m = 1;
    else if(strcmp(month, "February") == 0)
        m = 2;
    else if(strcmp(month, "March") == 0)
        m = 3;
    else if(strcmp(month, "April") == 0)
        m = 4;
    else if(strcmp(month, "May") == 0)
        m = 5;
    else if(strcmp(month, "June") == 0)
        m = 6;
    else if(strcmp(month, "July") == 0)
        m = 7;
    else if(strcmp(month, "August") == 0)
        m = 8;
    else if(strcmp(month, "September") == 0)
        m = 9;
    else if(strcmp(month, "October") == 0)
        m = 10;
    else if(strcmp(month, "November") == 0)
        m = 11;
    else if(strcmp(month, "December") == 0)
        m = 12;

    // printing the converted date in a medieval style
    printf("Tis writ as %d day of the %dth month in the year of our Lord %d\n", d, m, y);

    return 0;
}