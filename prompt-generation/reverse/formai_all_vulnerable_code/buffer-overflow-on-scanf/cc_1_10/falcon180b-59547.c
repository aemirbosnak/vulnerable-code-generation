//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct date {
    int day;
    int month;
    int year;
};

struct date get_date(char* input) {
    struct date date;
    char* token = strtok(input, " ");
    if (token == NULL) {
        printf("Invalid input\n");
        exit(1);
    }
    date.month = atoi(token);
    token = strtok(NULL, " ");
    if (token == NULL) {
        printf("Invalid input\n");
        exit(1);
    }
    date.day = atoi(token);
    token = strtok(NULL, " ");
    if (token == NULL) {
        printf("Invalid input\n");
        exit(1);
    }
    date.year = atoi(token);
    return date;
}

void print_date(struct date date) {
    printf("%d-%d-%d\n", date.day, date.month, date.year);
}

int main() {
    char* input;
    printf("Enter a date (dd/mm/yyyy): ");
    scanf("%s", input);
    struct date date = get_date(input);
    printf("Date in natural language: ");
    switch(date.month) {
        case 1:
            printf("January ");
            break;
        case 2:
            printf("February ");
            break;
        case 3:
            printf("March ");
            break;
        case 4:
            printf("April ");
            break;
        case 5:
            printf("May ");
            break;
        case 6:
            printf("June ");
            break;
        case 7:
            printf("July ");
            break;
        case 8:
            printf("August ");
            break;
        case 9:
            printf("September ");
            break;
        case 10:
            printf("October ");
            break;
        case 11:
            printf("November ");
            break;
        case 12:
            printf("December ");
            break;
    }
    printf("%d, %d\n", date.day, date.year);
    return 0;
}