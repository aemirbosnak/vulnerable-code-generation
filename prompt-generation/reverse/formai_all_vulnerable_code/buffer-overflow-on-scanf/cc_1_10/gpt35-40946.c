//FormAI DATASET v1.0 Category: Banking Record System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

struct record {
    int account_number;
    char name[50];
    float balance;
} bank_record;

void new_record() {
    printf("\n\t\tNew Record\n");
    printf("\tEnter Account Number: ");
    scanf("%d", &bank_record.account_number);
    printf("\tEnter Name: ");
    scanf("%s", bank_record.name);
    printf("\tEnter Balance: ");
    scanf("%f", &bank_record.balance);
}

void display_record() {
    printf("\n\t\tDisplay Record\n");
    printf("\tAccount Number: %d\n", bank_record.account_number);
    printf("\tName: %s\n", bank_record.name);
    printf("\tBalance: %.2f\n", bank_record.balance);
}

void modify_record() {
    printf("\n\t\tModify Record\n");
    printf("\tEnter Account Number: ");
    scanf("%d", &bank_record.account_number);
    printf("\tEnter Name: ");
    scanf("%s", bank_record.name);
    printf("\tEnter Balance: ");
    scanf("%f", &bank_record.balance);
}

void delete_record() {
    printf("\n\t\tDelete Record\n");
    printf("\tEnter Account Number: ");
    scanf("%d", &bank_record.account_number);
    strcpy(bank_record.name, "");
    bank_record.balance = 0.0;
}

int main() {
    int option;
    do {
        printf("\n\t\tBanking Record System");
        printf("\n\t1. New Record");
        printf("\n\t2. Display Record");
        printf("\n\t3. Modify Record");
        printf("\n\t4. Delete Record");
        printf("\n\t5. Exit");

        printf("\n\tEnter Option: ");
        scanf("%d", &option);

        switch(option) {
            case 1: new_record(); break;
            case 2: display_record(); break;
            case 3: modify_record(); break;
            case 4: delete_record(); break;
            case 5: exit(0);
            default: printf("\n\tInvalid Option. Try Again.");
        }
    } while (option != 5);
}