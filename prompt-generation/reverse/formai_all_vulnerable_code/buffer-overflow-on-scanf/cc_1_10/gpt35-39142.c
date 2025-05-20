//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct guest {
    char name[50];
    char room[10];
    int duration;
    int cost;
};

void add_guest(struct guest *g) {
    printf("Enter guest name: ");
    scanf("%s", g->name);
    printf("Enter room number: ");
    scanf("%s", g->room);
    printf("Enter duration of stay (in days): ");
    scanf("%d", &g->duration);
    g->cost = g->duration * 100; // $100 per day
    printf("Guest added.\n");
}

void print_guest(struct guest g) {
    printf("Name: %s\n", g.name);
    printf("Room: %s\n", g.room);
    printf("Duration: %d days\n", g.duration);
    printf("Cost: $%d\n", g.cost);
}

int main() {
    struct guest guests[10];
    int num_guests = 0;
    char choice[10];
    printf("Welcome to the Cyberpunk Hotel Management System.\n");
    while (1) {
        printf("1. Add guest\n");
        printf("2. View all guests\n");
        printf("3. Delete guest\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", choice);
        if (strcmp(choice, "1") == 0) {
            if (num_guests >= 10) {
                printf("Maximum number of guests reached.\n");
            } else {
                add_guest(&guests[num_guests]);
                num_guests++;
            }
        } else if (strcmp(choice, "2") == 0) {
            printf("All guests:\n");
            for (int i = 0; i < num_guests; i++) {
                print_guest(guests[i]);
            }
        } else if (strcmp(choice, "3") == 0) {
            char del_room[10];
            printf("Enter room number to delete: ");
            scanf("%s", del_room);
            for (int i = 0; i < num_guests; i++) {
                if (strcmp(guests[i].room, del_room) == 0) {
                    printf("Deleting guest %s from room %s.\n", guests[i].name, guests[i].room);
                    for (int j = i; j < num_guests - 1; j++) {
                        guests[j] = guests[j+1];
                    }
                    num_guests--;
                    break;
                }
            }
        } else if (strcmp(choice, "4") == 0) {
            printf("Thank you for using the Cyberpunk Hotel Management System.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}