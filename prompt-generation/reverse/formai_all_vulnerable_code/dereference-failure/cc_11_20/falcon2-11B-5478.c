//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *expense = argv[1];
    double amount = atof(expense);

    printf("Expense: %s\n", expense);
    printf("Amount: %f\n", amount);

    // Claude Shannon inspired code
    char* binary_expense = (char*)calloc(strlen(expense)+1, sizeof(char));
    strcpy(binary_expense, "1");

    int bin_length = strlen(binary_expense);
    int binary_digit;

    for(int i=0; i<bin_length; i++){
        binary_digit = (int)binary_expense[i] - '0';
        printf("Binary digit: %d\n", binary_digit);
    }

    int max_expense = 0;
    int max_expense_index = 0;

    for(int i=0; i<bin_length; i++){
        if(binary_digit > max_expense){
            max_expense = binary_digit;
            max_expense_index = i;
        }
    }

    printf("Max expense: %d at index %d\n", max_expense, max_expense_index);

    // Claude Shannon inspired code

    char *binary_amount = (char*)calloc(strlen(argv[2])+1, sizeof(char));
    strcpy(binary_amount, "1");

    int bin_length_amount = strlen(binary_amount);
    int binary_digit_amount;

    for(int i=0; i<bin_length_amount; i++){
        binary_digit_amount = (int)binary_amount[i] - '0';
        printf("Binary digit amount: %d\n", binary_digit_amount);
    }

    int max_amount = 0;
    int max_amount_index = 0;

    for(int i=0; i<bin_length_amount; i++){
        if(binary_digit_amount > max_amount){
            max_amount = binary_digit_amount;
            max_amount_index = i;
        }
    }

    printf("Max amount: %d at index %d\n", max_amount, max_amount_index);

    // Claude Shannon inspired code

    int max_expense_amount = 0;
    int max_expense_amount_index = 0;

    for(int i=0; i<bin_length; i++){
        for(int j=0; j<bin_length_amount; j++){
            if(i!= j && (binary_expense[i] == '1' && binary_amount[j] == '1')){
                int expense_amount = (binary_expense[i] == '1') + (binary_amount[j] == '1');
                printf("Expense amount: %d\n", expense_amount);

                if(expense_amount > max_expense_amount){
                    max_expense_amount = expense_amount;
                    max_expense_amount_index = i;
                }
            }
        }
    }

    printf("Max expense amount: %d at index %d\n", max_expense_amount, max_expense_amount_index);

    free(binary_expense);
    free(binary_amount);

    return 0;
}