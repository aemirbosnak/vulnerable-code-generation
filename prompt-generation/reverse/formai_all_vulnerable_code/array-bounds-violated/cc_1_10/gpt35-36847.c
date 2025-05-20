//FormAI DATASET v1.0 Category: Digital Auction System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    double bid;
    char status[10];
} bidder;

void print_bidder(bidder b) {
    printf("ID: %d\n", b.id);
    printf("Name: %s\n", b.name);
    printf("Bid: %.2lf\n", b.bid);
    printf("Status: %s\n", b.status);
}

void bid(bidder* bidders, int n) {
    int id;
    double bid;
    printf("Enter your ID:\n");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (bidders[i].id == id) {
            found = 1;
            printf("Enter your bid:\n");
            scanf("%lf", &bid);
            if (bid > bidders[i].bid) {
                bidders[i].bid = bid;
                strcpy(bidders[i].status, "Winning");
                printf("Bid submitted successfully!\n");
            }
            else {
                printf("Your bid must be higher than the current bid!\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Bidder not found!\n");
    }
}

void print_menu() {
    printf("\n==========================\n");
    printf("Digital Auction System Menu\n");
    printf("==========================\n");
    printf("1. Display All Bidders\n");
    printf("2. Display Winning Bidders\n");
    printf("3. Submit A Bid\n");
    printf("4. Exit\n");
    printf("Enter your choice:\n");
}

int main() {
    int n;
    printf("Enter number of bidders:\n");
    scanf("%d", &n);

    bidder* bidders = (bidder*)malloc(n * sizeof(bidder));

    for (int i = 0; i < n; i++) {
        bidder b;
        printf("Enter bidder ID:\n");
        scanf("%d", &b.id);
        getchar();
        printf("Enter bidder name:\n");
        fgets(b.name, 50, stdin);
        b.name[strlen(b.name) - 1] = '\0'; // remove newline character
        b.bid = 0.0;
        strcpy(b.status, "Not Winning");
        bidders[i] = b;
    }

    int choice = 0;

    while (choice != 4) {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nAll Bidders:\n");
                for (int i = 0; i < n; i++) {
                    print_bidder(bidders[i]);
                }
                break;
            case 2:
                printf("\nWinning Bidders:\n");
                for (int i = 0; i < n; i++) {
                    if (strcmp(bidders[i].status, "Winning") == 0) {
                        print_bidder(bidders[i]);
                    }
                }
                break;
            case 3:
                bid(bidders, n);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    free(bidders);

    return 0;
}