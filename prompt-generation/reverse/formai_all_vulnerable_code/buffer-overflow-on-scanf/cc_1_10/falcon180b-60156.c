//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int budget;
    int income;
    int expenses;
} user;

void main() {
    int choice, i;
    user u[10];
    int num_users = 0;

    do {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add User\n");
        printf("2. View Users\n");
        printf("3. Manage Finances\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_users < 10) {
                    num_users++;
                    printf("Enter the name of the user: ");
                    scanf("%s", u[num_users-1].name);
                    printf("Enter the monthly budget: ");
                    scanf("%d", &u[num_users-1].budget);
                    printf("Enter the monthly income: ");
                    scanf("%d", &u[num_users-1].income);
                    printf("Enter the monthly expenses: ");
                    scanf("%d", &u[num_users-1].expenses);
                } else {
                    printf("Maximum number of users reached.\n");
                }
                break;

            case 2:
                printf("Users:\n");
                for(i=0; i<num_users; i++) {
                    printf("%s\n", u[i].name);
                }
                break;

            case 3:
                printf("Enter the name of the user: ");
                scanf("%s", u[num_users-1].name);
                printf("Enter the monthly budget: ");
                scanf("%d", &u[num_users-1].budget);
                printf("Enter the monthly income: ");
                scanf("%d", &u[num_users-1].income);
                printf("Enter the monthly expenses: ");
                scanf("%d", &u[num_users-1].expenses);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 4);
}