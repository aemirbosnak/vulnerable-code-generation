//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

typedef struct {
    int room_number;
    char type[20];
    int price;
    int status;
} room;

room hotel[MAX];

void main() {
    int choice, i, j, n, flag = FALSE;

    printf("\nWelcome to the Surreal Hotel Management System\n");
    printf("Please select an option:\n");
    printf("1. Check-in\n2. Check-out\n3. Room status\n4. Exit\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter number of rooms: ");
            scanf("%d", &n);

            for(i = 0; i < n; i++) {
                printf("Enter room number: ");
                scanf("%d", &hotel[i].room_number);
                printf("Enter room type: ");
                scanf("%s", hotel[i].type);
                printf("Enter room price: ");
                scanf("%d", &hotel[i].price);
                printf("Enter room status (0 for vacant, 1 for occupied): ");
                scanf("%d", &hotel[i].status);
            }

            break;

        case 2:
            printf("Enter room number: ");
            scanf("%d", &n);

            for(i = 0; i < MAX; i++) {
                if(hotel[i].room_number == n && hotel[i].status == 1) {
                    hotel[i].status = 0;
                    printf("\nRoom %d has been vacated successfully\n", n);
                    flag = TRUE;
                }
            }

            if(flag == FALSE)
                printf("\nRoom not found\n");

            break;

        case 3:
            printf("Enter room number: ");
            scanf("%d", &n);

            for(i = 0; i < MAX; i++) {
                if(hotel[i].room_number == n) {
                    if(hotel[i].status == 0)
                        printf("\nRoom %d is vacant\n", n);
                    else
                        printf("\nRoom %d is occupied\n", n);

                    flag = TRUE;
                }
            }

            if(flag == FALSE)
                printf("\nRoom not found\n");

            break;

        case 4:
            exit(0);

        default:
            printf("\nInvalid choice\n");
    }
}