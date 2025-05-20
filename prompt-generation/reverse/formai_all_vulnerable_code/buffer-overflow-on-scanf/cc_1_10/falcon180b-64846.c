//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_DISKS 10

typedef struct {
    int from_rod;
    int to_rod;
    int top_disk;
} move_t;

void* move_disk(void* arg) {
    move_t* move = (move_t*) arg;
    int i;

    for(i = move->top_disk; i > 0; i--) {
        printf("Move disk %d from rod %d to rod %d\n", i, move->from_rod, move->to_rod);
        sleep(1);
    }

    printf("Move disk %d from rod %d to rod %d\n", move->top_disk, move->from_rod, move->to_rod);

    pthread_exit(0);
}

void tower_of_hanoi(int n_disks, int from_rod, int to_rod, int aux_rod) {
    if(n_disks == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from_rod, to_rod);
        return;
    }

    tower_of_hanoi(n_disks - 1, from_rod, aux_rod, to_rod);

    move_t move;
    move.from_rod = from_rod;
    move.to_rod = to_rod;
    move.top_disk = n_disks;

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, move_disk, (void*) &move);

    pthread_join(thread_id, NULL);

    tower_of_hanoi(n_disks - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n_disks;

    printf("Enter the number of disks: ");
    scanf("%d", &n_disks);

    if(n_disks < 1 || n_disks > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }

    tower_of_hanoi(n_disks, 'A', 'C', 'B');

    return 0;
}