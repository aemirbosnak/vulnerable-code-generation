//FormAI DATASET v1.0 Category: Banking Record System ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Struct definition for Bank Record
typedef struct{
    int acc_no;
    char name[20];
    float balance;
} Record;

//Function to add new record
void addRecord(Record* records, int* num_records){
    printf("\nEnter account number: ");
    scanf("%d",&records[*num_records].acc_no);
    printf("Enter name: ");
    scanf("%s",records[*num_records].name);
    printf("Enter balance: ");
    scanf("%f",&records[*num_records].balance);
    (*num_records)++;
}

//Function to display all records
void displayRecords(Record* records, int num_records){
    if(num_records==0){
        printf("\nNo records found.\n");
    }
    else{
        printf("\nBank Records:\n");
        printf("Acc No \tName \tBalance\n");
        for(int i=0;i<num_records;i++){
            printf("%d \t%s \t%.2f\n",records[i].acc_no,records[i].name,records[i].balance);
        }
    }
}

//Function to find a record by account number
void findRecord(Record* records, int num_records){
    int acc_no,found=0;
    printf("\nEnter account number: ");
    scanf("%d",&acc_no);
    for(int i=0;i<num_records;i++){
        if(records[i].acc_no==acc_no){
            printf("\nRecord Found:\n");
            printf("Acc No \tName \tBalance\n");
            printf("%d \t%s \t%.2f\n",records[i].acc_no,records[i].name,records[i].balance);
            found=1;
            break;
        }
    }
    if(!found){
        printf("\nRecord not found.\n");
    }
}

//Function to delete a record by account number
void deleteRecord(Record* records, int* num_records){
    int acc_no,found=0;
    printf("\nEnter account number: ");
    scanf("%d",&acc_no);
    for(int i=0;i<*num_records;i++){
        if(records[i].acc_no==acc_no){
            for(int j=i;j<*num_records-1;j++){
                records[j]=records[j+1];
            }
            (*num_records)--;
            printf("\nRecord deleted successfully.\n");
            found=1;
            break;
        }
    }
    if(!found){
        printf("\nRecord not found.\n");
    }
}

int main(){
    Record* records=(Record*)malloc(sizeof(Record)*10);//Allocate memory for 10 records
    int choice,num_records=0;
    while(1){
        printf("\nBank Record System\n");
        printf("1. Add record\n");
        printf("2. Display all records\n");
        printf("3. Find a record\n");
        printf("4. Delete a record\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                if(num_records==10){
                    printf("\nMemory limit exceeded. Cannot add more records.\n");
                }
                else{
                    addRecord(records,&num_records);
                }
                break;
            case 2:
                displayRecords(records,num_records);
                break;
            case 3:
                findRecord(records,num_records);
                break;
            case 4:
                deleteRecord(records,&num_records);
                break;
            case 5:
                free(records);//Free memory
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}