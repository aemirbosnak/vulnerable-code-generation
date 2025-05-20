//FormAI DATASET v1.0 Category: Banking Record System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to hold banking record
struct record{
    int accountNumber;
    char holderName[50];
    float balance;
};

// Function to add new record
void addRecord(struct record *r, int *size){
    printf("Enter account number: ");
    scanf("%d", &r[*size].accountNumber);

    printf("Enter account holder name: ");
    scanf("%s", r[*size].holderName);

    printf("Enter account balance: ");
    scanf("%f", &r[*size].balance);

    printf("Record added successfully!\n");

    (*size)++;
}

// Function to display all records
void displayRecords(struct record *r, int size){
    if(size == 0){
        printf("No records found!\n");
        return;
    }

    printf("ACCOUNT NUMBER\tHOLDER NAME\tBALANCE\n");

    for(int i=0; i<size; i++){
        printf("%d\t\t%s\t\t%.2f\n", r[i].accountNumber, r[i].holderName, r[i].balance);
    }
}

int main(){
    int size = 0, choice;
    struct record *records = NULL;

    while(choice != 3){
        printf("\nBANKING RECORD SYSTEM\n");
        printf("1. Add new record\n");
        printf("2. Display all records\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                records = (struct record*)realloc(records, (size+1)*sizeof(struct record));
                addRecord(records, &size);
                break;

            case 2:
                displayRecords(records, size);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }

    }

    free(records);

    return 0;
}