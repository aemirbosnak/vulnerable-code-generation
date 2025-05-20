//FormAI DATASET v1.0 Category: Banking Record System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Structure for record entries
struct banking_record {
    char name[25];
    char account_number[15];
    float balance;
    time_t last_access;
};

// Function to display menu options
void display_menu() {
    printf("\n--- Bank Record System ---\n");
    printf("1. Add new record\n");
    printf("2. Update record\n");
    printf("3. Delete record\n");
    printf("4. View all records\n");
    printf("5. Search record\n");
    printf("6. Exit\n");
    printf("---------------------------\n");
}

// Function to convert string to uppercase
void str_to_upper(char *str) {
    while(*str) {
        *str = toupper(*str);
        str++;
    }
}

int main() {
    int choice;
    int i, j;
    char search_name[25], search_acc_num[15];
    struct banking_record record_list[100];
    int num_records = 0;

    printf("\t\tWelcome to the Cyberbank Record System\n\n");

    while(1) {
        display_menu();
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Add new record
                printf("Enter name (max 25 characters): ");
                scanf("%s", record_list[num_records].name);
                printf("Enter account number (max 15 characters): ");
                scanf("%s", record_list[num_records].account_number);
                printf("Enter balance: ");
                scanf("%f", &record_list[num_records].balance);
                record_list[num_records].last_access = time(NULL);
                printf("Record added successfully!\n");
                num_records++;
                break;

            case 2: // Update record
                printf("Enter account number to update: ");
                scanf("%s", search_acc_num);

                for(i=0; i<num_records; i++) {
                    if(strcmp(record_list[i].account_number, search_acc_num) == 0) {
                        printf("Record found. Enter new balance: ");
                        scanf("%f", &record_list[i].balance);
                        record_list[i].last_access = time(NULL);
                        printf("Record updated successfully!\n");
                        break;
                    }
                }

                if(i == num_records) {
                    printf("Record not found!\n");
                }
                break;

            case 3: // Delete record
                printf("Enter account number to delete: ");
                scanf("%s", search_acc_num);

                for(i=0; i<num_records; i++) {
                    if(strcmp(record_list[i].account_number, search_acc_num) == 0) {
                        for(j=i; j<num_records-1; j++) {
                            record_list[j] = record_list[j+1];
                        }
                        num_records--;
                        printf("Record deleted successfully!\n");
                        break;
                    }
                }

                if(i == num_records) {
                    printf("Record not found!\n");
                }
                break;

            case 4: // View all records
                printf("Name\t\tAccount Number\tBalance\tLast Access\n");
                printf("--------------------------------------------------\n");

                for(i=0; i<num_records; i++) {
                    printf("%-25s%-15s%-10.2f%s", record_list[i].name, record_list[i].account_number, record_list[i].balance, ctime(&record_list[i].last_access));
                }
                printf("--------------------------------------------------\n");
                break;

            case 5: // Search record
                printf("Enter name to search: ");
                scanf("%s", search_name);
                str_to_upper(search_name);

                for(i=0; i<num_records; i++) {
                    char name_upper[25];
                    strcpy(name_upper, record_list[i].name);
                    str_to_upper(name_upper);

                    if(strstr(name_upper, search_name) != NULL) {
                        printf("Record found:\n");
                        printf("Name: %s\n", record_list[i].name);
                        printf("Account number: %s\n", record_list[i].account_number);
                        printf("Balance: %.2f\n", record_list[i].balance);
                        printf("Last access: %s\n", ctime(&record_list[i].last_access));
                        break;
                    }
                }

                if(i == num_records) {
                    printf("Record not found!\n");
                }
                break;

            case 6: // Exit
                printf("Thank you for using the Cyberbank Record System!\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}