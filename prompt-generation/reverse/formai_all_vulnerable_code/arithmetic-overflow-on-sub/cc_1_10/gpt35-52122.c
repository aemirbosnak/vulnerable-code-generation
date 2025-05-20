//FormAI DATASET v1.0 Category: Banking Record System ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct bank_record {
  char account_number[20];
  char name[50];
  float balance;
};

void create(struct bank_record *b) {
  printf("Enter Account Number: ");
  scanf("%s", b->account_number);
  printf("Enter Name: ");
  scanf("%s", b->name);
  printf("Enter Balance: ");
  scanf("%f", &b->balance);
}

void read(struct bank_record *b) {
  printf("Account Number: %s \n", b->account_number);
  printf("Name: %s \n", b->name);
  printf("Balance: %f \n", b->balance);
}

void update(struct bank_record *b) {
  float balance;
  printf("Enter New Balance: ");
  scanf("%f", &balance);
  b->balance = balance;
}

void delete(struct bank_record *b) {
  strcpy(b->account_number, "");
  strcpy(b->name, "");
  b->balance = 0.0;
}

int main() {
  int choice, n, i;
  struct bank_record b[50];
  printf("Enter Number of Records: ");
  scanf("%d", &n);
  for(i=0;i<n;i++) {
    printf("\nRecord #%d\n", i+1);
    create(&b[i]);
  }
  do {
    printf("\n\n1. Create Record\n2. Read Record\n3. Update Balance\n");
    printf("4. Delete Record\n5. Exit\nEnter Choice: ");
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        create(&b[n]);
        n++;
        break;
      case 2:
        printf("Enter Record Number: ");
        scanf("%d", &i);
        read(&b[i-1]);
        break;
      case 3:
        printf("Enter Record Number: ");
        scanf("%d", &i);
        update(&b[i-1]);
        break;
      case 4: 
        printf("Enter Record Number: ");
        scanf("%d", &i);
        delete(&b[i-1]);
        break;
      case 5:
        exit(0);
      default:
        printf("Invalid Choice\n");
    }
  } while(1);
  return 0;
}