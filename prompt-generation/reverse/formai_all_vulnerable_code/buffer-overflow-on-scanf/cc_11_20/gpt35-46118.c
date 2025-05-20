//FormAI DATASET v1.0 Category: Digital Auction System ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct auction {
  char item[50];
  char highest_bidder[50];
  int highest_bid;
};

int main() {
  int n, flag, i, temp_bid;
  char response[5], name[50];
  struct auction items[10];

  printf("Enter the number of items in the auction: ");
  scanf("%d",&n);

  //Taking input
  for(i=0; i<n; i++) {
    printf("\nEnter the name of item %d: ", i+1);
    getchar();
    fgets(items[i].item, 50, stdin);
    items[i].item[strcspn(items[i].item, "\n")] = '\0';

    printf("Enter the starting bid for %s: ", items[i].item);
    scanf("%d",&items[i].highest_bid);
  }

  //Auction system
  do {
    flag=0;
    printf("\nEnter your name: ");
    getchar();
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';

    //Checking for highest bidder and highest bid
    for(i=0; i<n; i++) {
      if(strcmp(name, items[i].highest_bidder)==0) {
        printf("You are already the highest bidder for %s with a bid of %d\n", items[i].item, items[i].highest_bid);
        flag=1;
        break;
      }
    }
    if(flag==1) {
      printf("Do you want to bid again (Yes/No): ");
      scanf("%s",response);
      if(strcmp(response,"No")==0) {
        continue;
      }
    }

    printf("\nITEM\t\tHIGHEST BIDDER\t\tHIGHEST BID");
    printf("\n----\t\t--------------\t\t-----------");
    for(i=0; i<n; i++) {
      printf("\n%s\t", items[i].item);
      if(strlen(items[i].highest_bidder)>0) {
        printf("%s\t", items[i].highest_bidder);
      } else {
        printf("NONE\t\t");
      }
      printf("%d", items[i].highest_bid);

      if(strcmp(name, items[i].highest_bidder)==0) {
        printf(" <-- Your bid");
      }
    }

    //Taking bidder's bid input
    printf("\n\nEnter the name of item for which you want to bid: ");
    getchar();
    fgets(response, 50, stdin);
    response[strcspn(response, "\n")] = '\0';

    for(i=0; i<n; i++) {
      if(strcmp(response, items[i].item)==0) {
        temp_bid = items[i].highest_bid;
        printf("Enter your bid for %s: ",items[i].item);
        scanf("%d",&temp_bid);

        //Checking if bid is highest or not
        if(temp_bid > items[i].highest_bid) {
          strcpy(items[i].highest_bidder,name);
          items[i].highest_bid = temp_bid;
          printf("\nCongratulations! You are now the highest bidder for %s with a bid of %d\n", items[i].item, items[i].highest_bid);
        } else {
          printf("\nYour bid is lower than the current highest bidder for %s. The current highest bid is %d\n", items[i].item, items[i].highest_bid);
        }

        flag = 1;
        break;
      }
    }
    if(flag==0) {
      printf("\nSorry, no item found with the name %s\n",response);
    }

    //Asking if user wants to continue bidding
    printf("\nDo you want to bid for more items (Yes/No): ");
    scanf("%s",response);

  } while(strcmp(response,"Yes")==0);

  printf("\nThank you for participating in the auction!\n");

  return 0;
}