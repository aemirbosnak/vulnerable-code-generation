//FormAI DATASET v1.0 Category: Banking Record System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

struct banking_record {
    int account_number;
    char account_holder[50];
    float balance;
};

void create_record(struct banking_record *b) {
    printf("Enter account number: ");
    scanf("%d", &(b->account_number));
    printf("Enter account holder name: ");
    scanf("%s", b->account_holder);
    printf("Enter balance: ");
    scanf("%f", &(b->balance));
    printf("Record created successfully!\n\n");
}

void display_record(struct banking_record *b) {
    printf("Account number: %d\n", b->account_number);
    printf("Account holder: %s\n", b->account_holder);
    printf("Balance: %.2f\n\n", b->balance);
}

int main() {
    int choice;
    struct banking_record *records;
    int size = 0;
    
    // initialize an empty array of records
    records = (struct banking_record*) malloc(size * sizeof(struct banking_record));
    
    while (1) {
        printf("1. Create a record\n");
        printf("2. Display all records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                size++;
                records = (struct banking_record*) realloc(records, size * sizeof(struct banking_record));
                create_record(&records[size-1]);
                break;
            case 2:
                printf("Banking records:\n");
                for (int i=0; i<size; i++) {
                    display_record(&records[i]);
                }
                break;
            case 3:
                free(records);
                exit(0);
            default:
                printf("Invalid choice!\n\n");
                break;
        }
    }
    return 0;
}