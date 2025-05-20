//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

struct tm *parse_date(char *date_string);
void print_date(struct tm *date);

int main(int argc, char *argv[]) {
    char *date_string;
    struct tm *date;
    
    if (argc!= 2) {
        printf("Usage: %s <date_string>\n", argv[0]);
        exit(1);
    }
    
    date_string = argv[1];
    date = parse_date(date_string);
    print_date(date);
    
    return 0;
}

struct tm *parse_date(char *date_string) {
    struct tm date = {0};
    char *token;
    int i;
    
    token = strtok(date_string, " ");
    if (token == NULL) {
        return NULL;
    }
    date.tm_mday = atoi(token);
    
    token = strtok(NULL, " ");
    if (token == NULL) {
        return NULL;
    }
    date.tm_mon = atoi(token) - 1;
    
    token = strtok(NULL, " ");
    if (token == NULL) {
        return NULL;
    }
    date.tm_year = atoi(token) - 1900;
    
    date.tm_isdst = -1;
    date.tm_hour = 0;
    date.tm_min = 0;
    date.tm_sec = 0;
    date.tm_wday = 0;
    date.tm_yday = 0;
    
    return &date;
}

void print_date(struct tm *date) {
    char *day_of_week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    char *month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char buffer[80];
    time_t now;
    
    now = time(NULL);
    strftime(buffer, 80, "Today is %A, %B %d, %Y. The time is %I:%M %p. ", date);
    printf("%s\n", buffer);
    
    strftime(buffer, 80, "On %A, %B %d, %Y, at %I:%M %p, ", date);
    printf("%s", buffer);
    printf("%s ", day_of_week[date->tm_wday]);
    printf("%s ", month[date->tm_mon]);
    printf("%d, ", date->tm_mday);
    printf("%d\n", date->tm_year + 1900);
}