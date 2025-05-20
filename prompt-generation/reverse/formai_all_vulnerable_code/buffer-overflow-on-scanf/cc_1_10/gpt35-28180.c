//FormAI DATASET v1.0 Category: Digital Auction System ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef struct
{
  char bid_no[10],item_name[20];
  float bid_amt;
} Bid;
int top=-1;
Bid stack[MAX];
void push(Bid b)
{
  if(top==MAX-1)
  {
    printf("\nBid Stack is Full!");
  }
  else
  {
    top++;
    stack[top]=b;
    printf("\nBid has been accepted!");
  }
}
int pop()
{
  if(top==-1)
  {
    printf("\nBid Stack is Empty!");
    return -1;
  }
  else
  {
    int i;
    Bid temp=stack[top];
    for(i=top;i>=0;i--)
    {
      if(temp.bid_amt>stack[i].bid_amt)
      {
        stack[i+1]=stack[i];
      }
      else
      {
        break;
      }
    }
    stack[i+1]=temp;
    top--;
    return i+1;
  }
}
void display()
{
  int i;
  if(top==-1)
  {
    printf("\nBid Stack is Empty!");
  }
  else
  {
    printf("\nBid Number\tItem Name\tBid Amount");
    for(i=0;i<=top;i++)
    {
      printf("\n%s\t\t%s\t\t%.2f",stack[i].bid_no,stack[i].item_name,stack[i].bid_amt);
    }
  }
}
int main()
{
  int choice,result;
  Bid b;
  while(1)
  {
    printf("\n\n**************WELCOME TO DIGITAL AUCTION SYSTEM**************");
    printf("\n1) Place Bid");
    printf("\n2) Give Item to Highest Bidder");
    printf("\n3) Display All Bids");
    printf("\n4) Quit");
    printf("\nEnter Your Choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        printf("\nEnter Bid Number: ");
        scanf("%s",b.bid_no);
        printf("Enter Item Name: ");
        scanf("%s",b.item_name);
        printf("Enter Bid Amount: ");
        scanf("%f",&b.bid_amt);
        push(b);
        break;
      case 2:
        result=pop();
        if(result!=-1)
        {
          printf("\n**********Bid Winner**********");
          printf("\nBid Number: %s",stack[result].bid_no);
          printf("\nItem Name: %s",stack[result].item_name);
          printf("\nBid Amount: %.2f",stack[result].bid_amt);
        }
        break;
      case 3:
        display();
        break;
      case 4:
        exit(0);
      default:
        printf("\nInvalid Choice!");
    }
  }
  return 0;
}