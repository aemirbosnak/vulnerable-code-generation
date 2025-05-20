//FormAI DATASET v1.0 Category: Banking Record System ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 1000

// Structure to store customer details
struct customer {
    char name[20];
    char address[50];
    char phone[15];
    int account_no;
    float balance;
};

int main() {
    // Declare variables
    struct customer bank[MAX_SIZE];
    int choice, num_customers=0, i;
    FILE *fp;

    // Menu-driven program
    printf("Welcome to the Banking Record System!\n\n");
    while (1) {
        printf("1. Add Customer\n2. Display All Customers\n3. Search Customer\n4. Modify Customer Details\n5. Delete Customer\n6. Save Data to File\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                // Add customer details
                printf("\nEnter customer name: ");
                fflush(stdin);
                fgets(bank[num_customers].name, 20, stdin);
                printf("Enter customer address: ");
                fflush(stdin);
                fgets(bank[num_customers].address, 50, stdin);
                printf("Enter customer phone number: ");
                fflush(stdin);
                fgets(bank[num_customers].phone, 15, stdin);
                printf("Enter customer account number: ");
                scanf("%d", &bank[num_customers].account_no);
                printf("Enter opening balance: ");
                scanf("%f", &bank[num_customers].balance);
                num_customers++;
                printf("\nCustomer Details added successfully!\n\n");
                break;

            case 2:
                // Display all customer details
                printf("\n---All Customers---\n\n");
                for (i=0; i<num_customers; i++) {
                    printf("Customer %d\n", i+1);
                    printf("Name: %s", bank[i].name);
                    printf("Address: %s", bank[i].address);
                    printf("Phone: %s", bank[i].phone);
                    printf("Account number: %d\n", bank[i].account_no);
                    printf("Balance: Rs. %.2f\n\n", bank[i].balance);
                }
                break;

            case 3:
                // Search customer by account number
                printf("\nEnter account number: ");
                int acc_no;
                scanf("%d", &acc_no);
                for (i=0; i<num_customers; i++) {
                    if (bank[i].account_no == acc_no) {
                        printf("\nCustomer Details found!\n\n");
                        printf("Name: %s", bank[i].name);
                        printf("Address: %s", bank[i].address);
                        printf("Phone: %s", bank[i].phone);
                        printf("Account number: %d\n", bank[i].account_no);
                        printf("Balance: Rs. %.2f\n\n", bank[i].balance);
                        break;
                    }
                }
                if (i == num_customers)
                    printf("\nCustomer not found.\n\n");
                break;

            case 4:
                // Modify customer details by account number
                printf("\nEnter account number: ");
                int acc_no_mod;
                scanf("%d", &acc_no_mod);
                for (i=0; i<num_customers; i++) {
                    if (bank[i].account_no == acc_no_mod) {
                        printf("\nEnter new details:\n");
                        printf("Name: ");
                        fflush(stdin);
                        fgets(bank[i].name, 20, stdin);
                        printf("Address: ");
                        fflush(stdin);
                        fgets(bank[i].address, 50, stdin);
                        printf("Phone: ");
                        fflush(stdin);
                        fgets(bank[i].phone, 15, stdin);
                        printf("\nCustomer details modified successfully!\n\n");
                        break;
                    }
                }
                if (i == num_customers)
                    printf("\nCustomer not found.\n\n");
                break;

            case 5:
                // Delete customer by account number
                printf("\nEnter account number: ");
                int acc_no_del;
                scanf("%d", &acc_no_del);
                for (i=0; i<num_customers; i++) {
                    if (bank[i].account_no == acc_no_del) {
                        if (i != num_customers-1) {
                            bank[i] = bank[num_customers-1];
                        }
                        num_customers--;
                        printf("\nCustomer details deleted successfully!\n\n");
                        break;
                    }
                }
                if (i == num_customers)
                    printf("\nCustomer not found.\n\n");
                break;

            case 6:
                // Save data to file
                fp = fopen("bank_record.txt", "w");
                for (i=0; i<num_customers; i++) {
                    fprintf(fp, "%s %s %s %d %.2f\n", bank[i].name, bank[i].address, bank[i].phone, bank[i].account_no, bank[i].balance);
                }
                fclose(fp);
                printf("\nData saved to file successfully!\n\n");
                break;

            case 7:
                // Exit program
                printf("\nThank you for using the Banking Record System!\n");
                exit(0);

            default:
                printf("\nInvalid Input. Try Again.\n\n");
        }
    }

    return 0;
}