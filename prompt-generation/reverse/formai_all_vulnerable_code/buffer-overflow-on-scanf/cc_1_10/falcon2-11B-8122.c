//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    
    int num_months = 12;
    int num_weeks = num_months * 4;
    int num_days = num_weeks * 7;
    
    printf("Welcome to the C Personal Finance Planner!\n");
    printf("Please enter the number of months you want to plan for:\n");
    int months;
    scanf("%d", &months);
    
    int weekly_budget = 1000;
    int remaining_budget = weekly_budget * num_weeks;
    
    int day = 1;
    int week = 1;
    int month = 1;
    
    while (day <= num_days) {
        if (week % 4 == 0) {
            printf("%d-%d-%d: Week %d\n", month, day, week, week / 4);
            printf("Remaining budget: %d\n", remaining_budget);
            printf("Weekly budget: %d\n", weekly_budget);
        }
        else {
            printf("%d-%d-%d: Day %d\n", month, day, week, day);
            printf("Remaining budget: %d\n", remaining_budget);
            printf("Weekly budget: %d\n", weekly_budget);
        }
        
        if (month == 12) {
            month = 1;
            day = 1;
            week++;
        }
        else {
            month++;
            day = 1;
            week = 1;
        }
        
        remaining_budget -= 100;
        weekly_budget -= 100;
    }
    
    return 0;
}