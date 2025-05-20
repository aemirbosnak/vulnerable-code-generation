//FormAI DATASET v1.0 Category: Database simulation ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define MAX_TRANSACTIONS 1000
#define MAX_RECORDS 100

// Structure to store transaction details in the database
typedef struct {
    char type[10];
    float amount;
    char date[20];
} Transaction;

// Structure to store record details in the database
typedef struct {
    char name[50];
    char class[20];
    int age;
    int gold;
    Transaction transactions[MAX_TRANSACTIONS];
    int num_transactions;
} Record;

// Function to display menu options
void display_menu() {
    printf("Medieval Database\n");
    printf("-----------------\n");
    printf("1. Add New Record\n");
    printf("2. Display All Records\n");
    printf("3. Search Record\n");
    printf("4. Exit\n");
}

// Function to add a new record to the database
void add_record(Record records[], int *num_records) {
    // Check if there is space for a new record
    if (*num_records >= MAX_RECORDS) {
        printf("Database is full!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", records[*num_records].name);

    printf("Enter class: ");
    scanf("%s", records[*num_records].class);

    printf("Enter age: ");
    scanf("%d", &records[*num_records].age);

    printf("Enter gold: ");
    scanf("%d", &records[*num_records].gold);

    // Initialize number of transactions for this new record to 0
    records[*num_records].num_transactions = 0;

    printf("Record added to database!\n");

    // Increment number of records in the database
    (*num_records)++;
}

// Function to display all records in the database
void display_all_records(Record records[], int num_records) {
    printf("Name\tClass\tAge\tGold\tNum Transactions\n");
    for (int i = 0; i < num_records; i++) {
        printf("%s\t%s\t%d\t%d\t%d\n", records[i].name, records[i].class, records[i].age, records[i].gold, records[i].num_transactions);
    }
}

// Function to search for a record in the database
void search_record(Record records[], int num_records) {
    char search_name[50];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_records; i++) {
        if (strcasecmp(search_name, records[i].name) == 0) {
            printf("Name: %s\n", records[i].name);
            printf("Class: %s\n", records[i].class);
            printf("Age: %d\n", records[i].age);
            printf("Gold: %d\n", records[i].gold);
            printf("Transactions:\n");
            for (int j = 0; j < records[i].num_transactions; j++) {
                printf("%s\t%.2f\t%s\n", records[i].transactions[j].type, records[i].transactions[j].amount, records[i].transactions[j].date);
            }
            return;
        }
    }

    printf("Record not found!\n");
}

int main() {
    Record records[MAX_RECORDS];
    int num_records = 0;
    int choice;

    printf("Welcome to the Medieval Database!\n");

    // Seed random number generator for transaction dates
    srand(time(0));

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record(records, &num_records);
                break;
            case 2:
                display_all_records(records, num_records);
                break;
            case 3:
                search_record(records, num_records);
                break;
            case 4:
                printf("Thank you for using the Medieval Database!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}