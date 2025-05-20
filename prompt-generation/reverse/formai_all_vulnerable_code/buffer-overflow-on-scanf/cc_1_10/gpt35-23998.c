//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

/* Define the maximum length of the input strings */
#define MAX_LENGTH 100

/* Define the structure of each expense */
struct expense{
    char name[MAX_LENGTH];
    float cost;
};

int main(){
    int num_expenses;
    printf("How many expenses do you have for this month? ");
    scanf("%d", &num_expenses);
    printf("\n");

    /* Allocate memory for the expenses */
    struct expense *expenses = malloc(num_expenses * sizeof(struct expense));

    /* Read in each expense from the user */
    for(int i=0; i<num_expenses; i++){
        printf("Enter name of expense #%d: ", i+1);
        scanf("%s", &(expenses[i].name));
        printf("Enter cost of expense #%d: ", i+1);
        scanf("%f", &(expenses[i].cost));
        printf("\n");
    }

    /* Print out all of the expenses */
    printf("Here are your expenses for this month:\n");
    printf("------------------------------------\n");
    for(int i=0; i<num_expenses; i++){
        printf("%s:\t$%.2f\n", expenses[i].name, expenses[i].cost);
    }
    printf("\n");

    /* Calculate the total cost of all expenses */
    float total_cost = 0.0;
    for(int i=0; i<num_expenses; i++){
        total_cost += expenses[i].cost;
    }

    /* Print out the total cost */
    printf("Your total cost for this month is: $%.2f\n", total_cost);

    /* Calculate the average cost per expense */
    float avg_cost = total_cost / num_expenses;

    /* Print out the average cost */
    printf("Your average cost per expense is: $%.2f\n", avg_cost);

    /* Deallocate memory for the expenses */
    free(expenses);

    /* Terminate the program without error */
    return 0;
}