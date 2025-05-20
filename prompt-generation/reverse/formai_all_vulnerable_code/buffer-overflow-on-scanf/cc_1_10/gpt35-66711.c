//FormAI DATASET v1.0 Category: Banking Record System ; Style: paranoid
#include <stdio.h>
#include <string.h>

//define structure to store banking records
struct Record {
  char name[50];
  int account_number;
  float balance;
} record;

//function to encrypt account number
void encrypt(int *account_number){
  int key = 13; //arbitrary key
  *account_number ^= key; //bitwise XOR encryption
}

//function to decrypt account number
void decrypt(int *account_number){
  int key = 13; //same arbitrary key used for encryption
  *account_number ^= key; //bitwise XOR decryption
}

int main() {
  //initialize variables
  char password[50];
  int choice, num_records = 0;
  struct Record records[100];

  //prompt user to enter password
  printf("Enter password: ");
  scanf("%s", password);

  //encrypt password for storage
  for(int i = 0; i < strlen(password); i++){
    password[i] += i; //add index to each character
  }

  //menu loop
  do {
    //display options
    printf("\nSelect an option:\n");
    printf("1. Add banking record\n");
    printf("2. View banking record\n");
    printf("3. Exit program\n");

    //prompt user for input
    printf("Enter choice (1-3): ");
    scanf("%d", &choice);

    switch(choice){
      case 1: //add record
        //prompt user for record information
        printf("Enter name: ");
        scanf("%s", record.name);
        printf("Enter account number: ");
        scanf("%d", &record.account_number);
        printf("Enter balance: ");
        scanf("%f", &record.balance);

        //encrypt account number before storing
        encrypt(&record.account_number);

        //add record to array
        records[num_records] = record;
        num_records++;

        printf("Banking record added.\n");
        break;

      case 2: //view record
        //prompt user for account number
        printf("Enter account number: ");
        scanf("%d", &record.account_number);

        //decrypt account number for search
        decrypt(&record.account_number);
        
        //search for record in array
        for(int i = 0; i < num_records; i++){
          if(records[i].account_number == record.account_number){
            //print record information
            printf("Name: %s\nAccount Number: %d\nBalance: $%.2f\n",
              records[i].name, records[i].account_number, records[i].balance);
            break;
          }
        }
        break;

      case 3: //exit program
        printf("Exiting program.\n");
        break;

      default: //invalid input
        printf("Invalid choice.\n");
    }
  } while(choice != 3);

  return 0;
}