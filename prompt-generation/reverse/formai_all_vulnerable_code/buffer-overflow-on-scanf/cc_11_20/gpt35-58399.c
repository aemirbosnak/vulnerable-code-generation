//FormAI DATASET v1.0 Category: Digital Auction System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Bidder {
    int id;
    char name[50];
    int bid;
} Bidder;

int main()
{
    srand(time(NULL));
    Bidder bidders[10];
    int num_bidders = 0;

    printf("***Welcome to the Digital Auction System***\n");

    while (1) {
        printf("\n1. Register as a Bidder\n");
        printf("2. Start Bidding\n");
        printf("3. End Auction\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("Enter your name: ");
                scanf("%s", bidders[num_bidders].name);
                bidders[num_bidders].id = rand() % 1000 + 1;
                printf("\nCongrats, you have registered successfully!\n");
                printf("Your bidder id is: %d", bidders[num_bidders].id);
                num_bidders++;
                break;
            }
            case 2: {
                if (num_bidders == 0) {
                    printf("\nNo Bidders Registered yet, Please Register first!\n");
                    break;
                }
                printf("\nThe current bidders in the Auction are: \n");
                for (int i = 0; i < num_bidders; i++) {
                    printf("Bidder ID: %d, Name: %s\n", bidders[i].id, bidders[i].name);
                }
                printf("\nEnter your bidder id: ");
                int id;
                scanf("%d", &id);
                Bidder *b = NULL;
                for (int i = 0; i < num_bidders; i++) {
                    if (bidders[i].id == id) {
                        b = &bidders[i];
                        break;
                    }
                }
                if (b == NULL) {
                    printf("Invalid Bidder ID!\n");
                    break;
                }
                printf("\nEnter your bid amount: ");
                scanf("%d", &b->bid);
                printf("\nCongrats %s, your bid for $%d has been noted.\n", b->name, b->bid);
                break;
            }
            case 3: {
                printf("\nThe auction has ended! The results are: \n");
                if (num_bidders == 0) {
                    printf("\nNo Bidders Registered yet, Please Register first!\n");
                    break;
                }
                Bidder *winner = &bidders[rand() % num_bidders];
                for (int i = 0; i < num_bidders; i++) {
                    if (bidders[i].bid > winner->bid) {
                        winner = &bidders[i];
                    }
                }
                printf("\nThe winner of the auction is: %s with a bid of $%d.\n", winner->name, winner->bid);
                break;
            }
            case 4: {
                printf("\nThanks for using the Digital Auction System. Have a nice day!\n");
                exit(0);
            }
            default: {
                printf("\nInvalid Choice. Please try again!\n");
            }
        }
    }
    return 0;
}