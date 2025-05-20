//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y, choice;
    char msg[100];

    printf("Welcome to the GPS Navigation System!\n\n");
    printf("You are currently at position (0,0).\n\n");
    printf("Enter your destination coordinates (x,y): ");
    scanf("%d%d", &x, &y);

    while(1) {
        printf("\nCurrent position: (%d,%d)\n", x, y);
        printf("Enter your choice:\n");
        printf("1. Move north\n");
        printf("2. Move south\n");
        printf("3. Move east\n");
        printf("4. Move west\n");
        printf("5. Save current location\n");
        printf("6. View saved locations\n");
        printf("7. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(y > 0) {
                    y--;
                } else {
                    printf("You have reached the northernmost point.\n");
                }
                break;
            case 2:
                if(y < 10) {
                    y++;
                } else {
                    printf("You have reached the southernmost point.\n");
                }
                break;
            case 3:
                if(x < 10) {
                    x++;
                } else {
                    printf("You have reached the easternmost point.\n");
                }
                break;
            case 4:
                if(x > 0) {
                    x--;
                } else {
                    printf("You have reached the westernmost point.\n");
                }
                break;
            case 5:
                printf("Enter a name for this location: ");
                scanf("%s", msg);
                printf("Location '%s' saved.\n", msg);
                break;
            case 6:
                printf("Saved locations:\n");
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}