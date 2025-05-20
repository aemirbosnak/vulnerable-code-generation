//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ROOMS 100
#define MAX_NAME_LEN 20
#define MAX_PHONE_LEN 10
#define MAX_STREET_LEN 30
#define MAX_CITY_LEN 20
#define MAX_STATE_LEN 2
#define MAX_ZIP_LEN 5
#define MAX_RES_LEN 30
#define MAX_NOTES_LEN 100

struct room {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char street[MAX_STREET_LEN];
    char city[MAX_CITY_LEN];
    char state[MAX_STATE_LEN];
    char zip[MAX_ZIP_LEN];
    char room_type[MAX_RES_LEN];
    char notes[MAX_NOTES_LEN];
};

struct room rooms[MAX_ROOMS];
int num_rooms = 0;

int main() {
    int choice = 0;
    int index = 0;
    char input[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char street[MAX_STREET_LEN];
    char city[MAX_CITY_LEN];
    char state[MAX_STATE_LEN];
    char zip[MAX_ZIP_LEN];
    char room_type[MAX_RES_LEN];
    char notes[MAX_NOTES_LEN];
    int i;

    printf("Welcome to the C Hotel Management System!\n");

    while (1) {
        printf("1. Add a room\n");
        printf("2. Display room information\n");
        printf("3. Update room information\n");
        printf("4. Delete a room\n");
        printf("5. Search for a room\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the room name: ");
                fgets(input, MAX_NAME_LEN, stdin);
                input[strcspn(input, "\n")] = 0;
                strcpy(rooms[index].name, input);
                printf("Enter the room phone number: ");
                fgets(phone, MAX_PHONE_LEN, stdin);
                phone[strcspn(phone, "\n")] = 0;
                strcpy(rooms[index].phone, phone);
                printf("Enter the room street address: ");
                fgets(street, MAX_STREET_LEN, stdin);
                street[strcspn(street, "\n")] = 0;
                strcpy(rooms[index].street, street);
                printf("Enter the room city: ");
                fgets(city, MAX_CITY_LEN, stdin);
                city[strcspn(city, "\n")] = 0;
                strcpy(rooms[index].city, city);
                printf("Enter the room state: ");
                fgets(state, MAX_STATE_LEN, stdin);
                state[strcspn(state, "\n")] = 0;
                strcpy(rooms[index].state, state);
                printf("Enter the room zip code: ");
                fgets(zip, MAX_ZIP_LEN, stdin);
                zip[strcspn(zip, "\n")] = 0;
                strcpy(rooms[index].zip, zip);
                printf("Enter the room type: ");
                fgets(room_type, MAX_RES_LEN, stdin);
                room_type[strcspn(room_type, "\n")] = 0;
                strcpy(rooms[index].room_type, room_type);
                printf("Enter the room notes: ");
                fgets(notes, MAX_NOTES_LEN, stdin);
                notes[strcspn(notes, "\n")] = 0;
                strcpy(rooms[index].notes, notes);
                num_rooms++;
                index++;
                break;
            case 2:
                printf("Room Name\t\tRoom Phone\t\tRoom Street\t\tRoom City\t\tRoom State\t\tRoom Zip\t\tRoom Type\t\tRoom Notes\n");
                for (i = 0; i < num_rooms; i++) {
                    printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",
                            rooms[i].name, rooms[i].phone, rooms[i].street, rooms[i].city, rooms[i].state, rooms[i].zip, rooms[i].room_type, rooms[i].notes);
                }
                break;
            case 3:
                printf("Enter the room index to update: ");
                fgets(input, MAX_NAME_LEN, stdin);
                input[strcspn(input, "\n")] = 0;
                index = atoi(input);
                if (index >= 0 && index < num_rooms) {
                    printf("Enter the new room name: ");
                    fgets(input, MAX_NAME_LEN, stdin);
                    input[strcspn(input, "\n")] = 0;
                    strcpy(rooms[index].name, input);
                    printf("Enter the new room phone number: ");
                    fgets(phone, MAX_PHONE_LEN, stdin);
                    phone[strcspn(phone, "\n")] = 0;
                    strcpy(rooms[index].phone, phone);
                    printf("Enter the new room street address: ");
                    fgets(street, MAX_STREET_LEN, stdin);
                    street[strcspn(street, "\n")] = 0;
                    strcpy(rooms[index].street, street);
                    printf("Enter the new room city: ");
                    fgets(city, MAX_CITY_LEN, stdin);
                    city[strcspn(city, "\n")] = 0;
                    strcpy(rooms[index].city, city);
                    printf("Enter the new room state: ");
                    fgets(state, MAX_STATE_LEN, stdin);
                    state[strcspn(state, "\n")] = 0;
                    strcpy(rooms[index].state, state);
                    printf("Enter the new room zip code: ");
                    fgets(zip, MAX_ZIP_LEN, stdin);
                    zip[strcspn(zip, "\n")] = 0;
                    strcpy(rooms[index].zip, zip);
                    printf("Enter the new room type: ");
                    fgets(room_type, MAX_RES_LEN, stdin);
                    room_type[strcspn(room_type, "\n")] = 0;
                    strcpy(rooms[index].room_type, room_type);
                    printf("Enter the new room notes: ");
                    fgets(notes, MAX_NOTES_LEN, stdin);
                    notes[strcspn(notes, "\n")] = 0;
                    strcpy(rooms[index].notes, notes);
                } else {
                    printf("Invalid room index!\n");
                }
                break;
            case 4:
                printf("Enter the room index to delete: ");
                fgets(input, MAX_NAME_LEN, stdin);
                input[strcspn(input, "\n")] = 0;
                index = atoi(input);
                if (index >= 0 && index < num_rooms) {
                    num_rooms--;
                    for (i = index; i < num_rooms; i++) {
                        rooms[i] = rooms[i + 1];
                    }
                } else {
                    printf("Invalid room index!\n");
                }
                break;
            case 5:
                printf("Enter the search criteria: ");
                fgets(input, MAX_NAME_LEN, stdin);
                input[strcspn(input, "\n")] = 0;
                for (i = 0; i < num_rooms; i++) {
                    if (strstr(rooms[i].name, input) || strstr(rooms[i].phone, input) || strstr(rooms[i].street, input) || strstr(rooms[i].city, input) || strstr(rooms[i].state, input) || strstr(rooms[i].zip, input) || strstr(rooms[i].room_type, input) || strstr(rooms[i].notes, input)) {
                        printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",
                                rooms[i].name, rooms[i].phone, rooms[i].street, rooms[i].city, rooms[i].state, rooms[i].zip, rooms[i].room_type, rooms[i].notes);
                    }
                }
                break;
            case 6:
                printf("Quitting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}