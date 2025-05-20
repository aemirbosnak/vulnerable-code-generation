//LLAMA2-13B DATASET v1.0 Category: Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_NAME_LENGTH 20
#define MAX_GUESTS 10

typedef struct guest {
    char name[MAX_NAME_LENGTH];
    int arrived;
} guest;

typedef struct party {
    char host_name[MAX_NAME_LENGTH];
    char party_name[MAX_NAME_LENGTH];
    int num_guests;
    guest guests[MAX_GUESTS];
} party;

void print_guest_list(party *party) {
    int i;
    for (i = 0; i < party->num_guests; i++) {
        printf("%d. %s\n", i + 1, party->guests[i].name);
    }
}

void handle_arrival(party *party, guest *guest) {
    char name[MAX_NAME_LENGTH];
    int arrived = 0;
    printf("Guest: %s arrived\n", guest->name);
    strcpy(name, guest->name);
    guest->arrived = 1;
    party->num_guests++;
    print_guest_list(party);
}

void handle_departure(party *party, guest *guest) {
    char name[MAX_NAME_LENGTH];
    int arrived = 0;
    printf("Guest: %s departed\n", guest->name);
    strcpy(name, guest->name);
    guest->arrived = 0;
    party->num_guests--;
    print_guest_list(party);
}

int main() {
    srand(time(NULL));
    party party;
    party.host_name[0] = '\0';
    party.party_name[0] = '\0';
    party.num_guests = 0;
    guest guest;
    guest.name[0] = '\0';
    guest.arrived = 0;

    while (1) {
        int choice;
        printf("Enter your choice: (1) Arrive, (2) Depart, (3) View Guest List, (4) End Party\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            guest.name[0] = '\0';
            printf("Enter guest name: ");
            fgets(guest.name, MAX_NAME_LENGTH, stdin);
            handle_arrival(&party, &guest);
            break;

        case 2:
            handle_departure(&party, &guest);
            break;

        case 3:
            print_guest_list(&party);
            break;

        case 4:
            printf("Party ended\n");
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}