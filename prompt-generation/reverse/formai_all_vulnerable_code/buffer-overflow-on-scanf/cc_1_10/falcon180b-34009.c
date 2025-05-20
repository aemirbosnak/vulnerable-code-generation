//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_ITEMS 100

typedef struct {
    char name[100];
    double amount;
    time_t date;
} Item;

int main() {
    int numItems = 0;
    Item items[MAX_ITEMS];
    char choice;

    while(1) {
        printf("Personal Finance Planner\n");
        printf("1. Add item\n");
        printf("2. Modify item\n");
        printf("3. Delete item\n");
        printf("4. View items\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(numItems >= MAX_ITEMS) {
                    printf("Maximum number of items reached.\n");
                } else {
                    printf("Enter item name: ");
                    scanf("%s", items[numItems].name);
                    printf("Enter item amount: ");
                    scanf("%lf", &items[numItems].amount);
                    items[numItems].date = time(NULL);
                    numItems++;
                }
                break;
            case '2':
                printf("Enter item number to modify: ");
                scanf("%d", &numItems);
                printf("Enter new item name: ");
                scanf("%s", items[numItems-1].name);
                printf("Enter new item amount: ");
                scanf("%lf", &items[numItems-1].amount);
                items[numItems-1].date = time(NULL);
                break;
            case '3':
                printf("Enter item number to delete: ");
                scanf("%d", &numItems);
                numItems--;
                break;
            case '4':
                printf("Item\tDate\tAmount\n");
                for(int i=0; i<numItems; i++) {
                    printf("%s\t%s\t%.2lf\n", items[i].name, ctime(&items[i].date), items[i].amount);
                }
                break;
            case '5':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}