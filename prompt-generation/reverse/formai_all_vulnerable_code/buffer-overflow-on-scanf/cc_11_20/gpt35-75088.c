//FormAI DATASET v1.0 Category: Hotel Management System ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  int i, n, choice;
  char search[20];
  
  struct hotel
  {
    char name[20];
    int rooms;
    float price;
  }h[5];
  
  printf("Enter hotel details:\n");
  
  for(i = 0; i < 5; i++)
  {
    printf("\nHotel %d", i + 1);
    printf("\nEnter hotel name: ");
    scanf("%s", h[i].name);
    printf("Enter number of rooms: ");
    scanf("%d", &h[i].rooms);
    printf("Enter room price: ");
    scanf("%f", &h[i].price);
  }
  
  while(1)
  {
    printf("\n*** MENU ***");
    printf("\n1. Display hotel details. ");
    printf("\n2. Search hotel by name. ");
    printf("\n3. Sort hotel details by price. ");
    printf("\n4. Exit. ");
    
    printf("\nEnter choice: ");
    scanf("%d", &choice);
    
    switch(choice)
    {
      case 1: printf("\nHotel Details: ");
              for(i = 0; i < 5; i++)
              {
                printf("\n\nHotel %d", i + 1);
                printf("\nName: %s", h[i].name);
                printf("\nNumber of rooms: %d", h[i].rooms);
                printf("\nRoom price: %f", h[i].price);
              }
              break;
              
      case 2: printf("\nEnter hotel name to search: ");
              scanf("%s", search);
              for(i = 0; i < 5; i++)
              {
                if(strcmp(h[i].name, search) == 0)
                {
                  printf("\nHotel %d", i + 1);
                  printf("\nName: %s", h[i].name);
                  printf("\nNumber of rooms: %d", h[i].rooms);
                  printf("\nRoom price: %f", h[i].price);
                  break;
                }
              }
              if(i == 5)
                printf("\nHotel not found!");
              break;
              
      case 3: printf("\nHotel Details (sorted by price): ");
              struct hotel temp;
              for(i = 0; i < 5; i++)
              {
                for(int j = i+1; j < 5; j++)
                {
                  if(h[i].price > h[j].price)
                  {
                    temp = h[i];
                    h[i] = h[j];
                    h[j] = temp;
                  }
                }
              }
              for(i = 0; i < 5; i++)
              {
                printf("\n\nHotel %d", i + 1);
                printf("\nName: %s", h[i].name);
                printf("\nNumber of rooms: %d", h[i].rooms);
                printf("\nRoom price: %f", h[i].price);
              }
              break;
              
      case 4: exit(0);
              break;
      
      default: printf("\nInvalid Choice!");
               break;
    }
  }
  return 0;
}