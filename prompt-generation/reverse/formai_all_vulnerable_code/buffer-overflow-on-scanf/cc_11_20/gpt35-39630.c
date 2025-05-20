//FormAI DATASET v1.0 Category: Banking Record System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct bank_record {
    char name[50];
    int account_num;
    float balance;
};

int main() {
    struct bank_record records[MAX_RECORDS];
    int num_records = 0;
    int choice = 0;
    int i;

    do {
        printf("Enter a choice:\n");
        printf("1) Add a record\n");
        printf("2) Display all records\n");
        printf("3) Search for a record\n");
        printf("4) Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_records >= MAX_RECORDS) {
                    printf("Error: Maximum number of records reached!\n");
                    break;
                }
                printf("Enter name: ");
                scanf("%s", records[num_records].name);
                printf("Enter account number: ");
                scanf("%d", &records[num_records].account_num);
                printf("Enter balance: ");
                scanf("%f", &records[num_records].balance);
                num_records++;
                break;
            case 2:
                if (num_records == 0) {
                    printf("No records found!\n");
                    break;
                }
                printf("Records:\n");
                for (i = 0; i < num_records; i++) {
                    printf("%s (%d): $%.2f\n", records[i].name, records[i].account_num, records[i].balance);
                }
                break;
            case 3:
                if (num_records == 0) {
                    printf("No records found!\n");
                    break;
                }
                char search_term[50];
                int search_results[MAX_RECORDS];
                int num_search_results = 0;
                printf("Enter search term: ");
                scanf("%s", search_term);
                for (i = 0; i < num_records; i++) {
                    if (strstr(records[i].name, search_term)) {
                        search_results[num_search_results] = i;
                        num_search_results++;
                    }
                }
                if (num_search_results == 0) {
                    printf("No results found for search term \"%s\"\n", search_term);
                    break;
                }
                printf("%d results found for search term \"%s\":\n", num_search_results, search_term);
                for (i = 0; i < num_search_results; i++) {
                    printf("%s (%d): $%.2f\n", records[search_results[i]].name, records[search_results[i]].account_num, records[search_results[i]].balance);
                }
                break;
            case 4:
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}