//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
    char name[50];
    char room[10];
    int nights;
    float bill;
};

struct guest guests[100];
int numGuests = 0;

void addGuest(char *name, char *room, int nights, float bill) {
    strcpy(guests[numGuests].name, name);
    strcpy(guests[numGuests].room, room);
    guests[numGuests].nights = nights;
    guests[numGuests].bill = bill;
    numGuests++;
}

void displayGuests() {
    printf("Guests:\n");
    for (int i = 0; i < numGuests; i++) {
        printf("%s, %s, %d night(s), $%.2f\n", guests[i].name, guests[i].room, guests[i].nights, guests[i].bill);
    }
}

int main() {
    printf("Welcome to the C Hotel Management System. What would you like to do?\n");

    while (1) {
        printf("> ");
        char input[50];
        fgets(input, 50, stdin);
        if (strncmp(input, "exit", 4) == 0) {
            printf("Goodbye!\n");
            break;
        } else if (strncmp(input, "add", 3) == 0) {
            char name[50];
            char room[10];
            int nights;
            float bill;
            printf("Name: ");
            fgets(name, 50, stdin);
            printf("Room: ");
            fgets(room, 10, stdin);
            printf("Nights: ");
            scanf("%d", &nights);
            printf("Bill: ");
            scanf("%f", &bill);
            getchar();
            addGuest(name, room, nights, bill);
            printf("Guest added.\n");
        } else if (strncmp(input, "display", 7) == 0) {
            displayGuests();
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}