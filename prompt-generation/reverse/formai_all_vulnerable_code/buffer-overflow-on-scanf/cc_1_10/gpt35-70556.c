//FormAI DATASET v1.0 Category: Database querying ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Query_result {
    char employee_name[100];
    float salary;
    int years_of_service;
};

void query_and_display_data(int year) {
    struct Query_result result[10];

    printf("Retrieving data from database...\n");
    printf("Processing query...\n");
    printf("Crunching numbers...\n");
    printf("Finding the best donut shop in the area...\n");
    
    // Just kidding, that last one doesn't belong here.

    printf("Query completed!\n\n");

    for (int i=0; i<10; i++) {
        // Generating random data for demo purposes
        strcpy(result[i].employee_name, "John Doe");
        result[i].salary = (float)(rand() % 100000 + 40000);
        result[i].years_of_service = rand() % 20 + 1;
    }

    int count = 0;

    for (int i=0; i<10; i++) {
        if (result[i].years_of_service >= year) {
            printf("Employee name: %s\n", result[i].employee_name);
            printf("Salary: $%.2f\n", result[i].salary);
            printf("Years of service: %d\n", result[i].years_of_service);
            printf("\n");

            count++;
        }
    }
    if (count == 0) {
        printf("Sorry, no employees found with %d or more years of service.\n", year);
    }
}

int main() {
    int year;
    printf("Please enter the minimum years of service to retrieve: ");
    scanf("%d", &year);

    query_and_display_data(year);

    return 0;
}