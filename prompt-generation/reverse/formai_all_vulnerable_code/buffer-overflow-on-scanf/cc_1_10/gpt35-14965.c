//FormAI DATASET v1.0 Category: Banking Record System ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure definition for banking record
struct bankingRecord {
    int accountNumber;
    char name[60];
    float balance;
};

int main() {
    int size, choice, flag = 0, accountNumber, index = 0;
    float balance;
    char name[60];
    
    //Asking user to enter the size of array to hold banking records
    printf("Enter the number of banking records to be stored: ");
    scanf("%d", &size);
    
    //Dynamic memory allocation for bankingRecord structure array
    struct bankingRecord* record = malloc(size * sizeof(struct bankingRecord));
    
    //Loop for menu-driven program
    do {
        printf("1. Add new record\n");
        printf("2. Search record by account number\n");
        printf("3. Display all records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                //Add new record
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter balance: ");
                scanf("%f", &balance);
                
                //Storing values in structure array
                record[index].accountNumber = accountNumber;
                strcpy(record[index].name, name);
                record[index].balance = balance;
                
                index++; //incrementing index to add new record in next iteration
                break;
            
            case 2:
                //Search record by account number
                printf("Enter account number to search: ");
                scanf("%d", &accountNumber);
                
                //Linear search for record
                for(int i = 0; i < index; i++) {
                    if(record[i].accountNumber == accountNumber) {
                        //Printing the record if account number matches
                        printf("Account Number: %d \t Name: %s \t Balance: %.2f\n", record[i].accountNumber, record[i].name, record[i].balance);
                        flag = 1; //Setting flag to 1 as record found
                        break; //Breaking the loop once record found
                    }
                }
                if(flag == 0) {
                    //Check if flag is 0, if yes record not found
                    printf("Record not found!\n");
                }
                flag = 0; //resetting flag to 0 for next iteration
                break;
            
            case 3:
                //Display all records
                for(int i = 0; i < index; i++) {
                    printf("Account Number: %d \t Name: %s \t Balance: %.2f\n", record[i].accountNumber, record[i].name, record[i].balance);
                }
                break;
            
            case 4:
                //Exit program
                printf("Exiting program....\n");
                break;
            
            default:
                //For invalid input
                printf("Invalid input!\n");
        }
    }while(choice != 4); //Loop until user chooses to exit
    
    //Memory deallocation
    free(record);
    
    return 0;
}