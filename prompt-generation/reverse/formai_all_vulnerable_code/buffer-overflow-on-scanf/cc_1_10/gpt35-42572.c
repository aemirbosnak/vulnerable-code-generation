//FormAI DATASET v1.0 Category: Banking Record System ; Style: sophisticated
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct bank_record // structure to hold bank records
{
    int account_number;
    char name[30];
    float balance;
};

struct bank_record* insert_record(struct bank_record* records, int* count); // function to insert a new bank record
void display_records(struct bank_record* records, int count); // function to display all bank records
void search_record(struct bank_record* records, int count); // function to search for a specific account record
void update_record(struct bank_record* records, int count); // function to update a specific bank record
void delete_record(struct bank_record* records, int* count); // function to delete a specific bank record
void save_records(struct bank_record* records, int count); // function to save bank records to a file
struct bank_record* load_records(int* count); // function to load bank records from a file

int main()
{
    struct bank_record* records = NULL; // initialize to NULL
    int count = 0, choice;
    records = load_records(&count); // load the bank records from a file

    do
    {
        printf("\n\nBank Record System Menu\n");
        printf("1. Insert a new record\n");
        printf("2. Display all records\n");
        printf("3. Search a record\n");
        printf("4. Update a record\n");
        printf("5. Delete a record\n");
        printf("6. Save records to file\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                records = insert_record(records, &count); // insert a new bank record
                break;
            case 2:
                display_records(records, count); // display all bank records
                break;
            case 3:
                search_record(records, count); // search for a specific bank record
                break;
            case 4:
                update_record(records, count); // update a specific bank record
                break;
            case 5:
                delete_record(records, &count); // delete a specific bank record
                break;
            case 6:
                save_records(records, count); // save all bank records to a file
                break;
            case 7:
                printf("\nExiting Bank Record System. Thank you!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 7);

    free(records); // free the memory allocated for bank records
    return 0;
}

struct bank_record* insert_record(struct bank_record* records, int* count)
{
    (*count)++; // increment the count of bank records by 1
    records = (struct bank_record*) realloc(records, (*count) * sizeof(struct bank_record)); // add memory to hold the new bank record

    printf("\nEnter account number: ");
    scanf("%d", &records[(*count)-1].account_number);
    printf("Enter name: ");
    getchar();
    fgets(records[(*count)-1].name, 30, stdin);
    printf("Enter balance: ");
    scanf("%f", &records[(*count)-1].balance);

    printf("\nRecord successfully added!\n");

    return records;
}

void display_records(struct bank_record* records, int count)
{
    if (count == 0) // no records to display
    {
        printf("\nNo records found!\n");
    }
    else
    {
        printf("\nAccount Number\tName\tBalance\n");
        printf("---------------------------------------------------\n");
        for (int i = 0; i < count; i++)
        {
            printf("%d\t\t%s\t%.2f\n", records[i].account_number, records[i].name, records[i].balance);
        }
    }
}

void search_record(struct bank_record* records, int count)
{
    int account_number, flag = 0;

    if (count == 0) // no records to search for
    {
        printf("\nNo records found!\n");
    }
    else
    {
        printf("\nEnter account number to search for: ");
        scanf("%d", &account_number);

        for (int i = 0; i < count; i++)
        {
            if (records[i].account_number == account_number)
            {
                printf("\nRecord Found!\n");
                printf("Account Number\tName\tBalance\n");
                printf("---------------------------------------------------\n");
                printf("%d\t\t%s\t%.2f\n", records[i].account_number, records[i].name, records[i].balance);
                flag = 1;
                break;
            }
        }

        if (flag == 0) // record not found
        {
            printf("Record not found!\n");
        }
    }
}

void update_record(struct bank_record* records, int count)
{
    int account_number, flag = 0;

    if (count == 0) // no records to update
    {
        printf("\nNo records found!\n");
    }
    else
    {
        printf("\nEnter account number to update: ");
        scanf("%d", &account_number);

        for (int i = 0; i < count; i++)
        {
            if (records[i].account_number == account_number)
            {
                printf("\nRecord Found!\n");
                printf("Account Number\tName\tBalance\n");
                printf("---------------------------------------------------\n");
                printf("%d\t\t%s\t%.2f\n", records[i].account_number, records[i].name, records[i].balance);

                printf("\nEnter the new details:\n");
                printf("Enter new account number: ");
                scanf("%d", &records[i].account_number);
                printf("Enter new name: ");
                getchar();
                fgets(records[i].name, 30, stdin);
                printf("Enter new balance: ");
                scanf("%f", &records[i].balance);

                printf("\nRecord successfully updated!\n");
                flag = 1;
                break;
            }
        }

        if (flag == 0) // record not found
        {
            printf("\nRecord not found!\n");
        }
    }
}

void delete_record(struct bank_record* records, int* count)
{
    int account_number, flag = 0, index;

    if (*count == 0) // no records to delete
    {
        printf("\nNo records found!\n");
    }
    else
    {
        printf("\nEnter account number to delete: ");
        scanf("%d", &account_number);

        for (int i = 0; i < *count; i++)
        {
            if (records[i].account_number == account_number)
            {
                printf("\nRecord Found!\n");
                printf("Account Number\tName\tBalance\n");
                printf("---------------------------------------------------\n");
                printf("%d\t\t%s\t%.2f\n", records[i].account_number, records[i].name, records[i].balance);

                index = i;
                flag = 1;
                break;
            }
        }

        if (flag == 0) // record not found
        {
            printf("\nRecord not found!\n");
        }
        else
        {
            for (int i = index; i < *count-1; i++)
            {
                records[i] = records[i+1];
            }

            (*count)--; // decrement the count of bank records by 1
            records = (struct bank_record*) realloc(records, (*count) * sizeof(struct bank_record)); // remove memory used by deleted record
            printf("\nRecord successfully deleted!\n");
        }
    }
}

void save_records(struct bank_record* records, int count)
{
    FILE* fp = fopen("bank_records.txt", "w");

    if (fp == NULL) // error opening file
    {
        printf("\nError opening file!\n");
    }
    else if (count == 0) // no records to save
    {
        printf("\nNo records found!\n");
    }
    else
    {
        fprintf(fp, "Account Number\tName\tBalance\n");
        fprintf(fp, "---------------------------------------------------\n");
        for (int i = 0; i < count; i++)
        {
            fprintf(fp, "%d\t\t%s\t%.2f\n", records[i].account_number, records[i].name, records[i].balance);
        }
        printf("\nRecords successfully saved to file!\n");
    }

    fclose(fp); // close file
}

struct bank_record* load_records(int* count)
{
    struct bank_record* records = NULL;
    FILE* fp = fopen("bank_records.txt", "r");

    if (fp == NULL) // error opening file
    {
        printf("\nError opening file!\n");
    }
    else // process file contents
    {
        char line[100];

        while (fgets(line, 100, fp) != NULL)
        {
            (*count)++; // increment the count of bank records by 1
            records = (struct bank_record*) realloc(records, (*count) * sizeof(struct bank_record)); // add memory to hold the new bank record

            char* account_number_str = strtok(line, "\t");
            char* name = strtok(NULL, "\t");
            char* balance_str = strtok(NULL, "\t");

            records[(*count)-1].account_number = atoi(account_number_str);
            strcpy(records[(*count)-1].name, name);
            records[(*count)-1].balance = atof(balance_str);
        }

        fclose(fp); // close file
    }

    return records;
}