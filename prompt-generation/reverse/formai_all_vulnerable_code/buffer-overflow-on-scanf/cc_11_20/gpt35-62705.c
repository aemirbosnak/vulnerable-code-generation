//FormAI DATASET v1.0 Category: Banking Record System ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct client {
    int account_number;
    char name[20];
    float balance;
} client;

int main() {
    client c[50];
    int option = 0, num_clients = 0;

    printf("\n\nOh, Banking Record System! I am smitten with thee.\n");
    printf("What dost thou wish to do today?\n");
    printf("1. Add a new client.\n");
    printf("2. Update an existing client's balance.\n");
    printf("3. Search for a client by account number.\n");
    printf("4. Display all client records.\n");
    printf("5. Exit this program, and be but a memory.\n");

    while (option != 5) {
        printf("\nMake thy choice, and live or die by thine own sword: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (num_clients < 50) {
                    printf("\nWhich fair name doth this client bear? Enter it here: ");
                    scanf("%s", c[num_clients].name);
                    printf("\nAnd what be their account number, to be found on yonder roll?");
                    scanf("%d", &c[num_clients].account_number);
                    printf("\nAnd with what amount doth their accounts overflow? ");
                    scanf("%f", &c[num_clients].balance);
                    num_clients++;
                    printf("\nForsooth, a new client hath been added to our rolls. May their accounts never decrease, but always grow!");
                } else {
                    printf("\nAlack, our records are already full! Pray try again another day.");
                }

                break;

            case 2:
                printf("\nEnter the account number of the client whose balance thou dost seek to change: ");
                int search_acc_num;
                scanf("%d", &search_acc_num);

                for (int i = 0; i < num_clients; i++) {
                    if (c[i].account_number == search_acc_num) {
                        printf("\nThe current balance of %s's account is %.2f. ", c[i].name, c[i].balance);
                        printf("What amount would thou like to add or subtract? (Negative values will subtract)");
                        float add_or_sub;
                        scanf("%f", &add_or_sub);

                        c[i].balance += add_or_sub;

                        printf("\n%s's account now hath a balance of %.2f. ",
                            c[i].name, c[i].balance);
                        break;
                    }

                    if (i == num_clients - 1) {
                        printf("\nThis account number was not found in our records. Pray try again.");
                    }
                }

                break;

            case 3:
                printf("\nEnter the account number of the client thou dost wish to find: ");
                int search_account_num;
                scanf("%d", &search_account_num);

                for (int i = 0; i < num_clients; i++) {
                    if (c[i].account_number == search_account_num) {
                        printf("\n%s's account hath a balance of %.2f.", c[i].name, c[i].balance);
                        break;
                    }

                    if (i == num_clients - 1) {
                        printf("\nThis account number was not found in our records. Pray try again.");
                    }
                }

                break;

            case 4:
                printf("\nAll client records, as they stand:\n");

                for (int i = 0; i < num_clients; i++) {
                    printf("%d. %s hath an account balance of %.2f.\n", c[i].account_number, c[i].name, 
                        c[i].balance);
                }

                break;

            case 5:
                printf("\nFarewell, sweet Banking Record System, and be not forgotten!");
                break;

            default:
                printf("\nSpeak plainly, good sirrah! We cannot understand thee. Please enter one of the options above.");
                break;
        }
    }

    return 0;
}