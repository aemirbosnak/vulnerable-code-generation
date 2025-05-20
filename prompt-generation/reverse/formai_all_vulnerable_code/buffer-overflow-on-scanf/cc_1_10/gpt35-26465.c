//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: lively
#include <stdio.h>
#include <string.h>

// Function to convert string to integer
int convertToInt(char str[])
{
    int num = 0, i;
    for (i = 0; str[i] != '\0'; i++)
    {
        num = num * 10 + (str[i] - '0');
    }
    return num;
}

// Function to convert integer to string
void convertToString(int num, char str[])
{
    int i = 0, rem;
    while (num != 0)
    {
        rem = num % 10;
        str[i++] = rem + '0';
        num /= 10;
    }
    str[i] = '\0';
    // Reverse the string
    for (i = 0; i < strlen(str) / 2; i++)
    {
        char temp = str[i];
        str[i] = str[strlen(str) - i - 1];
        str[strlen(str) - i - 1] = temp;
    }
}

// Function to get month name from month number
void getMonthName(int month, char monthName[])
{
    switch(month)
    {
        case 1:
            strcpy(monthName, "January");
            break;
        case 2:
            strcpy(monthName, "February");
            break;
        case 3:
            strcpy(monthName, "March");
            break;
        case 4:
            strcpy(monthName, "April");
            break;
        case 5:
            strcpy(monthName, "May");
            break;
        case 6:
            strcpy(monthName, "June");
            break;
        case 7:
            strcpy(monthName, "July");
            break;
        case 8:
            strcpy(monthName, "August");
            break;
        case 9:
            strcpy(monthName, "September");
            break;
        case 10:
            strcpy(monthName, "October");
            break;
        case 11:
            strcpy(monthName, "November");
            break;
        case 12:
            strcpy(monthName, "December");
            break;
        default:
            printf("Invalid month number!\n");
            break;
    }
}

// Main function
int main()
{
    int day, month, year;
    char date[11], dayStr[3], monthStr[3], yearStr[5], monthName[10];
    printf("Enter date in dd/mm/yyyy format: ");
    scanf("%s", date);
    // Extract day, month and year from the date string
    dayStr[0] = date[0];
    dayStr[1] = date[1];
    dayStr[2] = '\0';
    monthStr[0] = date[3];
    monthStr[1] = date[4];
    monthStr[2] = '\0';
    yearStr[0] = date[6];
    yearStr[1] = date[7];
    yearStr[2] = date[8];
    yearStr[3] = date[9];
    yearStr[4] = '\0';
    day = convertToInt(dayStr);
    month = convertToInt(monthStr);
    year = convertToInt(yearStr);
    // Get month name
    getMonthName(month, monthName);
    // Print the date in string format
    printf("The date is: %s %d, %d\n", monthName, day, year);
    // Convert the date to integer format
    int dateInt = year * 10000 + month * 100 + day;
    // Print the date in integer format
    printf("The date in integer format is: %d\n", dateInt);
    // Convert the date back to string format
    convertToString(dateInt, date);
    printf("The date in string format is: %s\n", date);
    return 0;
}