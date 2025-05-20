//FormAI DATASET v1.0 Category: Hotel Management System ; Style: protected
#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 50
#define MAX_NAME_LENGTH 20

typedef struct {
    int roomNumber;
    char guestName[MAX_NAME_LENGTH];
    int daysStayed;
    float roomRate;
} Reservation;

int main() {
    Reservation reservations[MAX_ROOMS];
    int reservationsCount = 0;
    int menuOption = 0;

    do {
        printf("Welcome to the hotel management system! What would you like to do?\n\n");
        printf("1. Make a reservation\n");
        printf("2. Print all reservations\n");
        printf("3. Search for a reservation by name\n");
        printf("4. Exit\n\n");

        scanf("%d", &menuOption);

        switch (menuOption) {
            case 1:
                if (reservationsCount >= MAX_ROOMS) {
                    printf("Sorry, the hotel is fully booked.\n\n");
                    break;
                }

                printf("Enter guest name: ");
                scanf("%s", reservations[reservationsCount].guestName);

                printf("Enter number of days stayed: ");
                scanf("%d", &reservations[reservationsCount].daysStayed);

                printf("Enter room rate: ");
                scanf("%f", &reservations[reservationsCount].roomRate);

                reservations[reservationsCount].roomNumber = reservationsCount + 1;

                printf("Reservation created successfully. Room number is %d.\n\n", reservationsCount + 1);

                reservationsCount++;

                break;

            case 2:
                if (reservationsCount == 0) {
                    printf("There are no reservations to print.\n\n");
                    break;
                }

                printf("Room\tGuest Name\tDays Stayed\tRoom Rate\tTotal Cost\n");

                for (int i = 0; i < reservationsCount; i++) {
                    printf("%d\t%s\t\t%d\t\t%.2f\t\t%.2f\n", 
                           reservations[i].roomNumber, 
                           reservations[i].guestName, 
                           reservations[i].daysStayed, 
                           reservations[i].roomRate, 
                           reservations[i].daysStayed * reservations[i].roomRate);
                }

                printf("\n");

                break;

            case 3:
                if (reservationsCount == 0) {
                    printf("There are no reservations to search for.\n\n");
                    break;
                }

                char searchName[MAX_NAME_LENGTH];
                printf("Enter guest name to search for: ");
                scanf("%s", searchName);

                int searchFound = 0;

                for (int i = 0; i < reservationsCount; i++) {
                    if (strcmp(searchName, reservations[i].guestName) == 0) {
                        printf("Room number: %d\n", reservations[i].roomNumber);
                        printf("Guest name: %s\n", reservations[i].guestName);
                        printf("Days stayed: %d\n", reservations[i].daysStayed);
                        printf("Room rate: %.2f\n", reservations[i].roomRate);
                        printf("Total cost: %.2f\n\n", reservations[i].daysStayed * reservations[i].roomRate);

                        searchFound = 1;
                    }
                }

                if (!searchFound) {
                    printf("No reservations found for that guest name.\n\n");
                }

                break;

            case 4:
                printf("Exiting the hotel management system...\n\n");
                break;

            default:
                printf("Invalid option, please try again.\n\n");
        }
    } while (menuOption != 4);

    return 0;
}