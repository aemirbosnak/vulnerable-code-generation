//FormAI DATASET v1.0 Category: Hotel Management System ; Style: complex
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX_HOTELS 5 
#define MAX_ROOMS 10 

struct room { 
    int id; 
    int size; 
    int available; 
}; 

struct hotel { 
    char name[50]; 
    struct room rooms[MAX_ROOMS]; 
}; 

struct hotel hotels[MAX_HOTELS]; 

int n = 0; 

void createHotel() { 
    // Get hotel name 
    printf("\nEnter hotel name: "); 
    scanf("%s", hotels[n].name); 

    // Initialize rooms 
    for(int i = 0; i < MAX_ROOMS; i++) { 
        hotels[n].rooms[i].id = i + 1; 
        hotels[n].rooms[i].size = rand() % 3 + 1; 
        hotels[n].rooms[i].available = 1; 
    } 

    printf("\nHotel %s created with %d rooms.", hotels[n].name, MAX_ROOMS); 
    n++; 
} 

void bookRoom() { 
    char hotel[50]; 
    int room_id; 

    printf("\nEnter hotel name: "); 
    scanf("%s", hotel); 

    for(int i = 0; i < n; i++) { 
        if(strcmp(hotels[i].name, hotel) == 0) { 
            printf("\n%s\n", hotels[i].name); 
            printf("--------------------------------\n"); 

            for(int j = 0; j < MAX_ROOMS; j++) { 
                printf("Room id: %d\n", hotels[i].rooms[j].id); 
                printf("Size: %d\n", hotels[i].rooms[j].size); 
                printf("Availability: %d\n", hotels[i].rooms[j].available); 

                if(hotels[i].rooms[j].available == 1) { 
                    printf("Would you like to book this room? (1 = Yes, 0 = No)"); 
                    scanf("%d", &room_id); 

                    if(room_id == 1) { 
                        hotels[i].rooms[j].available = 0; 
                        printf("\nRoom %d booked successfully.", hotels[i].rooms[j].id); 
                        return; 
                    } 
                } 
            } 

            printf("Sorry, all of our rooms are booked. Please try again later."); 
            return; 
        } 
    } 

    printf("Sorry, hotel not found."); 
} 

void displayHotels() { 
    printf("\nHotels"); 
    printf("\n--------------------------------\n"); 

    for(int i = 0; i < n; i++) { 
        printf("%s\n", hotels[i].name); 
    } 
} 

int main() { 
    int choice; 

    while(1) { 
        printf("\n\nHotel Management System\n"); 
        printf("--------------------------------\n"); 
        printf("1. Create hotel\n"); 
        printf("2. Book room\n"); 
        printf("3. Display hotels\n"); 
        printf("4. Exit\n"); 

        printf("\nEnter your choice: "); 
        scanf("%d", &choice); 

        switch(choice) { 
            case 1: 
                createHotel(); 
                break; 

            case 2: 
                bookRoom(); 
                break; 

            case 3: 
                displayHotels(); 
                break; 

            case 4: 
                exit(0); 
        } 
    } 

    return 0; 
}