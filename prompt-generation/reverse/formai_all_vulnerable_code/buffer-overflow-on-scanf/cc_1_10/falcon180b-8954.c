//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TIME_TRAVEL 10
#define MAX_TIME_TRAVELLER_NAME 50
#define MAX_TIME_TRAVELLER_AGE 3

typedef struct {
    char name[MAX_TIME_TRAVELLER_NAME];
    int age;
    int status;
} TimeTraveller;

void main() {
    char choice;
    int numTravellers = 0;
    TimeTraveller timeTravellers[MAX_TIME_TRAVEL];

    do {
        system("clear");
        printf("Welcome to the Medieval Time Travel Simulator!\n\n");
        printf("Please choose an option:\n");
        printf("1. Create a new time traveller\n");
        printf("2. View time travellers\n");
        printf("3. Send a time traveller on a mission\n");
        printf("4. Exit\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(numTravellers >= MAX_TIME_TRAVEL) {
                    printf("You have reached the maximum number of time travellers.\n");
                } else {
                    printf("Enter the name of the new time traveller (max %d characters): ", MAX_TIME_TRAVELLER_NAME);
                    scanf("%s", timeTravellers[numTravellers].name);
                    printf("Enter the age of the new time traveller (between 1 and %d): ", MAX_TIME_TRAVELLER_AGE);
                    scanf("%d", &timeTravellers[numTravellers].age);
                    timeTravellers[numTravellers].status = 0;
                    numTravellers++;
                    printf("\nTime traveller created successfully!\n");
                }
                break;
            case '2':
                if(numTravellers == 0) {
                    printf("There are no time travellers to view.\n");
                } else {
                    printf("Time travellers:\n");
                    for(int i=0;i<numTravellers;i++) {
                        printf("%s, age %d, status %d\n", timeTravellers[i].name, timeTravellers[i].age, timeTravellers[i].status);
                    }
                }
                break;
            case '3':
                if(numTravellers == 0) {
                    printf("There are no time travellers to send on a mission.\n");
                } else {
                    printf("Enter the name of the time traveller to send on a mission (max %d characters): ", MAX_TIME_TRAVELLER_NAME);
                    scanf("%s", timeTravellers[0].name);
                    printf("Time traveller %s has been sent on a mission.\n", timeTravellers[0].name);
                }
                break;
            case '4':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while(choice!= '4');
}