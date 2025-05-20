//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: shape shifting
#include<stdio.h>
#include<string.h>

struct medicine {
  char name[50];
  int batch_no;
  int exp_date;
  float price;
};

void add_medicine(struct medicine med[], int *n)
{
  printf("\nEnter the name of the medicine : ");
  scanf("%s", &med[*n].name);

  printf("\nEnter the batch number of the medicine : ");
  scanf("%d", &med[*n].batch_no);

  printf("\nEnter the expiry date of the medicine : ");
  scanf("%d", &med[*n].exp_date);

  printf("\nEnter the price of the medicine : ");
  scanf("%f", &med[*n].price);

  (*n)++;
  printf("\nMedicine record added successfully!\n");
}

void display_medicine(struct medicine med[], int n)
{
  printf("\nMedicine List\n");

  for(int i=0;i<n;i++) {
      printf("\nName          : %s",med[i].name);
      printf("\nBatch Number  : %d",med[i].batch_no);
      printf("\nExpiry Date   : %d",med[i].exp_date);
      printf("\nPrice         : %.2f\n",med[i].price);
  }
}

void del_medicine(struct medicine med[], int *n)
{
  int batch_no, flag=0;
  printf("Enter the batch number of the medicine to delete : ");
  scanf("%d",&batch_no);
  for(int i=0;i<*n;i++) {
    if(med[i].batch_no==batch_no) {
      flag=1;
      for(int j=i;j<*n-1;j++)
        med[j]=med[j+1];
      break;
    }
  }
  if(flag==1) {
    (*n)--;
    printf("\nRecord deleted successfully!\n");
  }
  else
    printf("\nMedicine not found!\n");
}

void search_medicine(struct medicine med[], int n)
{
  int batch_no,flag=0;
  printf("\nEnter the batch number of the medicine to search : ");
  scanf("%d",&batch_no);
  for(int i=0;i<n;i++) {
    if(med[i].batch_no==batch_no) {
      flag=1;
      printf("\nName          : %s",med[i].name);
      printf("\nBatch Number  : %d",med[i].batch_no);
      printf("\nExpiry Date   : %d",med[i].exp_date);
      printf("\nPrice         : %.2f\n",med[i].price);
      break;
    }
  }
  if(flag==0)
    printf("\nMedicine not found!\n");
}

void update_medicine(struct medicine med[], int n)
{
  int batch_no;
  printf("\nEnter the batch number of the medicine to be updated : ");
  scanf("%d",&batch_no);
  for(int i=0;i<n;i++) {
    if(med[i].batch_no==batch_no) {
      printf("\nEnter new name of the medicine : ");
      scanf("%s",med[i].name);

      printf("\nEnter new Batch Number of the medicine : ");
      scanf("%d",&med[i].batch_no);

      printf("\nEnter new Expiry Date of the medicine : ");
      scanf("%d",&med[i].exp_date);

      printf("\nEnter new Price of the medicine : ");
      scanf("%f",&med[i].price);

      printf("\nRecord is updated successfully!\n");
      break;
    }
  }
}

int main()
{
  struct medicine med[100];
  int n=0,choice;

  while(1) {
    printf("\n\n*************** Medical Store Management System ***************\n");
    printf("\n1. Add Medicine.");
    printf("\n2. Display Medicine.");
    printf("\n3. Delete Medicine.");
    printf("\n4. Search Medicine.");
    printf("\n5. Update Medicine.");
    printf("\n6. Exit.");
    printf("\nEnter your choice : ");

    scanf("%d",&choice);

    switch(choice) {
      case 1: add_medicine(med,&n);
              break;
      case 2: display_medicine(med,n);
              break;
      case 3: del_medicine(med,&n);
              break;
      case 4: search_medicine(med,n);
              break;
      case 5: update_medicine(med,n);
              break;
      case 6: return 0;
      default: printf("\nInvalid choice!\n");
    }
  }
  return 0;
}