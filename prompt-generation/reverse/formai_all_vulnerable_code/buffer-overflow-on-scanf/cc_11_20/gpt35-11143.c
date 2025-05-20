//FormAI DATASET v1.0 Category: Banking Record System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record {
    int acc_number;
    char name[20];
    int balance;
};

int main() {
    int option, num_records = 0, i;
    struct Record records[100];

    while(1) {
        printf("C Banking Record System\n");
        printf("1. Add a record\n");
        printf("2. Edit a record\n");
        printf("3. Delete a record\n");
        printf("4. Display all records\n");
        printf("5. Exit\n");

        printf("Enter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nEnter account number: ");
                scanf("%d", &records[num_records].acc_number);

                printf("Enter name: ");
                scanf("%s", records[num_records].name);

                printf("Enter initial balance: ");
                scanf("%d", &records[num_records].balance);

                num_records++;
                printf("\nRecord added successfully!\n\n");
                break;

            case 2:
                printf("\nEnter account number to edit: ");
                int acc_num;
                scanf("%d", &acc_num);

                for(i = 0; i < num_records; i++) {
                    if(records[i].acc_number == acc_num) {
                        printf("\nEnter new name: ");
                        scanf("%s", records[i].name);

                        printf("Enter new balance: ");
                        scanf("%d", &records[i].balance);

                        printf("\nRecord updated successfully!\n\n");
                        break;
                    }
                }

                if(i == num_records) {
                    printf("\nRecord not found!\n\n");
                }
                break;

            case 3:
                printf("\nEnter account number to delete: ");
                int del_acc_num;
                scanf("%d", &del_acc_num);

                for(i = 0; i < num_records; i++) {
                    if(records[i].acc_number == del_acc_num) {
                        while(i < num_records-1) {
                            records[i] = records[i+1];
                            i++;
                        }

                        num_records--;
                        printf("\nRecord deleted successfully!\n\n");
                        break;
                    }
                }

                if(i == num_records) {
                    printf("\nRecord not found!\n\n");
                }
                break;

            case 4:
                printf("\n---All Records---\n\n");

                for(i = 0; i < num_records; i++) {
                    printf("Account Number: %d\n", records[i].acc_number);
                    printf("Name: %s\n", records[i].name);
                    printf("Balance: %d\n\n", records[i].balance);
                }
                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid option. Try again.\n\n");
        }
    }

    return 0;
}