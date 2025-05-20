//FormAI DATASET v1.0 Category: Hotel Management System ; Style: energetic
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int roomNum;
    int nightsStayed;
    float roomCost;
    float totalCost;
} guest;

int main() {
    guest hotelGuests[100];
    int numGuests = 0;

    int option;
    do {
        printf("Welcome to the C Hotel Management System!\n");
        printf("Please select an option:\n");
        printf("1. Add new guest\n");
        printf("2. View all guests\n");
        printf("3. Calculate total revenue\n");
        printf("4. Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nAdding new guest...\n");
                printf("Please enter guest name: ");
                scanf(" %[^\n]", hotelGuests[numGuests].name);
                printf("Please enter room number: ");
                scanf("%d", &hotelGuests[numGuests].roomNum);
                printf("Please enter number of nights stayed: ");
                scanf("%d", &hotelGuests[numGuests].nightsStayed);
                printf("Please enter room cost per night: ");
                scanf("%f", &hotelGuests[numGuests].roomCost);
                hotelGuests[numGuests].totalCost = hotelGuests[numGuests].roomCost * hotelGuests[numGuests].nightsStayed;
                printf("Guest added successfully!\n\n");
                numGuests++;
                break;
            case 2:
                printf("\nViewing all guests...\n");
                printf("Name\tRoom number\tNights stayed\tRoom cost per night\tTotal cost\n");
                for (int i = 0; i < numGuests; i++) {
                    printf("%s\t%d\t%d\t\t%.2f\t\t\t%.2f\n",
                           hotelGuests[i].name, hotelGuests[i].roomNum, hotelGuests[i].nightsStayed,
                           hotelGuests[i].roomCost, hotelGuests[i].totalCost);
                }
                printf("\n");
                break;
            case 3:
                printf("\nCalculating total revenue...\n");
                float totalRevenue = 0;
                for (int i = 0; i < numGuests; i++) {
                    totalRevenue += hotelGuests[i].totalCost;
                }
                printf("Total revenue: $%.2f\n\n", totalRevenue);
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid option, try again.\n\n");
        }
    } while (option != 4);

    return 0;
}