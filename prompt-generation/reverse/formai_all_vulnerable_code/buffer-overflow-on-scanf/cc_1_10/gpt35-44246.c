//FormAI DATASET v1.0 Category: Hotel Management System ; Style: protected
#include <stdio.h>
#include <string.h>

struct reservation {
    char guestName[50];
    int roomNumber;
    int numberOfGuests;
    char checkInDate[50];
    char checkOutDate[50];
};

void printMainMenu() {
    printf("\n*** Hotel Management System ***\n\n");
    printf("1. Make a reservation\n");
    printf("2. View all reservations\n");
    printf("3. Cancel a reservation\n");
    printf("4. Exit\n\n");
    printf("Please enter your choice: ");
}

void makeReservation(struct reservation reservations[], int *count) {
    printf("\n*** Make a Reservation ***\n\n");
    printf("Please enter guest name: ");
    scanf("%s", reservations[*count].guestName);
    printf("Please enter desired room number: ");
    scanf("%d", &reservations[*count].roomNumber);
    printf("Please enter number of guests: ");
    scanf("%d", &reservations[*count].numberOfGuests);
    printf("Please enter check-in date (dd/mm/yyyy): ");
    scanf("%s", reservations[*count].checkInDate);
    printf("Please enter check-out date (dd/mm/yyyy): ");
    scanf("%s", reservations[*count].checkOutDate);
    (*count)++;
    printf("\nReservation successfully made!\n");
}

void viewReservations(struct reservation reservations[], int count) {
    printf("\n*** Reservations ***\n\n");
    if (count == 0) {
        printf("No reservations found.\n");
    } else {
        printf("Guest Name\tRoom Number\tNumber of Guests\tCheck-in Date\tCheck-out Date\n");
        for (int i = 0; i < count; i++) {
            printf("%s\t\t%d\t\t%d\t\t%s\t\t%s\n", reservations[i].guestName, reservations[i].roomNumber,
                reservations[i].numberOfGuests, reservations[i].checkInDate, reservations[i].checkOutDate);
        }
    }
}

void cancelReservation(struct reservation reservations[], int *count) {
    printf("\n*** Cancel a Reservation ***\n\n");
    if (*count == 0) {
        printf("No reservations found.\n");
    } else {
        int roomNumber;
        printf("Please enter the room number of the reservation to cancel: ");
        scanf("%d", &roomNumber);
        for (int i = 0; i < *count; i++) {
            if (reservations[i].roomNumber == roomNumber) {
                for (int j = i; j < *count - 1; j++) {
                    strcpy(reservations[j].guestName, reservations[j+1].guestName);
                    reservations[j].roomNumber = reservations[j+1].roomNumber;
                    reservations[j].numberOfGuests = reservations[j+1].numberOfGuests;
                    strcpy(reservations[j].checkInDate, reservations[j+1].checkInDate);
                    strcpy(reservations[j].checkOutDate, reservations[j+1].checkOutDate);
                }
                (*count)--;
                printf("\nReservation successfully cancelled!\n");
                return;
            }
        }
        printf("\nNo reservation found with room number %d.\n", roomNumber);
    }
}

int main() {
    struct reservation reservations[10];
    int count = 0;
    int choice;
    do {
        printMainMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                makeReservation(reservations, &count);
                break;
            case 2:
                viewReservations(reservations, count);
                break;
            case 3:
                cancelReservation(reservations, &count);
                break;
            case 4:
                printf("\nThank you for using the Hotel Management System!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}