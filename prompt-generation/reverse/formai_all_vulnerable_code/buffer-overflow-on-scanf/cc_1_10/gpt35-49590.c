//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: lively
#include<stdio.h>

// Defining the structure for medicines
struct medicine{
  int med_id;
  char med_name[50];
  float price;
  int quantity;
};

// Function to display available medicines
void display_medicines(struct medicine med[], int n){
  printf("List of Medicines available:\n\n");
  printf("ID\tName\t\t\tPrice\tQuantity\n");
  for(int i=0;i<n;i++){
    printf("%d\t%-20s\t%.2f\t%d\n",med[i].med_id,med[i].med_name,med[i].price,med[i].quantity);
  }
}

// Function to search a medicine by ID
int search_by_id(struct medicine med[], int id, int n){
  for(int i=0;i<n;i++){
    if(med[i].med_id == id){
      return i;
    }
  }
  return -1;
}

// Function to buy a medicine
void buy_medicine(struct medicine med[], int n){
  int id, index, quantity;
  printf("Enter the ID of the medicine you want to buy: ");
  scanf("%d",&id);
  index = search_by_id(med, id, n);
  if(index == -1){
    printf("Sorry, we don't have this medicine.\n");
  }
  else{
    printf("Enter the quantity you want to buy: ");
    scanf("%d",&quantity);
    if(quantity > med[index].quantity){
      printf("Sorry, we have only %d units of this medicine.\n",med[index].quantity);
    }
    else{
      printf("Total Cost: %.2f\n",med[index].price*quantity);
      med[index].quantity -= quantity;
      printf("Thank you for shopping with us.\n");
    }
  }
}

int main(){
  int n, ch;
  printf("Welcome to ABC Medical Store\n\n");
  printf("Enter the number of medicines available: ");
  scanf("%d",&n);
  struct medicine med[n]; // creating med as an array of struct medicine
  for(int i=0;i<n;i++){
    printf("Enter the details of medicine %d:\n",i+1);
    printf("ID: ");
    scanf("%d",&med[i].med_id);
    printf("Name: ");
    scanf("%s",med[i].med_name);
    printf("Price: ");
    scanf("%f",&med[i].price);
    printf("Quantity: ");
    scanf("%d",&med[i].quantity);
    printf("\n");
  }
  while(1){
    printf("\n1. Display Medicines\n2. Buy Medicine\n3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
    switch(ch){
      case 1: display_medicines(med,n); break;
      case 2: buy_medicine(med,n); break;
      case 3: return 0;
      default: printf("Invalid choice.\n");
    }
  }
  return 0;
}