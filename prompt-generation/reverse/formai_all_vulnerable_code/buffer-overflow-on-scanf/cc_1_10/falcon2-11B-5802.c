//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>

typedef struct Room {
    int room_id;
    char room_type[50];
    int no_of_beds;
    double room_rate;
    int no_of_rooms;
} Room;

typedef struct Hotel {
    char hotel_name[50];
    int no_of_floors;
    int no_of_rooms;
    Room* rooms;
} Hotel;

int main() {
    Hotel* hotel = (Hotel*)malloc(sizeof(Hotel));

    printf("Enter hotel name: ");
    scanf("%s", hotel->hotel_name);

    printf("Enter number of floors: ");
    scanf("%d", &hotel->no_of_floors);

    printf("Enter number of rooms: ");
    scanf("%d", &hotel->no_of_rooms);

    Room* rooms = (Room*)malloc(hotel->no_of_rooms * sizeof(Room));

    for (int i = 0; i < hotel->no_of_rooms; i++) {
        printf("Enter room details for room %d: ", i+1);
        printf("Enter room id: ");
        scanf("%d", &rooms[i].room_id);
        printf("Enter room type: ");
        scanf("%s", rooms[i].room_type);
        printf("Enter number of beds: ");
        scanf("%d", &rooms[i].no_of_beds);
        printf("Enter room rate: ");
        scanf("%lf", &rooms[i].room_rate);
        printf("Enter number of rooms: ");
        scanf("%d", &rooms[i].no_of_rooms);
    }

    hotel->rooms = rooms;

    printf("Hotel details:\n");
    printf("Name: %s\n", hotel->hotel_name);
    printf("Floors: %d\n", hotel->no_of_floors);
    printf("Rooms: %d\n", hotel->no_of_rooms);

    free(rooms);
    free(hotel);

    return 0;
}