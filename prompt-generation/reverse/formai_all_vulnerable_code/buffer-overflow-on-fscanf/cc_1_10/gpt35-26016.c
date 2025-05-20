//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Finance {
    char category[30];
    float amount;
    char date[11];
};

int main() {
    struct Finance finance[100];
    int num_of_items = 0;
    char option[10];

    // check if file exists
    FILE* fp = fopen("finance.txt", "r");
    if(fp != NULL) {
        while(!feof(fp)) {
            fscanf(fp, "%s %f %s", finance[num_of_items].category, &finance[num_of_items].amount, finance[num_of_items].date);
            num_of_items++;
        }
        fclose(fp);
    }

    while(1) {
        printf("\nPersonal Finance Planner\n");
        printf("-----------------------\n");
        printf("1. Add Item\n");
        printf("2. View Item\n");
        printf("3. Exit\n");

        printf("\nEnter your option: ");
        scanf("%s", option);

        if(!strcmp(option, "1")) {
            printf("\nEnter category name: ");
            scanf("%s", finance[num_of_items].category);

            printf("Enter amount: ");
            scanf("%f", &finance[num_of_items].amount);

            printf("Enter date (dd/mm/yyyy): ");
            scanf("%s", finance[num_of_items].date);

            num_of_items++;

            printf("\nItem added successfully!\n");
        }
        else if(!strcmp(option, "2")) {
            int i;
            float total_spent = 0;
            printf("\n+----------------------+----------------------+-------------+\n");
            printf("| Category             | Amount               | Date        |\n");
            printf("+----------------------+----------------------+-------------+\n");
            for(i = 0; i < num_of_items; i++) {
                printf("| %-20s| %-20.2f| %-12s|\n", finance[i].category, finance[i].amount, finance[i].date);
                total_spent += finance[i].amount;
            }
            printf("+----------------------+----------------------+-------------+\n");
            printf("| Total Spent          | %-20.2f|             |\n", total_spent);
            printf("+----------------------+----------------------+-------------+\n");
        }
        else if(!strcmp(option, "3")) {
            // save data to file
            int i;
            FILE* fp = fopen("finance.txt", "w");
            for(i = 0; i < num_of_items; i++) {
                fprintf(fp, "%s %.2f %s\n", finance[i].category, finance[i].amount, finance[i].date);
            }
            fclose(fp);

            printf("\nExiting from the program...\n");
            exit(0);
        }
        else {
            printf("\nInvalid option! Please try again.\n");
        }
    }

    return 0;
}