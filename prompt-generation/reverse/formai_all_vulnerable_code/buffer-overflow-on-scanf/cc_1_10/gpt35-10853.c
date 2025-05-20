//FormAI DATASET v1.0 Category: Banking Record System ; Style: surprised
#include<stdio.h>
#include<string.h>

struct bankingRecord {
    char accountNumber[20];
    char accountName[50];
    float balance;
};

// Function to search account
void searchAccount(struct bankingRecord records[], int size){
    char searchTerm[20];
    int found = 0;
    printf("\nEnter Account Number to Search: ");
    scanf("%s", searchTerm);

    for(int i = 0; i < size; i++){
        if(strcmp(searchTerm, records[i].accountNumber) == 0){
            printf("\nAccount Number: %s\nAccount Name: %s\nBalance: %.2f\n", records[i].accountNumber, records[i].accountName, records[i].balance);
            found = 1;
            break;
        }
    }

    if(!found){
        printf("\nAccount Not Found!!\n");
    }
}

// Function to display all records
void displayAllRecords(struct bankingRecord records[], int size){
    printf("\n--- Banking Record System ---\n\n");
    printf("Account Number\tAccount Name\tBalance\n");
    for(int i = 0; i < size; i++){
        printf("%s\t\t%s\t\t%.2f\n", records[i].accountNumber, records[i].accountName, records[i].balance);
    }
}

// Function to add new account
void addNewAccount(struct bankingRecord records[], int size){
    printf("\n--- Adding New Account ---\n\n");
    printf("Enter Account Number: ");
    scanf("%s", records[size].accountNumber);
    printf("Enter Account Name: ");
    scanf("%s", records[size].accountName);
    printf("Enter Initial Balance: ");
    scanf("%f", &records[size].balance);
    printf("\nAccount Successfully Added!!\n");
}

// Function to remove an account
void removeAccount(struct bankingRecord records[], int* size){
    char searchTerm[20];
    int found = 0;
    printf("\nEnter Account Number to Remove: ");
    scanf("%s", searchTerm);

    for(int i = 0; i < *size; i++){
        if(strcmp(searchTerm, records[i].accountNumber) == 0){
            for(int j = i; j < *size - 1; j++){
                strcpy(records[j].accountNumber, records[j+1].accountNumber);
                strcpy(records[j].accountName, records[j+1].accountName);
                records[j].balance = records[j+1].balance;
            }
            (*size)--;
            found = 1;
            printf("\nAccount Successfully Removed!!\n");
            break;
        }
    }

    if(!found){
        printf("\nAccount Not Found!!\n");
    }
}

int main(){
    int choice, size = 0;
    struct bankingRecord records[100];

    do {
        printf("\n--- Banking Record System ---\n\n");
        printf("1. Search Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Add New Account\n");
        printf("4. Remove Account\n");
        printf("5. Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                searchAccount(records, size);
                break;

            case 2:
                displayAllRecords(records, size);
                break;

            case 3:
                addNewAccount(records, size);
                size++;
                break;

            case 4:
                removeAccount(records, &size);
                break;

            case 5:
                printf("\nExiting Program...\n\n");
                break;

            default:
                printf("\nInvalid Choice!!\n");
        }
    } while(choice != 5);

    return 0;
}