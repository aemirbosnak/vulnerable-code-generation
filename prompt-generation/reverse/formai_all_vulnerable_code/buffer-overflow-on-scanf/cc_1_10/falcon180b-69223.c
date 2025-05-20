//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Function to check if a string is a valid date
int is_valid_date(char *date) {
    struct tm tm;
    strptime(date, "%d-%m-%Y", &tm);
    return!mktime(&tm);
}

// Function to convert a date string to a mathematical expression
char *date_to_expr(char *date) {
    char *expr = malloc(100);
    int i = 0;
    for (i = 0; i < strlen(date); i++) {
        if (date[i] == '-') {
            strncat(expr, " - ", 100);
        } else {
            strncat(expr, &date[i], 100);
        }
    }
    strcat(expr, " = ");
    return expr;
}

// Function to evaluate a mathematical expression
int evaluate_expr(char *expr) {
    int result = 0;
    char *token = strtok(expr, " ");
    while (token!= NULL) {
        if (isdigit(token[0])) {
            result += atoi(token) - 1;
        } else if (strcmp(token, "+") == 0) {
            result += 1;
        } else if (strcmp(token, "-") == 0) {
            result -= 1;
        }
        token = strtok(NULL, " ");
    }
    return result;
}

// Function to convert a mathematical expression to a date string
char *expr_to_date(int expr) {
    char *date = malloc(100);
    int i = 0;
    while (expr!= 0) {
        if (expr % 2 == 0) {
            strncat(date, "31-", 100);
        } else {
            strncat(date, "30-", 100);
        }
        expr /= 2;
        i++;
    }
    strcat(date, "-2000");
    return date;
}

int main() {
    char date[100];
    printf("Enter a date (dd-mm-yyyy): ");
    scanf("%s", date);
    if (is_valid_date(date)) {
        char *expr = date_to_expr(date);
        int result = evaluate_expr(expr);
        char *date_str = expr_to_date(result);
        printf("The date %s is equivalent to the expression %s\n", date, date_str);
    } else {
        printf("Invalid date\n");
    }
    return 0;
}