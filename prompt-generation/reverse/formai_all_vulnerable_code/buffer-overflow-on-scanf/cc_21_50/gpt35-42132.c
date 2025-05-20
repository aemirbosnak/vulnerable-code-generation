//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Warehouse
{
  char itemName[50];
  int itemQuantity;
  float itemPrice;
};

int main()
{
  int option, i, updateQuantity, flag=0, numItems=0;
  float totalValue=0;
  char name[50], search[50];
  struct Warehouse stock[100];

  printf("\n Welcome to Warehouse Management System!");
  
  while(1)
  {
    printf("\n\n[Warehouse Menu]\n");
    printf("1. Add Item\n");
    printf("2. Search Item\n");
    printf("3. Update Item Quantity\n");
    printf("4. Display all Items\n");
    printf("5. Total Value of Stock\n");
    printf("6. Exit\n");

    printf("\nChoose an option:");
    scanf("%d", &option);

    switch(option)
    {
      case 1:
      {
        printf("\nEnter the item name:");
        scanf("%s", name);
        for(i=0; i<numItems; i++)
        {
          if(strcmp(stock[i].itemName, name)==0)
          {
            flag=1;
            printf("\nItem already exists in stock. Update quantity instead.");
          }
        }
        if(flag==0)
        {
          printf("\nEnter the item quantity:");
          scanf("%d", &stock[numItems].itemQuantity);
          printf("\nEnter the item price:");
          scanf("%f", &stock[numItems].itemPrice);
          strcpy(stock[numItems].itemName, name);
          numItems++;
          printf("\nItem %s has been added to the stock!", name);
        }
        break;
      }

      case 2:
      {
        printf("\nEnter the item name to search:");
        scanf("%s", search);
        flag=0;
        for(i=0; i<numItems; i++)
        {
          if(strcmp(stock[i].itemName, search)==0)
          {
            printf("\nItem %s is found in stock. Quantity:%d Price:%.2f", stock[i].itemName, stock[i].itemQuantity, stock[i].itemPrice);
            flag=1;
            break;
          }
        }
        if(flag==0)
        {
          printf("\nItem %s is not found in stock!", search);
        }
        break;
      }

      case 3:
      {
        printf("\nEnter the item name to update:");
        scanf("%s", search);
        flag=0;
        for(i=0; i<numItems; i++)
        {
          if(strcmp(stock[i].itemName, search)==0)
          {
            printf("\nEnter the new quantity:");
            scanf("%d", &updateQuantity);
            stock[i].itemQuantity=updateQuantity;
            printf("\nQuantity of %s has been updated to %d", stock[i].itemName, updateQuantity);
            flag=1;
            break;
          }
        }
        if(flag==0)
        {
          printf("\nItem %s is not found in stock!", search);
        }
        break;
      }

      case 4:
      {
        if(numItems==0)
        {
          printf("\nStock is empty!");
        }
        else
        {
          printf("\nStock List:\n");
          for(i=0; i<numItems; i++)
          {
            printf("%d. %s Quantity:%d Price:%.2f\n", i+1, stock[i].itemName, stock[i].itemQuantity, stock[i].itemPrice);
          }
        }
        break;
      }

      case 5:
      {
        if(numItems==0)
        {
          printf("\nStock is empty!");
        }
        else
        {
          for(i=0; i<numItems; i++)
          {
            totalValue+=(stock[i].itemPrice*stock[i].itemQuantity);
          }
          printf("\nTotal Value of Stock: $%.2f", totalValue);
        }
        break;
      }

      case 6:
      {
        printf("\nThank you for using Warehouse Management System! Goodbye!");
        exit(0);
        break;
      }

      default:
      {
        printf("\nInvalid option! Choose again.");
      }
    }
  }
  return 0;
}