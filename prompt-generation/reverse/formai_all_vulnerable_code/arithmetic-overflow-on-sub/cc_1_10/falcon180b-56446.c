//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return a > b? a : b;
}

int min(int a, int b) {
    return a < b? a : b;
}

int count_rooms(int *rooms, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (rooms[i] == 1) {
            count++;
        }
    }
    return count;
}

void print_rooms(int *rooms, int size) {
    for (int i = 0; i < size; i++) {
        if (rooms[i] == 1) {
            printf("%d ", i+1);
        }
    }
    printf("\n");
}

void find_rooms(int *rooms, int size, int start, int end, int guests) {
    if (start > end) {
        return;
    }
    int mid = (start + end) / 2;
    if (count_rooms(rooms, size) >= guests) {
        printf("Rooms available from %d to %d\n", start, end);
        return;
    }
    if (count_rooms(rooms, size) + mid >= guests) {
        rooms[mid] = 1;
        find_rooms(rooms, size, mid+1, end, guests);
    } else {
        find_rooms(rooms, size, start, mid-1, guests);
    }
}

int main() {
    int size;
    printf("Enter the number of rooms: ");
    scanf("%d", &size);
    int *rooms = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        rooms[i] = 0;
    }
    int guests;
    printf("Enter the number of guests: ");
    scanf("%d", &guests);
    find_rooms(rooms, size, 0, size-1, guests);
    printf("Rooms booked: ");
    print_rooms(rooms, size);
    free(rooms);
    return 0;
}