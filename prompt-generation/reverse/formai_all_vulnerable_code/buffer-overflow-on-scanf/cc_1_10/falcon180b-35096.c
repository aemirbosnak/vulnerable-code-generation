//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    char name[20];
    FILE *fp;
    time_t now = time(0);
    struct tm *tm = localtime(&now);
    fprintf(stdout, "Please enter your name: ");
    scanf("%s", name);
    fprintf(stdout, "Welcome, %s! Today is %s", name, asctime(tm));
    fprintf(stdout, "\n1. Create budget\n2. View budget\n3. Exit\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1: {
            fprintf(stdout, "Please enter the name of the budget: ");
            scanf("%s", name);
            fp = fopen(name, "w");
            fprintf(fp, "Name: %s\n", name);
            fprintf(fp, "Income: \nExpenses: \n");
            fclose(fp);
            fprintf(stdout, "Budget created successfully!");
            break;
        }
        case 2: {
            fprintf(stdout, "Please enter the name of the budget: ");
            scanf("%s", name);
            fp = fopen(name, "r");
            if(fp == NULL) {
                fprintf(stdout, "Budget not found!");
            }
            else {
                while(fgets(name, 20, fp)!= NULL) {
                    fprintf(stdout, "%s", name);
                }
                fclose(fp);
            }
            break;
        }
        case 3: {
            fprintf(stdout, "Thank you for using Personal Finance Planner!");
            break;
        }
        default: {
            fprintf(stdout, "Invalid choice!");
        }
    }
    return 0;
}