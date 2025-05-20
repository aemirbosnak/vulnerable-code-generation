//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: romantic
#include<stdio.h>

int main()
{
    printf("Welcome to the C Hotel Management System!\n");
    printf("-----------------------------\n");
    printf("We offer a variety of romantic rooms for your stay.\n");
    printf("-----------------------------\n");
    printf("1. Deluxe Suite\n");
    printf("2. Garden View Room\n");
    printf("3. Beachfront Villa\n");
    printf("4. Honeymoon Suite\n");
    printf("5. Back to Main Menu\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Deluxe Suite: \n");
            printf("- King-sized bed\n");
            printf("- Jacuzzi\n");
            printf("- Balcony with ocean view\n");
            printf("- In-room breakfast\n");
            printf("- Complimentary champagne\n");
            printf("- Price: $1000 per night\n");
            break;
        case 2:
            printf("Garden View Room: \n");
            printf("- Queen-sized bed\n");
            printf("- Garden view balcony\n");
            printf("- In-room breakfast\n");
            printf("- Complimentary wine\n");
            printf("- Price: $500 per night\n");
            break;
        case 3:
            printf("Beachfront Villa: \n");
            printf("- King-sized bed\n");
            printf("- Private beach access\n");
            printf("- Outdoor pool\n");
            printf("- In-room breakfast\n");
            printf("- Complimentary fruit basket\n");
            printf("- Price: $800 per night\n");
            break;
        case 4:
            printf("Honeymoon Suite: \n");
            printf("- King-sized bed\n");
            printf("- Private hot tub\n");
            printf("- Ocean view balcony\n");
            printf("- In-room breakfast\n");
            printf("- Complimentary chocolates\n");
            printf("- Price: $700 per night\n");
            break;
        case 5:
            printf("Back to Main Menu\n");
            break;
        default:
            printf("Invalid Choice. Please choose again.\n");
            break;
    }
    return 0;
}