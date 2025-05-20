//FormAI DATASET v1.0 Category: Hotel Management System ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int roomNo;
    char guestName[30];
    int numGuests;
    int numNights;
    int rate;
}reservation;

int main() {
    reservation r[50];
    int i, j, n, choice, totalRevenue = 0;

    do {
        printf("\n\n==========C Hotel Management System===========\n\n");
        printf("1. New Reservation\n");
        printf("2. View Reservation\n");
        printf("3. Check-Out and Payment\n");
        printf("4. Exit\n");
        printf("Enter your choice(1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n\n==========New Reservation===========\n\n");
                printf("Enter the number of reservations to be added: ");
                scanf("%d", &n);

                for (i = 0; i < n; i++) {
                    printf("\n\nReservation %d - \n", i+1);
                    printf("Enter Room Number: ");
                    scanf("%d", &r[i].roomNo);
                    printf("Enter Guest Name: ");
                    scanf("%s", r[i].guestName);
                    printf("Enter Number of Guests: ");
                    scanf("%d", &r[i].numGuests);
                    printf("Enter Number of Nights: ");
                    scanf("%d", &r[i].numNights);
                    printf("Enter Rate per Night: ");
                    scanf("%d", &r[i].rate);
                }
                break;
            case 2:
                printf("\n\n==========View Reservation===========\n\n");
                printf("Room No.\tGuest Name\tNo. of Guests\tNo. of Nights\tRate per night\n");
                for (i = 0; i < n; i++) {
                    printf("%d\t\t%s\t\t%d\t\t%d\t\t%d\n",r[i].roomNo, r[i].guestName, r[i].numGuests, r[i].numNights, r[i].rate);
                }
                break;
            case 3:
                printf("\n\n==========Check-Out and Payment===========\n\n");
                printf("Room No.\tGuest Name\tTotal Amount\n");
                for (i = 0; i < n; i++) {
                    printf("%d\t\t%s\t\t%d\n", r[i].roomNo, r[i].guestName, r[i].numNights * r[i].rate);
                    totalRevenue += r[i].numNights * r[i].rate;
                    for (j = 0; j < 30; j++) {
                        r[i].guestName[j] = '\0';
                    }
                }
                break;
            case 4:
                printf("Thank you for using C Hotel Management System\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

    } while (choice != 4);
    printf("Total Revenue: %d", totalRevenue);
    return 0;
}