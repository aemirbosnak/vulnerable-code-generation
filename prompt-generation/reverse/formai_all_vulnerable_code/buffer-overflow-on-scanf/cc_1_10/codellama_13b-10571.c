//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: surrealist
void main() {
    int room_num, floor, num_rooms, i;
    char room_type;
    float price;
    struct hotel {
        int room_num;
        int floor;
        char room_type;
        float price;
    };

    printf("Welcome to the surrealist hotel management system!\n");
    printf("Please enter the number of rooms: ");
    scanf("%d", &num_rooms);

    struct hotel rooms[num_rooms];

    for (i = 0; i < num_rooms; i++) {
        printf("Enter room number: ");
        scanf("%d", &room_num);
        printf("Enter floor: ");
        scanf("%d", &floor);
        printf("Enter room type (S/D/L): ");
        scanf("%c", &room_type);
        printf("Enter price: ");
        scanf("%f", &price);

        rooms[i].room_num = room_num;
        rooms[i].floor = floor;
        rooms[i].room_type = room_type;
        rooms[i].price = price;
    }

    printf("Room Num\tFloor\tRoom Type\tPrice\n");
    for (i = 0; i < num_rooms; i++) {
        printf("%d\t%d\t%c\t%.2f\n", rooms[i].room_num, rooms[i].floor, rooms[i].room_type, rooms[i].price);
    }

    printf("Enter room number to check availability: ");
    scanf("%d", &room_num);
    for (i = 0; i < num_rooms; i++) {
        if (rooms[i].room_num == room_num) {
            printf("Room %d is available for booking!\n", room_num);
            break;
        }
    }
    if (i == num_rooms) {
        printf("Sorry, room %d is not available.\n", room_num);
    }
}