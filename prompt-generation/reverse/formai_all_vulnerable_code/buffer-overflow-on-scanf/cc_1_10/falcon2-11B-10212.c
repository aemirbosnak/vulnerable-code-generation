//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: interoperable
#include <stdio.h>
#include <string.h>

typedef struct Room {
    int room_number;
    char* room_type;
    int num_of_bed;
    int room_rate;
} Room;

typedef struct Hotel {
    char* hotel_name;
    int num_of_rooms;
    Room* rooms;
} Hotel;

int main() {
    Hotel* hotel = (Hotel*) malloc(sizeof(Hotel));

    char hotel_name[50];
    printf("Enter hotel name: ");
    scanf("%s", hotel_name);
    hotel->hotel_name = (char*) malloc(sizeof(char) * strlen(hotel_name));
    strcpy(hotel->hotel_name, hotel_name);

    int num_of_rooms;
    printf("Enter number of rooms: ");
    scanf("%d", &num_of_rooms);
    hotel->num_of_rooms = num_of_rooms;

    Room* rooms = (Room*) malloc(sizeof(Room) * num_of_rooms);

    for (int i = 0; i < num_of_rooms; i++) {
        char room_type[50];
        int num_of_bed;
        int room_rate;

        printf("Enter room %d details:\n", i + 1);
        printf("Enter room type: ");
        scanf("%s", room_type);
        rooms[i].room_type = (char*) malloc(sizeof(char) * strlen(room_type));
        strcpy(rooms[i].room_type, room_type);

        printf("Enter number of beds: ");
        scanf("%d", &num_of_bed);
        rooms[i].num_of_bed = num_of_bed;

        printf("Enter room rate: ");
        scanf("%d", &room_rate);
        rooms[i].room_rate = room_rate;
    }

    hotel->rooms = rooms;

    printf("Hotel details:\n");
    printf("Name: %s\n", hotel->hotel_name);
    printf("Number of rooms: %d\n", hotel->num_of_rooms);
    printf("Rooms:\n");
    for (int i = 0; i < num_of_rooms; i++) {
        printf("Room %d: %s, %d bed(s), $%d/night\n", i + 1, rooms[i].room_type, rooms[i].num_of_bed, rooms[i].room_rate);
    }

    return 0;
}