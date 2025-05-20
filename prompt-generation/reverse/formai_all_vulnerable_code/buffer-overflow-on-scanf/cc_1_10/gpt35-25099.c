//FormAI DATASET v1.0 Category: Hotel Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

typedef struct Hotel {
    int room_num;
    int vacant;
    int price;
    char name[50];
} Hotel;

void display(Hotel *h, int n) {
    printf("\nRoom Num.\tName\t\tVacancy\tPrice\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%s\t\t%d\t\t%d\n", h[i].room_num, h[i].name, h[i].vacant, h[i].price);
    }
}

void check_in(Hotel *h, int n) {
    int room;
    printf("Enter room number: ");
    scanf("%d", &room);
    for (int i = 0; i < n; i++) {
        if (h[i].room_num == room) {
            if (h[i].vacant == 1) {
                printf("Enter guest name: ");
                scanf("%s", h[i].name);
                h[i].vacant = 0;
                printf("Checked in successfully!\n");
            } else {
                printf("Room is already occupied.\n");
            }
            return;
        }
    }
    printf("Invalid room number.\n");
}

void check_out(Hotel *h, int n) {
    int room;
    printf("Enter room number: ");
    scanf("%d", &room);
    for (int i = 0; i < n; i++) {
        if (h[i].room_num == room) {
            if (h[i].vacant == 0) {
                printf("Guest %s checked out successfully.\n", h[i].name);
                h[i].vacant = 1;
                h[i].name[0] = '\0';
            } else {
                printf("Room is not occupied.\n");
            }
            return;
        }
    }
    printf("Invalid room number.\n");
}

void search(Hotel *h, int n) {
    int min, max;
    printf("Enter minimum and maximum price range (separated by space): ");
    scanf("%d %d", &min, &max);
    printf("\nRoom Num.\tName\t\tVacancy\tPrice\n");
    for (int i = 0; i < n; i++) {
        if (h[i].price >= min && h[i].price <= max) {
            printf("%d\t\t%s\t\t%d\t\t%d\n", h[i].room_num, h[i].name, h[i].vacant, h[i].price);
        }
    }
}

int main() {
    int n;
    printf("Enter number of rooms: ");
    scanf("%d", &n);

    Hotel *h = (Hotel*) malloc(n * sizeof(Hotel));

    for (int i = 0; i < n; i++) {
        h[i].room_num = i+1;
        h[i].vacant = 1;
        if (i < 10) {
            h[i].price = 100;
        } else if (i < 20) {
            h[i].price = 150;
        } else {
            h[i].price = 200;
        }
    }

    int choice;
    while (1) {
        printf("\n1. Display\n2. Check-in\n3. Check-out\n4. Search\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display(h, n);
                break;
            case 2:
                check_in(h, n);
                break;
            case 3:
                check_out(h, n);
                break;
            case 4:
                search(h, n);
                break;
            case 5:
                printf("Quitting program...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    free(h);
    return 0;
}