//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_DATE_LEN 50
#define MONTHS_LEN 12

char *months[] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};

int check_date(char date[]){
    int day, month, year, len, i, j;
    char str[MAX_DATE_LEN];
    strcpy(str, date);

    len = strlen(str);

    day = atoi(strtok(str, "/"));
    strtok(NULL, "/");

    month = atoi(strtok(NULL, "/"));
    strtok(NULL, "\0");

    year = atoi(str);

    if(len != 10 || day < 1 || day > 31 || month < 1 || month > 12 || year < 1){
        return -1;
    }

    if(months[month-1][0] == 'F' && (day > 29 || (day == 29 && (year % 4 != 0 || year % 100 == 0 && year % 400 != 0)))){
        day -= 1;
    } else if(months[month-1][0] == 'F' && day > 28) day -= 1;

    if(day > (int)strlen(strchr(months[month-1], ' ')) + 1){
        return -1;
    }

    for(i = 0; i < day; i++){
        if(strchr(months[month-1] + i, ' ')[0] == 'F'){
            j = strlen(strchr(months[month-1] + i, ' ')) + 1;
            if(day > j){
                return -1;
            }
        }
    }

    return 1;
}

int main(void){
    char date[MAX_DATE_LEN];
    time_t rawtime;
    struct tm *timeinfo;

    while(1){
        printf("\nEnter a date in the format DD/MM/YYYY (Q to quit): ");
        fgets(date, MAX_DATE_LEN, stdin);

        if(date[0] == 'Q' || date[0] == 'q') break;

        if(check_date(date) == -1){
            printf("\nInvalid date! Try again.\n");
            continue;
        }

        rawtime = mktime(&(struct tm){.tm_mday = atoi(strtok(date, "/")),
                                     .tm_mon = atoi(strtok(NULL, "/")) - 1,
                                     .tm_year = atoi(strtok(NULL, "\0"))});

        if(rawtime == -1){
            printf("\nInvalid date! Try again.\n");
            continue;
        }

        timeinfo = localtime(&rawtime);

        printf("\nDate: %s\n", asctime(timeinfo));
    }

    return 0;
}