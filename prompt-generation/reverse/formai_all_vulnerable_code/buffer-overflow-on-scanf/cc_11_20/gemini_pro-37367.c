//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hotel {
    char name[50];
    char address[100];
    char phone[20];
    int num_rooms;
    float room_rate;
    char availability[10];
};

int main() {
    struct hotel h[5];
    int i, choice, j;
    char ch;

    printf("\n\t\t\t\t\t* * * HOTEL MANAGEMENT SYSTEM * * *\n\n");

    do {
        printf("\n\t\t\t\t\t\t1. Add Hotel\n");
        printf("\t\t\t\t\t\t2. Display Hotel\n");
        printf("\t\t\t\t\t\t3. Check Availability\n");
        printf("\t\t\t\t\t\t4. Book Room\n");
        printf("\t\t\t\t\t\t5. Exit\n");
        printf("\n\t\t\t\t\t\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n\t\t\t\t\t\tEnter hotel name: ");
                scanf("%s", h[i].name);
                printf("\t\t\t\t\t\tEnter hotel address: ");
                scanf("%s", h[i].address);
                printf("\t\t\t\t\t\tEnter hotel phone number: ");
                scanf("%s", h[i].phone);
                printf("\t\t\t\t\t\tEnter number of rooms: ");
                scanf("%d", &h[i].num_rooms);
                printf("\t\t\t\t\t\tEnter room rate: ");
                scanf("%f", &h[i].room_rate);
                strcpy(h[i].availability, "AVAILABLE");
                i++;
                break;
            case 2:
                printf("\n\t\t\t\t\t\tHotel List:\n\n");
                for (j = 0; j < i; j++) {
                    printf("\t\t\t\t\t\t%d. %s\n", j + 1, h[j].name);
                    printf("\t\t\t\t\t\t\t- Address: %s\n", h[j].address);
                    printf("\t\t\t\t\t\t\t- Phone: %s\n", h[j].phone);
                    printf("\t\t\t\t\t\t\t- Number of Rooms: %d\n", h[j].num_rooms);
                    printf("\t\t\t\t\t\t\t- Room Rate: %.2f\n", h[j].room_rate);
                    printf("\t\t\t\t\t\t\t- Availability: %s\n\n", h[j].availability);
                }
                break;
            case 3:
                printf("\n\t\t\t\t\t\tEnter hotel name: ");
                scanf("%s", h[i].name);
                for (j = 0; j < i; j++) {
                    if (strcmp(h[j].name, h[i].name) == 0) {
                        printf("\n\t\t\t\t\t\t%s is %s\n", h[j].name, h[j].availability);
                        break;
                    }
                }
                if (j == i) {
                    printf("\n\t\t\t\t\t\tHotel not found!\n");
                }
                break;
            case 4:
                printf("\n\t\t\t\t\t\tEnter hotel name: ");
                scanf("%s", h[i].name);
                for (j = 0; j < i; j++) {
                    if (strcmp(h[j].name, h[i].name) == 0) {
                        if (strcmp(h[j].availability, "AVAILABLE") == 0) {
                            strcpy(h[j].availability, "BOOKED");
                            printf("\n\t\t\t\t\t\tRoom booked successfully!\n");
                            break;
                        } else {
                            printf("\n\t\t\t\t\t\tHotel is full!\n");
                        }
                    }
                }
                break;
            case 5:
                printf("\n\t\t\t\t\t\tThank you for using the Hotel Management System!\n");
                break;
            default:
                printf("\n\t\t\t\t\t\tInvalid choice!\n");
                break;
        }

        printf("\n\t\t\t\t\t\tDo you want to continue? (Y/N): ");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');

    return 0;
}