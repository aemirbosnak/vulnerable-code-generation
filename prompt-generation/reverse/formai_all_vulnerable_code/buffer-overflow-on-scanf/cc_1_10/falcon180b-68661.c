//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 100

struct expense{
    char name[MAX_SIZE];
    float amount;
};

void add_expense(struct expense *exp, int *size){
    char name[MAX_SIZE];
    float amount;

    printf("Enter expense name: ");
    scanf("%s", name);

    printf("Enter expense amount: $");
    scanf("%f", &amount);

    strcpy(exp[*size].name, name);
    exp[*size].amount = amount;

    (*size)++;
}

void display_expenses(struct expense *exp, int size){
    printf("Expenses:\n");

    for(int i=0; i<size; i++){
        printf("%s - $%.2f\n", exp[i].name, exp[i].amount);
    }
}

void surreal_expense(){
    struct expense exp[MAX_SIZE];
    int size = 0;

    add_expense(exp, &size);
    add_expense(exp, &size);
    add_expense(exp, &size);

    display_expenses(exp, size);
}

int main(){
    surreal_expense();

    return 0;
}