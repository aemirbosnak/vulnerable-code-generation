//FormAI DATASET v1.0 Category: Hotel Management System ; Style: genious
#include <stdio.h>
#include <string.h>

// Defining the structure for the guest information.
struct guestInfo {
    char fname[50];
    char lname[50];
    int roomNum;
    int daysStayed;
    float roomRate;
    float totalCharge;
};

void displayMenu();
void checkIn(struct guestInfo []);
void checkOut(struct guestInfo []);
void displayGuests(struct guestInfo []);

int main() {
    // Defining the array of structures which contains guests' information.
    struct guestInfo guestList[50];
    
    int choice;

    printf("Welcome to the C Hotel Management System!\n");

    // Starting the program loop.
    do {
        displayMenu();
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                checkIn(guestList);
                break;
            case 2:
                checkOut(guestList);
                break;
            case 3:
                displayGuests(guestList);
                break;
            case 4:
                printf("Thank you for using the C Hotel Management System. Good bye!");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
                break;
        }
    } while(choice != 4);

    return 0;
}

void displayMenu() {
    printf("\nMAIN MENU\n");
    printf("1. Check In\n");
    printf("2. Check Out\n");
    printf("3. Display Guests\n");
    printf("4. Exit\n");
}

void checkIn(struct guestInfo guestList[]) {
    int numGuests, i;

    printf("Please enter the number of guests: ");
    scanf("%d", &numGuests);

    // Getting the guest information.
    for (i = 0; i < numGuests; i++) {
        printf("Guest %d:\n", i+1);
        printf("First Name: ");
        scanf("%s", guestList[i].fname);
        printf("Last Name: ");
        scanf("%s", guestList[i].lname);
        printf("Room Number: ");
        scanf("%d", &guestList[i].roomNum);
        printf("Days stayed: ");
        scanf("%d", &guestList[i].daysStayed);
        printf("Room Rate: ");
        scanf("%f", &guestList[i].roomRate);

        // Calculating the total charge.
        guestList[i].totalCharge = guestList[i].daysStayed * guestList[i].roomRate;
    }

    printf("Guests checked in successfully!\n");
}

void checkOut(struct guestInfo guestList[]) {
    int roomNum, i, found = 0;

    printf("Please enter the room number to check out: ");
    scanf("%d", &roomNum);

    // Checking if the room number exists in the guest list.
    for (i = 0; i < 50; i++) {
        if (guestList[i].roomNum == roomNum) {
            printf("Guest %d (%s %s) checked out successfully. Total charge: $%.2f\n",
                i+1, guestList[i].fname, guestList[i].lname, guestList[i].totalCharge);

            // Removing the guest from the guest list.
            guestList[i].roomNum = -1;
            guestList[i].daysStayed = -1;
            guestList[i].roomRate = -1.0;
            guestList[i].totalCharge = -1.0;
            strcpy(guestList[i].fname, "");
            strcpy(guestList[i].lname, "");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Room number not found.\n");
    }
}

void displayGuests(struct guestInfo guestList[]) {
    int i;

    printf("\nGUEST LIST\n");
    printf("------------------------------------------------------------------------\n");
    printf("| %10s | %20s | %20s | %10s | %10s |\n", "Room Num", "First Name", "Last Name", "Days Stayed", "Total");
    printf("------------------------------------------------------------------------\n");

    // Displaying the guests which have checked in.
    for (i = 0; i < 50; i++) {
        if (guestList[i].roomNum != -1) {
            printf("| %10d | %20s | %20s | %10d | $%8.2f |\n",
                guestList[i].roomNum, guestList[i].fname, guestList[i].lname, guestList[i].daysStayed, guestList[i].totalCharge);
        }
    }

    printf("------------------------------------------------------------------------\n");
}