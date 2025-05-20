//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Record{
    char name[50];
    double amount;
};

void display_menu(){
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. Add Savings\n");
    printf("4. Add Investment\n");
    printf("5. View All Records\n");
    printf("6. Delete Record\n");
    printf("7. Modify Record\n");
    printf("8. Quit\n");
}

int main(){
    srand(time(NULL));
    int choice;
    struct Record record;
    int num_records = 0;

    while(1){
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter income name: ");
                scanf("%s", record.name);
                printf("Enter income amount: ");
                scanf("%lf", &record.amount);
                printf("Income record added successfully.\n");
                break;
            case 2:
                printf("Enter expense name: ");
                scanf("%s", record.name);
                printf("Enter expense amount: ");
                scanf("%lf", &record.amount);
                printf("Expense record added successfully.\n");
                break;
            case 3:
                printf("Enter savings name: ");
                scanf("%s", record.name);
                printf("Enter savings amount: ");
                scanf("%lf", &record.amount);
                printf("Savings record added successfully.\n");
                break;
            case 4:
                printf("Enter investment name: ");
                scanf("%s", record.name);
                printf("Enter investment amount: ");
                scanf("%lf", &record.amount);
                printf("Investment record added successfully.\n");
                break;
            case 5:
                printf("All records:\n");
                for(int i=0; i<num_records; i++){
                    printf("Name: %s, Amount: %.2lf\n", record.name, record.amount);
                }
                break;
            case 6:
                printf("Delete Record:\n");
                printf("Enter name of the record to delete: ");
                scanf("%s", record.name);
                printf("Record deleted successfully.\n");
                break;
            case 7:
                printf("Modify Record:\n");
                printf("Enter name of the record to modify: ");
                scanf("%s", record.name);
                printf("Enter new name: ");
                scanf("%s", record.name);
                printf("Enter new amount: ");
                scanf("%lf", &record.amount);
                printf("Record modified successfully.\n");
                break;
            case 8:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}