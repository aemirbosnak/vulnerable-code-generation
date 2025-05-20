//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

//structure for a transaction
typedef struct {
    char date[20];
    char type[20];
    float amount;
} transaction;

//structure for a category
typedef struct {
    char name[20];
    float total;
} category;

//function prototypes
void addTransaction(transaction *trans, int *size);
void printTransactions(transaction *trans, int size);
void addCategory(category *cat, int *size);
void printCategories(category *cat, int size);
void calculateTotal(transaction *trans, category *cat, int size);

int main() {
    transaction trans[MAX_SIZE];
    category cat[MAX_SIZE];
    int transSize = 0, catSize = 0;

    //initialize categories
    addCategory(cat, &catSize);

    int choice;
    while(1) {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Transaction\n");
        printf("2. Print Transactions\n");
        printf("3. Add Category\n");
        printf("4. Print Categories\n");
        printf("5. Calculate Total\n");
        printf("6. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addTransaction(trans, &transSize);
                break;
            case 2:
                printTransactions(trans, transSize);
                break;
            case 3:
                addCategory(cat, &catSize);
                break;
            case 4:
                printCategories(cat, catSize);
                break;
            case 5:
                calculateTotal(trans, cat, transSize);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

//add a transaction
void addTransaction(transaction *trans, int *size) {
    printf("Enter transaction details:\n");
    printf("Date: ");
    scanf("%s", trans[*size].date);
    printf("Type: ");
    scanf("%s", trans[*size].type);
    printf("Amount: ");
    scanf("%f", &trans[*size].amount);

    (*size)++;
}

//print transactions
void printTransactions(transaction *trans, int size) {
    printf("\nTransactions:\n");
    for(int i=0; i<size; i++) {
        printf("%s - %s - %.2f\n", trans[i].date, trans[i].type, trans[i].amount);
    }
}

//add a category
void addCategory(category *cat, int *size) {
    printf("Enter category name: ");
    scanf("%s", cat[*size].name);
    cat[*size].total = 0;

    (*size)++;
}

//print categories
void printCategories(category *cat, int size) {
    printf("\nCategories:\n");
    for(int i=0; i<size; i++) {
        printf("%s - Total: %.2f\n", cat[i].name, cat[i].total);
    }
}

//calculate total for each category
void calculateTotal(transaction *trans, category *cat, int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(strcmp(trans[j].type, cat[i].name) == 0) {
                cat[i].total += trans[j].amount;
            }
        }
    }
}