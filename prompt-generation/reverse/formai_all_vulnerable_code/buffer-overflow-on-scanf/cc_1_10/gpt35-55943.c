//FormAI DATASET v1.0 Category: Hotel Management System ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ROOMS 200
#define ROOM_NO_LENGTH 5

char* generate_room_code(int room_no) {
    char* room_code = (char*) malloc(sizeof(char) * (ROOM_NO_LENGTH + 1));
    room_code[0] = 'R';
    int i = 4;
    while (room_no > 0 && i >= 1) {
        room_code[i] = (room_no % 10) + '0';
        room_no /= 10;
        i--;
    }
    while (i >= 1) {
        room_code[i--] = '0';
    }
    room_code[5] = '\0';
    return room_code;
}

struct room {
    char* room_code;
    char* room_type;
    int floor_no;
    int occupancy;
    float price;
} rooms[MAX_ROOMS];

int current_total_rooms = 0;

void add_room() {
    int room_no;
    char room_type[20];
    int floor_no;
    int occupancy;
    float price;

    printf("Enter Room No. : ");
    scanf("%d", &room_no);
    getchar();

    printf("Enter Room Type : ");
    scanf("%[^\n]%*c", room_type);

    printf("Enter Floor No. : ");
    scanf("%d", &floor_no);
    getchar();

    printf("Enter Occupancy : ");
    scanf("%d", &occupancy);

    printf("Enter Price : ");
    scanf("%f", &price);

    rooms[current_total_rooms].room_code = generate_room_code(room_no);
    rooms[current_total_rooms].room_type = (char*) malloc(sizeof(char) * (strlen(room_type) + 1));
    strcpy(rooms[current_total_rooms].room_type, room_type);
    rooms[current_total_rooms].floor_no = floor_no;
    rooms[current_total_rooms].occupancy = occupancy;
    rooms[current_total_rooms].price = price;

    current_total_rooms++;
}

void display_rooms() {
    printf("%-10s %-15s %-10s %-10s %-10s\n", "Room Code", "Room Type", "Floor No.", "Occupancy", "Price");
    for (int i = 0; i < current_total_rooms; i++) {
        printf("%-10s %-15s %-10d %-10d %-10.2f\n", rooms[i].room_code, rooms[i].room_type, rooms[i].floor_no, rooms[i].occupancy, rooms[i].price);
    }
}

void search_room(char* room_code) {
    for(int i = 0; i < current_total_rooms; i++) {
        if(strcmp(rooms[i].room_code, room_code) == 0) {
            printf("%-10s %-15s %-10s %-10s %-10s\n", "Room Code", "Room Type", "Floor No.", "Occupancy", "Price");
            printf("%-10s %-15s %-10d %-10d %-10.2f\n", rooms[i].room_code, rooms[i].room_type, rooms[i].floor_no, rooms[i].occupancy, rooms[i].price);
            return;
        }
    }
    printf("No room found with code \"%s\"\n", room_code);
}

void update_room_price(char* room_code, float new_price) {
    for(int i = 0; i < current_total_rooms; i++) {
        if(strcmp(rooms[i].room_code, room_code) == 0) {
            rooms[i].price = new_price;
            printf("Room price updated!\n");
            return;
        }
    }
    printf("No room found with code \"%s\"\n", room_code);
}

void delete_room(char* room_code) {
    int delete_index = -1;
    for(int i = 0; i < current_total_rooms; i++) {
        if(strcmp(rooms[i].room_code, room_code) == 0) {
            delete_index = i;
            break;
        }
    }
    if(delete_index == -1) {
        printf("No room found with code \"%s\"\n", room_code);
    } else {
        free(rooms[delete_index].room_code);
        free(rooms[delete_index].room_type);
        for(int i = delete_index + 1; i < current_total_rooms; i++) {
            rooms[i - 1] = rooms[i];
        }
        current_total_rooms--;
        printf("Room deleted successfully!\n");
    }
}

int main() {
    int choice;
    printf("===== Welcome to C Hotel Management System =====\n");
    while(1) {
        printf("\nMenu:\n");
        printf("1. Add Room\n");
        printf("2. Display All Rooms\n");
        printf("3. Search Room\n");
        printf("4. Update Room Price\n");
        printf("5. Delete Room\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1: 
                add_room();
                break;
            case 2:
                display_rooms();
                break;
            case 3:
                {
                    char room_code[ROOM_NO_LENGTH + 1];
                    printf("Enter Room Code : ");
                    scanf("%s", room_code);
                    search_room(room_code);
                }
                break;
            case 4:
                {
                    char room_code[ROOM_NO_LENGTH + 1];
                    float new_price;
                    printf("Enter Room Code : ");
                    scanf("%s", room_code);
                    printf("Enter New Price : ");
                    scanf("%f", &new_price);
                    update_room_price(room_code, new_price);
                }
                break;
            case 5:
                {
                    char room_code[ROOM_NO_LENGTH + 1];
                    printf("Enter Room Code : ");
                    scanf("%s", room_code);
                    delete_room(room_code);
                }
                break;
            case 6:
                printf("Thanks for using C Hotel Management System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid Choice! Please try again.\n");
        }
    }
    return 0;
}