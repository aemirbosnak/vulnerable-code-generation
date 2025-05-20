//FormAI DATASET v1.0 Category: Digital Auction System ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ITEMS 100
#define MAX_BIDS 10

// Structure for an Item
typedef struct
{
    int id;
    char name[50];
    char desc[100];
    float current_bid;
    int current_bidder_id;
} Item;

// Structure for a Bidder
typedef struct
{
    int id;
    char name[50];
    float budget;
    int bid_count;
    int bid_items[MAX_BIDS];
    float bid_values[MAX_BIDS];
} Bidder;

// Global Variables
Item items[MAX_ITEMS];
Bidder bidders[MAX_BIDS];
int item_count = 0;
int bidder_count = 0;

// Function Declarations
void add_item();
void add_bidder();
void display_items();
void display_bidders();
void make_bid(int bidder_id, int item_id, float value);

int main()
{
    int choice, bidder_id, item_id;
    float value;

    printf("Welcome to the Decentralized Auction System\n");

    do
    {
        printf("\nMain Menu\n");
        printf("1. Add Item\n");
        printf("2. Add Bidder\n");
        printf("3. Display Items\n");
        printf("4. Display Bidders\n");
        printf("5. Make Bid\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                add_item();
                break;

            case 2:
                add_bidder();
                break;

            case 3:
                display_items();
                break;

            case 4:
                display_bidders();
                break;

            case 5:
                printf("Enter Bidder ID: ");
                scanf("%d", &bidder_id);
                printf("Enter Item ID: ");
                scanf("%d", &item_id);
                printf("Enter Bid Value: ");
                scanf("%f", &value);
                make_bid(bidder_id, item_id, value);
                break;

            case 6:
                printf("Thank you for using the Decentralized Auction System\n");
                break;

            default:
                printf("Invalid Choice. Please try again\n");
        }
    } while(choice != 6);

    return 0;
}

// Function to add a new Item
void add_item()
{
    if(item_count == MAX_ITEMS)
    {
        printf("Maximum Items limit reached. Cannot add new item\n");
        return;
    }

    Item new_item;

    printf("Enter Item ID: ");
    scanf("%d", &new_item.id);
    printf("Enter Name: ");
    scanf("%s", new_item.name);
    printf("Enter Description: ");
    scanf("%s", new_item.desc);
    printf("Enter Current Bid: ");
    scanf("%f", &new_item.current_bid);
    new_item.current_bidder_id = -1;

    items[item_count++] = new_item;

    printf("Item added successfully\n");
}

// Function to add a new Bidder
void add_bidder()
{
    if(bidder_count == MAX_BIDS)
    {
        printf("Maximum Bidders limit reached. Cannot add new bidder\n");
        return;
    }

    Bidder new_bidder;

    printf("Enter Bidder ID: ");
    scanf("%d", &new_bidder.id);
    printf("Enter Name: ");
    scanf("%s", new_bidder.name);
    printf("Enter Budget: ");
    scanf("%f", &new_bidder.budget);
    new_bidder.bid_count = 0;

    for(int i=0;i<MAX_BIDS;i++)
    {
        new_bidder.bid_items[i] = -1;
        new_bidder.bid_values[i] = -1;
    }

    bidders[bidder_count++] = new_bidder;

    printf("Bidder added successfully\n");
}

// Function to display all Items
void display_items()
{
    printf("Items List\n");
    printf("ID\tName\tDescription\tCurrent Bid\tCurrent Bidder ID\n");

    for(int i=0;i<item_count;i++)
    {
        printf("%d\t%s\t%s\t%.2f\t", items[i].id, items[i].name, items[i].desc, items[i].current_bid);

        if(items[i].current_bidder_id == -1)
        {
            printf("NA\n");
        }
        else
        {
            printf("%d\n", items[i].current_bidder_id);
        }
    }
}

// Function to display all Bidders
void display_bidders()
{
    printf("Bidders List\n");
    printf("ID\tName\tBudget\tBids Count\tBids Items\tBids Values\n");

    for(int i=0;i<bidder_count;i++)
    {
        printf("%d\t%s\t%.2f\t%d\t", bidders[i].id, bidders[i].name, bidders[i].budget, bidders[i].bid_count);

        for(int j=0;j<bidders[i].bid_count;j++)
        {
            printf("%d,", bidders[i].bid_items[j]);
        }

        printf("\t");

        for(int j=0;j<bidders[i].bid_count;j++)
        {
            printf("%.2f,", bidders[i].bid_values[j]);
        }

        printf("\n");
    }
}

// Function to make a new bid
void make_bid(int bidder_id, int item_id, float value)
{
    int bidder_index = -1, item_index = -1;

    // Find the Bidder
    for(int i=0;i<bidder_count;i++)
    {
        if(bidders[i].id == bidder_id)
        {
            bidder_index = i;
            break;
        }
    }

    if(bidder_index == -1)
    {
        printf("Invalid Bidder ID. Please try again\n");
        return;
    }

    // Find the Item
    for(int i=0;i<item_count;i++)
    {
        if(items[i].id == item_id)
        {
            item_index = i;
            break;
        }
    }

    if(item_index == -1)
    {
        printf("Invalid Item ID. Please try again\n");
        return;
    }

    // Check if Bidder has enough budget
    if(bidders[bidder_index].budget < value)
    {
        printf("Bidder %s does not have enough budget to make bid of %.2f\n", bidders[bidder_index].name, value);
        return;
    }

    // Check if Bid is higher than Current Bid
    if(value <= items[item_index].current_bid)
    {
        printf("Bid of %.2f is not higher than current bid for Item %s\n", value, items[item_index].name);
        return;
    }

    // Update Bidder's Budget and Bids
    bidders[bidder_index].budget -= value;
    bidders[bidder_index].bid_items[bidders[bidder_index].bid_count] = item_id;
    bidders[bidder_index].bid_values[bidders[bidder_index].bid_count] = value;
    bidders[bidder_index].bid_count++;

    // Update Item's Current Bid and Current Bidder ID
    items[item_index].current_bid = value;
    items[item_index].current_bidder_id = bidder_id;

    printf("Bid made successfully\n");
}