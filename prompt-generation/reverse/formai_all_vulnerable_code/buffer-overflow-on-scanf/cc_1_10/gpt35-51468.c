//FormAI DATASET v1.0 Category: Banking Record System ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Bank_Record{
  char name[50];
  int account_no;
  float balance;
};

void addRecord(struct Bank_Record[], int);
void displayRecords(struct Bank_Record[], int);
void searchRecord(struct Bank_Record[], int);
void updateRecord(struct Bank_Record[], int);
void deleteRecord(struct Bank_Record[], int);

int main(){
  int n=0,choice,i;
  struct Bank_Record record[100];
  while(1){
    printf("Enter your choice:\n");
    printf("1. Add a Bank Record\n");
    printf("2. Display All Records\n");
    printf("3. Search a Record\n");
    printf("4. Update a Record\n");
    printf("5. Delete a Record\n");
    printf("6. Exit\n");
    scanf("%d",&choice);

    switch(choice){
      case 1:
        addRecord(record,n);
        n++;
        break;
      case 2:
        displayRecords(record,n);
        break;
      case 3:
        searchRecord(record,n);
        break;
      case 4:
        updateRecord(record,n);
        break;
      case 5:
        deleteRecord(record,n);
        n--;
        break;
      case 6:
        exit(0);
      default:
        printf("Enter a valid choice.\n");
    }
  }
  return 0;
}

void addRecord(struct Bank_Record record[], int n){
  printf("Enter the name:\n");
  scanf("%s",&record[n].name);
  printf("Enter the account number:\n");
  scanf("%d",&record[n].account_no);
  printf("Enter the balance:\n");
  scanf("%f",&record[n].balance);
}

void displayRecords(struct Bank_Record record[], int n){
  if(n==0){
    printf("No records found.\n");
  }else{
    int i;
    printf("Name\tAccount Number\tBalance\n");
    for(i=0;i<n;i++){
      printf("%s\t%d\t%f\n",record[i].name, record[i].account_no, record[i].balance);
    }
  }
}

void searchRecord(struct Bank_Record record[], int n){
  int accountNo, i, flag=0;
  printf("Enter the account number:\n");
  scanf("%d",&accountNo);

  for(i=0;i<n;i++){
    if(record[i].account_no == accountNo){
      printf("Name: %s\n",record[i].name);
      printf("Account Number: %d\n",record[i].account_no);
      printf("Balance: %f\n",record[i].balance);
      flag=1;
      break;
    }
  }

  if(flag==0){
    printf("The record with account number %d not found.\n",accountNo);
  }
}

void updateRecord(struct Bank_Record record[], int n){
  int accountNo, i, flag=0;
  printf("Enter the account number:\n");
  scanf("%d",&accountNo);

  for(i=0;i<n;i++){
    if(record[i].account_no == accountNo){
      printf("Enter the updated name:\n");
      scanf("%s",&record[i].name);
      printf("Enter the updated balance:\n");
      scanf("%f",&record[i].balance);
      flag=1;
      break;
    }
  }

  if(flag==0){
    printf("The record with account number %d not found.\n",accountNo);
  }
}

void deleteRecord(struct Bank_Record record[], int n){
  int accountNo, i, flag=0;
  printf("Enter the account number:\n");
  scanf("%d",&accountNo);

  for(i=0;i<n;i++){
    if(record[i].account_no == accountNo){
      int j;
      for(j=i;j<n-1;j++){
        strcpy(record[j].name,record[j+1].name);
        record[j].account_no = record[j+1].account_no;
        record[j].balance = record[j+1].balance;
      }
      flag=1;
      break;
    }
  }

  if(flag==0){
    printf("The record with account number %d not found.\n",accountNo);
  }else{
    printf("Record deleted successfully.\n");
  }
}