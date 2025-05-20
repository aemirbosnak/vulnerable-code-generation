//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Person {
    char name[20];
    double salary;
    double savings;
    double expenses;
    double investments;
    double net_worth;
};

void add_person(struct Person *people, int n, char name[], double salary, double savings, double expenses, double investments, double net_worth) {
    struct Person p;
    strcpy(p.name, name);
    p.salary = salary;
    p.savings = savings;
    p.expenses = expenses;
    p.investments = investments;
    p.net_worth = net_worth;
    people[n] = p;
}

void print_person(struct Person *people, int n) {
    for(int i=0; i<n; i++) {
        printf("Person %d: %s\n", i+1, people[i].name);
        printf("Salary: $%.2f\n", people[i].salary);
        printf("Savings: $%.2f\n", people[i].savings);
        printf("Expenses: $%.2f\n", people[i].expenses);
        printf("Investments: $%.2f\n", people[i].investments);
        printf("Net Worth: $%.2f\n", people[i].net_worth);
        printf("\n");
    }
}

int main() {
    struct Person people[100];
    int n = 0;
    char name[20];
    double salary, savings, expenses, investments, net_worth;

    while(1) {
        printf("Enter person details: ");
        scanf("%s %lf %lf %lf %lf %lf", name, &salary, &savings, &expenses, &investments, &net_worth);

        if(strcmp(name, "quit") == 0) {
            break;
        }

        add_person(people, n, name, salary, savings, expenses, investments, net_worth);
        n++;
    }

    print_person(people, n);

    return 0;
}