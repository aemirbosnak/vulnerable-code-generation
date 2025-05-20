//FormAI DATASET v1.0 Category: Smart home light control ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to display the menu
void displayMenu() {
    printf("\n\nMedieval Smart Home Light Control Menu:\n");
    printf("1. Light candles in Living Room\n");
    printf("2. Light candles in Bed Room\n");
    printf("3. Light candles in Kitchen\n");
    printf("4. Turn off all candles\n");
    printf("5. Exit\n");
}

// Function for lighting candles
void lightCandles(char* room) {
    printf("\nLighting candles in the %s...\n", room);
    printf("Candles have been successfully lit!\n");
}

// Function for blowing out candles
void blowOutCandles(char* room) {
    printf("\nBlowing out candles in the %s...\n", room);
    printf("Candles have been successfully blown out!\n");
}

int main() {
    int choice;
    char livingRoom[] = "Living Room";
    char bedRoom[] = "Bed Room";
    char kitchen[] = "Kitchen";
    bool livingRoomCandlesOn = false, bedRoomCandlesOn = false, kitchenCandlesOn = false;

    printf("Welcome to the Medieval Smart Home Light Control Program!\n");

    do {
        displayMenu();

        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (livingRoomCandlesOn) {
                    printf("\nCandles in the Living Room are already lit!\n");
                } else {
                    lightCandles(livingRoom);
                    livingRoomCandlesOn = true;
                }
            break;

            case 2:
                if (bedRoomCandlesOn) {
                    printf("\nCandles in the Bed Room are already lit!\n");
                } else {
                    lightCandles(bedRoom);
                    bedRoomCandlesOn = true;
                }
            break;

            case 3:
                if (kitchenCandlesOn) {
                    printf("\nCandles in the Kitchen are already lit!\n");
                } else {
                    lightCandles(kitchen);
                    kitchenCandlesOn = true;
                }
            break;

            case 4:
                if (!livingRoomCandlesOn && !bedRoomCandlesOn && !kitchenCandlesOn) {
                    printf("\nNo candles are lit!\n");
                } else {
                    blowOutCandles(livingRoom);
                    livingRoomCandlesOn = false;
                    blowOutCandles(bedRoom);
                    bedRoomCandlesOn = false;
                    blowOutCandles(kitchen);
                    kitchenCandlesOn = false;
                }
            break;

            case 5:
                printf("Exiting program... Goodbye!\n");
            break;

            default:
                printf("Invalid choice. Please choose again.\n");
            break;
        }
    } while (choice != 5);

    return 0;
}