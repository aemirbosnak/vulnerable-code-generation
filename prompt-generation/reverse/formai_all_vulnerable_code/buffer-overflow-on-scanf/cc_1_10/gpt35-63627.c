//FormAI DATASET v1.0 Category: Banking Record System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Record{
  int account_number;
  char account_name[50];
  float account_balance;
}Record;

// Function declarations
void add_record();
void display_record();
void search_record();
void update_record();
void delete_record();

int main()
{
  int option;
  printf("\n<--- Welcome to the Banking Record System --->\n");

  do{
    printf("\nChoose an Option:\n");
    printf("1. Add a Record\n");
    printf("2. Display All Records\n");
    printf("3. Search a Record\n");
    printf("4. Update a Record\n");
    printf("5. Delete a Record\n");
    printf("6. Exit the Program\n");

    printf("\nOption: ");
    scanf("%d", &option);

    switch(option){
      case 1:
        add_record();
        break;
      case 2:
        display_record();
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
        printf("\nThank you for using the Banking Record System!\n\n");
        exit(0); // Terminate the program
      default:
        printf("\nInvalid option. Please try again.\n");
    }
  } while(1);

  return 0;
}

// Function definitions
void add_record(){
  Record r;
  FILE *fp;
  fp = fopen("records.dat", "a+b");
  printf("\nEnter the following details to add a Record:\n");
  printf("Account Number: ");
  scanf("%d", &r.account_number);
  printf("Account Name: ");
  scanf("%s", r.account_name);
  printf("Account Balance: ");
  scanf("%f", &r.account_balance);
  fwrite(&r, sizeof(r), 1, fp);
  fclose(fp);
  printf("\nRecord added successfully.\n");
}
void display_record(){
  Record r;
  FILE *fp;
  fp = fopen("records.dat", "rb");
  printf("\n<--- All Records in the System --->\n");
  printf("%-20s%-20s%-20s\n", "Account Number", "Account Name", "Account Balance");
  while(fread(&r, sizeof(r), 1, fp)){
    printf("%-20d%-20s%-20.2f\n", r.account_number, r.account_name, r.account_balance);
  }
  fclose(fp);
}
void search_record(){
  Record r;
  FILE *fp;
  int acc_no, found=0;
  fp = fopen("records.dat", "rb");
  printf("\nEnter Account Number to search for: ");
  scanf("%d", &acc_no);
  while(fread(&r, sizeof(r), 1, fp)){
    if(r.account_number == acc_no){
      found = 1;
      printf("\nRecord found!\n");
      printf("%-20s%-20s%-20s\n", "Account Number", "Account Name", "Account Balance");
      printf("%-20d%-20s%-20.2f\n", r.account_number, r.account_name, r.account_balance);
      break;
    }
  }
  if(!found){
    printf("\nRecord not found.\n");
  }
  fclose(fp);
}
void update_record(){
  Record r;
  FILE *fp;
  int acc_no, found=0;
  fp = fopen("records.dat", "rb+");
  printf("\nEnter Account Number to update: ");
  scanf("%d", &acc_no);
  while(fread(&r, sizeof(r), 1, fp)){
    if(r.account_number == acc_no){
      found = 1;
      printf("\nRecord found!\n");
      printf("%-20s%-20s%-20s\n", "Account Number", "Account Name", "Account Balance");
      printf("%-20d%-20s%-20.2f\n", r.account_number, r.account_name, r.account_balance);
      printf("\nEnter the new account name: ");
      scanf("%s", r.account_name);
      printf("Enter the new account balance: ");
      scanf("%f", &r.account_balance);
      fseek(fp, -sizeof(r), SEEK_CUR);
      fwrite(&r, sizeof(r), 1, fp);
      printf("\nRecord updated successfully.\n");
      break;
    }
  }
  if(!found){
    printf("\nRecord not found.\n");
  }
  fclose(fp);
}
void delete_record(){
  Record r;
  FILE *fp, *temp;
  int acc_no, found=0;
  fp = fopen("records.dat", "rb");
  temp = fopen("temp.dat", "wb");
  printf("\nEnter Account Number to delete: ");
  scanf("%d", &acc_no);
  while(fread(&r, sizeof(r), 1, fp)){
    if(r.account_number == acc_no){
      found = 1;
      printf("\nRecord found and deleted successfully.\n");
    }
    else{
      fwrite(&r, sizeof(r), 1, temp);
    }
  }
  if(!found){
    printf("\nRecord not found.\n");
  }
  fclose(fp);
  fclose(temp);
  remove("records.dat");
  rename("temp.dat", "records.dat");
}