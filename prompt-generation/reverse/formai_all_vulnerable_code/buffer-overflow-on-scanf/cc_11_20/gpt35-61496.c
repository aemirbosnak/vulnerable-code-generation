//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Romeo and Juliet
#include<stdio.h>
#include<string.h>

int roma_day(char*);
int roma_month(char*);
int roma_year(char*);

int main() {
    char date[20], month[20], year[20];
    int day;
    printf("Oh Romeo, what date is today?\n");
    scanf("%s %s %s", date, month, year);
    day = roma_day(date);
    if(day == 0) {
        printf("Alas! Today is not a valid date\n");
        return 0;
    }
    int c_month = roma_month(month);
    if(c_month == 0) {
        printf("Oh my dear Juliet, please enter a valid month\n");
        return 0;
    }
    int c_year = roma_year(year);
    if(c_year == 0) {
        printf("Oh my love Romeo, please enter a valid year\n");
        return 0;
    }
    printf("Sweet Romeo, Today is the %d", day);
    switch(day % 10) {
        case 1:
            if(day % 100 != 11) {
                printf("st");
                break;
            }
        case 2:
            if(day % 100 != 12) {
                printf("nd");
                break;
            }
        case 3:
            if(day % 100 != 13) {
                printf("rd");
                break;
            }
        default:
            printf("th");
            break;
    }
    switch(c_month) {
        case 1: 
            printf(" of January, ");
            break;
        case 2: 
            printf(" of February, ");
            break;
        case 3: 
            printf(" of March, ");
            break;
        case 4: 
            printf(" of April, ");
            break;
        case 5: 
            printf(" of May, ");
            break;
        case 6: 
            printf(" of June, ");
            break;
        case 7: 
            printf(" of July, ");
            break;
        case 8: 
            printf(" of August, ");
            break;
        case 9: 
            printf(" of September, ");
            break;
        case 10: 
            printf(" of October, ");
            break;
        case 11: 
            printf(" of November, ");
            break;
        case 12: 
            printf(" of December, ");
            break;
    }
    printf("in the year of %d", c_year);
    return 0;
}

int roma_day(char* s) {
    int d = 0, i = 0;
    if(s[i] < '0' || s[i] > '9') {
        return 0;
    }
    while(s[i] >= '0' && s[i] <= '9') {
        d = d*10 + s[i] - '0';
        i++;
    }
    if(d < 1 || d > 31) {
        return 0;
    }
    return d;
}

int roma_month(char* s) {
    if(strcmp(s, "January") == 0) {
        return 1;
    }
    else if(strcmp(s, "February") == 0) {
        return 2;
    }
    else if(strcmp(s, "March") == 0) {
        return 3;
    }
    else if(strcmp(s, "April") == 0) {
        return 4;
    }
    else if(strcmp(s, "May") == 0) {
        return 5;
    }
    else if(strcmp(s, "June") == 0) {
        return 6;
    }
    else if(strcmp(s, "July") == 0) {
        return 7;
    }
    else if(strcmp(s, "August") == 0) {
        return 8;
    }
    else if(strcmp(s, "September") == 0) {
        return 9;
    }
    else if(strcmp(s, "October") == 0) {
        return 10;
    }
    else if(strcmp(s, "November") == 0) {
        return 11;
    }
    else if(strcmp(s, "December") == 0) {
        return 12;
    }
    else {
        return 0;
    }
}

int roma_year(char* s) {
    int year = 0, i = 0;
    if(s[i] == '-') {
        i++;
    }
    while(s[i] >= '0' && s[i] <= '9') {
        year = year*10 + s[i] - '0';
        i++;
    }
    if(year < 1 || year > 2021) {
        return 0;
    }
    return year;
}