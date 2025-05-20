//FormAI DATASET v1.0 Category: Banking Record System ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//define structure for the record
struct record{
    char name[30];
    char account_type[20];
    int account_number;
    int balance;
};

//function to create new bank account
void create_account(){
    struct record new_record; //create new record
    FILE *f_ptr; //create file pointer

    //open file in append mode
    f_ptr = fopen("bank_records.txt", "a");

    //take input from user
    printf("--- Create New Account ---\n\n");
    printf("Enter Name: ");
    scanf("%s", new_record.name);
    printf("Enter Account Type: ");
    scanf("%s", new_record.account_type);
    printf("Enter Account Number: ");
    scanf("%d", &new_record.account_number);
    printf("Enter Balance: ");
    scanf("%d", &new_record.balance);

    //write the new record to the file
    fprintf(f_ptr, "%s\t%s\t%d\t%d\n", new_record.name, new_record.account_type, new_record.account_number, new_record.balance);

    //close the file
    fclose(f_ptr);

    printf("\nAccount created successfully.\n");
}

//function to display all records
void display_all_records(){
    struct record current_record;
    FILE *f_ptr;

    //open file in read mode
    f_ptr = fopen("bank_records.txt", "r");

    //display header
    printf("--- Bank Records ---\n\n");
    printf("Name\tType\tNumber\tBalance\n");

    //read and display all records
    while(fscanf(f_ptr, "%s%s%d%d", current_record.name, current_record.account_type, &current_record.account_number, &current_record.balance) != EOF){
        printf("%s\t%s\t%d\t%d\n", current_record.name, current_record.account_type, current_record.account_number, current_record.balance);
    }

    //close the file
    fclose(f_ptr);

    printf("\n");
}

//function to search for a record by account number
void search_record(){
    int account_number, found=0;
    struct record current_record;
    FILE *f_ptr;

    //open file in read mode
    f_ptr = fopen("bank_records.txt", "r");

    //take input from user
    printf("--- Search for a Record ---\n\n");
    printf("Enter Account Number: ");
    scanf("%d", &account_number);

    //search for the record with the given account number
    while(fscanf(f_ptr, "%s%s%d%d", current_record.name, current_record.account_type, &current_record.account_number, &current_record.balance) != EOF){
        if(current_record.account_number == account_number){
            printf("Name: %s\nAccount Type: %s\nAccount Number: %d\nBalance: %d\n", current_record.name, current_record.account_type, current_record.account_number, current_record.balance);
            found = 1;
            break;
        }
    }

    //close the file
    fclose(f_ptr);

    //if no record is found
    if(!found){
        printf("Record with account number %d not found.\n", account_number);
    }
}

//function to update record by account number
void update_record(){
    int account_number, found=0;
    struct record current_record, updated_record;
    FILE *f_ptr, *temp_ptr;

    //open files in read and write mode
    f_ptr = fopen("bank_records.txt", "r+");
    temp_ptr = fopen("temp.txt", "w+");

    //take input from user
    printf("--- Update Record ---\n\n");
    printf("Enter Account Number: ");
    scanf("%d", &account_number);

    //search for the record with the given account number
    while(fscanf(f_ptr, "%s%s%d%d", current_record.name, current_record.account_type, &current_record.account_number, &current_record.balance) != EOF){
        if(current_record.account_number == account_number){
            //take input for updated record
            printf("\nCurrent Balance: %d\n", current_record.balance);
            printf("Enter New Balance: ");
            scanf("%d", &updated_record.balance);

            //update the balance of the current record
            strcpy(updated_record.name, current_record.name);
            strcpy(updated_record.account_type, current_record.account_type);
            updated_record.account_number = current_record.account_number;
            fprintf(temp_ptr, "%s\t%s\t%d\t%d\n", updated_record.name, updated_record.account_type, updated_record.account_number, updated_record.balance);
            found = 1;
            printf("\nRecord updated successfully.\n");
        } else{
            //write the current record to the temp file
            fprintf(temp_ptr, "%s\t%s\t%d\t%d\n", current_record.name, current_record.account_type, current_record.account_number, current_record.balance);
        }
    }

    //close the files
    fclose(f_ptr);
    fclose(temp_ptr);

    //if no record is found
    if(!found){
        printf("Record with account number %d not found.\n", account_number);
    } else{
        //replace the original file with the temp file
        remove("bank_records.txt");
        rename("temp.txt", "bank_records.txt");
    }
}

//function to delete record by account number
void delete_record(){
    int account_number, found=0;
    struct record current_record;
    FILE *f_ptr, *temp_ptr;

    //open files in read and write mode
    f_ptr = fopen("bank_records.txt", "r+");
    temp_ptr = fopen("temp.txt", "w+");

    //take input from user
    printf("--- Delete Record ---\n\n");
    printf("Enter Account Number: ");
    scanf("%d", &account_number);

    //search for the record with the given account number
    while(fscanf(f_ptr, "%s%s%d%d", current_record.name, current_record.account_type, &current_record.account_number, &current_record.balance) != EOF){
        if(current_record.account_number == account_number){
            printf("\nRecord deleted successfully.\n");
            found = 1;
        } else{
            //write the current record to the temp file
            fprintf(temp_ptr, "%s\t%s\t%d\t%d\n", current_record.name, current_record.account_type, current_record.account_number, current_record.balance);
        }
    }

    //close the files
    fclose(f_ptr);
    fclose(temp_ptr);

    //if no record is found
    if(!found){
        printf("Record with account number %d not found.\n", account_number);
    } else{
        //replace the original file with the temp file
        remove("bank_records.txt");
        rename("temp.txt", "bank_records.txt");
    }
}

//main function
int main(){
    int choice;

    while(1){
        //display menu
        printf("--- Banking Record System ---\n\n");
        printf("1. Create New Account\n");
        printf("2. Display All Records\n");
        printf("3. Search for a Record\n");
        printf("4. Update Record\n");
        printf("5. Delete Record\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");

        //take input from user
        scanf("%d", &choice);

        //perform action based on user's choice
        switch(choice){
            case 1:
                create_account();
                break;
            case 2:
                display_all_records();
                break;
            case 3:
                search_record();
                break;
            case 4:
                update_record();
                break;
            case 5:
                delete_record();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid Choice. Please try again.\n");
        }
    }

    return 0;
}