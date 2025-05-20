//FormAI DATASET v1.0 Category: Banking Record System ; Style: Romeo and Juliet
// Romeo and Juliet style C Banking Record System Example Program
// O Romeo, O Romeo! Wherefore art thou, Romeo?
// Here, my Juliet. I stand before thee with my heart in my hands.
// Thy heart doth beat a melody sweet, but my mind doth wander to matters of finance.
// Fear not, my dear, for with this program we may keep record of our wealth.
// Aye, my love, let us write our names in the ledger and commence our business.

#include <stdio.h>
#include <stdlib.h>

struct account {
    char owner_name[20];
    int acc_num;
    float balance;
};

int main() {
    int choice, i, n, acc_count = 0;
    struct account acc[100];
    char name[20];
    float amount;

    printf("O Romeo, O Romeo! How many accounts shall we open today?\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("What shall be the name on the account, my love?\n");
        scanf("%s", acc[i].owner_name);
        printf("What shall be the account number, my sweet?\n");
        scanf("%d", &acc[i].acc_num);
        printf("What shall be the initial balance, my dearest?\n");
        scanf("%f", &acc[i].balance);
        acc_count++;
    }

    while (1) {
        printf("What shall we do today, my heart?\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check balance\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Whose account shall we deposit in, my love?\n");
                scanf("%s", name);
                for (i = 0; i < acc_count; i++) {
                    if (strcmp(name, acc[i].owner_name) == 0) {
                        printf("How much shall we deposit, my dove?\n");
                        scanf("%f", &amount);
                        acc[i].balance += amount;
                        printf("Deposit successful, my dear.\n");
                        break;
                    }
                }
                if (i == acc_count) {
                    printf("Alas, my love, no such account exists.\n");
                }
                break;

            case 2:
                printf("Whose account shall we withdraw from, my heart?\n");
                scanf("%s", name);
                for (i = 0; i < acc_count; i++) {
                    if (strcmp(name, acc[i].owner_name) == 0) {
                        printf("How much shall we withdraw, my angel?\n");
                        scanf("%f", &amount);
                        if (acc[i].balance >= amount) {
                            acc[i].balance -= amount;
                            printf("Withdrawal successful, my sweetest.\n");
                        }
                        else {
                            printf("Oh woe is me, there be insufficient funds in the account.\n");
                        }
                        break;
                    }
                }
                if (i == acc_count) {
                    printf("Alas, my love, no such account exists.\n");
                }
                break;

            case 3:
                printf("Whose balance shall we check, my darling?\n");
                scanf("%s", name);
                for (i = 0; i < acc_count; i++) {
                    if (strcmp(name, acc[i].owner_name) == 0) {
                        printf("The balance in the account is %.2f, my love.\n", acc[i].balance);
                        break;
                    }
                }
                if (i == acc_count) {
                    printf("Alas, my love, no such account exists.\n");
                }
                break;

            case 4:
                printf("Farewell, my love.\n");
                exit(0);

            default:
                printf("Oh woe is me, that is not a valid option.\n");
                break;
        }
    }

    return 0;
}