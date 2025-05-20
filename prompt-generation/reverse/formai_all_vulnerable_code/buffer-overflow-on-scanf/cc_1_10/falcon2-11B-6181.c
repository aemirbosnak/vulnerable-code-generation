//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_ROOM_NAME 20
#define MAX_CHECK_IN_DATE 20
#define MAX_CHECK_OUT_DATE 20
#define MAX_GUEST_NAME 20
#define MAX_GUEST_NUM 5

struct room_info {
    char room_name[MAX_ROOM_NAME];
    char check_in_date[MAX_CHECK_IN_DATE];
    char check_out_date[MAX_CHECK_OUT_DATE];
    char guest_name[MAX_GUEST_NAME];
    int guest_num;
};

int main() {
    struct room_info rooms[MAX_ROOMS];
    int num_rooms = 0;

    printf("Welcome to the Hotel Management System!\n");
    printf("Please enter the number of rooms:\n");
    int num_rooms_input;
    scanf("%d", &num_rooms_input);

    for (int i = 0; i < num_rooms_input; i++) {
        printf("Enter room name:\n");
        scanf("%s", rooms[i].room_name);

        printf("Enter check-in date (YYYY-MM-DD):\n");
        scanf("%s", rooms[i].check_in_date);

        printf("Enter check-out date (YYYY-MM-DD):\n");
        scanf("%s", rooms[i].check_out_date);

        printf("Enter guest name:\n");
        scanf("%s", rooms[i].guest_name);

        printf("Enter number of guests:\n");
        scanf("%d", &rooms[i].guest_num);

        num_rooms++;
    }

    printf("Rooms added successfully!\n");

    return 0;
}