//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 50

int rooms_available = MAX_ROOMS;

typedef struct {
    int room_number;
    char guest_name[50];
    int days_stayed;
    float total_cost;
} Room;

Room hotel[MAX_ROOMS];

void display_menu();
void book_room();
void check_out();
void display_guests();
void update_file();

int main() {
    FILE *file;
    file = fopen("hotel_data.txt", "r");

    if (file != NULL) {
        int count = 0;
        while (!feof(file)) {
            fscanf(file, "%d %s %d %f\n", &hotel[count].room_number, hotel[count].guest_name, &hotel[count].days_stayed, &hotel[count].total_cost);
            count++;
            rooms_available--;
        }
        fclose(file);
    }

    display_menu();

    return 0;
}

void display_menu() {
    int choice;

    printf("Welcome to the Cyberpunk C Hotel Management System!\n");
    printf("1. Book a Room.\n");
    printf("2. Check Out.\n");
    printf("3. Display Guests.\n");
    printf("4. Exit.\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: book_room();
                break;
        case 2: check_out();
                break;
        case 3: display_guests();
                break;
        case 4: update_file();
                exit(0);
        default: printf("Invalid Choice.\n");
                display_menu();
                break;
    }
}

void book_room() {
    if (rooms_available == 0) {
        printf("Sorry, all rooms are booked.\n");
        display_menu();
    } else {
        int index;
        for(int i=0; i<MAX_ROOMS; i++) {
            if (hotel[i].room_number == 0) {
                index = i;
                break;
            }
        }

        hotel[index].room_number = MAX_ROOMS - rooms_available + 1;
        printf("Room Number: %d\n", hotel[index].room_number);
        printf("Enter Guest Name: ");
        scanf(" %[^\n]s", hotel[index].guest_name);
        printf("Enter number of days stayed: ");
        scanf("%d", &hotel[index].days_stayed);
        printf("Enter Total Cost: ");
        scanf("%f", &hotel[index].total_cost);
        printf("Room Booked Successfully!\n");

        rooms_available--;
        display_menu();
    }
}

void check_out() {
    int room_num, found = 0;

    printf("Enter Room Number: ");
    scanf("%d", &room_num);

    for (int i=0; i<MAX_ROOMS; i++) {
        if (hotel[i].room_number == room_num) {
            printf("Guest Name: %s\n", hotel[i].guest_name);
            printf("Total Cost: %f\n", hotel[i].total_cost);
            strcpy(hotel[i].guest_name, "");
            hotel[i].days_stayed = 0;
            hotel[i].total_cost = 0;
            hotel[i].room_number = 0;
            printf("Checked Out Successfully!\n");
            found = 1;
            rooms_available++;
            break;
        }
    }

    if (found == 0) {
        printf("Room Not Found.\n");
    }

    display_menu();
}

void display_guests() {
    printf("Room\tGuest\tDays\tCost\n");
    for (int i=0; i<MAX_ROOMS; i++) {
        if (hotel[i].room_number != 0) {
            printf("%d\t%s\t%d\t%f\n", hotel[i].room_number, hotel[i].guest_name, hotel[i].days_stayed, hotel[i].total_cost);
        }
    }

    display_menu();
}

void update_file() {
    FILE *file;
    file = fopen("hotel_data.txt", "w");

    for (int i=0; i<MAX_ROOMS; i++) {
        if (strlen(hotel[i].guest_name) > 0) {
            fprintf(file, "%d %s %d %f\n", hotel[i].room_number, hotel[i].guest_name, hotel[i].days_stayed, hotel[i].total_cost);
        }
    }

    fclose(file);
}