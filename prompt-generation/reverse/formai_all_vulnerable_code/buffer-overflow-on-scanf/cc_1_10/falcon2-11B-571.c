//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    int amount;
    char category[20];
    int month;
    int year;
} Entry;

int main() {
    Entry entries[MAX_ENTRIES];
    int i;

    printf("Welcome to the C Personal Finance Planner!\n");

    for (i = 0; i < MAX_ENTRIES; i++) {
        entries[i].name[0] = '\0';
        entries[i].amount = 0;
        entries[i].category[0] = '\0';
        entries[i].month = 0;
        entries[i].year = 0;
    }

    printf("Enter your name: ");
    scanf("%s", entries[0].name);

    printf("Enter the amount of your monthly income: ");
    scanf("%d", &entries[0].amount);

    printf("Enter the category of your income (e.g., salary, rent): ");
    scanf("%s", entries[0].category);

    printf("Enter the month of your income (e.g., 1 for January): ");
    scanf("%d", &entries[0].month);

    printf("Enter the year of your income (e.g., 2022): ");
    scanf("%d", &entries[0].year);

    for (i = 1; i < MAX_ENTRIES; i++) {
        printf("Enter the name of entry #%d: ", i);
        scanf("%s", entries[i].name);

        printf("Enter the amount of entry #%d: ", i);
        scanf("%d", &entries[i].amount);

        printf("Enter the category of entry #%d: ", i);
        scanf("%s", entries[i].category);

        printf("Enter the month of entry #%d: ", i);
        scanf("%d", &entries[i].month);

        printf("Enter the year of entry #%d: ", i);
        scanf("%d", &entries[i].year);
    }

    printf("Here is your personal finance planner:\n");
    for (i = 0; i < MAX_ENTRIES; i++) {
        printf("%s\t%d\t%s\t%d\t%d\n", entries[i].name, entries[i].amount, entries[i].category, entries[i].month, entries[i].year);
    }

    return 0;
}