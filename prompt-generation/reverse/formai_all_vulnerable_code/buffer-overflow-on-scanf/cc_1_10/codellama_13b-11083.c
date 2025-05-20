//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256
#define MAX_PLANS 10

typedef struct {
    char name[MAX_INPUT_LENGTH];
    float amount;
    char frequency[MAX_INPUT_LENGTH];
    char start_date[MAX_INPUT_LENGTH];
} Plan;

void print_plan(Plan plan) {
    printf("Plan: %s\n", plan.name);
    printf("Amount: $%0.2f\n", plan.amount);
    printf("Frequency: %s\n", plan.frequency);
    printf("Start Date: %s\n", plan.start_date);
}

void add_plan(Plan plans[], int *num_plans, Plan plan) {
    plans[*num_plans] = plan;
    (*num_plans)++;
}

void remove_plan(Plan plans[], int *num_plans, char *name) {
    int i;
    for (i = 0; i < *num_plans; i++) {
        if (strcmp(plans[i].name, name) == 0) {
            plans[i] = plans[*num_plans - 1];
            (*num_plans)--;
            return;
        }
    }
}

void display_plans(Plan plans[], int num_plans) {
    int i;
    for (i = 0; i < num_plans; i++) {
        print_plan(plans[i]);
    }
}

int main() {
    Plan plans[MAX_PLANS];
    int num_plans = 0;

    char input[MAX_INPUT_LENGTH];
    while (1) {
        printf("Enter a command: ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            Plan plan;
            printf("Enter plan name: ");
            scanf("%s", plan.name);
            printf("Enter amount: ");
            scanf("%f", &plan.amount);
            printf("Enter frequency: ");
            scanf("%s", plan.frequency);
            printf("Enter start date: ");
            scanf("%s", plan.start_date);
            add_plan(plans, &num_plans, plan);
        } else if (strcmp(input, "remove") == 0) {
            char name[MAX_INPUT_LENGTH];
            printf("Enter plan name: ");
            scanf("%s", name);
            remove_plan(plans, &num_plans, name);
        } else if (strcmp(input, "display") == 0) {
            display_plans(plans, num_plans);
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}